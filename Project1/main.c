#include "struct.h"

int main()
{
	printf("����");
	int menu=-1;
	init();
	printf("\n3");
	DisplayGradeData();
	printf("\n4");
	printf("�����Ϸ��� 0 �Է� >> ");
	scanf("%d", &menu);
	if (menu == 0) {
		DeleteAllData();
		return 0;
	}
}