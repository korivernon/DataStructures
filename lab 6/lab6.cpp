//============================================================================
// Name         : lab5.cpp
// Author       : Kori Vernon
// Version      : 1.0
// Date Created : 13-03-2019
// Date Modified: 01-03-2020 
// Copyright    : All rights are reserved
// Description  : Conver Infix expression to PostFix and then evaluate it
//============================================================================
#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<stdlib.h>
#include<ctype.h>


using namespace std;

bool isOperator(char); //Helper method which checks if the input char is an operator
int convertOpToInt (char); //Helper mehtod which converts operators into int so their precdence can be compared
bool isleq(char, char); //Helper method which compare two operators  and return True if first operator has less or equal predence than the right operator
string infix2postfix(string);   //Helper Method which converts an infix notaiton into a postfix notation (lab4)
float evaluate(string postfix)		//Method which will evaluate a PostfixExpression and return the result
{	
	stack <float> myStack;  //1. Create a stack of type float to store the operands
	//2.	Scan the POSTFIX expression from left to right for every element
    int i = 0;
    float hold = 0;
    myStack.push(hold);
    cout << myStack.top() << endl;
    while(i!= postfix.size()-1){
        
        char c = postfix[i];
        cout << c << endl;
        if (isalnum(c)){
            myStack.push(c);
            cout << atof(myStack.top()) << endl;
        } else {
            cout << "ascii value???: " << myStack.top() << endl;
            float num1 = myStack.top();
            cout << "num1: " << num1 << endl;
            myStack.pop();
            float num2 = myStack.top();
            cout << "num2: " << num2 << endl;
            myStack.pop();
            num1 = num1 + num2;
            cout << "num: " << num1 << endl;
            myStack.push(num1);
        }
        i++;
    }
	//	a.	if the element is an operand push it to the stack
	//	b.	if the element is an operator pop 2 elements from the stack, apply the operator on it and push the result back to the stack

	return myStack.top();//3. return the value from the top of the stack (i.e. the final answer)
}
//=============Main funciton ==============
int main()
{

	// while(true)
	// {
	// 	string infix;  						//Infix expression
	// 	cout<<"Enter an Infix Expression: ";
	// 	cin>>infix;
	
	// 	if(infix=="exit") 
	// 		break;

	// 	string postfix = infix2postfix("6+3+2");	//Postfix Expression
	// 	float ans=evaluate(postfix);			//evaluate the postfix Expresion
	// 	cout<<"The postfix form is: "<<postfix<<endl;
	// 	cout<<infix<<"="<<ans<<endl;		//print the final answer
	// }
    string infix = "6+3+2";
    string postfix = infix2postfix(infix);	//Postfix Expression
	float ans=evaluate(postfix);			//evaluate the postfix Expresion
	cout<<"The postfix form is: "<<postfix<<endl;
	cout<<infix<<"="<<ans<<endl;		//print the final answer

	return EXIT_SUCCESS;
}
//=====================================================================
bool isOperator(char ch)
{
	if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return true;
	else
		return false;

}
//Helper mehtod which converts operators into int so their precdence can be compared
int convertOpToInt (char ch)
{
    if (ch=='+' || ch=='-') return 1;
    if (ch=='*' || ch=='/') return 2;
    if (ch=='^') return 3;
    return 0;
}

//Helper method which compare two operators and return True if first operator
//has less or equal predence than the right operator
bool isleq(char opA, char opB)
{
	return (convertOpToInt(opA)<=convertOpToInt(opB));
}

// Helper Method which converts an Infix Notaiton to a Postfix notation
string infix2postfix(string infix)
{//    ((a+b)/c)  --> ab+
    string postfix = "";
    int curr_precedence = 0;
    int i = 0;
    //cout << "Infix: " << infix << endl;
    //cout << "infix[0]: " << infix[0] << endl; 

    stack<char> mystack;
    mystack.push('(');
    while(!mystack.empty()){
        // cout << "index " << i << endl;
        char c = infix[i];
        if (c == '(' || ((convertOpToInt(c) >= curr_precedence) && isOperator(c))) {
            //cout << "firstif" <<endl;
            mystack.push(c); // a precedence can replace, but a precedence cannot be overtaken
            curr_precedence = convertOpToInt(c);
             //incrementing counter
        } //pushing the right parentheses
        else if (convertOpToInt(c) < curr_precedence && isOperator(c)){ //if the operator is less than the current precedence
            //cout << "2ndif" <<endl;
            while (convertOpToInt(mystack.top()) < curr_precedence){
                char temp = mystack.top();
                if (mystack.top() != '('){
                    postfix = postfix + temp;
                } // push operator to stack
                mystack.pop();
            }
            
        }
        else if (isalnum(c)) {
            //cout << "c: "<< c <<endl;
            postfix = postfix + c; //adding number to the postfix string
            
        } else if (c == ')' || (mystack.size() == i+1)){
            while (mystack.top()!= '('){
                //add to postfix notation
                if (isOperator(c)){
                    // if it is an operator you have to check its precedence and delete???
                    curr_precedence = convertOpToInt(c);
                } else {
                    if (mystack.top() != '('){
                    postfix = postfix + (char)mystack.top();
                }
                    mystack.pop();
                }
            }
            mystack.pop(); //pop last parentheses
        }
        if (i+1 == infix.size()){
            while (!mystack.empty()){
                if (mystack.top() != '('){
                    postfix = postfix + mystack.top();
                }
                mystack.pop();
            }
        }
        i++;
        // cout << "POSTFIX: "<< postfix << endl;
        }
        // cout<< "End" << endl;
        
        return postfix;
    }
	// stack <char> mystack;
	// string postfix="";
	// 1.	Push “(“onto Stack, and add “)” to the end of INFIX.
	// 2.	Scan INFIX from left to right and repeat Step 3 to 6 for each element of INFIX until the Stack is empty.
	// 3.	If an operand is encountered, add it to POSTFIX.
	// 4.	If a left parenthesis is encountered, push it onto Stack.
	// 5.	If an operator is encountered, then: 
	// 	a.	Repeatedly pop from Stack and add to POSTFIX each operator (from top of the Stack) which has the same precedence as or higher precedence than operator.
	// 	b.	Add operator to Stack.
	// 	[End of If]
	// 6.	If a ")" is encountered, then: 
	// 	a.	Repeatedly pop from Stack and add to POSTFIX each operator (from top of the Stack) until a left parenthesis is encountered.
	// 	b.	Remove the "(" from stack
	// [End of If]
	// 7.	END.