#include "link_list_for_10_and_11.c"

int main(int argc, char const *argv[])
{
	int i;
	tLink_list *plink_list_A = Creat();
	tLink_list *plink_list_B = Creat();
	tLink_list *plink_list;
	tStudent student;
	for (i = 0; i < STD_NUM; ++i)
	{
		strcpy(student.school_num, SCHOOL_NUM[i]);
		strcpy(student.name, NAME[i]);
		Append(plink_list_A, student);
	}
	for (i = 0; i < STD_NUM; ++i)
	{
		strcpy(student.school_num, SCHOOL_NUM[i + STD_NUM]);
		strcpy(student.name, NAME[i + STD_NUM]);
		Append(plink_list_B, student);
	}
	Show(plink_list_A);
	Show(plink_list_B);
	printf("\n");
	plink_list = Combine(plink_list_A, plink_list_B);
	Show(plink_list);
	printf("\n");

	Swap(plink_list, Find_forenode(plink_list, Find_forenode(plink_list, plink_list->ptail)), plink_list->phead);
	Swap(plink_list, Find_forenode(plink_list, Find_forenode(plink_list, plink_list->ptail)), Find_forenode(plink_list, plink_list->ptail));
	Show(plink_list);
	printf("\n");

	Sort(plink_list);
	Show(plink_list);
	return 0;
}


