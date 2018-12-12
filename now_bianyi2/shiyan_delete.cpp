/*
#include<iostream>
//#include<string>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<map>
#include<set>
#include<stack>
#include"LL1.h"
#include"token1.h"
extern Token token[100];
extern  int token_num;
int main(){
   char *p;
   token_class Token;
   Token.initial_Key_word();
   Token.intitial_boundary_signal();
   char a[10000];
   p = a;
   string infile = "ab.txt";
   ifstream fin(infile.c_str(),ios::in);
   while(fin.getline(a,sizeof(a))){
     p = a;
    // cout<<a<<endl;
     Token.Begin(p);
     memset(a,0,sizeof(a));

   }
   char shiyan_arry[100];
   int i = 1;
   for( ; i<= token_num;i++)
   {
       if(token[i].kind==6&&(token[i].token_num1=="+"||token[i].token_num1=="-"))
         shiyan_arry[i-1] = 'w';
       else if(token[i].kind == 5||token[i].kind==2)shiyan_arry[i-1] = 'i';
       else if(token[i].kind ==6&&(token[i].token_num1=="*"|token[i].token_num1=="/"))
        shiyan_arry[i-1] = 'r';
       else if(token[i].token_num1=="("){
          shiyan_arry[i-1]='(';
       }
       else if(token[i].token_num1==")"){
        shiyan_arry[i-1]=')';
       }
       else{
         shiyan_arry[i-1]='$';
       }
   }
   cout<<"shiyan"<<i<<endl;
   shiyan_arry[i-1] = '#';
   for(int j = 0 ; j<= i-1 ;j++)
    cout<<shiyan_arry[j];

 cout<<endl;
     LL1 L;
   L.initial_grammar();
  L.initial_signal();
  L.selected();
   L.chachong();
  L.make_excel();
  L.control(shiyan_arry,'E');
   return 0;
}

*/
