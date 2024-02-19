//Task-2
//kiran bajirao mane
//simple calculator program

#include <iostream>
using namespace std;

class Calculator {
public:
    double Addition(double a, double b) {
        return (a+b);
    }

    double Subtraction(double a, double b) {
        return (a-b);
    }

    double Multiplication(double a, double b) {
        return (a*b);
    }

    double Division(double a, double b) {
        if (b != 0) {
            return (a/b);
        } else {
            cout << "Infinity error." << endl;
            return 0.0;  // Return a default value in case of an error
        }
    }
};

int main() {
    Calculator c;

    double a, b, result;
    int operation;
    do{
        cout<<"\nSimple Calculator.";
        cout<<"\nOperations:";
        cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nExit.";
        cout<<"\nEnter your choice:";
        cin>>operation;

        if(operation==1 || operation==2 || operation==3 || operation==4)
        {
         cout << "Enter the first number: ";
        cin >> a;

        cout << "Enter the second number: ";
        cin >> b;
        }
    switch (operation) {
        case 1:
            result = c.Addition(a, b);
            cout << "Result: " << result << endl;
            break;
        case 2:
            result = c.Subtraction(a, b);
            cout << "Result: " << result << endl;
            break;
        case 3:
            result = c.Multiplication(a, b);
            cout << "Result: " << result << endl;
            break;
        case 4:
            result = c.Division(a, b);
            cout << "Result: " << result << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nEnter valid choice." << endl;        
    }
    }
    while(operation!=5);
    
    return 0;
}