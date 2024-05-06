#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];
int temp[MAX];
int comparisonCountMerge = 0;
int shiftCountMerge = 0;
int comparisonCountQuick = 0;
int shiftCountQuick = 0;

// Prosedur merge sort
void merge(int Data[], int temp[], int kiri, int tengah, int kanan)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = tengah - 1;
    tmp_pos = kiri;
    num_elements = kanan - kiri + 1;
    while ((kiri <= left_end) && (tengah <= kanan))
    {
        comparisonCountMerge++;
        if (Data[kiri] <= Data[tengah])
        {
            temp[tmp_pos] = Data[kiri];
            tmp_pos = tmp_pos + 1;
            kiri = kiri + 1;
        }
        else
        {
            temp[tmp_pos] = Data[tengah];
            tmp_pos = tmp_pos + 1;
            tengah = tengah + 1;
            shiftCountMerge++;
        }
    }
    while (kiri <= left_end)
    {
        temp[tmp_pos] = Data[kiri];
        kiri = kiri + 1;
        tmp_pos = tmp_pos + 1;
        shiftCountMerge++;
    }
    while (tengah <= kanan)
    {
        temp[tmp_pos] = Data[tengah];
        tengah = tengah + 1;
        tmp_pos = tmp_pos + 1;
        shiftCountMerge++;
    }
    for (i = 0; i < num_elements; i++)
    {
        Data[kanan] = temp[kanan];
        kanan = kanan - 1;
    }
}

// Prosedur membuat kumpulan data
void m_sort(int Data[], int temp[], int kiri, int kanan)
{
    int tengah;
    if (kanan > kiri)
    {
        tengah = (kanan + kiri) / 2;
        m_sort(Data, temp, kiri, tengah);
        m_sort(Data, temp, tengah + 1, kanan);
        merge(Data, temp, kiri, tengah + 1, kanan);
    }
}
void mergeSort(int Data[], int temp[], int array_size)
{
    m_sort(Data, temp, 0, array_size - 1);
}

// Prosedur pengurutan metode Quick Sort
void QuickSortRekursif(int L, int R)
{
    int i, j, x;
    x = Data[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j) {
        comparisonCountQuick++;
        while (Data[i] < x)
        {
            i++;
            comparisonCountQuick++;
        }
        while (Data[j] > x)
        {
            j--;
            comparisonCountQuick++;
        }
        if (i <= j) {
            swap(Data[i], Data[j]);
            i++;
            j--;
            shiftCountQuick++;
        }
    }
    if (L < j)
        QuickSortRekursif(L, j);
    if (i < R)
        QuickSortRekursif(i, R);
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT : ";
    for (int i = 0; i < MAX; i++)
    {
        Data[i] = rand() / 1000 + 1;
        cout << Data[i] << " ";
    }
    cout << endl;

    // Merge Sort
    cout << "\nMerge Sort Process:" << endl;
    for (int size = 1; size <= MAX; size *= 2)
    {
        mergeSort(Data, temp, size);
        cout << "Array saat ini: ";
        displayArray(Data, MAX);
        cout << "Perbandingan: " << comparisonCountMerge << ", Pergeseran: " << shiftCountMerge << endl;
    }
    cout << endl;

    // Quick Sort
    cout << "\nQuick Sort Process:" << endl;
    QuickSortRekursif(0, MAX - 1);
    displayArray(Data, MAX);
    cout << "Perbandingan: " << comparisonCountQuick << ", Pergeseran: " << shiftCountQuick << endl;

    return 0;
}

