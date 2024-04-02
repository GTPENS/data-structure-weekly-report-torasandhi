#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Fungsi untuk mengecek apakah ekspresi memiliki kurung seimbang.
bool isBalancedParenthesis(const string &expression)
{
    stack<char> bracketStack; // Stack untuk menyimpan tanda kurung

    // Iterasi melalui setiap karakter dalam ekspresi
    for (char ch : expression)
    {
        // Jika karakter adalah tanda kurung pembuka, dorong ke dalam stack
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            bracketStack.push(ch);
            break;
        // Jika karakter adalah tanda kurung penutup
        case ')':
            // Jika stack kosong atau tidak ada tanda kurung pembuka yang cocok, ekspresi tidak seimbang
            if (bracketStack.empty() || bracketStack.top() != '(')
            {
                return false;
            }
            // Jika ada tanda kurung pembuka yang cocok, hapus dari stack
            bracketStack.pop();
            break;
        case ']':
            if (bracketStack.empty() || bracketStack.top() != '[')
            {
                return false;
            }
            bracketStack.pop();
            break;
        case '}':
            if (bracketStack.empty() || bracketStack.top() != '{')
            {
                return false;
            }
            bracketStack.pop();
            break;
        default:
            break;
        }
    }

    // Jika semua tanda kurung pembuka cocok dengan tanda kurung penutup dan stack kosong, ekspresi seimbang
    return bracketStack.empty();
}

int main()
{
    // Ekspresi yang akan diuji
    string expression1 = "{()}";
    string expression2 = "{())}";

    // Mengecek apakah ekspresi seimbang atau tidak
    cout << "Expression: " << expression1 << " is "
         << (isBalancedParenthesis(expression1) ? "balanced" : "not balanced") << endl;
    cout << "Expression: " << expression2 << " is "
         << (isBalancedParenthesis(expression2) ? "balanced" : "not balanced") << endl;

    return 0;
}
