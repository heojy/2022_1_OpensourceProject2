#include "struct.h"

NODE* Head = NULL;
NODE* Tail = NULL;


void AddNode(GRADE _GRADE) {
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	printf("newnode 생성\n");
	NewNode->grade = _GRADE;
	NewNode->Next = NULL;
	printf("newnode 저장\n");
	if (Head == NULL) {
		printf("헤드가 null\n");
		Head = NewNode;
	}
	else
		Tail->Next = NewNode;
	printf("헤드 테일 저장\n");
	Tail = NewNode;
	printf("!");
}

void init() {
	FILE *p_file = NULL;  // 파일을 열어서 사용할 파일 포인터!
	// fopen_s 함수를 사용하여 'grd_sbjtGrade1.csv' 파일을 텍스트 형식의 읽기 모드로 연다!
	// 이 함수는 파일 열기에 성공했다면 0을 반환한다.

	if (0 == fopen_s(&p_file, "grd_sbjtGrade1.csv", "rt")) {
		// 파일에서 한 줄의 정보를 읽어서 저장할 변수
		char one_line_string[128];
		char delimiter[] = ",";
		char *p_token;
		char *p_next_token;

		int namelength;
		GRADE grade;

		fgets(one_line_string, 128, p_file);

		while (1) {
			//fgets(one_line_string, 128, p_file);
			//fgets(one_line_string, 128, p_file);
			//fgets(one_line_string, 128, p_file);
			//fgets(one_line_string, 128, p_file);
			fgets(one_line_string, 128, p_file);
			//printf("%s", one_line_string);

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
				//printf("공백");
				p_token = "\0";
			}
			else {
				p_token = strtok_s(NULL, delimiter, &p_next_token);
			}
			//p_token = "\0";
			//printf("\np token : %s\t", p_token);
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

			printf("구조체 생성\n");
			AddNode(grade);

 			//while (p_token != NULL) {
				//printf("%s\t", p_token);
				//p_token = strtok_s(NULL, delimiter, &p_next_token);
			//}
			//printf("%s", one_line_string);
			printf("\n");    
		}
		printf("2");
		fclose(p_file);
	}
}

void DisplayGrade(GRADE* pGrade) {
	printf("%3hd \t %4hd \t %4s \t %5s \t %10u \t %3hd \t %30s \t %2hd \t %10s \t %20s \t %3s \t %4f \t %10s \n",
		pGrade->index, pGrade->year, pGrade->semester_type, pGrade->semester,
		pGrade->subject_number, pGrade->subject_number2, pGrade->subject,
		pGrade->credit, pGrade->completion_division, pGrade->subject_division,
		pGrade->rating, pGrade->grade, pGrade->credit_division);
}

void GradeIndex() {
	printf("\n%3s \t %4s \t %4s \t %5s \t %10s \t %3s \t %30s \t %2s \t %10s \t %20s \t %3s \t %4s \t %10s \n",
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
	printf("!!\n");

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
	printf("삭제 완료우");
}