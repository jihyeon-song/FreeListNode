/*
 * libbf.c
 *
 *  Created on: Mar 8, 2017
 *      Author: song
 */

#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE		4096
#define BF_HASH_TBL_SIZE 20


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

typedef struct BFhash_entry {
  struct BFhash_entry *nextentry;     /* next hash table element or NULL */
  struct BFhash_entry *preventry;     /* prev hash table element or NULL */
  int fd;                             /* file descriptor                 */
  int pageNum;                        /* page number                     */
  struct BFpage *bpage;               /* ptr to buffer holding this page */
} BFhash_entry;

typedef struct _buffer_request_control {
    int         fd;                     /* PF file descriptor */
    int         unixfd;                 /* Unix file descriptor */
    int         pagenum;                /* Page number in the file */
    bool_t      dirty;                  /* TRUE if page is dirty */
} BFreq;

void BF_Init() {
/*
 * initializes the BF layer
 * creates all the buffer entries and add them to the free list
 * Initializes the hash table
 * first function to call in order to use the BF layer
 */

	BFpage *BFpage = (BFpage *)malloc(sizeof(BFpage));
	if(!BFpage) {
		printf("memory error");
		exit(1);
	}

//	BFpage->count
//	BFpage->dirty
//	BFpage->fd
//	BFpage->fpage
//	BFpage->nextpage
//	BFpage->pageNum
//	BFpage->prevpage


	void DLLInsert(BFpage *Bfpage, /*data, position(first always*/) {

	}




	BFhash_entry *BFhash = (BFhash_entry *)malloc(sizeof(BFhash_entry)*BF_HASH_TBL_SIZE);
	if(!BFhash) {
		printf("memory error");
		exit(1);
	}

	for(int i=0; i<BF_HASH_TBL_SIZE; i++) {
		BFhash[i].nextentry= NULL;
	}

//	BFhash->bpage
//	BFhash->fd
//	BFhash->nextentry
//	BFhash->pageNum
//	BFhash->preventry



}

int BF_GetBuf(BFreq bq, PFpage **fpage) {
/*
 * returns a PF page
 * This memory block stores a file page associated with a PF file descriptor and a page number passed over in the buffer control block bq.
 * the file page is read into the buffer page, its pin count is set to one, and its dirty flag is set to FALSE, and other appropriate fields of the buffer entry are set accordingly
 * In both the cases, the page becomes the most recently used.
 * This function returns BFE_OK if the operation is successful, an error condition otherwise.
 */

	BFpage *BFpage = BF_Init();



//	bq.dirty
//	bq.pagenum
//	bq.unixfd
//	bq.fd

	if(/*buffer page is already in the buffer pool*/) {
		BFpage->count ++;
	} else {
		if(/*free page*/) {
			/* new buffer allocated*/
			BFpage->count ++;
		} else {
			/*page replacement*/
			BFpage->count ++;
		}
	}

	return *fpage;

}

int BF_AllocBuf(BFreq bq, PFpage **fpage) {
	BFpage *BFpage = BF_Init();
	BFpage->count = 1;
	BFpage->dirty = FALSE;


	fpage->pagebuf



//	bq.dirty
//	bq.pagenum
//	bq.unixfd
//	bq.fd
}

int BF_UnpinBuf(BFreq bq) {
	BFpage *BFpage = BF_Init();

	if(BFpage->pageNum<bq.pagenum) {
		BFpage->count = 1;
	}
}

int BF_TouchBuf(BFreq bq) {
	bq.dirty = TRUE;


//	bq.pagenum
//	bq.unixfd
//	bq.fd
}

int BF_FlushBuf(int fd) {

}

int BF_ShowBuf() {
/*
 * displays the status of the LRU list
 * the number of pages in the LRU list
 * identification and the dirty flag of each individual buffer page
 */


}

