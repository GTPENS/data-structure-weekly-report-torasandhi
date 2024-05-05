#include <iostream>
#include <cstdlib>

#define MAX 10
int Data[MAX];

using namespace std;

int comparisonCount = 0; // Menghitung jumlah perbandingan
int shiftCount = 0;      // Menghitung jumlah pergeseran

void Tukar(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void StraightInsertSort()
{
    cout << "\n\nPROSES PENYORTIRAN DENGAN PENYISIPAN LANGSUNG:" << endl;
    for (int i = 1; i < MAX; i++) {
        int x = Data[i];
        int j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
            comparisonCount++; // Setiap kali ada perbandingan, tambahkan hitungannya
            shiftCount++;      // Jumlah pergeseran juga bertambah
        }
        Data[j + 1] = x;
        shiftCount++; // Pergeseran tambahan untuk memasukkan x ke posisi yang tepat

        cout << "Iterasi " << i << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
    cout << "Jumlah perbandingan: " << comparisonCount << endl;
    cout << "Jumlah pergeseran: " << shiftCount << endl;
}

void SelectionSort()
{
    cout << "\n\nPROSES PENYORTIRAN DENGAN SELEKSI:" << endl;
    comparisonCount = 0; // Reset jumlah perbandingan
    shiftCount = 0;      // Reset jumlah pergeseran
    for (int i = 0; i < MAX - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < MAX; j++) {
            comparisonCount++; // Setiap perbandingan, tambahkan hitungannya
            if (Data[k] > Data[j])
                k = j;
        }
        Tukar(&Data[i], &Data[k]);
        shiftCount++; // Setiap pertukaran, tambahkan hitungannya

        cout << "Iterasi " << i + 1 << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
    cout << "Jumlah perbandingan: " << comparisonCount << endl;
    cout << "Jumlah pergeseran: " << shiftCount << endl;
}

int main()
{
    srand(0);
    cout << "DATA SEBELUM TERURUT" << endl;
    for (int i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    StraightInsertSort();

    SelectionSort();

    cout << "\nDATA SETELAH TERURUT" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
