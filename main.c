#include "struct.h"

int main(void) {
	system("mode con:cols=180");
	SetConsoleTitle("���� ���� ���α׷�");
	printf("���� ���� ���α׷��� �����մϴ�.\n");

	int menu = -1;
	extern char name1[10];
	extern char name2[10];
	
	while (menu != 0) {
		printf("\n>> �޴� - ���� ���� ��ü����<1>, ��� ��������<2>, ���ֺ� ���� ��� ��<3>, ���� �߰��ϱ�<4>, ���� ���ϱ�<5>, ����<0> : ");
		scanf("%d", &menu);

		switch (menu) {
		case 0:
			DeleteAllData();
			break;
		case 1:
			DisplayGradeData();
			break;
		case 2:
			average_grade();
			break;
		case 3:
			credit_divide();
			break;
		case 4:
			printf("���� �̸�: ");
			scanf("%s", &excel_name);
			//printf("%s", excel_name);
			init(excel_name);
			break;
		case 5:
			printf("\n���� ���� ���� : ");
			scanf("%d", &y1);
			printf("�б� : ");
			s1 = (char*)malloc(sizeof(char));
			scanf("%s", s1);
			
			printf("���� ���� ���� : ");
			scanf("%d", &y2);
			printf("�б� : ");
			s2 = (char*)malloc(sizeof(char));
			scanf("%s", s2);
			
			compare_mycredit();
			break;
		}
	}
	return 0;
}