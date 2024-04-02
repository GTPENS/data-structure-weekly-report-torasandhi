#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Fungsi untuk memeriksa apakah karakter adalah operator.
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

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
    return 0;
}

// Fungsi untuk mengonversi ekspresi infix menjadi ekspresi postfix.
string infixToPostfixConversion(const string &infixExpression)
{
    stack<char> operatorStack; // Stack untuk menyimpan operator.
    string postfixExpression;  // String untuk menyimpan ekspresi postfix.

    // Iterasi melalui setiap karakter dalam ekspresi infix.
    for (char character : infixExpression)
    {
        // Jika karakter adalah operand, tambahkan ke ekspresi postfix.
        if (isalnum(character))
        {
            postfixExpression += character;
        }
        // Jika karakter adalah tanda kurung buka, dorong ke dalam stack.
        else if (character == '(')
        {
            operatorStack.push(character);
        }
        // Jika karakter adalah tanda kurung tutup, keluarkan operator dari stack hingga menemukan tanda kurung buka.
        else if (character == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
            {
                operatorStack.pop();
            }
        }
        // Jika karakter adalah operator, keluarkan operator dari stack dengan precedensi yang lebih tinggi atau sama.
        else
        {
            while (!operatorStack.empty() && operatorPrecedence(character) <= operatorPrecedence(operatorStack.top()))
            {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(character); // Dorong operator saat ini ke dalam stack.
        }
    }

    // Keluarkan sisa operator dari stack dan tambahkan ke ekspresi postfix.
    while (!operatorStack.empty())
    {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression; // Kembalikan ekspresi postfix.
}

int main()
{
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";                     // Ekspresi infix
    string postfixExpression = infixToPostfixConversion(infixExpression); // Konversi infix menjadi postfix.

    // Menampilkan ekspresi infix dan postfix.
    cout << "Infix expression: " << infixExpression << endl;
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
