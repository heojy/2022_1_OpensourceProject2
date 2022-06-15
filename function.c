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
	//printf("newnode ����\n");
	NewNode->grade = _GRADE;
	NewNode->Next = NULL;
	//printf("newnode ����\n");
	if (Head == NULL) {
		//printf("��尡 null\n");
		Head = NewNode;
	}
	else
		Tail->Next = NewNode;
	//printf("��� ���� ����\n");
	Tail = NewNode;
	//printf("!");
}

void init() {
	FILE *p_file = NULL;  // ������ ��� ����� ���� ������!
	// fopen_s �Լ��� ����Ͽ� 'grd_sbjtGrade1.csv' ������ �ؽ�Ʈ ������ �б� ���� ����!
	// �� �Լ��� ���� ���⿡ �����ߴٸ� 0�� ��ȯ�Ѵ�.
	strcat(excel_name, ".csv");
	if (0 == fopen_s(&p_file, excel_name, "rt")) {
		// ���Ͽ��� �� ���� ������ �о ������ ����
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
		"����", "�⵵", "�б�����", "�б�", "�������ȣ", "�й�", "�������", "����", "�̼�����", "��������", "���", "����", "��������");
}

void DisplayGradeData() {
	NODE *Cur = Head;

	if (Head == NULL) {
		printf("������ ����\n");
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
		printf("������ ����\n");
		return;
	}
	for (int i = 1; Cur != NULL; i++) {
		calculate_average_grade(&Cur->grade);		
		Cur = Cur->Next;
	}
	printf("\n ���ݱ��� ����� ������ %d��, ���� ������ %.1f�� �Դϴ�.", credit_sum, rating_sum);
	printf(" \n ��� ������ : %.3f / 4.5 \n", rating_sum / credit_sum);
}

void calculate_credit_divide(GRADE* pGrade) {
	
	if (strcmp(pGrade->completion_division, "�����ʼ�") == 0) {
		essential_major_credit += pGrade->credit;
	}
	else if(strcmp(pGrade->completion_division, "��������") == 0) {
		choice_major_credit += pGrade->credit;
	}
	else if (strcmp(pGrade->completion_division, "���缱��") == 0) {
		liberal_credit += pGrade->credit;
	}
	total_credit += pGrade->credit;
}

void credit_divide() {
	NODE *Cur = Head;
	if (Head == NULL) {
		printf("������ ����\n");
		return;
	}
	essential_major_credit = 0;
	choice_major_credit = 0;
	liberal_credit = 0;
	for (int i = 1; Cur != NULL; i++) {
		calculate_credit_divide(&Cur->grade);
		Cur = Cur->Next;
	}
	printf("\n ���ݱ��� �����ʼ��� %d ����, ���������� %d ����, ������ %d ���� ����׿�.\n", 
		essential_major_credit, choice_major_credit, liberal_credit);
	printf("\n ���ɷκ����а� ������� : \n\t�����ʼ� : %d/30\n\t�������� : %d/33\n\t���� : %d/42\n\t�������� : %d/140\n",
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
		printf("������ ����\n");
		return;
	}
	for (int i = 1; Cur != NULL; i++) {
		calculate_compare_grade(&Cur->grade);
		Cur = Cur->Next;
	}

	float mycredit1 = (float)rating1 / credit1;
	float mycredit2 = (float)rating2 / credit2;
	printf("\n%d�г⵵ %s�� ���� : %f \n%d�г⵵ %s�� ���� : %f ", y1, s1, mycredit1, y2, s2, mycredit2);
	if (mycredit1 > mycredit2) {
		printf("\n%d�г⵵ %s�� %d�г⵵ %s ���� %f���� ���׿�.\n", y1, s1, y2, s2, mycredit1 - mycredit2);
	}
	else if ((mycredit1) < (mycredit2)) {
		printf("\n%d�г⵵ %s�� %d�г⵵ %s ���� %f���� ���׿�.\n", y2, s2, y1, s1, mycredit2 - mycredit1);
	}
	else {
		printf("%d�г⵵ %s�� %d�г⵵ %s�� ������ %f �� ���ƿ�.\n", y1, s1, y2, s2, mycredit1);
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

//	���� ����Ʈ�� ������ ��� ����
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
	printf("���α׷��� �����մϴ�.");
}