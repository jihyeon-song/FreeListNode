/*
 * FreeList.c
 *
 *  Created on: Mar 15, 2017
 *      Author: song
 */


#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE		4096


typedef struct PFpage {
    char pagebuf[PAGE_SIZE];
} PFpage;

typedef struct BFpage {
  PFpage         fpage;       /* page data from the file                 */
  struct BFpage  *nextpage;   /* next in the linked list of buffer pages */
  struct BFpage  *prevpage;   /* prev in the linked list of buffer pages */
  bool_t         dirty;       /* TRUE if page is dirty                   */
  short          count;       /* pin count associated with the page      */
  int            pageNum;     /* page number of this page                */
  int            fd;          /* PF file descriptor of this page         */
} BFpage;

typedef struct FreeListNode {
	BFpage BFpage;
	struct FreeListNode *next;
} FreeListNode;

void InsertInFreeList(FreeListNode **head, BFpage bfpage, int position) {
	int k = 1;
	FreeListNode *p, *q, *newNode;
	newNode = (FreeListNode *)malloc(sizeof(FreeListNode));
	if(!newNode) {
		printf("memory error");
		exit(1);
	}

	newNode->BFpage = bfpage;
	p = *head;

	if(position == 1) {
		newNode->next = p;
		*head = newNode;
	} else {
		while((p != NULL) && (k<position)) {
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}

}

void DeleteFromFreeList(FreeListNode **head, int position) {
	int k = 1;
	FreeListNode *p, *q;

	if(*head == NULL) {
		printf("empty list");
		return;
	}

	p = *head;

	if(position == 1) {
		*head = (*head)->next;
		free(p);
		return;
	} else {
		while((p != NULL) && (k<position)) {
			k++;
			q = p;
			p = p->next;
		}
		if(p == NULL) {
			printf("non-exist position");
		} else {
			q->next = p->next;
			free(p);
		}
	}
}
