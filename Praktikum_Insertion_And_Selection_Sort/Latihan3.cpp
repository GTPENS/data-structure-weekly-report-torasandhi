#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk Pegawai
struct Pegawai {
    string NIP;
    string NAMA;
};

// Metode pengurutan yang dapat dipilih
enum MetodePengurutan {
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT
};

// Pengurutan dapat dipilih secara urut naik atau turun
enum Urutan {
    NAIK,
    TURUN
};

// Pengurutan dapat dipilih berdasarkan NIP dan NAMA
enum Berdasarkan {
    NIP,
    NAMA
};

// Fungsi untuk tukar dua elemen Pegawai
void Tukar(Pegawai& a, Pegawai& b) {
    Pegawai temp = a;
    a = b;
    b = temp;
}

// Implementasi pengurutan data Pegawai dengan Bubble Sort
void BubbleSort(Pegawai arr[], int n, Urutan urutan, Berdasarkan berdasarkan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((berdasarkan == NIP && arr[j].NIP > arr[j + 1].NIP) ||
                (berdasarkan == NAMA && arr[j].NAMA > arr[j + 1].NAMA)) {
                if (urutan == NAIK) {
                    Tukar(arr[j], arr[j + 1]);
                }
            }
            else {
                if (urutan == TURUN) {
                    Tukar(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

// Implementasi pengurutan data Pegawai dengan Selection Sort
void SelectionSort(Pegawai arr[], int n, Urutan urutan, Berdasarkan berdasarkan) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((berdasarkan == NIP && arr[j].NIP < arr[minIndex].NIP) ||
                (berdasarkan == NAMA && arr[j].NAMA < arr[minIndex].NAMA)) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            if (urutan == NAIK) {
                Tukar(arr[i], arr[minIndex]);
            }
        }
        else {
            if (urutan == TURUN) {
                Tukar(arr[i], arr[minIndex]);
            }
        }
    }
}

// Implementasi pengurutan data Pegawai dengan Insertion Sort
void InsertionSort(Pegawai arr[], int n, Urutan urutan, Berdasarkan berdasarkan) {
    for (int i = 1; i < n; i++) {
        Pegawai key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((berdasarkan == NIP && arr[j].NIP > key.NIP) ||
            (berdasarkan == NAMA && arr[j].NAMA > key.NAMA))) {
            if (urutan == NAIK) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            else {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk menampilkan data Pegawai
void TampilkanData(Pegawai arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Pegawai ke " << i + 1 << ": NIP = " << arr[i].NIP << ", NAMA = " << arr[i].NAMA << endl;
    }
}

int main() {
    const int JUMLAH_PEGAWAI = 5;
    Pegawai dataPegawai[JUMLAH_PEGAWAI] = {
        {"123", "John"},
        {"456", "Alice"},
        {"789", "Bob"},
        {"234", "David"},
        {"567", "Eva"}
    };

    // Pilihan pengguna
    MetodePengurutan metode = BUBBLE_SORT;
    Urutan urutan = NAIK;
    Berdasarkan berdasarkan = NIP;

    cout << "Data Sebelum Diurutkan:" << endl;
    TampilkanData(dataPegawai, JUMLAH_PEGAWAI);

    // Memilih metode pengurutan
    switch (metode) {
    case BUBBLE_SORT:
        BubbleSort(dataPegawai, JUMLAH_PEGAWAI, urutan, berdasarkan);
        cout << "\nData Setelah Diurutkan dengan Bubble Sort:" << endl;
        break;
    case SELECTION_SORT:
        SelectionSort(dataPegawai, JUMLAH_PEGAWAI, urutan, berdasarkan);
        cout << "\nData Setelah Diurutkan dengan Selection Sort:" << endl;
        break;
    case INSERTION_SORT:
        InsertionSort(dataPegawai, JUMLAH_PEGAWAI, urutan, berdasarkan);
        cout << "\nData Setelah Diurutkan dengan Insertion Sort:" << endl;
        break;
    }

    // Menampilkan data setelah diurutkan
    TampilkanData(dataPegawai, JUMLAH_PEGAWAI);

    return 0;
}
