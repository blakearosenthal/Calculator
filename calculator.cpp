// USERNAME: brosenthal
// AUTHORS: Clare Casey and Blake Rosenthal
// DATE: 10/10/2018
// FILENAME: calculator.cpp
// DESCRIPTION: A simulation of a HP calculator using infix expressions to
//				make calculations.

#include "stack.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/*
	performs the functions of the HP calculator
	pre: input, storage, isAdded, overflow, underflow have been initialized
	post: calculator methods have been used to simulate a HP calculator
	usage: hPCalculate(input, storage, isAdded, overflow, underflow);
*/
void hPCalculate(char& input, Stack& storage, bool& isAdded, bool& overflow, bool& underflow);

/*
	prints a specified number of blank lines
	pre: none
	post: a number of blank line has  been printed to the console
	usage: printNewLines(lineNumber);
*/
void printNewLines(int desiredNumber);

/*
	prints HP calculator screen including the top 3 values of stack
	pre: pstack, isAdded, overflow, and underflow have been initialized
	post: HP calculator screen has been printed to console
	usage: printCalculatorScreen(storage, isAdded, overflow, underflow);
*/
void printCalculatorScreen(Stack& pstack, bool isAdded, bool& overflow, bool& underflow);

/*
	prompts user for input and adds the input to pstack
	pre: input, pstack, isAdded have been initialized
	post: if stack is not full pstack has been filled with input from user
	usage: getInputFromUser(input, storage, isAdded);
*/
void getInputFromUser(char& input, Stack& pstack, bool& isAdded);

/*
	evaluates infix expression based on topItem(s) in pstack
	pre: pstack, isAdded, overflow, underflow have been initialized
	post: if an arithmetic operator has been found a calculation has been
		  made and added to stack.
	usage: evaluate(storage, isAdded, overflow, underflow);
*/
void evaluate(Stack& pstack, bool isAdded, bool& overflow, bool& underflow);

/*
	checks to see if there is an underflow in the calculator
	pre: pstack and total have been initialized
	post: false has been returned if underflow has been found else true has
	usage: checkUnderflow(pstack, total);
*/
bool checkUnderflow(Stack& pstack, int total);

/*
	checks to see if there is an overflow in the calculator
	pre: pstack and total have been initialized
	post: false has been returned if overflow has been found else true has
	usage: checkOverflow(pstack, total);
*/
bool checkOverflow(Stack& pstack, int total);

/*
	checks if the char at the top of the stack is a '+'
	pre: achar has been assigned
	post: achar is the same; if achar is '+' return true; else false is returned;
	usage: isAddition(topItem)
*/
bool isAddition(char achar);

/*
	checks if the char at the top of the stack is a '-'
	pre: achar has been assigned
	post: achar is the same; if achar is '-' return true; else false is returned;
	usage: isSubtraction(topItem)
*/
bool isSubtraction(char achar);

/*
	checks if the char at the top of the stack is a '*'
	pre: achar has been assigned
	post: achar is the same; if achar is '*' return true; else false is returned;
	usage: isMultiplication(topItem)
*/
bool isMultiplication(char achar);

/*
	checks if the char at the top of the stack is a '/'
	pre: achar has been assigned
	post: achar is the same; if achar is '/' return true; else false is returned;
	usage: isDivision(topItem)
*/
bool isDivision(char achar);

/*
	checks if the char at the top of the stack is a '+'
	pre: achar has been assigned
	post: achar is the same; if achar is '+' return true; else false is returned;
	usage: isDoubleDigit(topItem)
*/
bool isDoubleDigit(char achar);


/*
	checks if the char at the top of the stack is a '+'
	pre: achar has been assigned
	post: achar is the same; if achar is '+' return true; else false is returned;
	usage: isNegative(topItem)
*/
bool isNegative(char achar);

/*
	checks if the char at the top of the stack is a '%'
	pre: achar has been assigned
	post: achar is the same; if achar is '%' return true; else false is returned;
	usage: isMod(topItem)
*/
bool isMod(char achar);

/*
	checks if the char at the top of the stack is a '^'
	pre: achar has been assigned
	post: achar is the same; if achar is '^' return true; else false is returned;
	usage: isExponent(topItem)
*/
bool isExponent(char achar);

/*
	converts a char to a it's corresponding ascii value
	pre: achar has been initialized
	post: char has been converted to integer value
	usage: convertDigitCharToIntegerValue(topItem);
*/
int convertDigitCharToIntegerValue(char achar);

int main()
{
	char input;
	Stack storage;
	bool isAdded;
	bool overflow;
	bool underflow;
	
	isAdded = true;
	overflow = true;
	underflow = true;
	
	hPCalculate(input, storage, isAdded, overflow, underflow);
	
	return 0;
}

/*
	performs the functions of the HP calculator
	pre: input, storage, isAdded, overflow, underflow have been initialized
	post: calculator methods have been used to simulate a HP calculator
	usage: hPCalculate(input, storage, isAdded, overflow, underflow);
*/
void hPCalculate(char& input, Stack& storage, bool& isAdded, bool& overflow, bool& underflow)
{
	while (input != 'x')
	{
		getInputFromUser(input, storage, isAdded);
		if(input != 'x')
		{
			evaluate(storage, isAdded, overflow, underflow);
			printCalculatorScreen(storage, isAdded, overflow, underflow);
		}
	}
	if (input == 'x')
	{
		cout << "\t\t      Goodbye. Thanks for using our calculator" << endl;
	}
}

/*
	prints a specified number of blank lines
	pre: none
	post: a number of blank line has  been printed to the console
	usage: printNewLines(lineNumber);
*/
void printNewLines(int desiredNumber)
{
	for (int i = 0; i < desiredNumber; i++)
	{
		cout << endl;
	}
}

/*
	prints HP calculator screen including the top 3 values of stack
	pre: pstack, isAdded, overflow, and underflow have been initialized
	post: HP calculator screen has been printed to console
	usage: printCalculatorScreen(storage, isAdded, overflow, underflow);
*/
void printCalculatorScreen(Stack& pstack, bool isAdded, bool& overflow, bool& underflow)
{
	ItemType topItem; Stack cpstack; int lineNumber = 2; int stackSize = 0;
	cout << "\t\t\tScreen" << endl;
	
	while (not pstack.isEmpty())
	{
		pstack.retrieve(topItem);
		cpstack.push(topItem, isAdded);
		pstack.pop();
		stackSize++;
	}
	
	if (!overflow) {
		cout << "\t\t      3:" << endl << "\t\t      2: " << endl;
		cout << "\t\t      1: OVERFLOW" << endl;
	} else if (!underflow) {
		cout << "\t\t      3:" << endl << "\t\t      2: " << endl;
		cout << "\t\t      1: UNDERFLOW" << endl;
	} else if (!isAdded) {
		cout << "\t\t      3:" << endl << "\t\t      2: " << endl;
		cout << "\t\t      1: STACKFULL" << endl;
	}else if (stackSize == 1) {
		cout << "\t\t      3:" << endl << "\t\t      2: " << endl;
		cpstack.retrieve(topItem);
		cout << "\t\t      1: " << topItem << endl;
		pstack.push(topItem, isAdded);
		cpstack.pop();
	} else if (stackSize == 2) {
		cout << "\t\t      3:" << endl;
		cpstack.retrieve(topItem);
		cout << "\t\t      2: " << topItem << endl;
		pstack.push(topItem, isAdded);
		cpstack.pop();
		cpstack.retrieve(topItem);
		cout << "\t\t      1: " << topItem << endl;
		pstack.push(topItem, isAdded);
		cpstack.pop();
	}  else {
		cpstack.retrieve(topItem);
		cout << "\t\t      3: " << topItem << endl;
		pstack.push(topItem, isAdded);
		cpstack.pop();
		cpstack.retrieve(topItem);
		cout << "\t\t      2: " << topItem << endl;
		pstack.push(topItem, isAdded);
		cpstack.pop();
		cpstack.retrieve(topItem);
		cout << "\t\t      1: " << topItem << endl;
		pstack.push(topItem, isAdded);
		cpstack.pop();
		for (int i = 3; i < stackSize; i++) {
			pstack.retrieve(topItem);
			pstack.push(topItem, isAdded);
			cpstack.pop();
		}
	}
	printNewLines(lineNumber);
}

/*
	prompts user for input and adds the input to pstack
	pre: input, pstack, isAdded have been initialized
	post: if stack is not full pstack has been filled with input from user
	usage: getInputFromUser(input, storage, isAdded);
*/
void getInputFromUser(char& input, Stack& pstack, bool& isAdded)
{
	int lineNumber = 2;
	cout << "input> ";
	cin >> input;
	printNewLines(lineNumber);
	pstack.push(input, isAdded);
}

/*
	evaluates infix expression based on topItem(s) in pstack
	pre: pstack, isAdded, overflow, underflow have been initialized
	post: if an arithmetic operator has been found a calculation has been
		  made and added to stack.
	usage: evaluate(storage, isAdded, overflow, underflow);
*/
void evaluate(Stack& pstack, bool isAdded, bool& overflow, bool& underflow)
{
	ItemType topItem;
	int total = 0;
	
	pstack.retrieve(topItem);
	if (isAddition(topItem))
	{
		pstack.pop();
		pstack.retrieve(topItem);
		int a = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		pstack.retrieve(topItem);
		int b = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		total = a + b;
		char achar = '0' + total;
		pstack.push(achar, isAdded);
	} else if (isSubtraction(topItem))
	{
		pstack.pop();
		pstack.retrieve(topItem);
		int a = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		pstack.retrieve(topItem);
		int b = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		total = a - b;
		char achar = '0' + total;
		pstack.push(achar, isAdded);
	} else if (isMultiplication(topItem))
	{
		pstack.pop();
		pstack.retrieve(topItem);
		int a = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		pstack.retrieve(topItem);
		int b = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		total = a * b;
		char achar = '0' + total;
		pstack.push(achar, isAdded);
	} else if (isDivision(topItem))
	{
		pstack.pop();
		pstack.retrieve(topItem);
		int a = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		pstack.retrieve(topItem);
		int b = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		total = b / a;
		char achar = '0' + total;
		pstack.push(achar, isAdded);
	} else if (isMod(topItem))
	{
		pstack.pop();
		pstack.retrieve(topItem);
		int a = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		pstack.retrieve(topItem);
		int b = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		total = a % b;
		char achar = '0' + total;
		pstack.push(achar, isAdded);
	} else if (isExponent(topItem))
	{
		pstack.pop();
		pstack.retrieve(topItem);
		int a = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		pstack.retrieve(topItem);
		int b = convertDigitCharToIntegerValue(topItem);
		pstack.pop();
		total = a ^ b;
		char achar = '0' + total;
		pstack.push(achar, isAdded);
	}
	underflow = checkUnderflow(pstack, total);
	overflow = checkOverflow(pstack, total);
}

/*
	checks to see if there is an underflow in the calculator
	pre: pstack and total have been initialized
	post: false has been returned if underflow has been found else true has
	usage: checkUnderflow(pstack, total);
*/
bool checkUnderflow(Stack& pstack, int total)
{
	if (total < 0)
	{
		pstack.pop();
		return false;
	}
	return true;
}

/*
	checks to see if there is an overflow in the calculator
	pre: pstack and total have been initialized
	post: false has been returned if overflow has been found else true has
	usage: checkOverflow(pstack, total);
*/
bool checkOverflow(Stack& pstack, int total)
{
	if (total > 9)
	{
		pstack.pop();
		return false;
	}
	return true;
}

/*
	checks if the char at the top of the stack is a '+'
	pre: achar has been assigned
	post: achar is the same; if achar is '+' return true; else false is returned;
	usage: isAddition(topItem)
*/
bool isAddition(char achar)
{
	if (achar == '+')
	{
		return true;
	} else {
		return false;
	}
}

/*
	checks if the char at the top of the stack is a '-'
	pre: achar has been assigned
	post: achar is the same; if achar is '-' return true; else false is returned;
	usage: isSubtraction(topItem)
*/
bool isSubtraction(char achar)
{
	if (achar == '-')
	{
		return true;
	} else {
		return false;
	}
}

/*
	checks if the char at the top of the stack is a '*'
	pre: achar has been assigned
	post: achar is the same; if achar is '*' return true; else false is returned;
	usage: isMultiplication(topItem)
*/
bool isMultiplication(char achar)
{
	if (achar == '*')
	{
		return true;
	} else {
		return false;
	}
}

/*
	checks if the char at the top of the stack is a '/'
	pre: achar has been assigned
	post: achar is the same; if achar is '/' return true; else false is returned;
	usage: isDivision(topItem)
*/
bool isDivision(char achar)
{
	if (achar == '/')
	{
		return true;
	} else {
		return false;
	}
}

/*
	checks if the char at the top of the stack is a '%'
	pre: achar has been assigned
	post: achar is the same; if achar is '%' return true; else false is returned;
	usage: isMod(topItem)
*/
bool isMod(char achar)
{
	if (achar == '%')
	{
		return true;
	} else {
		return false;
	}
}

/*
	checks if the char at the top of the stack is a '^'
	pre: achar has been assigned
	post: achar is the same; if achar is '^' return true; else false is returned;
	usage: isExponent(topItem)
*/
bool isExponent(char achar)
{
	if (achar == '^')
	{
		return true;
	} else {
		return false;
	}
}

/*
	converts a char to a it's corresponding ascii value
	pre: achar has been initialized
	post: char has been converted to integer value
	usage: convertDigitCharToIntegerValue(topItem);
*/
int convertDigitCharToIntegerValue(char achar)
{
	int ascii;
	int asciiZero = 48;
	ascii = achar;
	return(ascii - asciiZero);
}