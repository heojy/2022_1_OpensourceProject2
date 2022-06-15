#include "struct.h"

int main(void) {
	system("mode con:cols=180");
	SetConsoleTitle("학점 관리 프로그램");
	printf("학점 관리 프로그램을 시작합니다.\n");

	int menu = -1;
	extern char name1[10];
	extern char name2[10];
	
	while (menu != 0) {
		printf("\n>> 메뉴 - 과목별 성적 전체보기<1>, 평균 학점보기<2>, 범주별 졸업 요건 비교<3>, 파일 추가하기<4>, 성적 비교하기<5>, 종료<0> : ");
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
			printf("문서 이름: ");
			scanf("%s", &excel_name);
			//printf("%s", excel_name);
			init(excel_name);
			break;
		case 5:
			printf("\n비교할 성적 연도 : ");
			scanf("%d", &y1);
			printf("학기 : ");
			s1 = (char*)malloc(sizeof(char));
			scanf("%s", s1);
			
			printf("비교할 성적 연도 : ");
			scanf("%d", &y2);
			printf("학기 : ");
			s2 = (char*)malloc(sizeof(char));
			scanf("%s", s2);
			
			compare_mycredit();
			break;
		}
	}
	return 0;
}