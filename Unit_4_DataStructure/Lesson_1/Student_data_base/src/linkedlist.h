/*
 * linkedlist.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ibrahim
 */


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stdint.h"

typedef struct {
    char name[40];
    uint32_t ID;
    float height;
} Sdata;

typedef struct Sstudent {
    Sdata student;
    struct Sstudent* pNextStudent;
} Snode_t;

typedef enum {
    No_error,
    Full,
    empty,
    failed,
} Operation_status;

typedef enum {
    AddStudent = 1,
    DeleteStudent,
    PrintStudents,
    DeleteAllStudents,
    PrintStudentsNum,
    GetNthStudent,
    GetMidStudent,
    GetNthFromEnd,
    ReverseStudents,
    Exit,
} Database_Options;

void Add_Student();
void Delete_Student();
void Print_Students();
void Delete_All_Students();
void Print_Students_Num();
void Get_Nth_Student();
void Get_Mid_Student();
void Get_Nth_From_End();
void Reverse_Students();

#endif // LINKEDLIST_H

