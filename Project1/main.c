#include "struct.h"

int main()
{
	printf("시작");
	int menu=-1;
	init();
	printf("\n3");
	DisplayGradeData();
	printf("\n4");
	printf("종료하려면 0 입력 >> ");
	scanf("%d", &menu);
	if (menu == 0) {
		DeleteAllData();
		return 0;
	}
}