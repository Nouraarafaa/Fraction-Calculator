/*
FCAI – Structured Programming – 2024 - Assignment 2
----------------------------------------------------
Purpose: Calculate Rational Operations
Author: Kirollos Adel Samir-S17
        Noura Muhammad Mahmoud-S18
        Eman Emad Abdulrahim-S18
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ld  long double


double addition(ld num1, ld num2) {
    ld res = 0;
    res = num1 + num2;
    return res;
}

double subtract(ld num1, ld num2) {
    ld res = 0;
    res = num1 - num2;
    return res;
}

double multiplication(ld num1, ld num2) {
    ld res = 0;
    res = num1 * num2;
    return res;
}

double divided(ld num1, ld num2) {
    ld res = 0;
    res = num1 / num2;
    return res;

}
// convert the user input to rational number e.g: [ 1/2 => 0.5 ]
double toRational(ld numerator, ld denominator) {
    ld res = 0;
    res = numerator / denominator;
    return res;
}

// convert the final result to fraction number e.g: [0.5 => 1/2]
void toFraction(ld result_number, int cycles = 10, double precision = 5e-4){
    // Set the main variables
    ld frac_number,floating_number;
    int counter = 0;
    int sign  = result_number >= 0 ? 1 : -1;
    result_number = result_number * sign; // |Abs| value
    ld decimal_number =  result_number - (int)result_number;
    valarray<double> numerator{double((int) result_number), 1}, denominator{1,0}, temporary;

    // Start converting
    while(decimal_number > precision & counter < cycles){
        frac_number = 1 / decimal_number;
        floating_number = (int) frac_number;

        temporary = numerator;
        numerator = floating_number * numerator + denominator;
        denominator = temporary;

        decimal_number = frac_number - floating_number;
        counter += 1;
    }
    cout << " = ";
    if (numerator[1] == 0) {
        cout << "Math Error. Try Again";
    }
    else {
        if (numerator[1] == 1) { // Denominator is 1
            cout << sign * numerator[0]<<endl;
        } else {
            cout << sign * numerator[0] << '/' << numerator[1]<<endl;
        }
    }
}

bool validation0(ld n2, ld n4) {
    if (n2 == 0 || n4 == 0) {
        cout << "Invalid operation. Try again\n";
        return false;
    }
    return true;
}

bool isValidInput(const string& input, char& div_op, char& op, ld& n1, ld& n2, ld& n3, ld& n4) {
    int spaceCount = count(input.begin(), input.end(), ' ');
    if (spaceCount != 2) {
        cout << "Invalid input format. \n";
        return false;
    }

    size_t f1 = input.find("++");
    size_t f2 = input.find("--");
    size_t f3 = input.find("**");
    size_t f4 = input.find("//");

    if (f1 != string::npos || f2 != string::npos || f3 != string::npos || f4 != string::npos) {
        cout << "Invalid input format.\n";
        return false;
    }

    istringstream iss(input);
    if ((iss >> n1 >> div_op >> n2 >> op >> n3 >> div_op >> n4)) { // case 1/2 + 1/2
        return true;
    } else {
        iss.clear();
        iss.seekg(0);

        if ((iss >> n1 >> op >> n3 >> div_op >> n4 )) { // case 1 + 1/2
            n2 = 1;
            div_op = '/';
            return true;
        } else {
            iss.clear();
            iss.seekg(0);

            if ((iss >> n1 >> div_op >> n2 >> op >> n3)) { // case 1/2 + 1
                n4 = 1;
                div_op = '/';
                return true;
            } else {
                iss.clear();
                iss.seekg(0);

                if ((iss >> n1 >> op >> n3)) { // case 1 + 1
                    n2 = 1;
                    n4 = 1;
                    div_op = '/';
                    return true;
                } else {
                    cout << "Invalid operation. Try again\n";
                    return false;
                }
            }
        }
    }
}

bool isNotEmpty(const string& str){
    return !str.empty();
}

bool isValidChoice(char choice) {
    return choice == '1' || choice == '2' ;
}

int main() {
    cout << "---Rational Number Calculator---\n";
    while (true){
        cout << "\nChoose to :\n" << "1) Calculate Rational operation\n" << "2) Exit\n => ";
        char choice;
        string in;
        getline(cin, in);
        if (in.size() != 1 || (in[0] != '1' && in[0] != '2')) {
            cout << "Invalid input. Please enter '1' for Calculate Rational operation or '2' for Exit." << endl;
            continue;
        }
        if (!isNotEmpty(in) || !isdigit(in[0]) || !isValidChoice(in[0])) {
            cout << "Invalid input. Please enter '1' for Calculate Rational operation or '2' for Exit." << endl;
            continue;
        }
        choice = in[0];
        if (choice == '1'){
            char div_op, op;
            ld n1, n2, n3, n4, res;
            string input;
            cout << "========================================\n";
            cout << "Please put spaces between the operations\n";
            cout << "Enter the operation : ";
            getline(cin, input);
            if (!isValidInput(input, div_op, op, n1, n2, n3, n4)) {
                continue;
            }

            if (!validation0(n2, n4)) {
                continue;
            }

            switch (op) {
                case '+':
                    res = addition(toRational(n1, n2 ), toRational(n3, n4 ));
                    toFraction(res);
                    break;
                case '-':
                    res = subtract(toRational(n1, n2), toRational(n3, n4));
                    toFraction(res);
                    break;
                case '*':
                    res = multiplication(toRational(n1, n2), toRational(n3, n4));
                    toFraction(res);
                    break;
                case '/':
                    res = divided(toRational(n1, n2), toRational(n3, n4));
                    toFraction(res);
                    break;
                default:
                    cout << "Invalid operation. Try again\n";
                    continue;
            }

        }
        else if (choice =='2'){
            cout << "Thank you for using Rational Calculator";
            break;
        }
    }
    return 0;
}
/*
Pseudo Code:
------------

Define the functions for addition, subtraction, multiplication, division.
These functions should take the necessary parameters and return the result.
Define function to convert a decimal result to a fraction.

The function toFraction takes three parameters: result_number, cycles, and precision.
uses a counter (counter) to limit the number of iterations and prevent an infinite loop.
It approximates the fraction representation of the decimal number by continuously calculating the
reciprocal of the decimal part and updating the numerator and denominator accordingly.

Implement the validation functions for input and denominator values.
The validation0 function checks if the denominators (n2 or n4) are zero it displays an error message.
isValidInput function checks all the required components in the user's input 
(division operator, arithmetic operator,four rational numbers).
If any component is missing or invalid, it displays an error message .

Display the program title: "Rational Number Calculator"
Initialize the necessary variables and start an infinite loop until the user chooses to exit.
Display the menu options:
"Choose to:"
"1) Calculate Rational operation"
"2) Exit"
Read the user's input into the variable in and Check the validity of the user's input:
If the input is not a single character or the character is not '1' or '2'
        display an error message and continue to the next iteration of the loop.
        
Convert the user's input to the variable choice (the first character of in).
If choice is equal to '1':

Read the user's operation input into the variable input.
Check the validity of the operation input Using the function isValidInput(input, div_op, op, n1, n2, n3, n4).
Check the validity of the denominator values Using the function validation0(n2, n4).

Perform the arithmetic operation based on the operator op:
Use the appropriate function (addition, subtract, multiplication, divided) to perform the operation
on the rationalnumbers n1, n2, n3, n4.
Store the result in the variable res.
Convert the result to a fraction Using toFraction(res) and display it.

If choice is equal to '2':
Display the message "Thank you for using Rational Calculator" and exit the program.
*/
