// Tora Sandhi Kamulian 5223600013

#include <iostream>

using namespace std;

struct Elemen
{
    int nilai;          // Menyimpan nilai data
    Elemen *berikutnya; // Pointer ke node berikutnya
    Elemen *sebelumnya; // Pointer ke node sebelumnya
};

// Menyisipkan node di awal (sebagai simpul ujung)
void sisipAwal(Elemen *&kepala, Elemen *&ekor, int nilai)
{
    // Membuat node baru
    Elemen *baru = new Elemen;
    baru->nilai = nilai;

    // Jika list kosong
    if (kepala == nullptr)
    {
        // Node baru menjadi satu-satunya node
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
    cout << "Tampilan LIFO: ";
    // Menelusuri node dari awal hingga akhir
    while (temp != nullptr)
    {
        cout << temp->nilai << " ";
        temp = temp->berikutnya;
    }
    cout << endl;
    // Menampilkan informasi head
    cout << "Head pada nilai " << kepala->nilai << ", next-nya " << kepala->berikutnya->nilai << endl;
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
        // Jika node berikutnya tidak ada, data tidak ditemukan
        if (temp->berikutnya == nullptr)
        {
            cout << "Nilai " << nilai << " tidak ditemukan!" << endl;
            return;
        }
        temp = temp->berikutnya;
        posisi++;
    }

    // Menampilkan informasi node yang ditemukan
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

    // Menghapus node
    delete temp;
}

// Menghapus seluruh node
void hapusSemua(Elemen *&kepala)
{
    // Menelusuri dan menghapus node satu per satu
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

    int pilihan, data;

    do
    {
        cout << "\nMenu Pilihan:\n";
        cout << "1. Sisipkan Node di Awal\n";
        cout << "2. Tampilkan Node\n";
        cout << "3. Cari Node\n";
        cout << "4. Hapus Node (by data)\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data yang akan disisipkan: ";
            cin >> data;
            sisipAwal(kepala, ekor, data);
            break;
        case 2:
            cout << "Linked List: ";
            tampilkanLIFO(kepala);
            break;
        case 3:
            cout << "Masukkan data yang akan dicari: ";
            cin >> data;
            cari(kepala, data);
            break;
        case 4:
            cout << "Masukkan data yang akan dihapus: ";
            cin >> data;
            hapusNode(kepala, ekor, data);
            break;
        case 5:
            cout << "Keluar dari program\n";
            break;
        default:
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    delete (kepala);

    return 0;
}
