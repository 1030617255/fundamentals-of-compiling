

#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include"token1.h"
#include<stdlib.h>
using namespace std;
 Token token[1000];
int state[100] = {0};

 string Key_word[330];  //1
  string Identifier[1000];//2
 string String[1000];//3
 string Char[1000];//4
 string constant[1000];//5
 string boundary_signal[1000];//6
 int token_num = 0;
 int Key_word_num = 17;
 int Identifier_num = 0;
 int String_num = 0;
 int constant_num = 0;
 int boundary_signal_num = 30;
int Char_num = 0;

void token_class::add_token(string token1,int kind1,int position1){
   token_num++;
   int n = token_num;
  token[n].token_num1 = token1;
  token[token_num].kind = kind1;
  token[token_num].num = token_num;
  token[token_num].position = position1;
}
void token_class::initial_Key_word(){
     Key_word[6] = "int";Key_word[2] = "void";
     Key_word[3] = "if"; Key_word[4] = "else"; Key_word[5] = "char";
     Key_word[7] = "float";Key_word[8] = "if";Key_word[9] = "else";
     Key_word[10] = "while";Key_word[11] = "break";Key_word[12] = "continue";
     Key_word[13] = "return";Key_word[1] = "struct"; Key_word[14] = "bool";
     Key_word[15] = "false";Key_word[16] = "true";Key_word[17] = "for";
}
void token_class::intitial_boundary_signal(){
     boundary_signal[1] = "==";boundary_signal[2] = ">=";
     boundary_signal[3] = ">";boundary_signal[4] = "<";boundary_signal[5] = "=";
     boundary_signal[6] = "-";boundary_signal[7] = "+";boundary_signal[8] = ".";
     boundary_signal[9] = "/";boundary_signal[10] = "{";boundary_signal[11] = "}";
     boundary_signal[12] = ",";boundary_signal[13] = ";";boundary_signal[14] = "(";
     boundary_signal[15] = ")";boundary_signal[16] = "<=";boundary_signal[17] = "?";
     boundary_signal[18] = "+=";boundary_signal[19] = "-=";boundary_signal[20]="(";
     boundary_signal[21] = "[";boundary_signal[22] = "]";boundary_signal[23] = "//";
     boundary_signal[24] = "&&"; boundary_signal[25] = "&";boundary_signal[26] = "|";
     boundary_signal[27] = "||";boundary_signal[28] = "<<";boundary_signal[29] = ">>";
     boundary_signal[30] = "*";//boundary_signal[31] = "'";
}

void token_class::clear_state(){
    for(int i = 0 ; i < 100 ; i++)
        state[i] = 0;
}
bool token_class::is_space(char *p){
  if(*p == ' ') return true;
  else return false;
}
void token_class::read_space(char* &p){
    while(*p == ' ' || *p=='\n') {p++;}
    return ;
}
bool token_class::is_bc( char *p){
   if(*p>=48&&*p<=57) return true;
   else return false;

}
bool token_class::is_letter(char *p){
   if((*p>=65&&*p<=90)||(*p>=97&&*p<=122)) return true;
   else return false;
}
void token_class::back_p(char *&p){
    p--;
}
int token_class::is_Key_word(string token){
   // cout<<2222222;
   // string str = "";
  //  str+=*p;
    int t = 1;
   for(int i = 1 ; i <= Key_word_num ; i++){
    if(Key_word[i] == token ) {t= 0;return i;}
   }
    if(t==1) return 0;
}

int token_class::is_boundary_signal(char* p){
   string str = "";
   str+=*p;
   //cout<<str<<" ";
   int t = 1;
   for(int i = 1 ; i <= boundary_signal_num ; i++){
    if(boundary_signal[i] == str) {t = 0 ; return i;break;}
   }
    if(t == 1) return 0;
}
int token_class::is_boundary_signal_double(string str){
   int t = 1;
   for(int i = 1 ; i <= boundary_signal_num ; i++){
    if(boundary_signal[i] == str) {t = 0 ; return i;break;}
     }
   if(t == 1) return 0;
}
void token_class::Begin(char *p){
    string strtoken ;
    while(*p != '#'&& *p!='\0'){
        read_space(p);// p 是文件里开头字符的指针，写完后面再把这里加上,这里的返回值是第一个不为空格的p
        if(is_letter(p)){
            while(is_bc(p)||is_letter(p)||*p == '_'){
                strtoken+=*p;
                p++;
            }
           // back_p(p);
           // back_p(p);
           // back_p(p);
           // back_p(p);
           //cout<<strtoken.size()<<endl;
          if(is_Key_word(strtoken)){
            add_token(strtoken,1,is_Key_word(strtoken));
            cout<<"Key_word:{"<<strtoken<<","<<is_Key_word(strtoken)<<"} "<<endl;
            strtoken = "";
          }
          else{
            Identifier[++Identifier_num] = strtoken;
            cout<<"Identifier:{"<<strtoken<<","<<Identifier_num<<"} "<<endl;;
            if(strtoken=="a")  cout<<"yes"<<endl;
            add_token(strtoken,2,Identifier_num);
            strtoken = "";
          }
        }
        else if(is_bc(p)){
            if(state[2] == 0 && state[3] == 0)
            {
                state[1] = 1;
            }
            int tag = 0;
           while(tag == 0){//  自动机完成
            //cout<<strtoken<<endl;

            //cout<<1;
            while(is_bc(p)&&state[1]==1){
            //  cout<<1;
              strtoken += *p;
              p++;
            }
            while(is_bc(p)&&state[3]==1){
             //   cout<<3;
                strtoken += *p;
                p++;
            }
            if(is_bc(p)&&state[2]==1){
            //    cout<<3;
                state[3] = 1;
                state[2] = 0;
                strtoken += *p;
                p++;
            }
            if(state[1] == 1 && is_letter(p)){
                state[1] = 0;
                state[4] = 1;
                p++;
            }
            if(*p == '.'&&state[1] == 1){
            //   cout<<2;
              state[1] = 0;
              strtoken += *p;
              state[2] = 1;//////////////
              p++;
            }
            if(is_letter(p)&& state[2] == 1 ){                          // error
              //  cout<<4;
                state[2] = 0;
                state[4] = 1;///////////////
                p++;
            }
            if(state[2] == 1 && is_space(p)){
            //    cout<<4;
                state[2] = 0;
                state[4] = 1;//////////////
                p++;
            }
            if(state[2] == 1 && is_boundary_signal(p)){
           //      cout<<4;
                state[2] = 0;
                state[4] = 1;//////////////
                p++;
            }
            if(state[3] == 1 && (is_space(p))){
           //     back_p(p);
                state[3] = 0;
                constant[++constant_num] = strtoken;
                cout<<"constant:{"<<strtoken<<","<<constant_num<<"} "<<endl;;

                add_token(strtoken,5,constant_num);
                 strtoken = "";
                 tag = 1;
                 break;
            }
            if(state[3] == 1 && is_letter(p)){
                //cout<<4;
                state[3] = 0;
                state[4] = 1;//////////////////
                p++;
            }
            if(state[3] == 1 && is_boundary_signal(p) && is_boundary_signal(p)!=8){
           //     back_p(p);
             // cout<<55555555;
                state[3] = 0;
                constant[++constant_num] = strtoken;
                cout<<"constant:{"<<strtoken<<","<<constant_num<<"} "<<endl;;

                add_token(strtoken,5,constant_num);
                strtoken = "";
                tag = 1;
                break;
            }
            if(state[3] == 1 && *p == '\0'){
                 state[3] = 0;
                constant[++constant_num] = strtoken;
                cout<<"constant:{"<<strtoken<<","<<constant_num<<"} "<<endl;;

                add_token(strtoken,5,constant_num);
                strtoken = "";
                tag = 1;
                break;
            }
            if(state[3] == 1&&is_boundary_signal(p)==8){
             //   cout<<4;
                state[3] = 0;
                state[4] = 1;
                p++;
            }
            if(state[1] == 1 && ((is_boundary_signal(p))||*p == '\0')){
           //     back_p(p);
                state[1] = 0;
                constant[++constant_num] = strtoken;
                cout<<"constant:{"<<strtoken<<","<<constant_num<<"} "<<endl;;

                add_token(strtoken,5,constant_num);
                strtoken = "";
                 tag = 1;
                break;
            }
            if(state[1] == 1 && (is_space(p)||*p=='\0')){
             //   cout<<6666;
          //      back_p(p);
                state[1] = 0;
             //    cout<<6666;
                constant[++constant_num] = strtoken;

                cout<<"{"<<strtoken<<","<<constant_num<<"} "<<endl;;

                add_token(strtoken,5,constant_num);
                strtoken = "";
                 tag = 1;
                break;
            }
            if(state[4] == 1){
                state[4] = 0;
          //      back_p(p);
                cout << "error!,indentifiers are not valid" <<endl;
                strtoken = "";
                 tag = 1;
                 exit(0);
                break;
            }
         }
       }
     else if(is_boundary_signal(p)){

            strtoken += *p;
            p++;

       // if(strtoken.size()>=3){
      //      cout<<" error!,boundary_signals are not valid"<<endl;
     //       strtoken = "";
     //       break;
      //  }
      //  else if(strtoken.size() == 2){
            if(is_boundary_signal_double(strtoken+(*p))){
               if(is_boundary_signal_double(strtoken+(*p))==23){ strtoken = "";p++;}
               else{
                int t = is_boundary_signal_double(strtoken+(*p));
                 cout<<"boundary_signal:{"<<strtoken+(*p)<<","<<t<<"} "<<endl;;
                 add_token(strtoken+(*p),6,t);
                 strtoken = "";
                 p++;
               }
            }
            else{
                int t = is_boundary_signal_double(strtoken);
                cout<<"boundary_signal:{"<<strtoken<<","<<t<<"} "<<endl;;         //////////////////////////////
                 add_token(strtoken,6,t);
              // cout<<strtoken[0];
              //  cout<<"error!,boundary_signals are not valid"<<endl;
              strtoken = "";

            }

     }
     else if(*p == 39){

        int tag = 1;
     while(tag == 1){

        strtoken+=*p;
        p++;
        state[5] = 1;
        if(*p == 39&&state[5] == 1)
        {
            state[5] = 0;
            state[8] = 1;  //error
            p++;
        }
        else{
           strtoken+=*p;
           p++;
           state[5] = 0;
           state[6] = 1;
        }
        if(state[6] == 1 && *p == 39){
            state[7] = 1;
            state[6] = 0;
            strtoken+=*p;
            p++;
        }
        if(state[6] == 1 && *p != 39){
            state[6] = 0;
            state[8] = 1;
            p++;
        }
        if(state[7]==1){
            state[7] = 0;
            tag = 0;
            strtoken = strtoken.substr(1,1);
       //     boundary_signal[++boundary_signal_num] = "'";
             add_token("'",6,boundary_signal_num);
            Char[++Char_num] = strtoken;
            cout<<"Char:{"<<strtoken<<","<<Char_num<<"} "<<endl;;
            add_token(strtoken,4,Char_num);
         //   boundary_signal[++boundary_signal_num] = "'";
             add_token("'",6,boundary_signal_num);
            strtoken = "";                    //这里写的很差
            break;
        }
        if(state[8]==1){
            state[8] = 0;
            tag = 0;
            cout<<"error!,Chars are not valid"<<endl;
           strtoken = "";
           exit(0);
           break;
        }
      }
     }
     else if(*p == 34){
        strtoken += *p;
        p++;
        while(*p != '#'&& *p != 34){
            strtoken += *p;
            p++;
        }
        if(*p==34){
            strtoken+=*p;
            String[++String_num] = strtoken;
            cout<<"String:{"<<strtoken<<","<<String_num<<"}"<<endl;
            add_token(strtoken,3,String_num);
            strtoken = "";
            p++;
        }
        else if(*p ==  '#'){
             cout<<"error!,String are not valid"<<endl;
             exit(0);
             strtoken = "";
        }
     }
     else if(*p == '\0'){
          strtoken = "";
          break;
     }
     else{
        cout<<"error!, what are you doing!"<<endl;////////////// 这里感觉不是很合理
        exit(0);
        strtoken = "";
        break;
     }
    }
}

