#include<iostream>
#include"stack.h"
bool is_operande(char* token);
void push (int tab[],int token2,int* adrtop);
int pop (int tab[],int* adrtop);
int rpn_eval (int n,char* tabE[]);
