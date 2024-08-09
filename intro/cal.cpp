#include <iostream>
using namespace std;

// Function prototypes
void add(double Number, double Number1);
void subtract(double Number, double Number1);
void multiply(double Number, double Number1);
void divide(double Number, double Number1);

int main() {
    double Number, Number1; 
    char Operators; 

    cout << "Enter a Number: ";
    cin >> Number;

    cout << "Enter an Operator (+, -, *, /): ";
    cin >> Operators; 

    cout << "Enter Another Number: ";
    cin >> Number1;

    // Switch
    switch (Operators) {
        case '+':
            add(Number, Number1);
            break;
        case '-':
            subtract(Number, Number1);
            break;
        case '*':
            multiply(Number, Number1);
            break;
        case '/':
            divide(Number, Number1);
            break;
        default:
            cout << "Invalid Operator!" << endl;
            break;
    }

    return 0;
}

void add(double Number, double Number1) {
    double sum = Number + Number1;
    cout << "Addition of " << Number << " + " << Number1 << " = " << sum << endl;
}

void subtract(double Number, double Number1) {
    double sub = Number - Number1;
    cout << "Subtraction of " << Number << " - " << Number1 << " = " << sub << endl;
}

void multiply(double Number, double Number1) {
    double mul = Number * Number1;
    cout << "Multiplication of " << Number << " * " << Number1 << " = " << mul << endl;
}

void divide(double Number, double Number1) {
    if (Number1 == 0) {
        cout << "Error! Division by zero." << endl;
    } else {
        double div = Number / Number1;
        cout << "Division of " << Number << " / " << Number1 << " = " << div << endl;
    }
}
