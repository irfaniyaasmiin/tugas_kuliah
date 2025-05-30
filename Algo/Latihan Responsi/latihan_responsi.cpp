#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    string album;
};

struct Node {
    Lagu* data;
    Node* next;
};

Node* head = nullptr;              // Daftar lagu utama (sorted)
Node* antrianDepan = nullptr;      // Antrian lagu manual (FIFO)
Node* antrianBelakang = nullptr;
Node* stackUndo = nullptr;         // Stack undo hapus (LIFO manual)

// Fungsi buat node baru
Node* buatNode(string judul, string penyanyi, string album) {
    Lagu* laguBaru = new Lagu{judul, penyanyi, album};
    Node* nodeBaru = new Node{laguBaru, nullptr};
    return nodeBaru;
}

// Tambah lagu ke list utama (urut A-Z)
void tambahLagu() {
    string judul, penyanyi, album;
    cout << "Judul      : "; getline(cin >> ws, judul);
    cout << "Penyanyi   : "; getline(cin, penyanyi);
    cout << "Album      : "; getline(cin, album);

    Node* baru = buatNode(judul, penyanyi, album);

    if (!head || judul < head->data->judul) {
        baru->next = head;
        head = baru;
    } else {
        Node* curr = head;
        while (curr->next && curr->next->data->judul < judul)
            curr = curr->next;
        baru->next = curr->next;
        curr->next = baru;
    }

    cout << "Lagu berhasil ditambahkan.\n";
    cin.get();
}

// Lihat semua lagu
void lihatDaftar() {
    if (!head) {
        cout << "Daftar lagu kosong.\n";
    } else {
        cout << "\n=== Daftar Lagu ===\n";
        Node* curr = head;
        while (curr) {
            cout << curr->data->judul << " - " << curr->data->penyanyi << " | " << curr->data->album << "\n";
            curr = curr->next;
        }
    }
    cin.ignore(); // Flush newline
    cin.get();    // Tunggu Enter
}

// Cari lagu
void cariLagu() {
    string judul;
    cout << "Judul yang dicari: "; getline(cin >> ws, judul);
    Node* curr = head;
    while (curr) {
        if (curr->data->judul == judul) {
            cout << "Lagu ditemukan: " << curr->data->judul << " - " << curr->data->penyanyi << " - " << curr->data->album << endl;
            cin.get();
            return;
        }
        curr = curr->next;
    }
    cout << "Lagu tidak ditemukan.\n";
    cin.get();
}

// Tambah ke antrian (manual FIFO pakai linked list)
void tambahAntrian() {
    string judul;
    lihatDaftar();
    cout << "Judul lagu ke antrian: "; getline(cin >> ws, judul);

    Node* curr = head;
    while (curr && curr->data->judul != judul)
        curr = curr->next;

    if (!curr) {
        cout << "Lagu tidak ditemukan." << endl;
        cin.get();
        return;
    }

    Node* nodeAntrian = new Node{curr->data, nullptr};
    if (!antrianDepan) {
        antrianDepan = antrianBelakang = nodeAntrian;
    } else {
        antrianBelakang->next = nodeAntrian;
        antrianBelakang = nodeAntrian;
    }

    cout << "Lagu ditambahkan ke antrian.\n";
    cin.get();
}

// Putar lagu (ambil dari antrian depan)
void putarLagu() {
    if (!antrianDepan) {
        cout << "Antrian kosong.\n";
    } else {
        Node* diputar = antrianDepan;
        cout << "Memutar: " << diputar->data->judul << " - " << diputar->data->penyanyi << " - " << diputar->data->album << "\n";
        antrianDepan = antrianDepan->next;
        if (!antrianDepan) antrianBelakang = nullptr;
        delete diputar;
    }

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore(); // Flush newline dari input sebelumnya
    cin.get();    // Tunggu Enter
}

// Tambah ke stack undo
void tambahUndo(Lagu* lagu) {
    Node* nodeUndo = new Node{lagu, stackUndo};
    stackUndo = nodeUndo;
}

// Undo penghapusan terakhir
void undoHapus() {
    if (!stackUndo) {
        cout << "Tidak ada lagu untuk di-undo.\n";
    } else {
        Lagu* lagu = stackUndo->data;
        Node* baru = new Node{lagu, nullptr};

        // Insert kembali ke list utama (berurutan berdasarkan judul)
        if (!head || lagu->judul < head->data->judul) {
            baru->next = head;
            head = baru;
        } else {
            Node* curr = head;
            while (curr->next && curr->next->data->judul < lagu->judul)
                curr = curr->next;
            baru->next = curr->next;
            curr->next = baru;
        }

        Node* temp = stackUndo;
        stackUndo = stackUndo->next;
        delete temp;

        cout << "Lagu berhasil dikembalikan.\n";
    }

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore(); // Buang newline dari input sebelumnya
    cin.get();    // Tunggu enter
}

// Hapus lagu dari daftar utama
void hapusLagu() {
    string judul;
    cout << "Judul lagu yang ingin dihapus: "; getline(cin >> ws, judul);

    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        if (curr->data->judul == judul) {
            if (prev) prev->next = curr->next;
            else head = curr->next;

            tambahUndo(curr->data);
            delete curr;
            cout << "Lagu berhasil dihapus (bisa di-undo).\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Lagu tidak ditemukan.\n";
    cin.get();
}

// Menu utama
void menu() {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== Spotify KW 100 ===\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Cari Lagu\n";
        cout << "3. Lihat Daftar Lagu\n";
        cout << "4. Tambah ke Antrian\n";
        cout << "5. Putar Lagu\n";
        cout << "6. Hapus Lagu\n";
        cout << "7. Undo Hapus\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        system("cls");
        switch (pilihan) {
            case 1: tambahLagu(); break;
            case 2: cariLagu(); break;
            case 3: lihatDaftar(); break;
            case 4: tambahAntrian(); break;
            case 5: putarLagu(); break;
            case 6: hapusLagu(); break;
            case 7: undoHapus(); break;
            case 0: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid."; cin.get();
        }
    } while (pilihan != 0);
    system("pause");
    system("cls");
}

int main() {
    system("cls");
    menu();
    // cin.ignore();
    // cin.get();
    return 0;
}
