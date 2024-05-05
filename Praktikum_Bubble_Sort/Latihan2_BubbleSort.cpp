#include <iostream>
#include <cstdlib>

#define MAX 10
int Data[MAX];
int comparisonCountBubble = 0;
int shiftCountBubble = 0;
int comparisonCountShell = 0;
int shiftCountShell = 0;

using namespace std;

// Prosedur menukar data
void Tukar(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode Bubble Sort
void BubbleSort()
{
    cout << "\n\nBUBBLE SORT PROCESS:" << endl;
    for (int i = 0; i < MAX - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < MAX - i - 1; j++)
        {
            comparisonCountBubble++;
            if (Data[j] > Data[j + 1])
            {
                Tukar(&Data[j], &Data[j + 1]);
                swapped = true;
                shiftCountBubble++;
            }
        }
        if (!swapped) break; // Jika tidak ada pertukaran, pengurutan sudah selesai
        cout << "Iteration " << i + 1 << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
}

// Prosedur pengurutan metode Shell Sort
void ShellSort()
{
    cout << "\n\nSHELL SORT PROCESS:" << endl;
    int Jarak;
    for (Jarak = MAX / 2; Jarak > 0; Jarak /= 2)
    {
        for (int i = Jarak; i < MAX; i += 1)
        {
            int temp = Data[i];
            int j;
            for (j = i; j >= Jarak && Data[j - Jarak] > temp; j -= Jarak)
            {
                Data[j] = Data[j - Jarak];
                comparisonCountShell++;
                shiftCountShell++;
            }
            Data[j] = temp;
        }
        cout << "Gap " << Jarak << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (int i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Memanggil fungsi BubbleSort untuk mengurutkan data
    BubbleSort();

    // Menampilkan jumlah perbandingan dan pergeseran pada algoritma Bubble Sort
    cout << "\nBUBBLE SORT COMPARISON COUNT: " << comparisonCountBubble << endl;
    cout << "BUBBLE SORT SHIFT COUNT: " << shiftCountBubble << endl;

    // Memanggil fungsi ShellSort untuk mengurutkan data
    ShellSort();

    // Menampilkan jumlah perbandingan dan pergeseran pada algoritma Shell Sort
    cout << "\nSHELL SORT COMPARISON COUNT: " << comparisonCountShell << endl;
    cout << "SHELL SORT SHIFT COUNT: " << shiftCountShell << endl;

    // Menampilkan data setelah diurutkan
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
