
#include<iostream>
#include<string>
using namespace std;

typedef   struct Token_sum{
  string token_num1;
  int kind = -1;
  int position;   //在相应的分组里的位置
  int num;//在整个token串里的位置
} Token;
class token_class{
public:

 void add_token(string token1,int kind1,int position1);
 void initial_Key_word();
 void intitial_boundary_signal();
 void clear_state();
 bool is_space(char *p);
 void read_space(char* &p);
 bool is_bc( char *p);
 bool is_letter(char *p);
 void back_p(char *&p);
 int is_Key_word(string token);
 int is_boundary_signal(char* p);
 int is_boundary_signal_double(string str);
 void Begin(char *p);
};


