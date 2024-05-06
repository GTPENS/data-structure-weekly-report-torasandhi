#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur data Pegawai
struct Pegawai {
    string NIP;
    string Nama;
    int Usia;
    double Gaji;
};

// Fungsi untuk membandingkan dua Pegawai berdasarkan NIP
bool compareByNIP(const Pegawai& a, const Pegawai& b) {
    return a.NIP < b.NIP;
}

// Fungsi untuk membandingkan dua Pegawai berdasarkan Nama
bool compareByNama(const Pegawai& a, const Pegawai& b) {
    return a.Nama < b.Nama;
}

// Fungsi untuk menampilkan data Pegawai
void displayPegawai(const vector<Pegawai>& pegawai) {
    for (const auto& p : pegawai) {
        cout << "NIP: " << p.NIP << ", Nama: " << p.Nama << ", Usia: " << p.Usia << ", Gaji: " << p.Gaji << endl;
    }
}

int main() {
    // Membuat data Pegawai
    vector<Pegawai> dataPegawai = {
        {"123", "John Doe", 30, 5000},
        {"456", "Jane Smith", 35, 6000},
        {"789", "Alice Johnson", 28, 4500},
        {"234", "Bob Williams", 32, 5500},
        {"567", "Emily Davis", 40, 7000}
    };

    // Memilih metode pengurutan
    int choice;
    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Berdasarkan NIP" << endl;
    cout << "2. Berdasarkan Nama" << endl;
    cin >> choice;

    // Memilih urutan pengurutan
    int order;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "1. Urut naik" << endl;
    cout << "2. Urut turun" << endl;
    cin >> order;

    // Menggunakan fungsi pengurutan sesuai dengan pilihan
    if (choice == 1) {
        if (order == 1) {
            // Pengurutan berdasarkan NIP secara naik
            sort(dataPegawai.begin(), dataPegawai.end(), compareByNIP);
        }
        else {
            // Pengurutan berdasarkan NIP secara turun
            sort(dataPegawai.begin(), dataPegawai.end(), [](const Pegawai& a, const Pegawai& b) {
                return a.NIP > b.NIP;
                });
        }
    }
    else {
        if (order == 1) {
            // Pengurutan berdasarkan Nama secara naik
            sort(dataPegawai.begin(), dataPegawai.end(), compareByNama);
        }
        else {
            // Pengurutan berdasarkan Nama secara turun
            sort(dataPegawai.begin(), dataPegawai.end(), [](const Pegawai& a, const Pegawai& b) {
                return a.Nama > b.Nama;
                });
        }
    }

    // Menampilkan data Pegawai setelah diurutkan
    cout << "\nData Pegawai setelah diurutkan:" << endl;
    displayPegawai(dataPegawai);

    return 0;
}
