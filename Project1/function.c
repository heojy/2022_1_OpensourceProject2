#include "struct.h"

NODE* Head = NULL;
NODE* Tail = NULL;


void AddNode(GRADE _GRADE) {
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	printf("newnode ����\n");
	NewNode->grade = _GRADE;
	NewNode->Next = NULL;
	printf("newnode ����\n");
	if (Head == NULL) {
		printf("��尡 null\n");
		Head = NewNode;
	}
	else
		Tail->Next = NewNode;
	printf("��� ���� ����\n");
	Tail = NewNode;
	printf("!");
}

void init() {
	FILE *p_file = NULL;  // ������ ��� ����� ���� ������!
	// fopen_s �Լ��� ����Ͽ� 'grd_sbjtGrade1.csv' ������ �ؽ�Ʈ ������ �б� ���� ����!
	// �� �Լ��� ���� ���⿡ �����ߴٸ� 0�� ��ȯ�Ѵ�.

	if (0 == fopen_s(&p_file, "grd_sbjtGrade1.csv", "rt")) {
		// ���Ͽ��� �� ���� ������ �о ������ ����
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
				//printf("����");
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

			printf("����ü ����\n");
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
	printf("���� �Ϸ��");
}