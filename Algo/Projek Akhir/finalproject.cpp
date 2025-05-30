#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits> // untuk numeric_limits
using namespace std;

const int ROW = 5, COL = 5; // Konstanta jumlah baris dan kolom kursi bioskop

// Struktur data untuk menyimpan informasi pemesan kursi
struct Kursi {
    string nama;
};

// Struktur data untuk menyimpan informasi film dan kursinya
struct Film {
    string judul;
    Kursi kursi[ROW][COL];
    Film* next;
};

Film* head = nullptr;

// Fungsi login untuk autentikasi admin
bool login() {
    system("cls");
    string u, p;
    cout << "Login to System\n" << endl;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    return u == "admin" && p == "1234";
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
    return 0;
}

// Menampilkan semua film yang tersedia
void lihatDaftarFilm() {
    if (!head) {
        cout << "\nTidak ada film!" << endl;
        return;
    } else {
        urutkanFilmByJudul(); // mengurutkan sebelum menampilkan
        int i = 1;
        Film* temp = head;
        cout << "\n";
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
Film* pilihFilm(bool allowAdd = true) {
    lihatDaftarFilm();
    if (!head) {
        return 0;
    } else {
        cout << "Cari judul film: ";
        cin.ignore();
        string judul;
        getline(cin, judul);

        Film* temp = cariFilmByJudul(judul);  // Search by title
        if (!temp) {
            cout << "\nFilm " << judul << " tidak ditemukan.\n";
            return 0;
        } 
        return temp;
    }
}

// Pembelian tiket dan menyimpan ke file
void beliTiket() {
    cout << "Pembelian Tiket" << endl;
    Film* film = pilihFilm();
    if (!film) {
        system("pause");
        return;
    }
    
    tampilkanKursi(film);
    int r, c;
    cout << "Pilih baris (0-" << ROW-1 << "): "; cin >> r;
    cout << "Pilih kolom (0-" << COL-1 << "): "; cin >> c;

    if (film->kursi[r][c].nama != "kosong") {
        cout << "\nKursi sudah terisi." << endl;
        system("pause");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    string nama;
    cout << "Nama pemesan: "; cin >> nama;
    film->kursi[r][c].nama = nama;

    string fileNama = "tiket_" + nama + ".txt";
    ofstream file(fileNama);
    file << "Tiket Bioskop\n";
    file << "Nama      : " << nama << "\n";
    file << "Film      : " << film->judul << "\n";
    file << "Kursi     : Baris " << r << ", Kolom " << c << "\n";
    file.close();

    cout << "\nTiket berhasil dibeli!";
    cout << "\nFile: " << fileNama << endl;
    system("pause");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Pembatalan tiket (mengosongkan kursi)
void batalTiket() {
    cout << "Pembatalan Tiket" << endl;
    Film* film = pilihFilm(false);
    if (!film) {
        system("pause");
        return;
    }
    
    tampilkanKursi(film);
    int r, c;
    cout << "Baris (0-" << ROW-1 << "): "; cin >> r;
    cout << "Kolom (0-" << COL-1 << "): "; cin >> c;

    if (film->kursi[r][c].nama == "kosong") {
        cout << "\nPembatalan gagal! Kursi kosong.\n";
        system("pause");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << "\nTiket atas nama " << film->kursi[r][c].nama << " dibatalkan.\n";
    film->kursi[r][c].nama = "kosong";
    
    system("pause");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Kosongkan semua kursi dalam suatu film
void resetKursi() {
    cout << "Reset Kursi" << endl;
    Film* film = pilihFilm(false);
    if (!film) {
        system("pause");
        return;
    }

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            film->kursi[i][j].nama = "kosong";
            
    cout << endl << "Semua kursi berhasil direset." << endl;
    system("pause");
}

// Fungsi menu
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
        
        switch (pilihan) {
            case 1: 
                tambahFilm();
                cin.get();
                break;
            case 2: 
                cout << "Daftar Film\n";
                lihatDaftarFilm(); 
                cin.ignore();
                cin.get();
                break;
            case 3: 
                beliTiket(); 
                break;  
            case 4: 
                batalTiket(); 
                break; 
            case 5: 
                resetKursi(); 
                break;  
            case 0: 
                break;
            default: 
                cout << "Pilihan tidak valid.\n";
                cin.ignore();
                cin.get();
                break;
        }
    } while (pilihan != 0);
}

// Menu utama
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
