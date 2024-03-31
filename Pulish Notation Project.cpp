#include <iostream>
#include <stack> 
#include <string>

using namespace std;

// Convert infix to postfix function
string infixtopostfix(string infix);
// HighPrecedent function
int HighPrecedent(char op1, char op2);

int main() {
	string expression;
	cout << "Enter Your infix string: " << endl;
	getline(cin, expression);
	string postfix = infixtopostfix(expression);
	cout << "Postfix is: " << postfix;
	return 0;
}

string infixtopostfix(string infix) {
	string postfix = "";
	stack<char> S;
	
	for (unsigned int i = 0; i < infix.length(); i++) {
		if (isdigit(infix[i]) 
			|| (infix[i] >= 'a' && infix[i] <= 'z') 
			|| (infix[i] >= 'A' && infix[i] <= 'Z')) 
			postfix += infix[i];
		// Add the precedent for () >>> Parentheses		
		//  
		else
		{
			if (!S.empty()) {
				while (!S.empty() && HighPrecedent(S.top(), infix[i]) ) {
					postfix += S.top();
					S.pop();
				}
			}
			S.push(infix[i]);
		}
	}
	
	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	
	return postfix;
}

// PEMDAS >> "Please Excuse My Dear Aunt Sally" '()' '^' '*/' '+-'
int HighPrecedent(char op1, char op2) {
	if (op1 == '^')		return 1;
	else if ((op1 == '*') || (op1 == '/'))
		return op2 != '^';
	else if ((op1 == '+') || (op2 == '-'))
		return ((op2 != '*') && (op2 != '/') && (op2 != '^'));
	// return 0;
}


/*
#include <iostream>
#include <stack>
#include <string>

// Infix to postfix conversion in C++
//  Input Postfix expression must be in a desired format.
//  Operands and operator, both must be single character.
//  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.


using namespace std;

// Function to convert Infix expression to postfix 
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool IsOperand(char C);

// prifix: 5+3+4+5*2*3+4+5 >>> postfix: 53+4+52*3*+4+5+ >>> ProgramPostFix: 53+4+5+2*3*4+5+ 
// prifix: 5+3+4*2*3+10/5+2 >> postfix: 53+42*3*+105/+2+ >> ProgramPostfix: 53+4+2*3*10+5/2+
int main()
{
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << "\n";
	return 0;
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++. 
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for (unsigned int i = 0; i < expression.length(); i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(expression[i], S.top()))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.empty() && S.top() != '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit. 
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	
	// if (C >= 'a' && C <= 'z') return true;
	// if (C >= 'A' && C <= 'Z') return true;
	
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

// Function to perform an operation and return output. 
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;

}
*/