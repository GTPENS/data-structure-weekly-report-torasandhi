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
