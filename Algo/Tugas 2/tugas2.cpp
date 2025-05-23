#include <iostream>
#include <string>

using namespace std;

const int MAX = 50;

struct Pesanan {
    string nama;
    string jenis_roti;
    double total_harga;
};

struct Queue {
    Pesanan data[MAX];
    int front = 0, rear = -1;

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(Pesanan p) {
        if (isFull()) {
            cout << "Antrean penuh!\n";
            return;
        }
        data[++rear] = p;
    }

    Pesanan dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
            return {};
        }
        return data[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrean kosong.\n";
            return;
        }
        for (int i = front; i <= rear; ++i) {
            cout << i - front + 1 << ". " << data[i].nama << " - " << data[i].jenis_roti << " - Rp" << data[i].total_harga << endl;
        }
    }

    Pesanan removeLast() {
        if (isEmpty()) {
            cout << "Antrean kosong.\n";
            return {};
        }
        return data[rear--];
    }
};

struct Stack {
    Pesanan data[MAX];
    int top = -1;

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(Pesanan p) {
        if (isFull()) {
            cout << "Stack penuh!\n";
            return;
        }
        data[++top] = p;
    }

    Pesanan pop() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return {};
        }
        return data[top--];
    }

    Pesanan peek() {
        if (isEmpty()) return {};
        return data[top];
    }
};

struct History {
    Pesanan data[MAX];
    int count = 0;

    void add(Pesanan p) {
        if (count < MAX) {
            data[count++] = p;
        }
    }

    void display() {
        if (count == 0) {
            cout << "Belum ada riwayat pesanan.\n";
            return;
        }
        for (int i = 0; i < count; ++i) {
            cout << i + 1 << ". " << data[i].nama << " - " << data[i].jenis_roti << " - Rp" << data[i].total_harga << endl;
        }
    }
};

Queue antrean;
Stack pembatalan;
History riwayat;

void ambilAntrean() {
    Pesanan p;
    cout << "Nama Pembeli   : ";
    getline(cin >> ws, p.nama);
    cout << "Jenis Roti     : ";
    getline(cin, p.jenis_roti);
    cout << "Total Harga    : ";
    cin >> p.total_harga;

    antrean.enqueue(p);
    pembatalan.push(p);
    cout << "Pesanan berhasil ditambahkan ke antrean.\n";
}

void layaniPembeli() {
    if (!antrean.isEmpty()) {
        Pesanan p = antrean.dequeue();
        riwayat.add(p);

        if (!pembatalan.isEmpty()) pembatalan.pop();

        cout << "Pesanan atas nama " << p.nama << " telah dilayani.\n";
    } else {
        cout << "Tidak ada antrean untuk dilayani.\n";
    }
}

void batalkanPesanan() {
    if (!pembatalan.isEmpty()) {
        Pesanan p = pembatalan.pop();
        antrean.removeLast();
        cout << "Pesanan atas nama " << p.nama << " telah dibatalkan.\n";
    } else {
        cout << "Tidak ada pesanan untuk dibatalkan.\n";
    }
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "== Cashier Toko Roti Manis Lezat ==\n" << endl;
        cout << "1. Buat Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan dalam Antrean\n";
        cout << "4. Batalkan Pesanan Terakhir\n";
        cout << "5. Tampilkan Riwayat Pesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        system("cls");

        switch (pilihan) {
            case 1: 
                cout << "Buat Antrian\n" << endl;
                ambilAntrean(); 
                cin.ignore();
                cin.get();
                break;
            case 2: 
                layaniPembeli();
                cin.get();
                break;
            case 3: 
                cout << "Daftar Antrian\n" << endl;
                antrean.display();
                cin.get(); 
                break;
            case 4: 
                batalkanPesanan(); 
                cin.get();
                break;
            case 5: 
                cout << "Riwayat Pesanan\n" << endl;
                riwayat.display(); 
                cin.get();
                break;
            case 0:
                cout << "Terima kasih!\n";
                system("pause");
                break;
            default: 
                cout << "Pilihan tidak valid.\n"; 
                cin.get();
                break;
        }
    } while (pilihan != 0);
    system("cls");
    return 0;
}
