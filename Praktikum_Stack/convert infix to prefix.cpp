#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Fungsi untuk menentukan precedensi operator.
int operatorPrecedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    return 0;
}

// Fungsi untuk mengonversi ekspresi infix menjadi ekspresi prefix.
string infixToPrefix(const string &infix)
{
    string reversedInfix = infix;                        // Inisialisasi string untuk menyimpan infix yang dibalik.
    reverse(reversedInfix.begin(), reversedInfix.end()); // Membalikkan infix.

    // Mengubah tanda kurung buka menjadi tanda kurung tutup dan sebaliknya.
    for (int i = 0; i < reversedInfix.length(); i++)
    {
        if (reversedInfix[i] == '(')
        {
            reversedInfix[i] = ')';
        }
        else if (reversedInfix[i] == ')')
        {
            reversedInfix[i] = '(';
        }
    }

    stack<char> stack; // Stack untuk menyimpan operator.
    string prefix;     // String untuk menyimpan ekspresi prefix.

    // Iterasi melalui setiap karakter dalam infix yang dibalik.
    for (char ch : reversedInfix)
    {
        // Jika karakter adalah operand, tambahkan ke ekspresi prefix.
        if (isalnum(ch))
        {
            prefix += ch;
        }
        // Jika karakter adalah tanda kurung tutup, dorong ke dalam stack.
        else if (ch == ')')
        {
            stack.push(ch);
        }
        // Jika karakter adalah tanda kurung buka, keluarkan operator dari stack hingga menemukan tanda kurung tutup.
        else if (ch == '(')
        {
            while (!stack.empty() && stack.top() != ')')
            {
                prefix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == ')')
            {
                stack.pop();
            }
        }
        // Jika karakter adalah operator, keluarkan operator dari stack dengan precedensi yang lebih tinggi atau sama.
        else
        {
            while (!stack.empty() && stack.top() != ')' &&
                   ((ch != '^' && operatorPrecedence(ch) <= operatorPrecedence(stack.top())) ||
                    (ch == '^' && operatorPrecedence(ch) < operatorPrecedence(stack.top()))))
            {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(ch); // Dorong operator saat ini ke dalam stack.
        }
    }

    // Keluarkan sisa operator dari stack dan tambahkan ke ekspresi prefix.
    while (!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end()); // Balikkan ekspresi prefix.
    return prefix;                         // Kembalikan ekspresi prefix.
}

int main()
{
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";         // Ekspresi infix
    string prefixExpression = infixToPrefix(infixExpression); // Konversi infix menjadi prefix.

    // Menampilkan ekspresi infix dan prefix.
    cout << "Infix expression: " << infixExpression << endl;
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
