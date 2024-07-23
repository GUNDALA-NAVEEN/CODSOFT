#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Enter First Number: ";
    cin >> num1;
    cout << "Enter Second Number: ";
    cin >> num2;

    cout << "Select an operator: " << endl;
    cout << "  + for Addition" << endl;
    cout << "  - for Subtraction" << endl;
    cout << "  * for Multiplication" << endl;
    cout << "  / for Division" << endl;
    cout << "Enter your choice: ";
    cin >> op;

    switch (op) {
        case '+':
            cout << "Sum is: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Difference is: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Product is: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Quotient is: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed" << endl;
            }
            break;
        default:
            cout << "Enter a valid operator" << endl;
            break;
    }

    return 0;
}
