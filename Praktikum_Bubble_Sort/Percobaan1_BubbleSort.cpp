#include <iostream>
#include <cstdlib>

#define MAX 10
int Data[MAX];

using namespace std;

// Prosedur menukar data
void Tukar(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort()
{
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = MAX - 1; j >= i; j--) {
            // Membandingkan dua elemen berturut-turut dan menukar posisi jika perlu
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
    }
}

int main()
{
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (int i = 0; i < MAX; i++) {
        Data[i] = (int)rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Memanggil fungsi BubbleSort untuk mengurutkan data
    BubbleSort();

    // Menampilkan data setelah diurutkan
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
