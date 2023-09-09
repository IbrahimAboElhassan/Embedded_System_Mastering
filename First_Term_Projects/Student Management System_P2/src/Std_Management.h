/*
 * Std_Management.h
 *
 *  Created on: Sep 4, 2023
 *      Author: ibrahim
 */

#ifndef STD_MANAGEMENT_H_
#define STD_MANAGEMENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50
#define COURSES_NUMBERS 5

typedef struct Sinfo {
    char student_first_name[NAME_LENGTH];
    char student_last_name[NAME_LENGTH];
    int student_ID;
    float student_GPA;
    int student_courses_ids[COURSES_NUMBERS];
}Item;

typedef struct {
    Item* base;
    Item* tail;
    Item* head;
    int length;
    int counter;
} Fifo_buf;

typedef enum {
    FIFO_No_error,
    FIFO_Empty,
    FIFO_Full,
    FIFO_Null,
    FIFO_NOT_Full,
    FIFO_NOT_Empty
}Fifo_status;

Fifo_status List_is_full(Fifo_buf* student);
Fifo_status List_is_empty(Fifo_buf* student);
void Add_Data_From_File(Fifo_buf* student, char* read_date);
Fifo_status System_init(Fifo_buf* student, Item* list, int length);
Fifo_status Add_Students_Manually(Fifo_buf* student);
void Search_By_first_name(Fifo_buf* student);
void Search_about_course_id(Fifo_buf* student);
void Search_By_ID(Fifo_buf* student);
void Total_number_of_students(Fifo_buf* student);
void Delete_student_By_id(Fifo_buf* student);
void Update_student_info(Fifo_buf* student);
void Top_students(Fifo_buf* student);
void Show_all_number(Fifo_buf* student);

#endif /* STD_MANGEMENT_H_ */

