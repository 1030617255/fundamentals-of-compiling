#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef struct TPOINT{
    int excel_name;//1 .pinfl 2.consl 3.lenl 4.vall 5.ainfl 6.rinfl
    int rol;//��excel���λ��
}tpoint;
//typedef struct tpoint1{
//    int
//}


class SYNBL{
public:
    int pos_my_excel = 0;//��������synbl�����е��±�
    int last_synbl_excel = -1;//����һ������λ������������±�
    string name;
    int length_lastnum = 0;//ƫ����
    int LENGTH_SYNBL = 0;  //���ű�ĳ���
    string NAME_SYNBL[100];  //����������
    int TYPE_SYNBL[100];//����������,ָ��TYPEL,��һ��ָ�룬ָ��ڼ���
    string CAT_SYNBL[100];//����������
    map<int,tpoint>  ADDR_SYNBL;//�����ĵ�ַ,��mapӳ��////////////////////////////
    int LEVEL_SYNBL[100];//��ʾ������������,������for while struct �������Լ��������ŵ� ��Ҫ��һ������Щ���̽���ʱ��1
};
class TYPEL{
public:
    int LEGNTH_TYPEL;
    string TYPE_TYPEL[100];
    map<int,tpoint> ADDR_TYPEL;  //��Ϊָ��ͬ�ı������map����ӳ���,Map[1_AINFL] = 3����ָ��map����1�ŵ�Ԫ��ָ��AINFL��ĵ�3��Ԫ��
    TYPEL();

};
class AINFL{
public:

    int LENGTH_AINFL = 0;
    int LOW[100] = {0};
    int UP[100];
    int CTP[100];  //��ʾҪ����ָ�����ͱ�ĵڼ��� ��TYPEL�ĵڼ���
    int CLEN[100];

};
class RINFL{
public:
    int end_pos = 0;
    int LENGTH_RINFL = 0;;
    string NAME_SYNBL[100];  //����������
    int OFF[100];
    int TP[100];//��ʾҪָ�����ͱ�ĵڼ��� ��TYPEL�ĵڼ���
    int length_lastnum = 0;
    int tag = 0;
    class RINFL* tpr = NULL;
};
class VAR_DEFINE{
public:
    string NAME_VAR_DEFINE;  //jie gou ti de ming zi,fuqin
    string NAME_OF_VAR[100];  //����������
    int LENGTH_VAR_DEFINE = 0;
     int OFF[100];
     int TP[100];//��ʾҪָ�����ͱ�ĵڼ��� ��TYPEL�ĵڼ���
    int length_lastnum = 0;

  //  string type[100];//���� int float char double
   // map<int,tpoint>ADDR_VAR_DEFINE;
};
class control_about_ALLSYNBL{
public:
    int is_main_begin = 0;
    int synbl_num = 0;
    int typel_num = 0;
    int rinfl_num = 0;
    int ainfl_num = 0;
    int last_A ;//synbl�������ҵ����±�,��һ�ξͲ���������
    int last_A_pos;//��synbl�����е��±꣬�´ν����ŵĶ����Ͳ�����������
    int find_tag = 0;
    void INITIAL_RINFL_BEGIN(class RINFL* &A,class SYNBL* &B);
    void WRITE_RINFL(class RINFL* &A,class TYPEL* &B,string name,string type );
    void WRITE_TYPEL(class TYPEL* &B,class RINFL* &C,class AINFL* &D,string type);
    void WRITE_SYNBL_ABOUT_RINFL_NAME(class SYNBL* &A,class TYPEL* &B,class RINFL* &C,class AINFL* &D,string name);
    void WRITE_SYNBL_OR_RINFL(class SYNBL* &C, class RINFL* &A,class TYPEL* &B,class AINFL* &D,string type,string name);
    void INITIAL_RINFL_END(class RINFL* &A,class TYPEL* &B);
    control_about_ALLSYNBL();
    void show_synbl(SYNBL* A);
    void show_typel(TYPEL* A);
    void show_ainfl(AINFL* A);
    void show_rinfl(RINFL* A);
    void WRITE_VAR_DEFINE(VAR_DEFINE* A);
    void WRITE_TYPE_OF_TYPEL(TYPEL* A,string name);
    void find_redefinitionSYNBL(SYNBL* A,string name);
    void find_redefinitionRINFL(RINFL* A,string name);
    void find_IsBeDefined(SYNBL* A,string name);
    void find_IsBeDefined(RINFL* A,TYPEL* B,string name);
    void is_same_BSF_kind(SYNBL* A,TYPEL* B,string name,string type);
    void is_same_CS_kind(TYPEL* B,string type);
    void is_same_ZF_kind(TYPEL* B,string type);
    void find_excel_BSF(SYNBL* A,TYPEL* B,string name,string &type);
    void find_excel_BSF(RINFL* A,TYPEL* B,string name,string &type);
    void is_same_bool_kind(TYPEL* B,string type);
    void is_main(string name,SYNBL* &A,string temp);
    void new_synbl(SYNBL* &A);
    void back_to_last_synbl(SYNBL *&A);
    void change_tagg_zero();
};
