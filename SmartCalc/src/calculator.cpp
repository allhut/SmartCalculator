/* Copyright 2016 @ALLHUT */


#include "header.h"



int evaluateString(char *p_str){

char *p_ittr = p_str;
int num =0, num1 = 0, num2 = 0;
stack<int> value;
stack<char> opr;


for(int i = 0; *(p_ittr+i) != '\0'; i++){

//cout<<*(p_ittr+i)<<" p ";
num = 0;

// Current token is a whitespace, skip it
if(*(p_ittr+i) == ' ')
	continue;

// Current token is a number, push it to stack for numbers
if(*(p_ittr+i) >= '0' && *(p_ittr+i) <= '9' ){
 
do{
   num = num + (int)*(p_ittr+i) - 48 ;
   num = num * 10;
   i++;
}while(*(p_ittr+i) >= '0' && *(p_ittr+i) <= '9');
num = num / 10;
i--;
value.push(num);
}

// Current token is an opening brace, push it to 'ops'
else if(*(p_ittr+i) == '('){
 opr.push(*(p_ittr+i));
}

// Closing brace encountered, solve entire brace
else if(*(p_ittr+i) == ')'){
	while(opr.top() != '('){		  
		num1 = value.top();
		value.pop();
		num2 = value.top();
		value.pop();
		value.push(applyOperation(opr.top(), num1, num2));    
		opr.pop();
	}
	opr.pop();
}

// Current token is an operator.
else if (*(p_ittr+i) == '+' || *(p_ittr+i) == '-' ||
         *(p_ittr+i) == '*' || *(p_ittr+i) == '/'){

        // While top of 'ops' has same or greater precedence to current
        // token, which is an operator. Apply operator on top of 'ops'
        // to top two elements in values stack
        while (!opr.empty() && hasPrecedence(*(p_ittr+i), opr.top())){
        	num1 = value.top();
			value.pop();
			num2 = value.top();
			value.pop();
			value.push(applyOperation(opr.top(), num1, num2));    
			opr.pop();
 		}
        // Push current token to 'ops'.
        opr.push(*(p_ittr+i));
        }
    }
 
        // Entire expression has been parsed at this point, apply remaining
        // ops to remaining values
        while (!opr.empty()){
            num1 = value.top();
			value.pop();
			num2 = value.top();
			value.pop();
			value.push(applyOperation(opr.top(), num1, num2));    
			opr.pop();
 		}
        // Top of 'values' contains result, return it
        return value.top();
    }



// Returns true if 'op2' has higher or same precedence as 'op1',
// otherwise returns false.
bool hasPrecedence(char op1, char op2){
        if (op2 == '(' || op2 == ')')
            return false;
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return false;
        else
            return true;
    }
 
// A utility method to apply an operator 'op' on operands 'a' 
// and 'b'. Return the result.
int applyOperation (char op, int b, int a){

	switch (op){

		case '+':
			return a+b;
			
		case '-':
			return a-b;
			
		case '*':
			return a*b;
			
		case '/':
			if (b == 0){
				cout<<"can not divide by zero"<<endl;
				return -1;
			}
			return a/b;			
	}
	return 0;
}