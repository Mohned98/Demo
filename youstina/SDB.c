#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "STD.h"
#include "SDB.h"












bool SDB_IsFull (struct node* head)
{
	int size = getSize(head);
	if (size>=10)
		return true;

	else
		return false ;

}
uint8 SDB_GetUsedSize(struct node* head)
{
	int size = getSize(head);

	return size;

}
bool SDB_AddEntry(student data,struct node* head)
{
	if(SDB_IsFull (head)== true)
	{
		printf("database is full");
		return false;
	}
	else
	{
		insertatend(data);
		return true;
	}

}

void SDB_DeletEntry (uint32 id)
{
	deletenode(id);
}
bool SDB_ReadEntry (uint32 id)
{int chk = display(id);
	if( chk)
	{
		return true;
	}
	else
		return false ;

}
void SDB_GetList ()
{
	printList();
}



bool SDB_IsIdExist (uint32 id)
{
	int chk = searchlist(id);
		if( chk)
		{
			return true;
		}
		else
			{return false ;}
}
