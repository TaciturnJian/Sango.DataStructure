/*
	Author: ����Sango
	Brief: �ṩһЩ��(typedef char)�ض�������ͣ��Լ���Щ������صĺ꺯�����궨��
*/

#ifndef SANGO_BOOL
#define SANGO_BOOL

//��ʾ�ںϷ������ֻ��0��1����״̬������
typedef unsigned char SangoBool, condition;
#define TRUE 1
#define FALSE 0

//��ʾ�ںϷ������ֻ������״̬�����ͣ��ȽϽ��: ����=>More; С��=>LESS; ����=>EQUAL��
typedef char CompareResult;
#define MORE 1
#define EQUAL 0
#define LESS -1
#define CheckMoreOrEqual(compareResult) ((compareResult) >= 0)
#define CheckLessOrEqual(compareResult) ((compareResult) <= 0)

//��ʾ�ںϷ������ֻ������״̬�����ͣ�-1��ʾ����,0��ʾ������
typedef char status;
#define STATUS_ERROR -1
#define STATUS_NORMAL 0

//��ʾ�ںϷ������ֻ������״̬�����ͣ�ѡ��: ͬ��=>ACCEPTED; ��=>DENIED; δ֪=>UNKNOWN��
typedef char choice;
#define ACCEPTED 1
#define DENIED -1
#define UNKNWON 0

#endif
