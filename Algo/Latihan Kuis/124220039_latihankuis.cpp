#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Pegawai {
    int id;
    string nama;
    double gaji;
};

void bubbleSort(vector<Pegawai> &pegawais) {
    int n = pegawais.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pegawais[j].id > pegawais[j + 1].id) {
                swap(pegawais[j], pegawais[j + 1]);
            }
        }
    }
}

void tambahPegawai() {
    ofstream file("pegawai.dat", ios::app);
    if (!file) {
        cout << "\nGagal membuka file!" << endl;
        return;
    }
    
    int jumlah;
    cout << "\nMasukkan jumlah pegawai yang ingin ditambahkan: ";
    cin >> jumlah;
    vector<Pegawai> pegawais(jumlah);
    
    for (int i = 0; i < jumlah; i++) {
        cout << "\nID Pegawai: "; cin >> pegawais[i].id;

        // Check ID goes here...

        cin.ignore();
        cout << "Nama Pegawai: "; getline(cin, pegawais[i].nama);
        cout << "Gaji Pegawai: "; cin >> pegawais[i].gaji;
        // file << pegawais[i].id << " " << pegawais[i].nama << " " << pegawais[i].gaji << endl;
        file << pegawais[i].id << " \"" << pegawais[i].nama << "\" " << pegawais[i].gaji << endl;
    }
    file.close();

    if(jumlah != 0) {
        cout << "\nPegawai berhasil ditambahkan!";
    } else {
        cout << "\nTidak ada pegawai yang ditambahkan!";
    }
}

void lihatDaftarPegawai() {
    ifstream file("pegawai.dat");
    if (!file) {
        cout << "\nBelum ada data pegawai!" << endl;
        return;
    }

    vector<Pegawai> pegawais;
    Pegawai p;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        iss >> p.id;
        iss.ignore();
        iss >> ws;
        if (iss.peek() == '"') { 
            iss.get();
            getline(iss, p.nama, '"');
        } else {
            iss >> p.nama;
        }

        iss >> p.gaji;
        pegawais.push_back(p);
    }
    file.close();

    if (pegawais.empty()) {
        cout << "\nTidak ada data pegawai!" << endl;
        return;
    }

    bubbleSort(pegawais);

    cout << "\nDaftar Pegawai (Sorted by ID):\n";
    for (const auto& peg : pegawais) {
        cout << "ID: " << peg.id << ", Nama: " << peg.nama << ", Gaji: " << peg.gaji << endl;
    }
    
    cout << "\nTekan Enter untuk kembali ke menu...";
}

void cariPegawai() {
    ifstream file("pegawai.dat");
    if (!file) {
        cout << "\nBelum ada data pegawai!" << endl;
        return;
    }

    int cariID;
    cout << "\nMasukkan ID Pegawai yang dicari: ";
    cin >> cariID;

    Pegawai p;
    bool ditemukan = false;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        iss >> p.id;
        iss.ignore();
        iss >> ws;
        if (iss.peek() == '"') { 
            iss.get();
            getline(iss, p.nama, '"');
        } else {
            iss >> p.nama;
        }

        iss >> p.gaji;

        if (p.id == cariID) {
            cout << "\nID: " << p.id << ", Nama: " << p.nama << ", Gaji: " << p.gaji << endl;
            ditemukan = true;
            break;
        }
    }

    file.close();

    if (!ditemukan) {
        cout << "\nPegawai tidak ditemukan!" << endl;
    }
}

void hapusPegawai() {
    ifstream file("pegawai.dat");
    if (!file) {
        cout << "\nBelum ada data pegawai!" << endl;
        return;
    }
    
    vector<Pegawai> pegawais;
    Pegawai p;
    while (file >> p.id) {
        // getline(iss, p.nama, ' '); // Ensures reading full name
        file >> ws; // Skip whitespace

        // Check if name starts with a quote
        if (file.peek() == '"') {
            file.get(); // Consume opening quote
            getline(file, p.nama, '"'); // Read until closing quote
        } else {
            file >> p.nama; // Read single-word names
        }

        file >> p.gaji;
        pegawais.push_back(p);
    }
    file.close();
    
    int hapusID;
    cout << "\nMasukkan ID Pegawai yang ingin dihapus: ";
    cin >> hapusID;
    
    vector<Pegawai> pegawaisBaru;
    bool ditemukan = false;
    for (const auto &peg : pegawais) {
        if (peg.id != hapusID) {
            pegawaisBaru.push_back(peg);
        } else {
            ditemukan = true;
        }
    }
    
    if (!ditemukan) {
        cout << "\nPegawai tidak ditemukan!" << endl;
        return;
    }
    
    ofstream outFile("pegawai.dat", ios::trunc);
    for (const auto &peg : pegawaisBaru) {
        // Preserve quotes if the name contains spaces
        if (peg.nama.find(' ') != string::npos) {
            outFile << peg.id << " \"" << peg.nama << "\" " << peg.gaji << endl;
        } else {
            outFile << peg.id << " " << peg.nama << " " << peg.gaji << endl;
        }
    }
    outFile.close();
    
    cout << "\nPegawai berhasil dihapus!" << endl;
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "Menu:\n1. Tambah Pegawai\n2. Lihat Daftar Pegawai\n3. Cari Pegawai\n4. Hapus Pegawai\n5. Keluar\nPilihan: ";
        cin >> pilihan;
        
        system("cls");
        switch (pilihan) {
            case 1: 
                cout << "Menu 1 - Tambah Pegawai" << endl;
                tambahPegawai(); cin.ignore(); cin.get(); break;
            case 2: 
                cout << "Menu 2 - Lihat Daftar Pegawai" << endl;
                lihatDaftarPegawai(); cin.ignore(); cin.get(); break;
            case 3: 
                cout << "Menu 3 - Cari Pegawai" << endl;
                cariPegawai(); cin.ignore(); cin.get(); break;
            case 4: 
                cout << "Menu 4 - Hapus Pegawai" << endl;
                hapusPegawai(); cin.ignore(); cin.get(); break;
            case 5: 
                cout << "Tekan enter untuk keluar dari program..." << endl; cin.ignore(); cin.get(); break;
            default: 
                cout << "Pilihan tidak valid!" << endl; cin.ignore(); cin.get();
        }
    } while (pilihan != 5);
    system("cls");
    return 0;
}
