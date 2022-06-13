#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>  // printf, fopen_s, fgets, fclose 함수를 사용하기 위해!
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Grade {
	unsigned short index; // 순번 , short는 %hd로 출력
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
void DeleteInfo(GRADE* pGrade);
void DeleteAllData();

#endif