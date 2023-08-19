#ifndef HELPERSDB_H_
#define HELPERSDB_H_

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;

//////////////////////////

typedef enum {
	false,
	true
} bool;

///////////////////////////////

typedef struct {
	uint32 student_ID;
	uint32 student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;

} simpleDb;

////////////////////////////////

void SDB_action(uint8);

bool SDB_AddEntry();

uint8 SDB_GetUsedSize();

bool SDB_ReadEntry(uint32);

bool SDB_IsIdExist(uint32);

void SDB_DeletEntry(uint32);

bool scan_clr_buf(uint32*);	//a function that is used to scan from the user and to clear the buffer in case of wrong entry to prevent infinite loop

void keep_in_loop(bool*); // gets the address of a flag and call scan_clr_buf and change the flag to stay in the calling function loop or to exit

/////////////////////////////////

#endif
