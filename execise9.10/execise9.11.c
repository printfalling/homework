#include "link_list_for_10_and_11.c"

tNode *Find_schoolNUM(tLink_list *plink_list, char *school_num)
{
	tNode *ptemp_node;

	if (plink_list->phead == NULL){perror("Void link_list");}	//Void error

	for (ptemp_node = plink_list->phead; ptemp_node != NULL; ptemp_node = ptemp_node->pNext)
	{
		if (strcmp(ptemp_node->student.school_num, school_num) == 0)
		{
			return ptemp_node;
		}	
	}
	printf("Can't find!    %s\n", school_num);
	return NULL;
}

int Delete(tLink_list *plink_list, char *school_num)
{
	tNode *ptemp_node;
	tNode *pnode;
	if (plink_list->phead == NULL){perror("Void link_list");}

	if(!(pnode = Find_schoolNUM(plink_list , school_num))) return -1;
	if (pnode ==plink_list->phead)
	{
		plink_list->phead = pnode->pNext;
		free(pnode);
	}else	{
		ptemp_node = Find_forenode(plink_list, pnode);
		ptemp_node->pNext = pnode->pNext;
		free(pnode);
	}
	return 0;
}

int Find_and_Delete(tLink_list *plink_list_B, tLink_list *plink_list_A)
{
	tNode *ptemp_node_A, ptemp_node_B;
	tNode *ptemp_node;
	if (plink_list_A->phead == NULL){perror("Void link_list");}
	if (plink_list_B->phead == NULL){perror("Void link_list");}

	for (ptemp_node_A = plink_list_A->phead; ptemp_node_A != NULL; ptemp_node_A = ptemp_node_A->pNext)
	{
		Delete(plink_list_B, ptemp_node_A->student.school_num);
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int i;
	tLink_list *plink_list_A = Creat();
	tLink_list *plink_list_B = Creat();
	//tLink_list *plink_list;
	tStudent student;
	for (i = 0; i < STD_NUM + 3; ++i)
	{
		strcpy(student.school_num, SCHOOL_NUM[i]);
		strcpy(student.name, NAME[i]);
		Append(plink_list_A, student);
	}
	for (i = 0; i < STD_NUM + 3; ++i)
	{
		strcpy(student.school_num, SCHOOL_NUM[i + STD_NUM - 3]);
		strcpy(student.name, NAME[i + STD_NUM - 3]);
		Append(plink_list_B, student);
	}
	Show(plink_list_A);
	printf("\n");
	Show(plink_list_B);
	

	Find_and_Delete(plink_list_A, plink_list_B);
	Show(plink_list_A);


	return 0;
}


