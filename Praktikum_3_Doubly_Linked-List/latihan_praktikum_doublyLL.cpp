// Tora Sandhi Kamulian 5223600013

#include <iostream>

using namespace std;

struct Elemen
{
    Elemen *berikutnya;
    int nilai;
    Elemen *sebelumnya;
};

// Menyisipkan node di awal (sebagai simpul ujung)
void sisipAwal(Elemen *&kepala, Elemen *&ekor, int nilai)
{
    Elemen *baru = new Elemen;
    baru->nilai = nilai;

    // Jika list kosong
    if (kepala == nullptr)
    {
        baru->berikutnya = nullptr;
        baru->sebelumnya = nullptr;
        kepala = baru;
        ekor = baru;
    }
    else
    {
        // Menyambungkan node baru dengan node awal
        baru->berikutnya = kepala;
        kepala->sebelumnya = baru;
        kepala = baru;
    }
}

// Menampilkan data dari awal (LIFO)
void tampilkanLIFO(Elemen *kepala)
{
    Elemen *temp = kepala;
    cout << "LIFO: ";
    while (temp != nullptr)
    {
        cout << temp->nilai << " ";
        temp = temp->berikutnya;
    }
    cout << endl;
}

// Menampilkan data dari akhir (FIFO)
void tampilkanFIFO(Elemen *ekor)
{
    Elemen *temp = ekor;
    cout << "FIFO: ";
    while (temp != nullptr)
    {
        cout << temp->nilai << " ";
        temp = temp->sebelumnya;
    }
    cout << endl;
}

// Mencari node dengan nilai tertentu
void cari(Elemen *kepala, int nilai)
{
    Elemen *temp = kepala;
    int posisi = 1;

    // Jika list kosong
    if (kepala == nullptr)
    {
        cout << "List kosong!" << endl;
        return;
    }

    // Mencari node dengan nilai yang diberikan
    while (temp->nilai != nilai)
    {
        if (temp->berikutnya == nullptr)
        {
            cout << "Nilai " << nilai << " tidak ditemukan!" << endl;
            return;
        }
        temp = temp->berikutnya;
        posisi++;
    }

    cout << "Nilai " << nilai << " ditemukan di node ke-" << posisi << endl;
}

// Menghapus node dengan nilai tertentu
void hapusNode(Elemen *&kepala, Elemen *&ekor, int nilai)
{
    Elemen *temp = kepala;

    // Mencari node dengan nilai yang diberikan
    while (temp->nilai != nilai)
    {
        temp = temp->berikutnya;
    }

    // Menghapus node di awal
    if (temp == kepala)
    {
        kepala = kepala->berikutnya;
        if (kepala != nullptr)
        {
            kepala->sebelumnya = nullptr;
        }
        else
        {
            ekor = nullptr;
        }
    }
    else if (temp == ekor)
    {
        // Menghapus node di akhir
        ekor = ekor->sebelumnya;
        if (ekor != nullptr)
        {
            ekor->berikutnya = nullptr;
        }
        else
        {
            kepala = nullptr;
        }
    }
    else
    {
        // Menghapus node di tengah
        temp->sebelumnya->berikutnya = temp->berikutnya;
        temp->berikutnya->sebelumnya = temp->sebelumnya;
    }

    delete temp;
}

// Menghapus seluruh node
void hapusSemua(Elemen *&kepala)
{
    while (kepala != nullptr)
    {
        Elemen *temp = kepala;
        kepala = kepala->berikutnya;
        delete temp;
    }
}

int main()
{
    Elemen *kepala = nullptr;
    Elemen *ekor = nullptr;

    // Menyisipkan beberapa node
    sisipAwal(kepala, ekor, 10);
    sisipAwal(kepala, ekor, 15);
    sisipAwal(kepala, ekor, 20);
    sisipAwal(kepala, ekor, 25);
    sisipAwal(kepala, ekor, 30);
    sisipAwal(kepala, ekor, 35);

    // Menampilkan data
    tampilkanLIFO(kepala);
    tampilkanFIFO(ekor);

    // Menghapus seluruh node
    hapusSemua(kepala);

    return 0;
}