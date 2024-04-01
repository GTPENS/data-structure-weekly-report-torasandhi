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
