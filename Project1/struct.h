#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>  // printf, fopen_s, fgets, fclose �Լ��� ����ϱ� ����!
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Grade {
	unsigned short index; // ���� , short�� %hd�� ���
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
void DeleteInfo(GRADE* pGrade);
void DeleteAllData();

#endif