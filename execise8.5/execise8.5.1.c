
#include <stdio.h>
#include <stdlib.h>
typedef struct tlink_node
{
	int num;
	struct tlink_node * next;
} tnode;

typedef struct tlink_list
{
	tnode* head;
	int length;
} tlist;

tlist CreatList()
{
	tlist* plink_list = (tlist*)malloc(sizeof(tlist));
	if (plink_list == NULL) printf("MALLOC ERROR\n");   // at first there is no datas in the linktable so it can't loop
	plink_list->head = NULL;
	plink_list->length = 0;
	return  *plink_list;
}

int FreeList(tlist* plink_list)
{
	tnode* ptemp;
	while(plink_list->length > 2)
	{
		for (ptemp = plink_list->head; ptemp->next->next != plink_list->head; ptemp = ptemp->next); //find the last one
		free(ptemp->next);
		ptemp->next = plink_list->head;
		plink_list->length--;
	}
	if (plink_list->length == 2)
	{
		free(plink_list->head->next);
		plink_list->length--;
	} //free last but two node
	else if (plink_list->length == 1){
		free(plink_list->head);
		plink_list->length = 0;
	}
	free(plink_list);
	return 0;
}
int Append(tlist* plink_list, int num)
{	
	tnode* pnew_node = (tnode*)malloc(sizeof(tnode));
	if (pnew_node == NULL) printf("MALLOC ERROR!!\n");
	tnode* ptemp;
	pnew_node->num = num;
	pnew_node->next = NULL; 	//set the list to allow it looping
	if (plink_list->head == NULL)
	{
		plink_list->head = pnew_node;
		plink_list->head->next = plink_list->head;
	}
	else
	{
		pnew_node->next = plink_list->head;
		for (ptemp = plink_list->head; ptemp->next != plink_list->head; ptemp = ptemp->next); //find the last one
		ptemp->next = pnew_node;
	}
	plink_list->length += 1;
	return 0;
}

int Dlete(tlist * plink_list, int num)
{
	tnode *ptemp = NULL;
	tnode *ptemp_sub;
	int i;
	/*if (plink_list->length < num)
	{
		printf("%s\n", "ERROR:the number istoo big!!");
		return 1;
	}
	else*/ ptemp = plink_list->head;
	if (num == 1)
	{
		
		plink_list->head = ptemp->next;
		free(ptemp);
		plink_list->length--;
	}
	else if (num > 1)
	{
		for (i = 1; i < num - 1; ++i)  ptemp = ptemp->next; //find the NO.i - 1 node and delete it
		ptemp_sub = ptemp->next;
		ptemp->next = ptemp->next->next;
		free(ptemp_sub);
		plink_list->length--;
	}

}
int Show(tlist *plink_list)
{
	tnode *ptemp;
	if (plink_list->head->next == NULL) 

	{
			printf("Void link_list!\n");
			return 1;
	}

	for (ptemp = plink_list->head; ptemp->next != plink_list->head; ptemp = ptemp->next)
	{
		printf("number : %d\n", ptemp->num);
	}
	printf("number : %d\n", ptemp->num);
	return 0;
}
tnode *Getnode(tlist * plink_list, int num)
{
	int i;
	tnode *ptemp = plink_list->head;
	/*if (plink_list->length == 0)
	{
		printf("Void link_list!!\n");
		
	}
	else if(plink_list->length < num)
	{
		printf("ERROR: the number is too large!!\n");
		
	}*/
	
	{
		for (i = 1; i < num; ++i)  ptemp = ptemp->next; //find the NO.i node 
	    return ptemp;
	}
}



int main()
{
	int i, temp, m;
	tnode *ptemp;
	tlist link_list = CreatList();
	srand(time(0));
	for (i = 0; i < 13; ++i)
	{
		temp = rand();
		Append(&link_list, temp);
	}
	Show(&link_list);
	while(link_list.length > 1)
	{
		ptemp = Getnode(&link_list, 4);
		Dlete(&link_list, 3);
		link_list.head = ptemp;
	}
	printf("\nThe last one:\n");
	Show(&link_list);
	FreeList(&link_list);
	return 0;
}