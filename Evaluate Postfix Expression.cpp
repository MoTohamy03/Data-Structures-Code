#include <iostream>
#include <string>
#include <stack>
#include <cmath>

double evaluate_postfix(std::string postfix);
double operation(char x, double y, double z);

using namespace std;

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    getline(cin, postfix);
    double result = evaluate_postfix(postfix);

    // Check if the result is an error message
    if (isnan(result)) {
        cout << "Error: Invalid expression" << endl;
    }
    else {
        cout << "The result is: " << result << endl;
    }
    return 0;
}

double evaluate_postfix(string postfix) {
    double value, num, op1, op2;
    stack<double> S;
    for (unsigned int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            num = double(postfix[i] - '0');
            S.push(num);
        }
        else {
            if (S.size() < 2) {
                return NAN; // Not a number, indicates error
            }
            op2 = S.top();
            S.pop();
            op1 = S.top();
            S.pop();
            value = operation(postfix[i], op1, op2);
            S.push(value);
        }
    }

    // Check if there's only one element left in the stack (the result)
    if (S.size() != 1) {
        return NAN;
    }
    return S.top();
}

double operation(char x, double y, double z) {
    switch (x) {
    case '+':
        return y + z;
    case '-':
        return y - z;
    case '*':
        return y * z;
    case '/':
        if (z == 0) {
            return NAN; // Indicate division by zero error
        }
        else {
            return y / z;
        }
    case '^':
        return pow(y, z);
    default:
        return NAN; // Indicate invalid operator error
    }
}



/*
#include <iostream>
#include <string>
#include <stack>

double evalutepostfix(std::string postfix);
double operation(char x, double y, double z);

using namespace std;
int main()
{
    string postfix;
    cout << "Enter The Postfix: ";
    getline(cin, postfix);
    cout << evalutepostfix(postfix) << endl;
    return 0;
}

double evalutepostfix(string postfix) {
    double value, num, op1, op2;
    stack<double> S;
    for (unsigned int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            num = double(postfix[i] - '0');
            S.push(num);
        }
        else {
            op2 = S.top();
            S.pop();
            op1 = S.top();
            S.pop();
            value = operation(postfix[i], op1, op2);
            S.push(value);
        }
        S.pop();
    }

    return value;
}

double operation(char x, double y, double z) { 
    switch (x) {
    case '+': 
        return y + z;
    case '-':
        return(y - z);
    case '*':
        return(y * z);
    case '/':
        return(y / z);
    case '^':
        return(pow(y,z));
    }
}

*/