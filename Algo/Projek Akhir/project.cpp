#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int ROW = 5, COL = 5; // Konstanta jumlah baris dan kolom kursi bioskop

// Struktur data untuk menyimpan informasi pemesan kursi
struct Kursi {
    string nama; // Nama pemesan kursi
};

// Struktur data untuk menyimpan informasi film dan kursinya
struct Film {
    string judul; // Judul film
    Kursi kursi[ROW][COL]; // Matriks kursi 5x5
    Film* next; // Pointer ke film berikutnya
};

Film* head = nullptr; // Head linked list

// Fungsi login untuk autentikasi admin
bool login() {
    system("cls");

    string u, p;
    cout << "Login to System\n" << endl;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    return u == "admin" && p == "1234"; // Autentikasi sederhana
}

// Fungsi untuk menambahkan film ke dalam linked list
void tambahFilm() {
    Film* baru = new Film;
    cout << "Tambah Film\n" << endl;
    cout << "Judul film: ";
    cin.ignore();
    getline(cin, baru->judul);
    baru->next = nullptr;

    // Inisialisasi kursi kosong
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            baru->kursi[i][j].nama = "kosong";

    // Menambahkan film ke akhir linked list
    if (!head) head = baru;
    else {
        Film* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }

    cout << "Film berhasil ditambahkan.\n";
}

// Sorting film by title (bubble sort)
void urutkanFilmByJudul() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Film* current = head;
        Film* prev = nullptr;
        while (current && current->next) {
            Film* next = current->next;
            if (current->judul > next->judul) {
                // Swap pointer
                if (prev) prev->next = next;
                else head = next;
                current->next = next->next;
                next->next = current;
                swapped = true;
                prev = next;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

// Searching film by title (linear search)
Film* cariFilmByJudul(string keyword) {
    Film* temp = head;
    while (temp) {
        if (temp->judul == keyword) {
            cout << "\nFilm " << keyword << " ditemukan." << endl;
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Menampilkan semua film yang tersedia
void lihatDaftarFilm() {
    cout << "Daftar Film\n" << endl;
    if (!head) {
        cout << "Tidak ada film.";
        return;
    } else {
        urutkanFilmByJudul(); // mengurutkan sebelum menampilkan
        int i = 1;
        Film* temp = head;
        while (temp) {
            cout << i++ << ". " << temp->judul << "\n";
            temp = temp->next;
        }
    }
}

// Menampilkan status kursi film
void tampilkanKursi(Film* film) {
    cout << "\nKursi Film: " << film->judul << "\n";
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << setw(10) << film->kursi[i][j].nama << " ";
        }
        cout << "\n";
    }
}

// Memilih film berdasarkan title
Film* pilihFilm() {
    lihatDaftarFilm();
    if (!head) {
        return 0;
    } else {
        cout << "Cari judul film: ";
        cin.ignore();
        string judul;
        getline(cin, judul);

        Film* temp = cariFilmByJudul(judul); // Search by title
        if(!temp) {
            cout << "\nFilm " << judul << " tidak ditemukan. Tambahkan film baru? (y/n): ";
            char jawab;
            cin >> jawab;
            cin.ignore();
            if(jawab == 'y' || jawab == 'Y') {
                system("cls");
                tambahFilm(); // Menambahkan film baru jika tidak ditemukan
                temp = cariFilmByJudul(judul); // Pencarian ulang
                if (temp) {
                    tampilkanKursi(temp);
                    return temp;
                } else {
                    cout << "Film belum berhasil ditambahkan.\n";
                    return nullptr;
                }
            } else {
                return 0;
            }
        }
        return temp; // Retrieving film
    } 
}

// Pembelian tiket dan menyimpan ke file
void beliTiket() {
    cout << "Pembelian Tiket\n" << endl;
    Film* film = pilihFilm();
    if (!film) return;
    tampilkanKursi(film);
    int r, c;
    cout << "Pilih baris (0-" << ROW-1 << "): "; cin >> r;
    cout << "Pilih kolom (0-" << COL-1 << "): "; cin >> c;

    // Cek status kursi
    if (film->kursi[r][c].nama != "kosong") {
        cout << "\nKursi sudah terisi.\n";
        return;
    }

    string nama;
    cout << "Nama pemesan: "; cin >> nama;
    film->kursi[r][c].nama = nama;

    // Menyimpan tiket ke file
    string fileNama = "tiket_" + nama + ".txt";
    ofstream file(fileNama);
    file << "Tiket Bioskop\n";
    file << "Nama      : " << nama << "\n";
    file << "Film      : " << film->judul << "\n";
    file << "Kursi     : Baris " << r << ", Kolom " << c << "\n";
    file.close();

    cout << "\nTiket berhasil dibeli!";
    cout << "\nFile: " << fileNama << endl;
}

// Pembatalan tiket (mengosongkan kursi)
void batalTiket() {
    cout << "Pembatalan Tiket\n" << endl;
    Film* film = pilihFilm();
    if (!film) return;
    tampilkanKursi(film);
    int r, c;
    cout << "Baris (0-" << ROW-1 << "): "; cin >> r;
    cout << "Kolom (0-" << COL-1 << "): "; cin >> c;

    // Cek status kursi
    if (film->kursi[r][c].nama == "kosong") {
        cout << "\nPembatalan gagal! Kursi kosong.\n";
        return;
    }

    // Mengosongkan kursi
    film->kursi[r][c].nama = "kosong";
    cout << "\nTiket atas nama " << film->kursi[r][c].nama << " dibatalkan.\n";
}

// Reset semua kursi dalam suatu film
void resetKursi() {
    cout << "Reset Kursi\n" << endl;
    Film* film = pilihFilm();
    if (!film) return;

    // Set semua kursi ke kosong
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            film->kursi[i][j].nama = "kosong";
    cout << "\nSemua kursi berhasil direset.\n";
}

// Menu utama
void menu() {
    int pilihan;
    do {
        system("cls");

        cout << "=== MENU ===\n" << endl;
        cout << "1. Tambah Film\n";
        cout << "2. Lihat Daftar Film\n";
        cout << "3. Pembelian Tiket\n";
        cout << "4. Pembatalan Tiket\n";
        cout << "5. Reset Kursi\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        system("cls");
        
        // Menjalankan fungsi sesuai pilihan user
        switch (pilihan) {
            case 1: 
                tambahFilm();
                cin.get();
                break;
            case 2: 
                lihatDaftarFilm(); 
                cin.ignore();
                cin.get();
                break;
            case 3: 
                beliTiket(); 
                cin.ignore();
                cin.get();
                break;
            case 4: 
                batalTiket(); 
                cin.ignore();
                cin.get();
                break;
            case 5: 
                resetKursi(); 
                cin.ignore();
                cin.get();
                break;
            case 0: 
                break;
            default: 
                cout << "Pilihan tidak valid.\n";
                cin.ignore();
                cin.get();
                break;
        }
    } while (pilihan != 0); // Memu akan terus ditampilkan sampai user memilih keluar
}

// Fungsi utama
int main() {
    if (!login()) {
        cout << "\nLogin gagal.";
        cin.ignore();
        cin.get();
        system("cls");
        return 0;
    } else {
        cout << "\nLogin berhasil.";
        cin.ignore();
        cin.get();
    }

    menu();
    cout << "Exiting Program...\n";
    system("pause");
    system("cls");

}
