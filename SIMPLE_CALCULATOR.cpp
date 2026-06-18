#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    int choice;

    // Input two numbers
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Display menu
    cout << "\nCalculator Menu\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Perform operation
    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result = " << result;
            break;

        case 2:
            result = num1 - num2;
            cout << "Result = " << result;
            break;

        case 3:
            result = num1 * num2;
            cout << "Result = " << result;
            break;

        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result = " << result;
            } else {
                cout << "Error: Division by zero is not allowed.";
            }
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}