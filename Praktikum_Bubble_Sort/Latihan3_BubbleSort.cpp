#include <iostream>
#include <string>
#include <algorithm>

#define MAX 10

using namespace std;

// Struktur data untuk Pegawai
struct Pegawai {
    string NIP;
    string NAMA;
    int UMUR;
    double GAJI;
};

// Fungsi untuk membandingkan Pegawai berdasarkan NIP secara naik
bool compareByNIPAsc(const Pegawai& a, const Pegawai& b) {
    return a.NIP < b.NIP;
}

// Fungsi untuk membandingkan Pegawai berdasarkan NIP secara turun
bool compareByNIPDesc(const Pegawai& a, const Pegawai& b) {
    return a.NIP > b.NIP;
}

// Fungsi untuk membandingkan Pegawai berdasarkan NAMA secara naik
bool compareByNamaAsc(const Pegawai& a, const Pegawai& b) {
    return a.NAMA < b.NAMA;
}

// Fungsi untuk membandingkan Pegawai berdasarkan NAMA secara turun
bool compareByNamaDesc(const Pegawai& a, const Pegawai& b) {
    return a.NAMA > b.NAMA;
}

int main()
{
    Pegawai dataPegawai[MAX] = {
        {"123", "John Doe", 30, 5000},
        {"456", "Jane Smith", 35, 6000},
        {"789", "David Brown", 40, 5500},
        {"234", "Sarah Johnson", 25, 5200},
        {"567", "Michael Williams", 45, 6500},
        {"890", "Emily Jones", 28, 4800},
        {"345", "Christopher Lee", 32, 5300},
        {"678", "Jessica Davis", 38, 5800},
        {"901", "Daniel Martinez", 33, 5700},
        {"012", "Amanda Wilson", 29, 5100}
    };

    int choice;
    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Pengurutan berdasarkan NIP" << endl;
    cout << "2. Pengurutan berdasarkan NAMA" << endl;
    cin >> choice;

    int sortOrder;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "1. Naik" << endl;
    cout << "2. Turun" << endl;
    cin >> sortOrder;

    // Memilih fungsi pembanding berdasarkan pilihan pengguna
    bool (*compareFunction)(const Pegawai&, const Pegawai&);
    if (choice == 1) {
        if (sortOrder == 1) {
            compareFunction = compareByNIPAsc;
        }
        else {
            compareFunction = compareByNIPDesc;
        }
    }
    else {
        if (sortOrder == 1) {
            compareFunction = compareByNamaAsc;
        }
        else {
            compareFunction = compareByNamaDesc;
        }
    }

    // Melakukan pengurutan menggunakan fungsi pembanding yang dipilih
    sort(dataPegawai, dataPegawai + MAX, compareFunction);

    // Menampilkan data setelah diurutkan
    cout << "\nDATA PEGAWAI SETELAH DIURUTKAN" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "NIP: " << dataPegawai[i].NIP << ", NAMA: " << dataPegawai[i].NAMA << endl;
    }

    return 0;
}
