#include <iostream>
using namespace std;

// Definisi struktur Node untuk representasi simpul dalam linked list
struct Node
{
    int data;
    Node *next;
};

// Inisialisasi pointer tail sebagai pointer terakhir pada linked list
Node *tail = NULL;

// Fungsi-fungsi untuk operasi pada linked list
void tambahSimpul(Node *&kepala, int nilai);
void tambahAwal(Node *&kepala, int nilai);
void tampilkan(Node *kepala);
void perbaruiUjung(Node *kepala, Node *&ekor);
void sisipkanSetelah(Node *&kepala, int setelah, int nilai);
void sisipkanSebelum(Node *&kepala, int sebelum, int nilai);
void cari(Node *&kepala, int nilai);
void hapusSimpul(Node *&kepala);
void hapusSimpulIndeks(Node *&kepala, int indeks);
void hapusSimpulData(Node *&kepala, int nilai);

int main()
{
    Node *kepala = NULL;

    // Menambah simpul pertama
    tambahSimpul(kepala, 10);
    tampilkan(kepala);

    // Menambah simpul kedua
    tambahSimpul(kepala, 30);
    tampilkan(kepala);

    // Menambah simpul ketiga
    tambahSimpul(kepala, 47);
    tampilkan(kepala);

    // Menambah simpul keempat
    tambahSimpul(kepala, 76);
    tampilkan(kepala);

    // Menyisipkan simpul setelah simpul dengan nilai 30
    sisipkanSetelah(kepala, 30, 45);
    tampilkan(kepala);

    // Menyisipkan simpul sebelum simpul dengan nilai 10
    sisipkanSebelum(kepala, 10, 37);
    tampilkan(kepala);

    // Mencari simpul dengan nilai 47
    cari(kepala, 47);
    tampilkan(kepala);

    // Menghapus simpul pada indeks ke-2
    hapusSimpulIndeks(kepala, 2);
    tampilkan(kepala);

    // Menghapus simpul dengan nilai 47
    hapusSimpulData(kepala, 47);
    tampilkan(kepala);

    // Menghapus seluruh linked list
    hapusSimpul(kepala);
}

// Fungsi untuk menambahkan simpul pada akhir linked list
void tambahSimpul(Node *&kepala, int nilai)
{
    cout << "Menambahkan data >> " << nilai;
    Node *simpulBaru = new Node();
    simpulBaru->data = nilai;
    simpulBaru->next = NULL;

    if (kepala == NULL)
    {
        kepala = simpulBaru;
        tail = kepala;
    }
    else
    {
        tail->next = simpulBaru;
        tail = simpulBaru;
    }
    perbaruiUjung(kepala, tail);
}

// Fungsi untuk menambahkan simpul di awal linked list
void tambahAwal(Node *&kepala, int nilai)
{
    Node *simpulBaru = new Node();
    simpulBaru->data = nilai;
    simpulBaru->next = NULL;

    if (kepala == NULL)
    {
        kepala = simpulBaru;
        tail = kepala;
    }
    else
    {
        simpulBaru->next = kepala;
        kepala = simpulBaru;
    }
}

// Fungsi untuk menampilkan isi linked list
void tampilkan(Node *kepala)
{
    Node *temp = kepala;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi untuk memperbarui pointer ekor linked list
void perbaruiUjung(Node *kepala, Node *&ekor)
{
    ekor = kepala;
    while (ekor->next != NULL)
    {
        ekor = ekor->next;
    }
    cout << "\tekor pada : " << ekor->data << endl;
}

// Fungsi untuk mencari simpul dengan nilai tertentu
void cari(Node *&kepala, int nilai)
{
    Node *cari = kepala;
    while (cari->data != nilai)
    {
        cari = cari->next;
    }
    cout << "Pencarian " << cari->data << " " << cari->next << endl;
}

// Fungsi untuk menyisipkan simpul setelah simpul dengan nilai tertentu
void sisipkanSetelah(Node *&kepala, int setelah, int nilai)
{
    Node *simpulBaru = new Node();
    simpulBaru->data = nilai;

    Node *temp = kepala;
    while (temp != nullptr && temp->data != setelah)
    {
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        simpulBaru->next = temp->next;
        temp->next = simpulBaru;
    }
    else
    {
        cout << "Data " << setelah << " tidak ada" << endl;
    }
    cout << "Menambahkan data >> " << nilai << " setelah " << setelah << endl;
}

// Fungsi untuk menghapus seluruh simpul pada linked list
void hapusSimpul(Node *&kepala)
{
    while (kepala != nullptr)
    {
        Node *temp = kepala;
        kepala = kepala->next;
        delete temp;
    }
}

// Fungsi untuk menyisipkan simpul sebelum simpul dengan nilai tertentu
void sisipkanSebelum(Node *&kepala, int sebelum, int nilai)
{
    Node *simpulBaru = new Node();
    simpulBaru->data = nilai;

    Node *temp = kepala;

    if (kepala != nullptr && kepala->data == sebelum)
    {
        simpulBaru->next = kepala;
        kepala = simpulBaru;
        return;
    }

    while (temp != nullptr && temp->next->data != sebelum)
    {
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        simpulBaru->next = temp->next;
        temp->next = simpulBaru;
    }
    else
    {
        cout << "Data " << sebelum << " tidak ada" << endl;
    }
    cout << "Menambahkan data >> " << nilai << " sebelum " << sebelum << endl;
}

// Fungsi untuk menghapus simpul berdasarkan indeks
void hapusSimpulIndeks(Node *&kepala, int indeks)
{
    cout << "Menghapus simpul ke-" << indeks << endl;
    Node *simpulBaru = kepala;
    Node *penghubung = kepala;

    for (int k = 0; k < indeks; k++)
    {
        simpulBaru = simpulBaru->next;
    }

    for (int i = 0; i < indeks - 1; i++)
    {
        penghubung = penghubung->next;
    }

    penghubung->next = simpulBaru->next;
    delete simpulBaru;
}

// Fungsi untuk menghapus simpul berdasarkan nilai
void hapusSimpulData(Node *&kepala, int nilai)
{
    Node *simpulBaru = kepala;
    Node *penghubung = new Node();

    while (simpulBaru->next->data != nilai)
    {
        simpulBaru = simpulBaru->next;
    }

    penghubung = simpulBaru;
    simpulBaru = simpulBaru->next;
    penghubung->next = simpulBaru->next;

    delete simpulBaru;
    cout << "Menghapus simpul dengan nilai " << nilai << endl;
}
