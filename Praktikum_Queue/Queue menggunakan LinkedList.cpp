// Tora Sandhi Kamulian
// 5223600013

#include <iostream>
using namespace std;

class Queue
{
private:
    // Struktur Node untuk merepresentasikan elemen dalam antrian.
    struct Node
    {
        int data;
        Node *nextNode;
        Node(int val, Node *next) : data(val), nextNode(next) {}
    };

    Node *headPtr = nullptr; // Pointer ke elemen pertama dalam antrian.
    Node *tailPtr = nullptr; // Pointer ke elemen terakhir dalam antrian.
    int itemCount = 0;       // Jumlah elemen dalam antrian.

public:
    // Mengembalikan jumlah elemen dalam antrian.
    int getSize() { return itemCount; }

    // Memeriksa apakah antrian kosong.
    bool isEmpty() { return itemCount == 0; }

    // Menampilkan isi dari antrian.
    void display()
    {
        Node *tempNode = headPtr;
        while (tempNode != nullptr)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->nextNode;
        }
        cout << endl;
    }

    // Mengembalikan nilai dari elemen pertama dalam antrian tanpa menghapusnya.
    int peek()
    {
        if (isEmpty())
        {
            throw invalid_argument("QueueEmptyException");
        }
        return headPtr->data;
    }

    // Menambahkan elemen baru ke dalam antrian.
    void enqueue(int value)
    {
        Node *newNode = new Node(value, nullptr); // Membuat node baru.
        if (headPtr == nullptr)
        {
            headPtr = tailPtr = newNode; // Jika antrian kosong, atur kepala dan ekor ke node baru.
        }
        else
        {
            tailPtr->nextNode = newNode; // Menghubungkan node baru ke ekor antrian.
            tailPtr = newNode;           // Mengatur node baru sebagai ekor antrian.
        }
        itemCount++; // Menambah jumlah elemen dalam antrian.
    }

    // Menghapus dan mengembalikan nilai dari elemen pertama dalam antrian.
    int dequeue()
    {
        if (isEmpty())
        {
            throw invalid_argument("QueueEmptyException");
        }
        int value = headPtr->data;   // Menyimpan nilai dari elemen pertama.
        Node *tempNode = headPtr;    // Menyimpan pointer sementara ke elemen pertama.
        headPtr = headPtr->nextNode; // Memindahkan kepala antrian ke elemen berikutnya.
        delete tempNode;             // Menghapus elemen pertama.
        itemCount--;                 // Mengurangi jumlah elemen dalam antrian.
        return value;                // Mengembalikan nilai dari elemen pertama yang dihapus.
    }
};

int main()
{
    Queue myQueue; // Membuat objek antrian.
    for (int i = 1; i <= 100; i++)
    {
        myQueue.enqueue(i); // Menambahkan nilai dari 1 hingga 100 ke dalam antrian.
    }
    for (int i = 1; i <= 50; i++)
    {
        myQueue.dequeue(); // Menghapus 50 elemen pertama dari antrian.
    }
    myQueue.display(); // Menampilkan sisa elemen dalam antrian.
    return 0;
}
