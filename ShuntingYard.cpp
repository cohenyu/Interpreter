//
// Created by yuval on 16/12/18.
//

#include "ShuntingYard.h"
#include "Minus.h"
#include "Mul.h"
#include "Number.h"
#include "Plus.h"
#include "Div.h"


// Function to find precedence of operators.
/*
 * this function bring precedence to operators
 * its return int that represent the precedence
 * ),( : precedence 0
 * +,- : precedence 1
 * *,/ : precedence 2
 *
 */
int ShuntingYard::precedence(char op) {
    if(op == '+'|| op == '-'){
        return 1;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    return 0;
}
/*
 * this function get a string of numbers as infix and returns an Expression
 * as pre fix, that we can calculate.
 * we have 2 stacks that storage the values(Expression) and the operators
 */
Expression* ShuntingYard::fromInfixToExp(string infixExpression) {
    // stack to store the Expression.
    stack <Expression*> values;
    // stack to store operators.
    stack <char> ops;
    int isNeg =1;
    //run over the infix string
    for(int  i = 0; i < infixExpression.length(); i++){

        // Current exp is a whitespace,skip it.
        if(infixExpression[i] == ' ')
            continue;

        // Current exp is an opening brace, push it to 'ops'
        else if(infixExpression[i] == '('){
            ops.push(infixExpression[i]);
        }

        // Current exp is a number, push it to stack of Expression
        else if(isdigit(infixExpression[i])){
            isNeg = 0;
            double val = 0;

            // There may be more than one digits in number.
            while(i < infixExpression.length() && isdigit(infixExpression[i]))
            {
                val = (val * 10) + (infixExpression[i] - '0');
                i++;
            }
            i--;
            Expression* num = new Number(val);
            values.push(num);
        }

        // Closing brace encountered, solve entire brace.
        else if(infixExpression[i] == ')') {
            //while we didnt finish the stack and we dont saw"("
            while (ops.top() != '(' && !ops.empty()){

                /*
                 * we take the right and the left Expression and the operator
                 * and create from them Expression.
                 * */
                Expression *right = values.top();
                values.pop();

                Expression *left = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(createExp(left, right, op));
            }

            //remove the operator '(' from the queue
            ops.pop();

          // Current exp is a operator
        } else{
            if (isNeg){
                Expression* num = new Number(0);
                values.push(num);
            }
            /*
             * While top of 'ops' has same or greater precedence to current
             * token, which is an operator.
             * Apply operator on top of 'ops' to top two elements in
             * values stack.
             * */
            while (!ops.empty() && !isNeg && (precedence((infixExpression[i])) <=
            precedence(ops.top()))){
                //remove the operator from the queue and put in the stack
                Expression *right = values.top();
                values.pop();

                Expression *left = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(createExp(left, right, op));
            }
            isNeg = 1;
            // add the operator to the stack
            ops.push(infixExpression[i]);
        }
    }

    while (!ops.empty()){
        //remove the operator from the queue and put in the stack
        Expression *right = values.top();
        values.pop();

        Expression *left = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(createExp(left, right, op));
    }

    return values.top();
}
/*
 * this function get a right and left Expression and an operator
 * and returns an expression from it.
 */
Expression *ShuntingYard::createExp(Expression *left, Expression *right, char operation) {
    switch (operation) {
        case '*':
            return new Mul(left, right);
        case '/':
            return new Div(left, right);
        case '+':
            return new Plus(left, right);
        case '-':
        default:
            return new Minus(left, right);
    }
}
