#include<iostream>
#include"SYNBL.h"
#include<stdio.h>
#include"LL1.h"
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;
/*extern string Key_word[330];  //1

extern string String[1000];//3
extern string Char[1000];//4
extern string constant[1000];//5
extern string boundary_signal[1000];//6*/
map<string,int> TYPE_LENGTH;
map<string,int> TYPE_POS_IN_TYPEL;
extern stackk sequence;
stack<int>address;//������ĵ�ַ��ջ
extern SYNBL synbl[100];
extern RINFL rinfl[100];
extern AINFL ainfl[100];
extern TYPEL typel[100];
int taggg = 0;
extern  string Identifier[1000];//2
vector<class VAR_DEFINE> STRUCT;
stack<SYNBL*>stack_synbl;
int addr[100] = {20};

int change_space = 20;//���ڻ��¼������
TYPEL::TYPEL(){
        TYPE_TYPEL[0] = "int";TYPE_TYPEL[1] = "char";TYPE_TYPEL[2] = "double";TYPE_TYPEL[3] = "float";TYPE_TYPEL[4] = "void";
        TYPE_TYPEL[5] = "bool";
        ADDR_TYPEL[0] = {-1,0};ADDR_TYPEL[1] = {-1,1};ADDR_TYPEL[2] = {-1,2};ADDR_TYPEL[3] = {-1,3};ADDR_TYPEL[4] = {-1,4};
        ADDR_TYPEL[5] = {-1,5};
        LEGNTH_TYPEL = 6;

    }
void control_about_ALLSYNBL::find_redefinitionSYNBL(SYNBL* A,string name){
      //  int num1 = synbl[synbl_num].LENGTH_SYNBL;
        int num1 = A->LENGTH_SYNBL;
        for(int i = 0 ; i < num1 ; i++){
            if(name==A->NAME_SYNBL[i]){
         //   if(name == synbl[synbl_num].NAME_SYNBL[i]){
                cout<<"��ʶ�� "<<name<<"  �ض��� "<<endl;
                exit(0);
            }
        }

}
void control_about_ALLSYNBL::find_redefinitionRINFL(RINFL* A,string name){
      //  int num1 = synbl[synbl_num].LENGTH_SYNBL;
        int num1 = A->LENGTH_RINFL;
        for(int i = A->end_pos ; i < num1 ; i++){
           if(name==A->NAME_SYNBL[i]){
    //        if(name == synbl[synbl_num].NAME_SYNBL[i]){

                cout<<"��ʶ�� "<<name<<"  �ض���"<<endl;
                exit(0);
            }
        }

}
void control_about_ALLSYNBL::INITIAL_RINFL_BEGIN(class RINFL* &A,class SYNBL* &B){   //������structʱ��������������ǰѱ�־��Ϊ1����ʾ��������ܱ��ͬʱ��Ҫ��д�ṹ���
        A->length_lastnum = 0;
        A->tag = 1;
   //     rinfl[rinfl_num].length_lastnum = 0;
   //      rinfl[rinfl_num].tag = 0;
        int h = sequence.high;
        int num1 = B->LENGTH_SYNBL;






    }
void control_about_ALLSYNBL::WRITE_RINFL(class RINFL* &A,class TYPEL* &B,string name,string type ){  //
    //�ز��أ������

    //����

        cout<<"���rinfl������"<<type<<" "<<name<< B->LEGNTH_TYPEL<<endl;
       // synbl[synbl_num]
       find_redefinitionRINFL(A,name);

        int num1 = A->LENGTH_RINFL;
        A->NAME_SYNBL[num1] = name;
        int num2 = A->length_lastnum;
        A->OFF[num1] = num2;
        cout<<name<<endl;
        for(int i = 0 ; i <= B->LEGNTH_TYPEL;i++){
            cout<<B->TYPE_TYPEL[i]<<name<<" "<<endl;
            if(type==B->TYPE_TYPEL[i]){
                 A->TP[num1] = i;
                 cout<<"�������"<<i<<endl;
                 break;
            }
        }
        A->LENGTH_RINFL++;

    }
void control_about_ALLSYNBL::WRITE_TYPEL(class TYPEL* &B,class RINFL* &C,class AINFL* &D,string type){   //��д����Ϊtype��TYPEL ��
        int num1 = B->LEGNTH_TYPEL;
        B->TYPE_TYPEL[num1] = type;
          cout<<"д��typel"<<type<<endl;
           getchar();
     /*   if(TYPE_LENGTH.find(type) != TYPE_LENGTH.end()){  //�ǻ������ͣ��Ȳ�������


        }
        else if(type == "struct"){
           */
           if(C->tag == 1){
            int num2 = C->LENGTH_RINFL;
            B->ADDR_TYPEL[num1] = {6,typel_num};//ָ��num2����һ��
             B->LEGNTH_TYPEL++;
        }

      /*  else if(type == "array"){
            int num2 = D->LENGTH_AINFL;
            B->ADDR_TYPEL[num1] = {5,num2};
             B->LEGNTH_TYPEL++;
        }*/


}
void control_about_ALLSYNBL::WRITE_SYNBL_ABOUT_RINFL_NAME(class SYNBL* &A,class TYPEL* &B,class RINFL* &C,class AINFL* &D,string name){  //�����д�����ܱ�Ľṹ��ר��
       // A = &synbl[synbl_num];
        int num1 = A->LENGTH_SYNBL;
        A->NAME_SYNBL[num1] = name;

        int num2 = B->LEGNTH_TYPEL;
       // cout<<"typel length"<<num2<<endl;
        getchar();
        A->TYPE_SYNBL[num1] = num2;  //�ṹ�������û������ֵ���ݶ�Ϊ-1����Ҫ��дΪһ�����໹Ҫ�ټ�����������
        WRITE_TYPEL(B,C,D,name);
        A->CAT_SYNBL[num1] = "t";
       // A->ADDR_SYNBL[num1] = {4,change_space}; �ȿ��� �ȴ����������ʱ����

        A->LENGTH_SYNBL++;
       // addr[num_memory] =


    }
void control_about_ALLSYNBL::WRITE_SYNBL_OR_RINFL(class SYNBL* &C, class RINFL* &A,class TYPEL* &B,class AINFL* &D,string type,string name){  //�����д�����ܱ�ı����ģ�ͬʱ����tag���ж��Ƿ�ͬʱд��rinfl��
    //�Ȳ��� ����д
     //��&��
   //  C = &synbl[synbl_num];
     find_redefinitionSYNBL(C,name);
     //����֮��ʼ��д
    int num1 = C->LENGTH_SYNBL;
    cout<<"��д"<<name<<"������"<<type<<"���"<<C->pos_my_excel<<"��ĵ�"<<num1<<" ��"<<endl;


    if(A->tag==0){
          //��дname
        C->NAME_SYNBL[num1] = name;
        //��дtype
          int i;
          for( i = 0 ; i < B->LEGNTH_TYPEL ; i++){
            if(type == B->TYPE_TYPEL[i]){
                C->TYPE_SYNBL[num1] = i;
                break;
            }
          }
          if(i==B->LEGNTH_TYPEL){
            cout<<"err,û�� "<<type<<" ���ֶ���"<<type<<endl;

            exit(0);
          }
          //��дcat
          if(i<4&&i>=0){
            C->CAT_SYNBL[num1] = "v";
          }
          else{
            C->CAT_SYNBL[num1] = "d";
          }
          //��дaddr
          int num2 = C->length_lastnum;
          C->ADDR_SYNBL[num1] = {4,num2};
          C->length_lastnum+=TYPE_LENGTH[type];
         //��񳤶ȼ�1
          C->LENGTH_SYNBL++;
    }
   else if(A->tag==1){
        WRITE_RINFL(A,B,name,type);
    }
}
void control_about_ALLSYNBL::INITIAL_RINFL_END(class RINFL* &A,class TYPEL* &B){   //������ṹ���Ҫ�ѱ�־�������ʾ�´���д���ű��ʱ������дrinfl����
        A->tag = 0;
        int num1 = B->LEGNTH_TYPEL;
        A->end_pos = num1;
        string new_type_name = B->TYPE_TYPEL[num1-1];
        TYPE_POS_IN_TYPEL[new_type_name] = num1-1;
        TYPE_LENGTH[new_type_name]=A->length_lastnum;
        cout<<new_type_name<<" weizhi "<<num1-1<<endl;
        typel_num++;
        A = &rinfl[typel_num];
        getchar();

}

void  control_about_ALLSYNBL::find_IsBeDefined(SYNBL* A,string name){
    cout<<"rrrrr "<<name<<endl;
    int num1 = A->LENGTH_SYNBL;
    int i;
    for( i = 0 ; i < num1 ; i++){
        if(name==A->NAME_SYNBL[i]){
            if(find_tag==0) last_A = A->pos_my_excel;///////////////////////
            last_A_pos = i;
            cout<<last_A_pos<<last_A<<endl;
            break;
        }
    }
    if(i == num1&&A->last_synbl_excel==-1){
        cout<< "��ʶ�� "<<name<<" δ����"<<endl;
        find_tag = 0;
        exit(0);
    }
    else if(i == num1&&A->last_synbl_excel!=-1){
        find_tag = 1;
        cout<<"ǰ���ϸ�����"<<endl;
        last_A = A->last_synbl_excel;
        cout<<last_A<<endl;
        SYNBL* temp = &synbl[last_A];
        find_IsBeDefined(temp,name);
    }
    else if(i != num1){
        find_tag = 0;
        return;
    }
    find_tag = 0;
    return;
}
void  control_about_ALLSYNBL::find_IsBeDefined(RINFL* A,TYPEL* B,string name){
    int num1;
    if(taggg == 0){
        taggg=1;
        num1 = synbl[last_A].TYPE_SYNBL[last_A_pos];//num1��Ӧ������Ӧ�Ľṹ��ı������������� ����˵ A.a ָ����A����typel�е���
    }
    else{
        num1=rinfl[last_A].TP[last_A_pos];
    }
    int num2 =  B->ADDR_TYPEL[num1].rol;
    cout<<"�ڽṹ��ĵ�"<<num1<<num2<<name;
    getchar();
    int   i = 0;
    for( i = 0 ; i < rinfl[num2].LENGTH_RINFL; i++){
        if(rinfl[num2].NAME_SYNBL[i]==name){
            last_A_pos = i;
            last_A = num2;
            break;
        }
    }
        if(i==rinfl[num2].LENGTH_RINFL){
        cout<< "��ʶ�� "<<name<<" δ����"<<endl;
        exit(0);
    }
    cout<<"�� �ṹ�����ҵ��˶���"<<endl;

   /* else{
        int num1=rinfl[last_A].TP[last_A_pos];
        int num2 =  B->ADDR_TYPEL[num1].rol;

    }*/
}

control_about_ALLSYNBL::control_about_ALLSYNBL(){
TYPE_LENGTH["int"] = 4;
TYPE_LENGTH["char"] = 2;
TYPE_LENGTH["float"] = 4;
TYPE_LENGTH["double"] = 8;
TYPE_LENGTH["bool"] = 2;
TYPE_POS_IN_TYPEL["int"] = 0;
TYPE_POS_IN_TYPEL["char"] = 1;
TYPE_POS_IN_TYPEL["double"] = 2;
TYPE_POS_IN_TYPEL["float"] = 3;
TYPE_POS_IN_TYPEL["void"] = 4;
TYPE_POS_IN_TYPEL["bool"] = 5;
}
void control_about_ALLSYNBL::show_synbl(SYNBL* A){
    cout<<"name    type    cat    addr    "<<endl;
    cout<<"----------------------------------------"<<endl;
    for(int i = 0  ; i < A->LENGTH_SYNBL ; i++){
        cout<<A->NAME_SYNBL[i]<<"  "<<A->TYPE_SYNBL[i]<<" "<<A->CAT_SYNBL[i]<<" "<<A->ADDR_SYNBL[i].excel_name<<" "<<A->ADDR_SYNBL[i].rol<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
void control_about_ALLSYNBL::show_typel(TYPEL* A){
    cout<<"type      kind_excel     addr    "<<endl;
    cout<<"----------------------------------------"<<endl;
    for(int i = 0 ; i < A->LEGNTH_TYPEL;i++){
        cout<<A->TYPE_TYPEL[i]<<" "<<A->ADDR_TYPEL[i].excel_name<<" "<<A->ADDR_TYPEL[i].rol<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
void control_about_ALLSYNBL::show_rinfl(RINFL* A){
   cout<<"name    off   type    "<<endl;
   cout<<"----------------------------------------"<<endl;
    for(int i = 0 ; i < A->LENGTH_RINFL;i++){
        cout<<A->NAME_SYNBL[i]<<" "<<A->OFF[i]<<" "<<A->TP[i]<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
 void control_about_ALLSYNBL::WRITE_TYPE_OF_TYPEL(TYPEL* A,string name){
    int num1 = A->LEGNTH_TYPEL;
    int tag = 0;
    for(int i = 0 ; i < num1 ; i++){
        if(A->TYPE_TYPEL[i]==name){tag= 1;break;}
    }
    if(tag == 0){
    A->TYPE_TYPEL[num1] = name;
    }

}
void control_about_ALLSYNBL::is_same_BSF_kind(SYNBL* A,TYPEL* B,string name,string type){
    int num1 = synbl[last_A].TYPE_SYNBL[last_A_pos];
    if(num1 != TYPE_POS_IN_TYPEL[type]){
            cout<<B->TYPE_TYPEL[num1]<<" �� "<<type;
            cout<<"���Ͳ�ƥ��"<<endl;
            cout<<last_A<<" "<<last_A_pos<<type<<endl;
            exit(0);
    }
    cout<<num1<<" "<<last_A<<last_A_pos<<"����ƥ��"<<endl;
}
 void control_about_ALLSYNBL::find_excel_BSF(RINFL* A,TYPEL* B,string name,string &type){
    int num1 = rinfl[last_A].TP[last_A_pos];
    int t;
    cout<<"չʾ"<<typel_num<<last_A<<last_A_pos<<rinfl[last_A].LENGTH_RINFL<<endl;
    for(int i = 0 ; i < rinfl[last_A].LENGTH_RINFL;i++){
        if(name == rinfl[last_A].NAME_SYNBL[i]){
            t = rinfl[last_A].TP[i];
            break;
        }
    }

   type =  B->TYPE_TYPEL[t];
 }
 void control_about_ALLSYNBL::is_same_CS_kind(TYPEL* B,string type){
     int num1 = TYPE_POS_IN_TYPEL[type];
     cout<<type<<" "<<num1<<endl;
     getchar();
    if(num1 == 0||num1 == 2 || num1 == 3){

    }
    else{
        cout<<B->TYPE_TYPEL[num1]<<" �� "<<"��������";
        cout<<"���Ͳ�ƥ��11"<<endl;
        exit(0);
    }

 }
 void control_about_ALLSYNBL::is_same_ZF_kind(TYPEL* B,string type){
   int num1 = TYPE_POS_IN_TYPEL[type];
    if(num1 != 1){
        cout<<B->TYPE_TYPEL[num1]<<" �� "<<"�ַ�����";
        cout<<"���Ͳ�ƥ��"<<endl;
        exit(0);
    }
}

void control_about_ALLSYNBL::find_excel_BSF(SYNBL* A,TYPEL* B,string name,string &type){
    int num1 = synbl[last_A].TYPE_SYNBL[last_A_pos];
    type =  B->TYPE_TYPEL[num1];
    cout<<name<<"�ڷ��ű����ҵ���������"<<type<<" "<<last_A<<last_A_pos<<endl;
    getchar();
}

void control_about_ALLSYNBL::is_same_bool_kind(TYPEL* B,string type){
    int num1 = TYPE_POS_IN_TYPEL[type];
    if(num1 != 5){
        cout<<B->TYPE_TYPEL[num1]<<" �� "<<"bool";
        cout<<"���Ͳ�ƥ��12"<<endl;
        exit(0);
    }



}
void control_about_ALLSYNBL::is_main(string name,SYNBL* &A,string type){
    if(name == "main"){
        is_main_begin = 1;
    }

    A->LENGTH_SYNBL--; //ɾ���ղ�������ű�ĺ�������
    A->length_lastnum -= TYPE_LENGTH[type];//��A�ĵ�ƫ����ҲҪ����Ϊ������
 /*   synbl_num++;
    A = &synbl[synbl_num];//��Aָ������
    A->last_synbl_excel = 0;//��ָ��ָ���ܷ��ű��*/
}
void control_about_ALLSYNBL::new_synbl(SYNBL* &A){
    SYNBL* temp = A;
    synbl_num++;
    stack_synbl.push(A);
    A = &synbl[synbl_num];
    A->pos_my_excel = synbl_num;
    A->last_synbl_excel = temp->pos_my_excel;
}
void control_about_ALLSYNBL::back_to_last_synbl(SYNBL *&A){
    A = stack_synbl.top();
 // A = &synbl[1];
    stack_synbl.pop();
}
void control_about_ALLSYNBL::change_tagg_zero(){

taggg = 0;
}
