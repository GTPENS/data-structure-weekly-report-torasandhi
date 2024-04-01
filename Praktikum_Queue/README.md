## Nama : Tora Sandhi Kamulian

## NRP : 52236000013

## Kelas : 11 GT-A

# Praktikum 05: Overview Queue

1. **Queue Menggunakan Linked List**

Mengimplementasikan struktur data Queue menggunakan Linked List.

```cpp
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

```

2. **Enqueue pada Queue Linked List**

Program ini hanya memuat implementasi metode `enqueue` untuk menambahkan elemen baru ke akhir Queue Linked List.

```cpp
void Queue::enqueue(int value)
{
    // Membuat node baru dengan nilai yang diberikan dan pointer next yang menunjuk ke nullptr.
    Node *newNode = new Node(value, nullptr);

    // Jika antrian kosong, atur head dan tail untuk menunjuk ke node baru.
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    // Jika antrian tidak kosong,
    else
    {
        // Menghubungkan node baru ke tail yang ada.
        tail->next = newNode;
        // Menggeser tail untuk menunjuk ke node baru sebagai tail baru.
        tail = newNode;
    }

    // Menambah jumlah elemen dalam antrian.
    count++;
}

```

3. **Dequeue pada Queue Linked List**

Program ini hanya memuat implementasi metode `dequeue` untuk menghapus elemen dari awal Queue Linked List.

```cpp
// Menghapus elemen pertama dari antrian dan mengembalikan nilainya.
int Queue::remove()
{
    // Memeriksa apakah antrian kosong.
    if (isEmpty())
    {
        // Jika antrian kosong, lempar pengecualian QueueEmptyException.
        throw invalid_argument("QueueEmptyException");
    }
    // Menyimpan nilai dari elemen pertama antrian.
    int data = headPtr->value;
    // Menyimpan pointer sementara ke elemen pertama antrian.
    Node *tempNode = headPtr;
    // Memindahkan kepala antrian ke elemen berikutnya.
    headPtr = headPtr->next;
    // Menghapus elemen pertama antrian yang disimpan dalam pointer sementara.
    delete tempNode;
    // Mengurangi jumlah elemen dalam antrian.
    itemCount--;
    // Mengembalikan nilai dari elemen pertama yang dihapus.
    return data;
}

```

4. **Implementasi Queue menggunakan 2 Stack**

Program ini mengimplementasikan struktur data Queue menggunakan dua buah Stack.

```cpp
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

```

## Tugas

**1. Stack using a Queue**
Pada permasalahan ini, kita harus mengimplementasikan struktur data Stack menggunakan struktur data Queue. Salah satu solusi yang diberikan adalah dengan menggunakan satu antrian (queue) saja.

```cpp
#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q;

public:
    void push(int value) {
        int size = q.size();
        q.push(value);

        // Memindahkan elemen-elemen lain ke belakang
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            throw out_of_range("Stack is empty");
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            throw out_of_range("Stack is empty");
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingQueue stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top: " << stack.top() << endl;

    stack.pop();

    cout << "Top: " << stack.top() << endl;

    return 0;
}
```

**2. Josephus problem**
Pada permasalahan Josephus, kita harus menemukan posisi di mana seseorang harus berdiri dalam sebuah antrian agar dapat mendapatkan kebebasan. Setiap langkah, k orang dihapus dari antrian, dan kemudian ditambahkan kembali satu per satu ke antrian

```cpp
#include <iostream>
#include <list>
using namespace std;

int josephus(int n, int k) {
    list<int> people;

    // Membuat daftar orang dari 1 hingga n
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    auto it = people.begin();
    while (people.size() > 1) {
        // Memindahkan iterator k-1 langkah
        for (int i = 0; i < k - 1; i++) {
            it++;
            if (it == people.end()) {
                it = people.begin();
            }
        }

        // Menghapus orang saat ini
        auto next = it;
        next++;
        if (next == people.end()) {
            next = people.begin();
        }
        it = people.erase(it);
        it = next;
    }

    return people.front();
}

int main() {
    int n, k;
    cout << "Masukkan jumlah orang: ";
    cin >> n;
    cout << "Masukkan nilai k: ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "Orang yang selamat adalah: " << survivor << endl;

    return 0;
}
```
