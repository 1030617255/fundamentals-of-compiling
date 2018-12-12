
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<map>
#include<set>
#include<stack>
#include"LL1.h"
#include"SYNBL.h"
extern Token token[1000];
extern int boundary_signal_num;
extern int token_num;
extern string boundary_signal[1000];








extern map<string,int> TYPE_LENGTH;
/*int main(){
    char a[100] = "iwiwi#";
    LL1 L;
    token_class token_now;
    token_now.initial_Key_word();
    token_now.intitial_boundary_signal();
    L.initial_grammar_isend();
   L.initial_grammar();
  L.initial_signal();
  L.selected();
   L.chachong();
  L.make_excel();s
 // L.control(a,'E');
}*/
int i = 1;


int main(){

    char *p;
   token_class Token;
   Token.initial_Key_word();
   Token.intitial_boundary_signal();
   char a[10000];
   p = a;
   string infile = "a1.txt";
   ifstream fin(infile.c_str(),ios::in);
   while(fin.getline(a,sizeof(a))){
     p = a;
     Token.clear_state();
     Token.Begin(p);
     memset(a,0,sizeof(a));
   }
   boundary_signal[++boundary_signal_num] = "'";
    LL1 L;
    L.initial_class();
    L.initial_grammar_isend();
    L.initial_grammar();
    L.initial_signal();
    L.make_excel();
    L.control(token,"CX");
   return 0;
}


