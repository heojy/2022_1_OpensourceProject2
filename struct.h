#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>  // printf, fopen_s, fgets, fclose 함수를 사용하기 위해!
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Grade {
	unsigned short index; // 순번
	unsigned short year;  // 년도
	char *semester_type;  // 학기유형
	char *semester;  // 학기
	unsigned int subject_number; // 교과목 번호
	unsigned short subject_number2; // 교과목 번호 
	char *subject; // 교과목명
	unsigned short credit; // 학점
	char *completion_division; // 이수구분
	char *subject_division; // 영역구분
	char *rating; //등급
	float grade; //평점
	char *credit_division; // 학점구분
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