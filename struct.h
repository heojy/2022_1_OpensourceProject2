#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>  // printf, fopen_s, fgets, fclose �Լ��� ����ϱ� ����!
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Grade {
	unsigned short index; // ����
	unsigned short year;  // �⵵
	char *semester_type;  // �б�����
	char *semester;  // �б�
	unsigned int subject_number; // ������ ��ȣ
	unsigned short subject_number2; // ������ ��ȣ 
	char *subject; // �������
	unsigned short credit; // ����
	char *completion_division; // �̼�����
	char *subject_division; // ��������
	char *rating; //���
	float grade; //����
	char *credit_division; // ��������
}GRADE;

typedef struct GradeNode {
	GRADE grade;
	struct GradeNode *Next;
}NODE;

void AddNode(GRADE _GRADE);
void init();
void DisplayGrade(GRADE* pGrade);
void GradeIndex();
void DisplayGradeData();
void calculate_average_grade(GRADE* pGrade);
void average_grade();
void calculate_credit_divide(GRADE* pGrade);
void credit_divide();
void DeleteInfo(GRADE* pGrade);
void DeleteAllData();
char excel_name[20];
void compare_mycredit(y1, s1, y2, s2);
int y1;
int y2;
char *s1;
char *s2;

#endif