#include <stdio.h>
#include <stdlib.h>


typedef struct tlink_node
{
	int num;
	struct tlink_node * next;
} tnode;

typedef struct tlint_list
{
	tnode* head;
	int length;
} tlist;

tlist CreatList()
{
	tlist* plink_list = (tlist*)malloc(sizeof(tlist));
	if (plink_list == NULL) printf("MALLOC ERROR\n");
	plink_list->head = NULL;
	plink_list->length = 0;
	return  *plink_list;
}

int FreeList(tlist* plink_list)
{
	tnode* ptemp;
	while(plink_list->length > 2)
	{
		for (ptemp = plink_list->head; ptemp->next->next != NULL; ptemp = ptemp->next); //find the last one
		free(ptemp->next);
		ptemp->next = NULL;
		plink_list->length--;
	}if (plink_list->length > 1)free(plink_list->head->next); //free last but two node
	free(plink_list->head);
	free(plink_list);
	return 0;
}
int Append(tlist* plink_list, int num)
{	
	tnode* pnew_node = (tnode*)malloc(sizeof(tnode));
	tnode* ptemp;
	pnew_node->num = num;
	pnew_node->next = NULL;
	if (plink_list->head == NULL)
	{
		plink_list->head = pnew_node;
	}
	else
	{
		for (ptemp = plink_list->head; ptemp->next != NULL; ptemp = ptemp->next); //find the last one
		ptemp->next = pnew_node;
	}
	plink_list->length += 1;
	return 0;
}
int Show(tlist *plink_list)
{
	tnode *ptemp;
	if (plink_list->head == NULL) printf("Void link_list!\n");
	for (ptemp = plink_list->head; ptemp->next != NULL; ptemp = ptemp->next)
	{
		printf("number : %d\n", ptemp->num);
	}
	printf("number : %d\n", ptemp->num);
}


int main()
{
	int i, temp, m;
	tlist link_list = CreatList();
	srand(time(0));
	for (i = 0; i < 20; ++i)
	{
		temp = rand();
		Append(&link_list, temp);
	}
	//creat && show
	Show(&link_list);
	printf("enter the number \'m\':\n");
	scanf("%d", &m);
	if (m > link_list.length) printf("number \'m\' is too large!!\n");

	Adjust(&link_list, m);
	
	Show(&link_list);
	
	FreeList(&link_list);
	return 0;
}

int Adjust(tlist * plink_list, int m)
{
	if(m == plink_list->length) return 0;
	tnode *ptemp1, *ptemp2;
	int i;
	ptemp2 = plink_list->head; //store the phead
	for (ptemp1 = plink_list->head; ptemp1->next != NULL; ptemp1 = ptemp1->next);
		ptemp1->next = plink_list->head;	//find the last node
	for (i = 0; i < plink_list->length-m-1; ++i)  ptemp2 = ptemp2->next;	//find the (n - m)th node 
	plink_list->head = ptemp2->next; 						//change the head node
	ptemp2->next = NULL;									// set the tail 
	return 0;

}

int test()
{
	char flag = 'y';
	int temp, m;
	tlist link_list = CreatList();
	while(flag == 'y')
	{
		printf("Please enter your number :\n");
		scanf("%d", &temp);
		Append(&link_list, temp);
		printf("More numbers?(y/n) : \n");
		fflush(stdin);
		scanf("%c", &flag);
	}
	Show(&link_list);
	printf("enter the number \'m\':\n");
	scanf("%d", &m);
	if (m > link_list.length) printf("number \'m\' is too large!!\n");
	else{
		Adjust(&link_list, m);
		Show(&link_list);
	}
	
	return 0;
}