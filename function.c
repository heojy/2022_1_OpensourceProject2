#include "struct.h"

NODE* Head = NULL;
NODE* Tail = NULL;


float rating_sum = 0;
int credit_sum = 0;

//char excel_name[10];

int essential_major_credit;
int choice_major_credit;
int liberal_credit;
int total_credit;
char name1[10], name2[10];
int credit1 = 0;
int credit2 = 0;
float rating1 = 0;
float rating2 = 0;


void AddNode(GRADE _GRADE) {
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	//printf("newnode 생성\n");
	NewNode->grade = _GRADE;
	NewNode->Next = NULL;
	//printf("newnode 저장\n");
	if (Head == NULL) {
		//printf("헤드가 null\n");
		Head = NewNode;
	}
	else
		Tail->Next = NewNode;
	//printf("헤드 테일 저장\n");
	Tail = NewNode;
	//printf("!");
}

void init() {
	FILE *p_file = NULL;  // 파일을 열어서 사용할 파일 포인터!
	// fopen_s 함수를 사용하여 'grd_sbjtGrade1.csv' 파일을 텍스트 형식의 읽기 모드로 연다!
	// 이 함수는 파일 열기에 성공했다면 0을 반환한다.
	strcat(excel_name, ".csv");
	if (0 == fopen_s(&p_file, excel_name, "rt")) {
		// 파일에서 한 줄의 정보를 읽어서 저장할 변수
		char one_line_string[128];
		char delimiter[] = ",";
		char *p_token;
		char *p_next_token;

		int namelength;
		GRADE grade;

		fgets(one_line_string, 128, p_file);

		while (1) {
			fgets(one_line_string, 128, p_file);

			if (strlen(one_line_string) < 4)
				break;
			p_token = strtok_s(one_line_string, delimiter, &p_next_token);
			grade.index = atoi(p_token);
			
			p_token = strtok_s(NULL, delimiter, &p_next_token);
			grade.year = atoi(p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			namelength = strlen(p_token);
			grade.semester_type = (char*)malloc(namelength + 1);
			strcpy(grade.semester_type, p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			namelength = strlen(p_token);
			grade.semester = (char*)malloc(namelength + 1);
			strcpy(grade.semester, p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			grade.subject_number = atoi(p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			grade.subject_number2 = atoi(p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			namelength = strlen(p_token);
			grade.subject = (char*)malloc(namelength + 1);
			strcpy(grade.subject, p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			grade.credit = atoi(p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			namelength = strlen(p_token);
			grade.completion_division = (char*)malloc(namelength + 1);
			strcpy(grade.completion_division, p_token);

			if (p_next_token[0] == ',') {
				p_token = "\0";
			}
			else {
				p_token = strtok_s(NULL, delimiter, &p_next_token);
			}
			namelength = strlen(p_token);
			grade.subject_division = (char*)malloc(namelength + 1);
			strcpy(grade.subject_division, p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			namelength = strlen(p_token);
			grade.rating = (char*)malloc(namelength + 1);
			strcpy(grade.rating, p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			grade.grade = atof(p_token);

			p_token = strtok_s(NULL, delimiter, &p_next_token);
			namelength = strlen(p_token);
			grade.credit_division = (char*)malloc(namelength + 1);
			strcpy(grade.credit_division, p_token);

			AddNode(grade);
		}
		fclose(p_file);
	}
}

void DisplayGrade(GRADE* pGrade) {
	printf("%3hd \t %4hd \t %4s \t    %5s \t %10u \t %3hd \t %30s \t %2hd \t %10s \t %20s \t %3s \t %.1f \t %10s \n",
		pGrade->index, pGrade->year, pGrade->semester_type, pGrade->semester,
		pGrade->subject_number, pGrade->subject_number2, pGrade->subject,
		pGrade->credit, pGrade->completion_division, pGrade->subject_division,
		pGrade->rating, pGrade->grade, pGrade->credit_division);
}

void GradeIndex() {
	printf("\n\n%3s \t %4s \t %4s  %5s \t %10s \t %3s \t %30s \t %2s \t %10s \t %20s \t %3s \t %4s \t %10s \n\n",
		"순번", "년도", "학기유형", "학기", "교과목번호", "분반", "교과목명", "학점", "이수구분", "영역구분", "등급", "평점", "학점구분");
}

void DisplayGradeData() {
	NODE *Cur = Head;

	if (Head == NULL) {
		printf("데이터 없음\n");
		return;
	}
	GradeIndex();
	for (int i = 1; Cur != NULL; i++) {
		DisplayGrade(&Cur->grade);
		Cur = Cur->Next;
	}
}

void calculate_average_grade(GRADE* pGrade) {
	credit_sum += pGrade->credit;
	rating_sum += pGrade->grade;
}

void average_grade() {
	NODE *Cur = Head;
	
	if (Head == NULL) {
		printf("데이터 없음\n");
		return;
	}
	for (int i = 1; Cur != NULL; i++) {
		calculate_average_grade(&Cur->grade);		
		Cur = Cur->Next;
	}
	printf("\n 지금까지 취득한 학점은 %d점, 누적 평점은 %.1f점 입니다.", credit_sum, rating_sum);
	printf(" \n 평균 학점은 : %.3f / 4.5 \n", rating_sum / credit_sum);
}

void calculate_credit_divide(GRADE* pGrade) {
	
	if (strcmp(pGrade->completion_division, "전공필수") == 0) {
		essential_major_credit += pGrade->credit;
	}
	else if(strcmp(pGrade->completion_division, "전공선택") == 0) {
		choice_major_credit += pGrade->credit;
	}
	else if (strcmp(pGrade->completion_division, "교양선택") == 0) {
		liberal_credit += pGrade->credit;
	}
	total_credit += pGrade->credit;
}

void credit_divide() {
	NODE *Cur = Head;
	if (Head == NULL) {
		printf("데이터 없음\n");
		return;
	}
	essential_major_credit = 0;
	choice_major_credit = 0;
	liberal_credit = 0;
	for (int i = 1; Cur != NULL; i++) {
		calculate_credit_divide(&Cur->grade);
		Cur = Cur->Next;
	}
	printf("\n 지금까지 전공필수는 %d 학점, 전공선택은 %d 학점, 교양은 %d 학점 들었네요.\n", 
		essential_major_credit, choice_major_credit, liberal_credit);
	printf("\n 지능로봇공학과 졸업요건 : \n\t전공필수 : %d/30\n\t전공선택 : %d/33\n\t교양 : %d/42\n\t졸업학점 : %d/140\n",
		essential_major_credit, choice_major_credit, liberal_credit, total_credit);
}

void calculate_compare_grade(GRADE* pGrade) {

	if ((pGrade->year == y1) && (strcmp(pGrade->semester, s1) == 0)) {
		credit1 += pGrade->credit;
		rating1 += pGrade->grade;
	}
	
	else if ((pGrade->year == y2) && (strcmp(pGrade->semester, s2) == 0)) {
		credit2 += pGrade->credit;
		rating2 += pGrade->grade;
	}
}

void compare_mycredit() {

	NODE *Cur = Head;

	if (Head == NULL) {
		printf("데이터 없음\n");
		return;
	}
	for (int i = 1; Cur != NULL; i++) {
		calculate_compare_grade(&Cur->grade);
		Cur = Cur->Next;
	}

	float mycredit1 = (float)rating1 / credit1;
	float mycredit2 = (float)rating2 / credit2;
	printf("\n%d학년도 %s의 학점 : %f \n%d학년도 %s의 학점 : %f ", y1, s1, mycredit1, y2, s2, mycredit2);
	if (mycredit1 > mycredit2) {
		printf("\n%d학년도 %s가 %d학년도 %s 보다 %f학점 높네요.\n", y1, s1, y2, s2, mycredit1 - mycredit2);
	}
	else if ((mycredit1) < (mycredit2)) {
		printf("\n%d학년도 %s가 %d학년도 %s 보다 %f학점 높네요.\n", y2, s2, y1, s1, mycredit2 - mycredit1);
	}
	else {
		printf("%d학년도 %s와 %d학년도 %s의 학점이 %f 로 같아요.\n", y1, s1, y2, s2, mycredit1);
	}
}
void DeleteInfo(GRADE* pGrade) {
	if (pGrade->semester_type != NULL)
		free(pGrade->semester_type);
	if (pGrade->semester != NULL)
		free(pGrade->semester);
	if (pGrade->subject != NULL)
		free(pGrade->subject);
	if (pGrade->completion_division != NULL)
		free(pGrade->completion_division);
	if (pGrade->subject_division != NULL)
		free(pGrade->subject_division);
	if (pGrade->rating != NULL)
		free(pGrade->rating);
	if (pGrade->credit_division != NULL)
		free(pGrade->credit_division);
}

//	연결 리스트의 정보를 모두 삭제
void DeleteAllData() {	
	NODE* Cur = Head;
	NODE* Del = NULL;

	if (Head == NULL)
		return;

	while (Cur != NULL)
	{
		Del = Cur;
		Cur = Cur->Next;
		DeleteInfo(&(Del->grade));
		free(Del);
	}

	Head = Tail = NULL;
	printf("프로그램을 종료합니다.");
}