

#include<iostream>
//#include<string>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<map>
#include<set>
#include<stack>
#include"LL1.h"
#include<stdlib.h>
#include<list>
#include"SYNBL.h"
using namespace std;
// 修改文法时，要修改文法的长度 以及保证开始的边远 在第0个文法,还有control函数可能也变
//char a[1000];//从文件里读出代码
extern  Token token[1000];
extern int token_num;
extern  int constant_num ;
extern  int boundary_signal_num;
extern int Key_word_num;
extern int Char_num;
extern  string Char[1000];//4
extern string boundary_signal[1000];
extern  string Key_word[330];
extern int Identifier_num;
extern string Identifier[1000];
extern  string constant[1000];//5
extern map<string,int> TYPE_LENGTH;
map<string,int> excel;
map<string,string>grammar_to_AlphaOrNumber;
map<string,int>isend_ornot;
set<string> terminal_signal;
//stack<Token> sequence;
map<string,string>boundary_w1;
map<string,string>boundary_w0;
map<string,string>boundary_w2;
stackk sequence;
set <string> unterminal_signal;
static set<string> follow_ricle;
static stack<char> now_follow_signal;
set<string> final_signal_selected[100];
string select[1000];//select set
int tag = 0;
int grammar_length = 60;//7是下标的大小
int unterminal_signal_num = 0;
stack<string>signal_type;
string signal_shuxing;
stack<string> name1;
Grammar grammar[1000];
SYNBL synbl[100];
RINFL rinfl[100];
AINFL ainfl[100];
TYPEL typel[100];
SYNBL* synblp;
RINFL* rinflp;
AINFL* ainflp;
TYPEL* typelp;
 string name,changshu,zifu;
control_about_ALLSYNBL control_about_allsynbl;
void stackk::pop(){
high--;
}
void stackk::push(Token s){
stack_name[high] = s;
high++;
}
Token stackk::top(){
return stack_name[high-1];
}
string LL1::left_grammar(string s){
    int t = s.find("->");
    return s.substr(0,t);

}
void LL1::initial_class(){
    synblp = synbl;
    rinflp = rinfl;
    ainflp = ainfl;
    typelp = typel;
}
bool LL1::isfind(string s,string str){
    if(s.find(str)!=-1){
        int t = s.find(str);
        int h = str.size();
        if(isalpha(s[t+h])){
            return false;
        }
        else return true;
    }
    return false;
}
string LL1::right_grammar(string s){
    int t = s.find("->");
    return s.substr(t+2,s.size()-2-t);
}
 void LL1::readfrom_file(string filename,char* &a){
    string infile = filename;
    ifstream fin(infile.c_str(),ios::in);
    while(fin.getline(a,sizeof(a))){
        memset(a,0,sizeof(a));
   }
}
/*
void LL1::initial_grammar(){//1 2 3 4 5 6 7 8 9 10 11 12  13  14 15 16 17
    grammar[0].grammar_all = "CX-> HS A ";grammar[1].grammar_all = "CX-> struct @ 1 BSF @ 2 { K } @ 3 CX ";
    grammar[2].grammar_all = "K-> BLSM K ";grammar[3].grammar_all = "K-> $ ";
    grammar[4].grammar_all = "A-> HS A ";grammar[5].grammar_all = "A-> $ ";
    grammar[6].grammar_all = "HS-> LX @ 5 BSF @ 15 ( ) { FHYJ } ";grammar[7].grammar_all = "FHYJ-> BLSM FHYJ ";
    grammar[8].grammar_all = "FHYJ-> FZYJ FHYJ ";grammar[9].grammar_all = "FHYJ-> if ( PDYJ ) { FHYJ } B ";
    grammar[10].grammar_all = "FHYJ-> while ( PDYJ ) { FHYJ } FHYJ ";grammar[11].grammar_all = "FHYJ-> TZYJ FHYJ B ";
    grammar[12].grammar_all = "FHYJ-> $ ";grammar[13].grammar_all = "B-> else { FHYJ } FHYJ ";
    grammar[14].grammar_all = "B-> FHYJ ";grammar[15].grammar_all = "BLSM-> LX @ 5 BSFB  ";
    grammar[16].grammar_all = "FZYJ-> BSF @ 7  @ 11 @ 5 STR G ";grammar[17].grammar_all = "G-> = J ";
    grammar[18].grammar_all = "G-> [ CS ] = J ";grammar[19].grammar_all = "J-> SSBDS ; ";
    grammar[20].grammar_all = "J-> ' ZF ' @ 10 ; ";grammar[21].grammar_all = "BSFB->  BSF @ 6 H  ";
    grammar[22].grammar_all = "H-> C ";grammar[23].grammar_all = "H-> [ CS ] ; ";
    grammar[24].grammar_all = "H-> = I  JXSM ";grammar[25].grammar_all = "I-> ' ZF ' @ 10   ";
    grammar[26].grammar_all = "I-> CS @ 9    ";grammar[27].grammar_all = "C-> , BSFB ";
    grammar[28].grammar_all = "C-> ; ";grammar[29].grammar_all = "PDYJ-> SSBDS D ";
    grammar[30].grammar_all = "D-> w2 SSBDS ";grammar[31].grammar_all = "D-> $ ";
    grammar[32].grammar_all = "TZYJ-> continue ; ";grammar[33].grammar_all = "TZYJ-> break ; ";
    grammar[34].grammar_all = "SSBDS-> XX E ";grammar[35].grammar_all = "E-> w0 XX E ";
    grammar[36].grammar_all = "E-> $ ";grammar[37].grammar_all = "XX-> YZ F ";grammar[38].grammar_all = "F-> w1 YZ F ";
    grammar[39].grammar_all = "F-> $ ";grammar[40].grammar_all = "YZ-> SSL ";grammar[41].grammar_all = "YZ-> ( SSBDS ) ";
    grammar[42].grammar_all = "SSL-> BSF  @ 7 @ 8 ";grammar[43].grammar_all = "SSL-> CS @ 9 ";
    grammar[44].grammar_all = "I-> false @ 12   ";grammar[45].grammar_all = "I-> true @ 12    "; grammar[46].grammar_all = "I-> BSF @ 7 @ 8   ";
    grammar[47].grammar_all = "J-> false @ 12 ; ";grammar[48].grammar_all = "J-> true @ 12 ; ";
    grammar[49].grammar_all = "JXSM-> ; ";grammar[50].grammar_all = "JXSM-> , BSFB   ";
    grammar[51].grammar_all = "STR->  $ ";grammar[52].grammar_all = "STR->  . BSF @ 13 @ 14 @ 5 ";
    grammar[53].grammar_all = "CX-> "
    boundary_w0["+"] = "w0";boundary_w0["-"] = "w0";boundary_w1["*"] = "w1";boundary_w1["/"] = "w1";
    boundary_w2[">"] = "w2";boundary_w2["<"] = "w2";boundary_w2[">="] = "w2";boundary_w2["<="] = "w2";boundary_w2["=="] = "w2";
    boundary_w2["&&"] = "w2";boundary_w2["||"] = "w2";

}*/
void LL1::initial_grammar(){//1 2 3 4 5 6 7 8 9 10 11 12  13  14 15 16 17 18
    grammar[0].grammar_all = "CX-> A ";grammar[1].grammar_all = "CX-> struct @ 1 BSF @ 2 { K } @ 3 CX ";
    grammar[2].grammar_all = "K-> BLSM K ";grammar[3].grammar_all = "K-> $ ";
    grammar[4].grammar_all = "A-> HS CX ";grammar[5].grammar_all = "A-> $ ";
    grammar[6].grammar_all = "HS-> LX @ 5 BSF @ 6 H  " /*( @ 15 ) { FHYJ }*/ ;grammar[7].grammar_all = "FHYJ-> BLSM FHYJ ";
    grammar[8].grammar_all = "FHYJ-> FZYJ FHYJ ";grammar[9].grammar_all = "FHYJ-> if ( PDYJ ) { FHYJ } B ";
    grammar[10].grammar_all = "FHYJ-> while @ 16 ( PDYJ ) { FHYJ } @ 17 FHYJ ";grammar[11].grammar_all = "FHYJ-> TZYJ FHYJ B ";
    grammar[12].grammar_all = "FHYJ-> $ ";grammar[13].grammar_all = "B-> else { FHYJ } FHYJ ";
    grammar[14].grammar_all = "B-> FHYJ ";grammar[15].grammar_all = "BLSM-> LX @ 5 BSFB  ";
    grammar[16].grammar_all = "FZYJ-> BSF @ 7  @ 11 @ 5 STR @ 18 G ";grammar[17].grammar_all = "G-> = J ";
    grammar[18].grammar_all = "G-> [ CS ] = J ";grammar[19].grammar_all = "J-> SSBDS DEVIDE ";
    grammar[20].grammar_all = "J-> ' ZF ' @ 10 DEVIDE ";grammar[21].grammar_all = "BSFB->  BSF @ 6 H  ";
    grammar[22].grammar_all = "H-> C ";grammar[23].grammar_all = "H-> [ CS ] ; ";
    grammar[24].grammar_all = "H-> = I  JXSM ";grammar[25].grammar_all = "I-> ' ZF ' @ 10   ";
    grammar[26].grammar_all = "I-> CS @ 9    ";grammar[27].grammar_all = "C-> , BSFB ";
    grammar[28].grammar_all = "C-> ; ";grammar[29].grammar_all = "PDYJ-> SSBDS D ";
    grammar[30].grammar_all = "D-> w2 SSBDS ";grammar[31].grammar_all = "D-> $ ";
    grammar[32].grammar_all = "TZYJ-> continue ; ";grammar[33].grammar_all = "TZYJ-> break ; ";
    grammar[34].grammar_all = "SSBDS-> XX E ";grammar[35].grammar_all = "E-> w0 XX E ";
    grammar[36].grammar_all = "E-> $ ";grammar[37].grammar_all = "XX-> YZ F ";grammar[38].grammar_all = "F-> w1 YZ F ";
    grammar[39].grammar_all = "F-> $ ";grammar[40].grammar_all = "YZ-> SSL ";grammar[41].grammar_all = "YZ-> ( SSBDS ) ";
    grammar[42].grammar_all = "SSL-> BSF  @ 7 @ 8 ";grammar[43].grammar_all = "SSL-> CS @ 9 ";
    grammar[44].grammar_all = "I-> false @ 12   ";grammar[45].grammar_all = "I-> true @ 12    "; grammar[46].grammar_all = "I-> BSF @ 7 @ 8   ";
    grammar[47].grammar_all = "J-> false @ 12 ; ";grammar[48].grammar_all = "J-> true @ 12 ; ";
    grammar[49].grammar_all = "JXSM-> ; ";grammar[50].grammar_all = "JXSM-> , BSFB   ";
    grammar[51].grammar_all = "STR->  $ ";grammar[52].grammar_all = "STR-> . BSF @ 13 @ 14 @ 5 STR ";
    grammar[53].grammar_all = "H-> ( @ 15 @ 16 ) { FHYJ } ";grammar[54].grammar_all="FHYJ-> for @ 16 ( FORNEXT  ";
    grammar[55].grammar_all = "FORNEXT-> FZYJ PDYJ ; FZYJFOR ) { FHYJ } @ 17 FHYJ ";
    grammar[56].grammar_all = "FORNEXT-> BLSM PDYJ ; FZYJFOR ) { FHYJ } @ 17 FHYJ ";grammar[57].grammar_all="FZYJFOR-> BSF STR G ";
    grammar[58].grammar_all = "DEVIDE-> ; ";grammar[59].grammar_all = "DEVIDE-> $ ";
    boundary_w0["+"] = "w0";boundary_w0["-"] = "w0";boundary_w1["*"] = "w1";boundary_w1["/"] = "w1";
    boundary_w2[">"] = "w2";boundary_w2["<"] = "w2";boundary_w2[">="] = "w2";boundary_w2["<="] = "w2";boundary_w2["=="] = "w2";
    boundary_w2["&&"] = "w2";boundary_w2["||"] = "w2";

}
void LL1::initial_grammar_isend(){   //
    isend_ornot["CX"] = 0;isend_ornot["HS"] = 0;isend_ornot["A"] = 0;
    isend_ornot["BSF"] = 1;isend_ornot["K"] = 0;isend_ornot["BLSM"] = 0;isend_ornot["$"] = 1;
    isend_ornot["LX"] = 0;isend_ornot["FHYJ"] = 0;isend_ornot["FZYJ"] = 0;isend_ornot["PDYJ"] = 0;
    isend_ornot["TZYJ"] = 0;isend_ornot["B"] = 0;isend_ornot["BSFB"] = 0;isend_ornot["G"] = 0;isend_ornot["J"] = 0;
    isend_ornot["CS"] = 1;isend_ornot["SSBDS"] = 0; isend_ornot["ZF"] = 1;isend_ornot["H"] = 0;isend_ornot["C"] = 0;
    isend_ornot["I"] = 0;isend_ornot["D"] = 0;isend_ornot["XX"] = 0;isend_ornot["E"] = 0;isend_ornot["w0"] = 1;
    isend_ornot["YZ"] =0;isend_ornot["F"] =0;isend_ornot["w1"] = 1;isend_ornot["SSL"] =0;isend_ornot["w2"] = 1;
    for(int i = 1 ; i <= boundary_signal_num ;i++){
        string temp = boundary_signal[i];
        isend_ornot[temp] = 1;
    }
    for(int i = 1 ; i <= Key_word_num ; i++)
    {
        string temp = Key_word[i];
        isend_ornot[temp] = 1;
    }

}
string LL1::isBegin(){
    return "CX";
}
int LL1::is_exit(int t,string w){
    int h = grammar[t].num;
    int tag = 0;
    for(int i = 0 ; i <h ; i++){
        if(grammar[t].selected[i]==w){tag = 1;cout<<"ok";return 1;}
 }
    if(tag == 0)
    return 0;
}
int LL1::isnot_end(string z){
    if(isend_ornot[z]==0)return 1;
    else return 0;
}
int LL1::is_end(char z){
    if(((z <= 'z' && z >= 'a') || z=='(' || z==')'|| z== 'x'|| z== 'w')&&z!='e'){
  //  terminal_signal.insert(z);
    return 1;
}
else return 0;
}

void LL1::initial_signal(){
    unterminal_signal.insert("CX");unterminal_signal.insert("HS");unterminal_signal.insert("A");
    terminal_signal.insert("BSF");unterminal_signal.insert("K");unterminal_signal.insert("BLSM");terminal_signal.insert("$");
    terminal_signal.insert("LX");unterminal_signal.insert("FHYJ");unterminal_signal.insert("FZYJ");unterminal_signal.insert("PDYJ");
    unterminal_signal.insert("TZYJ");unterminal_signal.insert("B");unterminal_signal.insert("BSFB");unterminal_signal.insert("G");
    unterminal_signal.insert("J");
    terminal_signal.insert("CS");unterminal_signal.insert("SSBDS"); terminal_signal.insert("ZF");unterminal_signal.insert("H");
    unterminal_signal.insert("C");unterminal_signal.insert("I");unterminal_signal.insert("D");unterminal_signal.insert("XX");
    unterminal_signal.insert("E");terminal_signal.insert("w0");
    unterminal_signal.insert("YZ");unterminal_signal.insert("F");terminal_signal.insert("w1");unterminal_signal.insert("SSL");
    terminal_signal.insert("w2");terminal_signal.insert("true");terminal_signal.insert("false");unterminal_signal.insert("JXSM");
    unterminal_signal.insert("STR");terminal_signal.insert("for");unterminal_signal.insert("FORNEXT");unterminal_signal.insert("DEVIDE");
    unterminal_signal.insert("FZYJFOR");
    for(int i = 1 ; i <= boundary_signal_num ;i++){
        string temp = boundary_signal[i];
        terminal_signal.insert(temp);
    }
    for(int i = 1 ; i <= Key_word_num ; i++)
    {
        string temp = Key_word[i];
       terminal_signal.insert(temp);
    }
    for(int i = 1 ; i <= Identifier_num; i++)
    {
        string temp = Identifier[i];
       terminal_signal.insert(temp);
    }
    for(int i= 1 ; i <= constant_num; i++){
        string temp = constant[i];
       terminal_signal.insert(temp);
    }

}
void LL1::first(string s,int p){
    if(s.size()>0){
        s= readspace(s);
       // cout<<"after space"<<s<<endl;
      //  cout<<isend_ornot["int"]<<endl;
        //getchar();
        string first_str = single_between_space(s);
      //  cout<<"first_str "<<first_str<<endl;
        if(isnot_end(first_str) == 0 &&first_str != "$"){
          //  cout<<first_str<<" is end"<<endl;
            string temp = single_between_space(s);
            int t = grammar[p].num;
            grammar[p].selected[t] = temp;
        //    cout<<left_grammar(grammar[p].grammar_all)<<" selected"<<t<<" "<<temp<<endl;
            grammar[p].num++;
            return ;
    }
    else if(s[0] == '$'){
        if(s.size()==1){ return;}
        s = s.substr(1,s.size()-1);
        first(s,p);
    }
   /* else{
        for(int j = 0 ; j <= grammar_length ; j++){

            if(grammar[j].grammar_left == s[0]){

            first(grammar[j].grammar_all.substr(3,grammar[j].grammar_all.size()-3)+s.substr(1,s.size()-1),p);
             // cout<<grammar[j].grammar_all.substr(3,grammar[j].grammar_all.size()-3)<<" tag "<<s.substr(1,s.size()-1)<<tag<<endl;
                }
            }


        }*/
    else{
         for(int j = 0 ; j <= grammar_length ; j++){

            string temp_left = left_grammar(grammar[j].grammar_all);
            string temp_now = single_between_space(s);
         //   cout<<"temp_now "<<temp_now.size()<<endl;
            if(temp_left == temp_now){
                int tp = temp_now.size();
                string next = s.substr(tp,s.size()-tp);
                string temp_right = right_grammar(grammar[j].grammar_all);
                first(temp_right+next,p);
              //cout<<grammar[j].grammar_all.substr(3,grammar[j].grammar_all.size()-3)<<" tag "<<s.substr(1,s.size()-1)<<tag<<endl;
        }
     }

   }
 }
}
string LL1::single_between_space(string s){
    string temp = readspace(s);
    int k = 0 ;
    while(1){
        if(temp[k]==' '||temp[k]=='\t')break;
        else k++;
    }
    return temp.substr(0,k);
}
string LL1::readspace(string s){ //返回读完空格之后的字符串
    int k = 0;
    //string temp;
    while(1){
        if(s[k]==' '||s[k]=='\t')k++;
        else break;
    }
    return s.substr(k,s.size()-k);
}
void LL1::is_change_empty(string s,int p){
    cout<<"检测"<<s<<"是否可能变为空"<<endl;
 if(s.size()>0){
    s = readspace(s);
    if(isnot_end(s) == 0 &&s!="$"){  //是终结符
        cout<<s<<"不为空，是终结符"<<endl;
        return ;
    }
    else if( s[0] == '$'){
        cout<<s<<"可能为为空"<<endl;
        cout<<"0000"<<p<<endl;
        if(s.size()==1){cout<<s<<"为空"<<endl;tag = 1; return;}
        s = s.substr(1,s.size()-1);
        cout<<"继续检测剩下的后半段"<<s<<endl;
        is_change_empty(s,p);
    }
    else{
         for(int j = 0 ; j <= grammar_length ; j++){
         string temp_left = left_grammar(grammar[j].grammar_all);
         string temp_now = single_between_space(s);
        if(temp_left == temp_now){
              int tp = temp_now.size();
              if(s.size()>tp){
              string next = s.substr(tp,s.size()-tp);
              string temp_right = right_grammar(grammar[j].grammar_all);
              is_change_empty(temp_right+next,p);
              }
              else{
                 string temp_right = right_grammar(grammar[j].grammar_all);
                 is_change_empty(temp_right,p);
              }
              //cout<<grammar[j].grammar_all.substr(3,grammar[j].grammar_all.size()-3)<<" tag "<<s.substr(1,s.size()-1)<<tag<<endl;
        }
     }


  }
 }
}
void LL1::follow(string grammar_left,int p){
    for(int j = 0 ; j <= grammar_length ; j++){
     //  if(p==5){cout<<j<<grammar_left<<endl;getchar();}
        string str = grammar_left ;   //str 是固定的，传进来的//寻找为空的产生式左部在每个式子中的位置
        cout<<"要求左部为"<<str<<"的follow"<<endl;
        string temp = "";
        temp = right_grammar(grammar[j].grammar_all);
        str+=" ";
        while(temp.find(str)!=-1){  //////////
        int t2 = temp.find(str);
        if(t2 + str.size()!=temp.size()){  //如果找到的不在结尾
            cout<<"不在哦i结尾"<<endl;
            t2 = t2+str.size();
           string follow_string = temp.substr(t2,temp.size()-t2);
           //follow_string += temp.substr(t2,temp.size()-t2);
         //  if(p==2){cout<<follow_string;getchar();}
            first(follow_string,p);
           cout<<j<<endl;

           is_change_empty(follow_string,p);
           if(tag == 1){  //weikong
              if(j==0){
                string str = ""+'#';
                 int num1 = grammar[p].num;
                grammar[p].selected[num1] = '#';
              //  if(p == 2) grammar[p].selected[num1] = 'Q';
                grammar[p].num++;
              }
              tag = 0;
              string temp_left = left_grammar(grammar[j].grammar_all);
              follow(temp_left,p);
           }
       /*    if(j==grammar_length){
          char h = now_follow_signal.top();
           now_follow_signal.pop();
           follow_ricle.erase(h);
           cout<<"shan chu "<<h<<endl;
           cout<<"xian zai set"<<follow_ricle.size()<<endl;
          }*/
            //temp = temp.substr(t2+1,temp.size()-t2-1);
            temp = follow_string;
        }
        else{
            string str1 = "";
            str1 +=  left_grammar(grammar[j].grammar_all);  //你想要一开始查找的左部
            if(follow_ricle.find(str1)!=follow_ricle.end()){  //说明出现间接递归
               //  cout<<2<<endl;;
                if(j==0){
                  int num = grammar[p].num;
                  grammar[p].selected[num] = '#';
                  grammar[p].num++;
                }
             break;
            }
            else {
                  string str1 =  left_grammar(grammar[j].grammar_all);
                follow_ricle.insert(str1);
               // cout<<"insert"<<grammar[j].grammar_left<<follow_ricle.size()<<endl;
              //  getchar();
              // cout<<grammar[j].grammar_left<<follow_ricle.size()<<j<<p<<grammar_left<<endl;
               //getchar();
             if(j==0){
                 int num = grammar[p].num;
                 grammar[p].selected[num] = '#';
                // terminal_signal.insert('#');
                 grammar[p].num++;
             }
                 follow(str1,p);
                 break;
            }
          }
        }
     }
}

void LL1::selected(){
  //cout<<"$"<<isend_ornot["$"]<<endl;
   for(int i = 0 ; i <= grammar_length; i++){
       // cout<<1;
       // string s = "->";
        string s1 = grammar[i].grammar_all;
        //int t1 = 3;  //右部开始的位置
        cout<<i<< right_grammar(s1)<<endl;
        string temp = right_grammar(s1);
        is_change_empty(temp,i);
        if(tag == 1)// 产生式为空
        {
            cout<<"temp"<<endl;
            getchar();
           // if(i==2){cout<<"sss "<<s1.substr(3,s1.size()-3)<<endl;getchar();}
            tag = 0;

            first(temp,i);

            //now_follow_signal.push(grammar[i].grammar_left);
            string temp_left = left_grammar(s1);
            follow_ricle.insert(temp_left);
         //   cout<<*follow_ricle.begin()<<" niu bi"<<" "<<s1<<endl;
            follow(temp_left,i);
            cout<<temp_left<<" de select"<<endl;
            for(int j = 0 ;j < grammar[i].num;j++)
                cout<<grammar[i].selected[j]<<endl;
              cout<<"show end"<<endl;
            }

        else{

            string temp_right = right_grammar(grammar[i].grammar_all);
        //  cout<<"first "<<temp_right<<endl;
            first(temp_right,i);
           // cout<<"grammar num"<<grammar[i].num<<endl;
          //  for(int j= 0 ; j <grammar[i].num;j++)
         //   cout<<i<<"de select "<<grammar[i].selected[j]<<endl;
        }
     }
}

/*void LL1::make_excel(){
    excel["CX_int"] = 0;excel["CX_float"] = 0;excel["CX_char"] = 0;excel["CX_void"] = 0;
    excel["CX_while"] = 40;excel["A_int"] = 4;excel["A_float"] = 4;excel["A_char"] = 4;
    excel["A_void"] = 4;excel["HS_int"] = 6;excel["HS_float"] = 6;excel["HS_char"] = 6;
     excel["HS_void"] = 6;excel["FHYJ_int"] = 7;excel["FHYJ_float"] = 7;excel["FHYJ_char"] = 7;
     excel["FHYJ_void"] = 7;excel["FHYJ_while"] = 10;excel["B_int"] = 14;
    excel["B_float"] = 14;excel["B_char"] = 14;excel["B_void"] = 14;
    excel["BLSM_int"] = 15;;excel["BLSM_float"] = 15;excel["BLSM_char"] = 15;excel["FHYJ_void"] = 15;
    excel["PDYJ_CS"] = 29;
    excel["SSBDS_CS"] = 34;excel["XX_CS"] = 37;excel["F_||"] = 39;excel["F_&&"] = 39;
    excel["YZ_CS"] = 40;excel["SSL_CS"] = 43; excel["LX_int"] = 44;excel["LX_float"] =45;
    excel["LX_char"] = 46;excel["LX_void"] = 47;
    excel["I_CS"] = 26;excel["J_CS"] = 19;excel["K_int"] = 2;excel["K_float"] =2;
    excel["K_char"] = 2;excel["K_void"] = 2;excel["CX_continue"] = 37;excel["CX_break"] =38 ;
    excel["A_#"] = 5;excel["FHYJ_continue"] = 11;excel["FHYJ_break"] = 11;excel["TZYJ_continue"] = 32;
    excel["TZYJ_break"] = 33;excel["G_["]= 18;excel["I_'"]= 25;excel["J_'"] = 20;
    excel["H_["]  = 23;
    excel["FHYJ_}"] = 12; excel["FHYJ_BSF"] = 8; excel["FHYJ_if"] = 9;excel["B_else"] = 13;excel["FZYJ_BSF"] = 16;
    excel["BSFB_BSF"] =21; excel["C_,"] = 27;excel["PDYJ_("] = 29;excel["PDYJ_BSF"] = 29;excel["D_)"] = 31;
    excel["SSBDS_("] = 34;excel["SSBDS_BSF"] = 34;excel["E_)"] = 36;excel["XX_("] =37;excel["XX_BSF"] = 37;
    excel["F_)"] = 39;excel["YZ_("] = 41;excel["YZ_BSF"] = 40;excel["SSL_BSF"] = 42;excel["G_="] = 17;
    excel["H_="] = 24;excel["H_,"] = 22;excel["J_("] = 19;excel["J_BSF"] = 19;excel["K_}"] = 3;
    excel["C_;"] = 28;
    excel["D_w2"] = 30;
    excel["E_;"] = 36;
    excel["E_w2"] = 36;
    excel["E_w0"] = 35;
    excel["F_;"] = 39;
    excel["F_w0"] = 39;
    excel["H_;"] = 22;
    excel["F_w1"] = 38;
    excel["F_w2"] = 39;
    excel["CX_struct"] = 1;
}*/
void LL1::make_excel(){
    excel["CX_LX"] = 0;//excel["CX_float"] = 0;excel["CX_char"] = 0;excel["CX_void"] = 0;
    excel["CX_while"] = 40;//excel["A_LX"] = 4;excel["A_float"] = 4;excel["A_char"] = 4;
    excel["A_LX"] = 4;excel["HS_LX"] = 6;//excel["HS_float"] = 6;excel["HS_LX"] = 6;
    // excel["HS_void"] = 6;
     excel["FHYJ_LX"] = 7;//excel["FHYJ_float"] = 7;excel["FHYJ_char"] = 7;
    // excel["FHYJ_void"] = 7;
     excel["FHYJ_while"] = 10;
     excel["B_LX"] = 14;
   // excel["B_float"] = 14;excel["B_char"] = 14;excel["B_void"] = 14;
    excel["BLSM_LX"] = 15;;//excel["BLSM_float"] = 15;excel["BLSM_char"] = 15;excel["FHYJ_void"] = 15;
    excel["PDYJ_CS"] = 29;
    excel["SSBDS_CS"] = 34;excel["XX_CS"] = 37;excel["F_||"] = 39;excel["F_&&"] = 39;
    excel["YZ_CS"] = 40;excel["SSL_CS"] = 43;// excel["LX_int"] = 44;excel["LX_float"] =45;
    //excel["LX_char"] = 46;excel["LX_void"] = 47;

    excel["I_CS"] = 26;excel["J_CS"] = 19;//excel["K_int"] = 2;excel["K_float"] =2;
    excel["K_LX"] = 2;//excel["K_void"] = 2;
    excel["CX_continue"] = 37;excel["CX_break"] =38 ;
    excel["A_#"] = 5;excel["FHYJ_continue"] = 11;excel["FHYJ_break"] = 11;excel["TZYJ_continue"] = 32;
    excel["TZYJ_break"] = 33;excel["G_["]= 18;excel["I_'"]= 25;excel["J_'"] = 20;
    excel["H_["]  = 23;
    excel["FHYJ_}"] = 12; excel["FHYJ_BSF"] = 8; excel["FHYJ_if"] = 9;excel["B_else"] = 13;excel["FZYJ_BSF"] = 16;
    excel["BSFB_BSF"] =21; excel["C_,"] = 27;excel["PDYJ_("] = 29;excel["PDYJ_BSF"] = 29;excel["D_)"] = 31;
    excel["SSBDS_("] = 34;excel["SSBDS_BSF"] = 34;excel["E_)"] = 36;excel["XX_("] =37;excel["XX_BSF"] = 37;
    excel["F_)"] = 39;excel["YZ_("] = 41;excel["YZ_BSF"] = 40;excel["SSL_BSF"] = 42;excel["G_="] = 17;
    excel["H_="] = 24;excel["H_,"] = 22;excel["J_("] = 19;excel["J_BSF"] = 19;excel["K_}"] = 3;
    excel["C_;"] = 28;
    excel["D_w2"] = 30;
    excel["E_;"] = 36;
    excel["E_w2"] = 36;
    excel["E_w0"] = 35;
    excel["F_;"] = 39;
    excel["F_w0"] = 39;
    excel["H_;"] = 22;
    excel["F_w1"] = 38;
    excel["F_w2"] = 39;
    excel["CX_struct"] = 1;
    excel["I_false"] = 44;
    excel["I_true"] = 45;excel["I_BSF"] = 46;excel["J_true"] = 48;excel["J_false"] = 47;excel["JXSM_;"] = 49;excel["JXSM_,"] = 50;
    excel["STR_="] = 51;excel["STR_["] = 51;excel["STR_."] = 52;excel["H_("] = 53;excel["FHYJ_for"] = 54;excel["FORNEXT_BSF"] = 55;
    excel["FORNEXT_LX"] = 56;excel["DEVIDE_;"] = 58;excel["DEVIDE_BSF"] = 59;excel["DEVIDE_CS"] = 59;excel["DEVIDE_)"] = 59;
    excel["DEVIDE_("] = 59;excel["FZYJFOR_BSF"] = 57;
}
void LL1::pop(Token &x){
  x = sequence.top();
  sequence.pop();
}
void LL1::next(Token *a,Token &w,int &i){
 w = a[i++];
}
bool LL1::isIdentifier(string s){

    int tag = 0;
    for(int i = 1 ; i <= Identifier_num; i++){
       // cout<<s<<" "<<s.size()<<Identifier[i]<< " "<<Identifier[i].size()<<endl;
        if(s==Identifier[i]){tag =  1;return true;}

    }
     if(tag == 0) return false;
}
bool LL1::isConstant(string s){

    for(int i = 1 ; i <= constant_num; i++){
        if(s==constant[i])return true;


    }
     return false;
}
bool LL1::isChar(string s){
    for(int i =1 ; i <= Char_num;i++){
        if(s==Char[i])return true;
    }
    return false;

}
void LL1::control(Token* token_now,string begin_signal){
    Token jing;
    jing.token_num1 = "#";
    sequence.push(jing);
    Token begin1;
    begin1.token_num1 = isBegin();
    sequence.push(begin1);
    int i = 1 ;//读 token串的指针
    Token w,x;
    next(token_now,w,i);
     Token x1,w1;
        x1 = x; w1 = w;
    while(1){
        pop(x);
        Token x1,w1;
        x1 = x; w1 = w;
        //下面写的很差if语句

        if(w.kind == 2&&(TYPE_LENGTH.find(w1.token_num1)==TYPE_LENGTH.end()&&w.token_num1!="LX") ){if(w.token_num1!="BSF"){name = w.token_num1;name1.push(name);cout<<"now_now "<<name<<endl;}w.token_num1 = "BSF";}
        if(w.kind == 5) {if(w.token_num1!="CS"){changshu = w.token_num1;cout<<"now_now "<<changshu<<endl;}w.token_num1="CS";}
        if(w.kind==4) {if(w.token_num1!="ZF"){zifu = w.token_num1;cout<<"now_now "<<zifu<<endl;}w.token_num1 = "ZF";}
        if(TYPE_LENGTH.find(w1.token_num1)!=TYPE_LENGTH.end()||w.token_num1=="LX"){
            if(w.token_num1!="LX"){signal_shuxing = w.token_num1;
            if(signal_shuxing==""||signal_shuxing==" "){cout<<22222222222222222222222222222<<endl;getchar();}
            cout<<"now_now "<<signal_shuxing<<endl;getchar();}w.token_num1 = "LX";
        }
        if(1){
            if(w.token_num1=="+"||w.token_num1=="-")w.token_num1 = "w0";
            else if(w.token_num1=="*"||w.token_num1=="/")w.token_num1 = "w1";
            else if(w.token_num1==">"||w.token_num1=="<"||w.token_num1==">="||w.token_num1=="<="||w.token_num1=="=="||w.token_num1=="&&"||w.token_num1=="||")
               w.token_num1 = "w2";
       }
        cout<<x1.token_num1<<" "<<w1.token_num1<<endl;
        if(terminal_signal.find(x.token_num1)!=terminal_signal.end())//shi zhong jie fu
        {
            cout<<"是 终结符"<<endl;

            if(x.token_num1==w.token_num1)
            {
                cout<<"x "<<x.token_num1<<"  w  "<<w.token_num1<<endl;

               // getchar();
                next(token_now,w,i);
            }
           else{
            cout<<"x "<<x.token_num1<<"  w  "<<w.token_num1<<endl;
            cout<<"err! x!=w"<<endl;
         //   getchar();
            exit(-1);
           }
        }
        else if(unterminal_signal.find(x.token_num1)!=unterminal_signal.end()){
            cout<<"is not end signal "<<x.token_num1<<endl;

           // signal_shuxing = w.token_num1;
             string temp = x.token_num1+"_"+w.token_num1;
              if(excel.find(temp)!=excel.end()){
                cout<<"查表查到了"<<temp<<excel[temp]<<endl;
               //getchar();
                int num = excel[temp];
                string str = grammar[num].grammar_all;
                str = right_grammar(str);
                stack<Token> temp_stack;
                while(str!=""){
                    string temp_single = single_between_space(str);
                    if(temp_single!="$"){
                        Token t;
                        t.token_num1 = temp_single;
                        temp_stack.push(t);
                    }
                    int tt = str.find(temp_single);
                    tt+=temp_single.size();
                    str = str.substr(tt,str.size()-tt);
                    str = readspace(str);
                }
                while(! temp_stack.empty()){
                    Token s = temp_stack.top();

                  //  if(s.token)
                    sequence.push(s);
                    temp_stack.pop();
                }

              }
             else if(temp=="A_"||temp=="CX_"){

             }

              else{
                cout<<temp<<endl;
                cout<<"err!表格里查不到!"<<endl;
                exit(-1);
              }

        }
        else if(x.token_num1=="#"){
            cout<<"ok!"<<endl;
            break;
        }
        else if(x.token_num1 == "@"){  //表明后面是动作
            cout<<"@@@@@@@@@@@@@@@@@@@@"<<endl;
            pop(x);
            int temp = atoi(x.token_num1.c_str());
            switch(temp){
            case 1:
                    control_about_allsynbl.INITIAL_RINFL_BEGIN(rinflp,synblp);
                    break;
            case 2:
                   control_about_allsynbl.WRITE_TYPEL(typelp,rinflp,ainflp,name1.top());
                  //  control_about_allsynbl.WRITE_SYNBL_ABOUT_RINFL_NAME(synblp,typelp,rinflp,ainflp,name);
                    cout<<"展示总符号表"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    control_about_allsynbl.show_synbl(synblp);
                    cout<<"----------------------------------------"<<endl;
                    cout<<"展示typel表"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    control_about_allsynbl.show_typel(typelp);
                     cout<<"展示rinfl表"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    control_about_allsynbl.show_rinfl(rinflp);
                     getchar();
                    break;
            case 3:
                    control_about_allsynbl.INITIAL_RINFL_END(rinflp,typelp);
                    break;
            case 4:
                   break;

            case 5:
                    if(signal_shuxing==" "||signal_shuxing=="")cout<<"111111111111111111111111111111111111111111111"<<endl;
                    signal_type.push(signal_shuxing);
                    cout<<"signal_shuxing"<<" 是"<<signal_shuxing<<endl;
                    getchar();

                    break;
            case 6:
                    control_about_allsynbl.WRITE_SYNBL_OR_RINFL(synblp,rinflp,typelp,ainflp,signal_type.top(),name1.top());
                    cout<<"展示总符号表"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    control_about_allsynbl.show_synbl(synblp);
                    cout<<"----------------------------------------"<<endl;
                    cout<<"展示typel表"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    control_about_allsynbl.show_typel(typelp);
                    cout<<"展示rinfl表"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    control_about_allsynbl.show_rinfl(rinflp);
                     getchar();
                    break;
            case 7:
                    control_about_allsynbl.find_IsBeDefined(synblp,name1.top());
                    cout<<"找 到了 "<<endl;
                    break;
            case 8:
                    control_about_allsynbl.is_same_BSF_kind(synblp,typelp,name1.top(),signal_type.top());
                    break;
            case 9:
                    cout<<"niubi0000000000000000000000000000000000000000000000000000000000"<<endl;
                   // signal_type.pop();
                    cout<<signal_type.top()<<endl;
                    control_about_allsynbl.is_same_CS_kind(typelp,signal_type.top());
                    break;
            case 10:
                    control_about_allsynbl.is_same_ZF_kind(typelp,signal_type.top());
                    break;
            case 11:
                  //  control_about_allsynbl.last_A = control_about_allsynbl.synbl_num;
                    control_about_allsynbl.find_excel_BSF(synblp,typelp,name1.top(),signal_shuxing);//zhege youcuo wu
                    break;
            case 12:
                    control_about_allsynbl.is_same_bool_kind(typelp,signal_type.top());
                    break;
            case 13:
                    control_about_allsynbl.find_IsBeDefined(rinflp,typelp,name1.top());
                    cout<<"nuuuuuuuuuuuu"<<endl;
                    break;
            case 14:
                    control_about_allsynbl.find_excel_BSF(rinflp,typelp,name1.top(),signal_shuxing);
                    cout<<"unnnnnnnnnnnnnnnnnn"<<endl;
                    break;
            case 15:
                    control_about_allsynbl.is_main(name1.top(),synblp,signal_type.top());
                    break;
            case 16:
                    control_about_allsynbl.new_synbl(synblp);
                    break;
            case 17:
                    control_about_allsynbl.back_to_last_synbl(synblp);
                    break;
            case 18:
                    control_about_allsynbl.change_tagg_zero();
            default:break;
            }

        }
        else{
            cout<<"err!不能结束 qi dai #"<<endl;
            exit(-2);
        }
    }

}

void LL1::chachong(){
   //cout<<"unterminal_signal_num"<<unterminal_signal_num<<endl;
 for(int i = 0 ; i <= grammar_length; i++)
  {
  //    cout<<"grammar[i].num "<<grammar[i].num <<endl;
    for(int j = 0 ; j < grammar[i].num ; j++)
     final_signal_selected[i].insert(grammar[i].selected[j]);
  //  memset(grammar[i].selected,0,sizeof(string)*grammar[i].num);
     set<string>::iterator it;
     int k = 0 ;

     for(it = final_signal_selected[i].begin(); it!=final_signal_selected[i].end() ; it++)
        grammar[i].selected[k++] = *it;
         grammar[i].num = k;
    //    if(i == 5) {cout<<k<<endl;getchar();}
     // grammar[i].num = final_signal[i].size();
      //cout<<final_signal[i].size();

  }
  // cout<<final_signal[5].size()<<endl;

}
