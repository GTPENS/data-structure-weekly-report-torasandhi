#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk memeriksa apakah sebuah string adalah palindrome.
bool isPalindrome(const string &inputString)
{
    stack<char> charStack; // Stack untuk menyimpan setengah karakter dari string.

    // Buat salinan string dan hapus spasi, ubah ke huruf kecil
    string processedString = inputString;
    processedString.erase(remove_if(processedString.begin(), processedString.end(), ::isspace), processedString.end());
    transform(processedString.begin(), processedString.end(), processedString.begin(), ::tolower);

    // Mendorong setengah karakter pertama ke dalam stack
    for (int i = 0; i < processedString.length() / 2; i++)
    {
        charStack.push(processedString[i]);
    }

    // Mulai dari tengah (atau tengah + 1 jika panjang ganjil)
    int startIndex = processedString.length() % 2 == 0 ? processedString.length() / 2 : (processedString.length() / 2) + 1;

    // Memeriksa karakter yang cocok dengan yang ada di stack
    for (int i = startIndex; i < processedString.length(); i++)
    {
        if (processedString[i] != charStack.top())
        {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main()
{
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString); // Menerima input dari pengguna.

    // Memeriksa apakah string adalah palindrome atau bukan dan menampilkan hasilnya.
    cout << "\"" << inputString << "\" is " << (isPalindrome(inputString) ? "a palindrome" : "not a palindrome") << endl;

    return 0;
}
