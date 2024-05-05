#include <iostream>
#include <cstdlib>

#define MAX 10
int Data[MAX];

using namespace std;

// Function for straight insertion sort
void StraightInsertSort()
{
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main()
{
    int i;
    srand(0);
    // Generating random numbers
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    StraightInsertSort();
    // Sorted data
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
