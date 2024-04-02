#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Fungsi untuk mengevaluasi ekspresi postfix dan mengembalikan hasilnya.
int evaluatePostfixExpression(const string &postfix)
{
    stack<int> operandStack; // Tumpukan untuk menyimpan operan

    // Iterasi melalui setiap karakter dalam ekspresi postfix
    for (char character : postfix)
    {
        // Jika karakter adalah angka, dorong nilainya ke dalam tumpukan operand.
        if (isdigit(character))
        {
            operandStack.push(character - '0');
        }
        // Jika karakter adalah operator
        else
        {
            // Ambil dua operand teratas dari tumpukan
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Lakukan operasi sesuai dengan operator
            switch (character)
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            }
        }
    }

    // Hasil akhir akan berada di puncak tumpukan
    return operandStack.top();
}

int main()
{
    string postfixExpression = "83+72*-";                      // Ekspresi postfix
    int result = evaluatePostfixExpression(postfixExpression); // Evaluasi ekspresi

    // Menampilkan ekspresi postfix dan hasil evaluasinya
    cout << "Postfix expression: " << postfixExpression << endl;
    cout << "Result: " << result << endl;

    return 0;
}
