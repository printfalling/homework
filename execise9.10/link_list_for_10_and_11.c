#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 20
#define STD_NUM 5

char SCHOOL_NUM[10][MAX] = {	"PB15111001",	"PB15111002",	"PB15111003",	"PB15111004",	"PB15111005",	"PB15111006",	"PB15111007",	"PB15111008",	"PB15111009", "PB15111010",};
char NAME[10][MAX] = {	"zhang", "wang", "Li", "xie", "lin", "zou", "dongfang", "sun", "huang", "yang"};

typedef struct Student 
{
	char school_num[MAX] ;
	char name[MAX];
} tStudent;

typedef struct Node
{
	struct Node *pNext;
	tStudent student;
} tNode;

typedef struct Link_list
{
	tNode *phead;
	tNode *ptail;
} tLink_list;

tLink_list *Creat()
{
	tLink_list *plink_list;
	plink_list = (tLink_list*)malloc(sizeof(tLink_list)); 

	if (plink_list == NULL){
		printf("Error:malloc error!!\n");
		exit(0);
	}	else{
		plink_list->ptail = NULL;
		plink_list->phead = NULL;
		return plink_list;
	}
}

int Free_linklist(tLink_list *plink_list)
{
	while(plink_list->phead != plink_list->ptail)
	{
		free(plink_list->ptail);
		for (plink_list->ptail = plink_list->phead; plink_list->ptail->pNext != NULL; plink_list->ptail = plink_list->ptail->pNext);
	}
	free(plink_list);
}



int Append(tLink_list *plink_list, tStudent student)
{
	tNode *pnode = malloc(sizeof(tNode));
	if (pnode == NULL){
		printf("Error:malloc error!!\n");
		exit(0);
	}
	pnode->student = student;
	pnode->pNext = NULL;
	if (plink_list->ptail == NULL)
	{
		plink_list->phead = pnode;
		plink_list->ptail = pnode;
	}	else{
		plink_list->ptail->pNext = pnode;
		plink_list->ptail = pnode;
	}
	
	return 0;
}

int Show(tLink_list *plink_list)
{
	tNode *pnode;
	if (plink_list->phead == NULL)
	{
		printf("Void Link_list!!\n");
	}	else{
		for(pnode = plink_list->phead; pnode->pNext != NULL; pnode = pnode->pNext)
		{
			printf("%s >>> %s\n", pnode->student.school_num, pnode->student.name);
		}
		printf("%s >>> %s\n", pnode->student.school_num, pnode->student.name);
	}
	return 0;
}

tLink_list *Combine(tLink_list *plink_list_A, tLink_list *plink_list_B) // clear
{
	tLink_list *plink_list = Creat();
	plink_list = plink_list_A;
	plink_list->ptail->pNext = plink_list_B->phead;			
	plink_list->ptail = plink_list_B->ptail;
	free(plink_list_B);
	
	return plink_list;
}


tNode *Find_forenode(tLink_list * plink_list, tNode *pnode)				// clear
{
	tNode *ptemp_node;
	if (plink_list->phead == NULL ){			// handling some error
		return NULL;
	}else if (plink_list->phead == plink_list->ptail)
	{
		perror("Only one node in link_list");
		return NULL;
	}

	for (ptemp_node = plink_list->phead; ptemp_node->pNext != pnode; ptemp_node = ptemp_node->pNext) 	//find the foreonde
	{
		if (ptemp_node->pNext == NULL)
		{

			printf("ERROR : node not in Link_list!!\n");
			return NULL;
		}
	}
	
	return ptemp_node;
}

int Swap(tLink_list *plink_list, tNode *pnode_A, tNode *pnode_B)	//交换前驱和后继
{
	tNode *ptemp_node;
	tNode *ptemp_node2;
	if (plink_list->phead == NULL )
	{
		printf("ERROR:empty Link_list\n");
	}

	if (pnode_A == plink_list->phead)		//clear				//change the forenode of two nodes
	{
		if (!(ptemp_node = Find_forenode(plink_list, pnode_B))) {printf("ERROR:fingding pnode_B\n"); return -1;};
		ptemp_node->pNext = pnode_A;
		plink_list->phead = pnode_B;
	}	
	else if (pnode_B == plink_list->phead)//clear
	{
		if (!(ptemp_node = Find_forenode(plink_list, pnode_A))) {printf("ERROR:fingding pnode_A\n"); return -1;};
		ptemp_node->pNext = pnode_B;
		plink_list->phead = pnode_A;
	}	
	else
	{
		if (!(ptemp_node = Find_forenode(plink_list, pnode_A))) {printf("ERROR:fingding pnode_A\n"); return -1;};
		if (!(ptemp_node2 = Find_forenode(plink_list, pnode_B))) {printf("ERROR:fingding pnode_B\n"); return -1;};
		ptemp_node->pNext = pnode_B;
		ptemp_node2->pNext = pnode_A;
	}

	ptemp_node = pnode_A->pNext;		//change nextnode of pnode_A and pnode_B
	pnode_A->pNext = pnode_B->pNext;
	pnode_B->pNext = ptemp_node;
}

int Sort(tLink_list *plink_list)			//选择排序
{
	tNode *ptemp_node;
	tNode *ptemp_node2;

	tNode *ptemp_node3;
	
	char temp_schoolNUM[MAX];

	if (plink_list->phead == NULL){perror("Void link_list");}	//Void error
	else if (plink_list->phead == plink_list->ptail){return 0;}	//only one node, no need to sort

	for (ptemp_node = plink_list->phead; ptemp_node->pNext != plink_list->ptail; ptemp_node = ptemp_node->pNext)
	{
		strcpy(temp_schoolNUM, ptemp_node->student.school_num); //考下初始化后的ptemp_node的data
		ptemp_node3 = ptemp_node;								//记录初始化的pnode

		for (ptemp_node2 = ptemp_node->pNext; ptemp_node2 != NULL; ptemp_node2 = ptemp_node2->pNext)
		{
			if(strcmp(temp_schoolNUM, ptemp_node2->student.school_num) > 0)
			{
				ptemp_node3 = ptemp_node2; //记录
				strcpy(temp_schoolNUM, ptemp_node2->student.school_num);//记录
			}	
		}
		Swap(plink_list, ptemp_node3, ptemp_node);	// swap交换的是前驱和后继
		ptemp_node = ptemp_node3;
	}

	return 0;
}
