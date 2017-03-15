#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PAGE_SIZE		4096



typedef struct PFhdr_str {
    int    numpages;      /* number of pages in the file */
} PFhdr_str;

typedef struct PFpage {
    char pagebuf[PAGE_SIZE];
} PFpage;

typedef struct PFftab_ele {
    bool_t    valid;       /* set to TRUE when a file is open. */
    ino_t     inode;       /* inode number of the file         */
    char      *fname;      /* file name                        */
    int       unixfd;      /* Unix file descriptor             */
    PFhdr_str hdr;         /* file header                      */
    short     hdrchanged;  /* TRUE if file header has changed  */
} PFftab_ele;

void PF_Init(void) {
	BF_Init();

	PFftab_ele *PFftab = (PFftab_ele *)malloc(sizeof(PFftab_ele));
	if(!PFftab) {
		printf("memory error");
		exit(1);
	}

	PFftab->fname
	PFftab->hdr
	PFftab->hdrchanged
	PFftab->inode
	PFftab->unixfd
	PFftab->valid


}

int PF_CreateFile (char *filename) {
/*
 * creates a file named filename
 * The system call open() is used to create the file, the PF file header is initialized and written to the file, and the file is closed using the close() system call.
 */


	PFftab_ele *PFftab = PF_Init();
	PFftab->fname = filename;
	PFftab->hdr


	int filedesc = open("filename", O_CREAT | O_EXCL);
	if(filedesc<0) {
		return 1;
	}
	if(close(filedesc)<0) {
		return 1;
	}

}

int PF_DestroyFile (char *filename) {

}

int PF_OpenFile (char *filename) {
	PFftab_ele *PFftab = PF_Init();
	int filedesc = open("filename", O_RDONLY);

	PFftab->fname = filename;
//	PFftab->hdr
	PFftab->hdrchanged = FALSE;
//	PFftab->inode
//	PFftab->unixfd
	PFftab->valid = TRUE;

	int filetableentry = PFftab->inode;
	return filetableentry

}

int PF_CloseFile (int fd) {
	int close = close(fd);


}

int PF_AllocPage (int fd, int *pageNum, char **pagebuf) {

}

int PF_GetNextPage (int fd, int *pageNum, char **pagebuf) {

}

int PF_GetFirstPage(int fd, int *pageNum, char **pagebuf) {

}

int PF_GetThisPage (int fd, int pageNum, char **pagebuf) {

}

int PF_DirtyPage(int fd, int pageNum) {

}

int PF_UnpinPage(int fd, int pageNum, int dirty) {

}

