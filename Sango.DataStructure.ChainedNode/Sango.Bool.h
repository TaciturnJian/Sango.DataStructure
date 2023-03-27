/*
	Author: ����Sango
	Brief: �ṩһЩ��(typedef char)�ض�������ͣ��Լ���Щ������صĺ꺯�����궨��
*/

#ifndef SANGO_BOOL
#define SANGO_BOOL

//��ʾ�ںϷ������ֻ��0��1����״̬������
typedef unsigned char SangoBool, condition;
#define TRUE 1												//��ʾ��
#define FALSE 0												//��ʾ��

//��ʾ�ںϷ������ֻ������״̬�����ͣ��ȽϽ��: ����=>More; С��=>LESS; ����=>EQUAL��
typedef char CompareResult;
#define MORE 1												//��ʾ����
#define EQUAL 0												//��ʾ����
#define LESS -1												//��ʾС��
#define CheckMoreOrEqual(compareResult) ((compareResult) >= 0)		//��ʾ���ڻ����
#define CheckLessOrEqual(compareResult) ((compareResult) <= 0)		//��ʾС�ڻ����

//��ʾ�ںϷ������ֻ������״̬�����ͣ�-1��ʾ����, 0��ʾ������
typedef char status;
#define STATUS_ERROR -1										//��ʾ����
#define STATUS_NORMAL 0										//��ʾ����

//��ʾ�ںϷ������ֻ������״̬�����ͣ�ѡ��: ͬ��=>ACCEPTED; ��=>DENIED; δ֪=>UNKNOWN��
typedef char choice;
#define ACCEPTED 1											//��ʾͬ��
#define DENIED -1											//��ʾ��
#define UNKNWON 0											//��ʾδȷ��
#define CheckMadeChoice(c) (c != 0)							//��ʾ����δ֪�ľ���

#endif
