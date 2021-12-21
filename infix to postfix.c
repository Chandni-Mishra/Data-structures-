#include <stdio.h>
int checkop (char n){
 if (n == '+' || n == '-' || n == '*' || n == '/' || n == '(' || n == ')'|| n == '^'){
 return 1;
 }
 else {
 return 0;
 }
}
int precedence (char n){
 if (n == '^') {
 return 3;
 }
 if (n == '/' || n == '*'){
 return 2;
 }
 if (n == '+' || n == '-'){
 return 1;
 }
}
int main (){
printf("NAME-CHANDNI MISHRA\nSECTION-B\nID-20012871\n");
 char expr[100];
 char stack[100];
 char output[100];
 int top = -1, i = 0, j = 0;
 printf ("Enter a Expression\n");
 scanf ("%s", expr);
 for (i = 0; expr[i] != '\0'; i++){
 if (checkop (expr[i]) == 0){
 output[j] = expr[i];
 j++;
}
 else{
 if (expr[i] == '(') {
 top++;
 stack[top] = expr[i];
 }
 else if (expr[i] == ')'){
 while (stack[top] != '('){
 output[j] = stack[top];
 top = top - 1;
 j++;
}
 top = top - 1;
 }
 else if (precedence (expr[i]) > precedence (stack[top]) || top == -1
 || stack[top] == '(')
 {
 top++;
 stack[top] = expr[i];
 }
 else{
 while ((precedence (expr[i]) <= precedence (stack[top]))){
 output[j] = stack[top];
 top = top - 1;
 j++;
 if (stack[top] == '(') {
 break;
 }
}
 top = top + 1;
 stack[top] = expr[i];
 }
}
 }
 for (i = top; i > -1; i--)
 {
 output[j] = stack[top];
 top = top - 1;
 j++;
 }
 output[j] == '\0';
 printf ("%s", output);
 return 0;
}
