#include <iostream>
using namespace std;

// Function to get the operation sign
char getOperationChar(){
    char operation_sign = ' ';
    cout << "Select operation: \n";
    cout << "+) Addition \n";
    cout << "-) Subtraction \n";
    cout << "*) Multiplication \n";
    cout << "/) Division \n";
    cin >> operation_sign;
    return operation_sign;
}

// functions for arithmetic operations
double add(double n1, double n2){
    return n1 + n2;
}
double subtract(double n1, double n2){
    return n1 - n2;
}
double multiply(double n1, double n2){
    return n1 * n2;
}
double divide(double n1, double n2){
    return n1 / n2;
}


int main(){
    double n1 = 0, n2 = 0, result = 0;
    char operation_sign = ' ';
    bool isValidSign = false; // flag to valid the sign
    cout << "Insert first number: ";
    cin >> n1;
    cout << "Insert second number: ";
    cin >> n2;
    do{
        operation_sign = getOperationChar();
        switch(operation_sign){
            case '+':
                result = add(n1, n2);
                isValidSign = true;
                break;
            
            case '-':
                result = subtract(n1, n2);
                isValidSign = true;
                break;
            
            case '*':
                result = multiply(n1, n2);
                isValidSign = true;
                break;
            
            case '/':
                if(n2 == 0){
                    cout << "Division by zero is not defined." << endl;
                    return 0;
                } else{
                    result = divide(n1, n2);
                }
                isValidSign = true;
                break;

            default:
                cout << "Invalid operation sign, try again." << endl;
            
        }

    }while(!isValidSign); // only take a valid operation sign

    cout << "The result of the operations is: " << result << endl;

    return 0;
}