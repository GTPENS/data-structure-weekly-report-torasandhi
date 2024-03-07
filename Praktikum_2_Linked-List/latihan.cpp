#include <iostream>

using namespace std;

// Define the Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Function to create a new node with the given data
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the linked list (as the head)
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node *last = *head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = newNode;
}

// Function to print the contents of the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to search for a node with the given data, handle the head node case
bool searchNode(Node *head, int data)
{
    if (head != nullptr && head->data == data)
    {
        return true;
    }

    while (head != nullptr)
    {
        if (head->data == data)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main()
{
    Node *head = nullptr;

    // Menu loop for user interaction
    int choice, data;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Menyisipkan sebagai node dari linked list.\n";
        cout << "2. Menyisipkan sebagian simpul diakhir.\n";
        cout << "3. Membaca atau menampilkan linked list\n";
        cout << "4. Mencari sebuah simpul tertentu.\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan data yang ingin disisipkan: ";
            cin >> data;
            insertAtBeginning(&head, data);
            break;
        case 2:
            cout << "Masukkan data untuk disisipkan diakhir: ";
            cin >> data;
            insertAtEnd(&head, data);
            break;
        case 3:
            cout << "List: ";
            printList(head);
            break;
        case 4:
            cout << "Ketik data yang ingin dicari: ";
            cin >> data;
            if (searchNode(head, data))
            {
                cout << "Data ditemukan!\n";
            }
            else
            {
                cout << "Data tidak ditemukan.\n";
            }
            break;
        case 5:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
