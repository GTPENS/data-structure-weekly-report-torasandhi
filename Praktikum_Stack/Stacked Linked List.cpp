#include <iostream>
using namespace std;

class Node
{
public:
    int data; // Merubah 'value' menjadi 'data' untuk lebih jelas.
    Node *next;

    // Konstruktor untuk Node.
    Node(int val, Node *n = nullptr)
    {
        data = val;
        next = n;
    }
};

class ListStack
{
private:
    Node *top; // Merubah 'head' menjadi 'top' untuk merepresentasikan elemen teratas stack.
    int count; // Mengubah 'count' untuk merepresentasikan jumlah elemen dalam stack.

public:
    ListStack()
    {
        top = nullptr; // Menginisialisasi top sebagai nullptr saat stack kosong.
        count = 0;     // Menginisialisasi jumlah elemen menjadi 0 saat stack kosong.
    }

    // Fungsi untuk mendapatkan ukuran stack (jumlah elemen).
    int size()
    {
        return count;
    }

    // Fungsi untuk memeriksa apakah stack kosong.
    bool empty()
    {
        return count == 0;
    }

    // Fungsi untuk melihat elemen teratas stack.
    int peek()
    {
        if (empty())
        {
            throw out_of_range("Stack is empty");
        }
        return top->data; // Mengembalikan data dari elemen teratas stack.
    }

    // Fungsi untuk menambahkan elemen ke dalam stack.
    void push(int value)
    {
        top = new Node(value, top); // Menambahkan node baru di atas elemen teratas dan mengubah top ke node baru.
        count++;                    // Menambah jumlah elemen dalam stack.
    }

    // Fungsi untuk menghapus elemen teratas dari stack.
    int pop()
    {
        if (empty())
        {
            throw out_of_range("Stack is empty");
        }
        int value = top->data; // Menyimpan data dari elemen teratas stack.
        Node *temp = top;      // Menyimpan pointer ke elemen teratas sebelumnya.
        top = top->next;       // Mengubah top ke elemen di bawahnya.
        delete temp;           // Menghapus elemen teratas yang telah disimpan.
        count--;               // Mengurangi jumlah elemen dalam stack.
        return value;          // Mengembalikan data dari elemen teratas yang dihapus.
    }
};

int main()
{
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}
