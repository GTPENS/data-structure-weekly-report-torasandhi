#include <iostream>
#include <cstdlib>

// Mendefinisikan ukuran maksimum dari array
#define MAX 10

// Mendeklarasikan array untuk menyimpan data
int Data[MAX];

using namespace std;

// Fungsi untuk menukar dua angka
void Tukar(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk melakukan pengurutan dengan penyisipan langsung
void StraightInsertSort()
{
    // Menampilkan header proses
    cout << "\n\nPROSES PENYORTIRAN DENGAN PENYISIPAN LANGSUNG:" << endl;

    // Mengulangi array dimulai dari elemen kedua
    for (int i = 1; i < MAX; i++) {
        int x = Data[i];    // Menyimpan elemen saat ini
        int j = i - 1;      // Memulai perbandingan dengan elemen sebelumnya

        // Memindahkan elemen yang lebih besar dari x ke kanan
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }

        // Memasukkan x ke posisi yang tepat
        Data[j + 1] = x;

        // Menampilkan keadaan terkini dari array setelah setiap iterasi
        cout << "Iterasi " << i << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk melakukan pengurutan dengan seleksi
void SelectionSort()
{
    // Menampilkan header proses
    cout << "\n\nPROSES PENYORTIRAN DENGAN SELEKSI:" << endl;

    // Mengulangi array
    for (int i = 0; i < MAX - 1; i++)
    {
        int k = i;  // Indeks dari elemen minimum

        // Mencari indeks dari elemen minimum di bagian yang belum diurutkan
        for (int j = i + 1; j < MAX; j++)
            if (Data[k] > Data[j])
                k = j;

        // Menukar elemen saat ini dengan elemen minimum
        Tukar(&Data[i], &Data[k]);

        // Menampilkan keadaan terkini dari array setelah setiap iterasi
        cout << "Iterasi " << i + 1 << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
}

// Fungsi utama
int main()
{
    srand(0);   // Menetapkan seed generator angka acak

    // Menampilkan data awal sebelum diurutkan
    cout << "DATA SEBELUM TERURUT" << endl;
    for (int i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;   // Menghasilkan data acak
        cout << "Data ke " << i << " : " << Data[i] << endl; // Menampilkan data
    }

    // Melakukan pengurutan dengan penyisipan langsung
    StraightInsertSort();

    // Melakukan pengurutan dengan seleksi
    SelectionSort();

    // Menampilkan data yang sudah diurutkan
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
