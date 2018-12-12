
#include<iostream>
#include<string>
#include<stdio.h>

#include"token1.h"
//#include"SYNBL.h"

using namespace std;
typedef struct A{
 string grammar_all;
 char grammar_left;
 string selected[1000];
 int num = 0;
}Grammar;
 class LL1{
public:
void readfrom_file(string filename,char* &a);
void initial_grammar();
string isBegin();
int is_exit(int t,string w);
int isnot_end(string z);
int is_end(char z);
void initial_signal();
void first(string s,int p);
void is_change_empty(string s,int p);
void follow(string grammar_left,int p);
void selected();
void make_excel();
void pop(Token &x);
void next(Token *a,Token &w,int &i);
void control(Token* a,string begin_signal);
void chachong();
void initial_grammar_isend();
bool isfind(string s,string str);
string readspace(string s);
string left_grammar(string s);
string right_grammar(string s);
string single_between_space(string s);
bool isConstant(string s);
bool isIdentifier(string s);
bool isChar(string s);
void initial_class();
};
class stackk{
public:

Token stack_name[100];
Token top();
void pop();
void push(Token s);
int high = 0;
};
