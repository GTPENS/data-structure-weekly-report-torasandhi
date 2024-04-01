#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> stack1, stack2; // Menggunakan dua tumpukan untuk mewakili antrian.

public:
    // Menambahkan elemen ke antrian.
    void add(int value)
    {
        stack1.push(value); // Menambahkan elemen ke dalam stack1.
    }

    // Menghapus dan mengembalikan elemen dari antrian.
    int remove()
    {
        int value;
        // Jika stack2 kosong, pindahkan semua elemen dari stack1 ke stack2.
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                value = stack1.top(); // Ambil nilai dari elemen teratas stack1.
                stack1.pop();         // Hapus elemen teratas stack1.
                stack2.push(value);   // Tambahkan nilai ke dalam stack2.
            }
        }
        // Jika setelah pindahkan stack1 ke stack2 masih kosong, lemparkan pengecualian.
        if (stack2.empty())
        {
            throw invalid_argument("QueueEmptyException");
        }
        value = stack2.top(); // Ambil nilai dari elemen teratas stack2.
        stack2.pop();         // Hapus elemen teratas stack2.
        return value;         // Kembalikan nilai elemen yang dihapus dari antrian.
    }
};

int main()
{
    MyQueue myQueue;
    myQueue.add(1);
    myQueue.add(11);
    myQueue.add(111);
    cout << myQueue.remove() << endl; // Menghapus dan mencetak elemen pertama dari antrian.
    myQueue.add(2);
    myQueue.add(21);
    myQueue.add(211);
    cout << myQueue.remove() << endl; // Menghapus dan mencetak elemen pertama dari antrian.
    cout << myQueue.remove() << endl; // Menghapus dan mencetak elemen pertama dari antrian.
    return 0;
}
