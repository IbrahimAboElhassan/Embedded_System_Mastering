/*
 * std_mangement.c
 *
 *  Created on: Sep 4, 2023
 *      Author: ibrahim
 */


#include "Std_Management.h"

Fifo_status List_is_full(Fifo_buf* student)
{
    if(!student || !student->base || !student->head || ! student->tail)
    {
        printf("List is NULL \n");
        return FIFO_Null;
    }


    if(student->counter == student->length)
    {
        return FIFO_Full;
    }

    return FIFO_NOT_Full;
}


Fifo_status List_is_empty(Fifo_buf* student)
{
    if(!student || !student->base || !student->head || ! student->tail)
    {
        printf("List is NULL \n");
        return FIFO_Null;
    }

    if(student->counter == 0)
    {
        return FIFO_Empty;
    }

    return FIFO_NOT_Empty;
}


void Add_Data_From_File(Fifo_buf* student, char* read_date)
{

    if (List_is_full(student) == FIFO_Full) {
        printf("[ERROR] Cannot add new students The list is full.\n");
    }

    Item new_std;
    sscanf(read_date, "%d %49s %49s %f %d %d %d %d %d",
           &new_std.student_ID, new_std.student_first_name, new_std.student_last_name, &new_std.student_GPA,
           &new_std.student_courses_ids[0], &new_std.student_courses_ids[1], &new_std.student_courses_ids[2], &new_std.student_courses_ids[3], &new_std.student_courses_ids[4]);

    for (int i = 0; i < student->counter; i++) {
        if (new_std.student_ID == student->base[i].student_ID) {
            return;
        }
    }

    if (student->counter < student->length) {
        student->base[student->counter] = new_std;
        student->counter++;
    }
}


Fifo_status System_init(Fifo_buf* student, Item* list, int length)
{
    if (!student || !list || length <= 0) {
        printf("Failed init \n");
        return FIFO_Null;
    }

    student->base = list;
    student->head = student->base;
    student->tail = student->base;
    student->length = length;
    student->counter = 0;

    return FIFO_No_error;
}

Fifo_status Add_Students_Manually(Fifo_buf* student)
{
    Item* std = student->base;
    Item new_std;

    if (List_is_full(student) == FIFO_Full)
        {
            printf("[ERROR] No need enough students The list is full.\n");
            return FIFO_No_error;
        }

    printf("Enter your ID: ");
    scanf("%d", &new_std.student_ID);

    for (int i = 0; i < student->counter; i++) {
        if (new_std.student_ID == std->student_ID)
        {
            printf("This id is already taken.\n");
            return FIFO_No_error;
        }
        std++;
    }

    printf("Enter your First Name: ");
    scanf("%s", new_std.student_first_name);
    printf("Enter your Last Name: ");
    scanf("%s", new_std.student_last_name);

    printf("Enter your course id:\n");
    for (int i = 0; i < 5; i++) {
        int temp;
        int already_registered = 0;

        printf("Course %d : ",i+1);
        scanf("%d", &temp);

        for (int j = 0; j < i; j++) {
            if (new_std.student_courses_ids[j] == temp) {
                printf("You are already registered in this course.\n");
                already_registered = 1;
                i--;
                break;
            }
        }

        if (!already_registered) {
            new_std.student_courses_ids[i] = temp;
        }
    }

    float test = 0.0;
    do {
        printf("Enter your GPA (out of 4): ");
        scanf("%f", &test);
        if (test > 4.00 || test < 0.00) {
            printf("Please, try again !!\n");
        }
    } while (test > 4.00 || test < 0.00);

    printf("\n");
    printf("=== Thanks for your registration ===\n");

    new_std.student_GPA = test;

    student->base[student->counter] = new_std;
    student->counter++;

    return FIFO_No_error;
}


void Search_By_first_name(Fifo_buf* student)
{
    char name[50];
    int nameFound = 0;

    if (List_is_empty(student) == FIFO_Empty) {
        printf("[ERROR] The student list is empty and your request can't achieve \n");
        printf("\n");
        return;
    }
    if (List_is_full(student) == FIFO_Full) {
        printf("[ERROR] The student list is full and your request can't achieve \n");
        printf("\n");
        return;
    }

    printf("Enter a first name: ");
    scanf("%s", name);

    for (int i = 0; i < student->counter; i++) {
        if (strcmp(name, student->base[i].student_first_name) == 0) {
            printf("Detailed info related to name [%s]:\n", name);
            printf("\tID: %d\n", student->base[i].student_ID);
            printf("\tFirst Name: %s\n", student->base[i].student_first_name);
            printf("\tLast Name: %s\n", student->base[i].student_last_name);
            printf("\tGPA: %.2f\n", student->base[i].student_GPA);
            printf("\tCourses IDS: \n");
            for (int j = 0; j < 5; j++) {
                printf("\tCourse %d : %d\n", j+1 , student->base[i].student_courses_ids[j]);
            }
            printf("=================================\n");
            printf("\n");

            nameFound = 1; // Set the flag since the name is found in at least one student's record
        }
    }

    if (!nameFound) {
        printf("This name [%s] is not found \n", name);
        printf("\n");
    }
}


void Search_about_course_id(Fifo_buf* student)
{
    int c_id;

    if (List_is_empty(student) == FIFO_Empty) {
        printf("[ERROR] The student list is empty and your request can't achieve \n");
        printf("\n");
        return;
    }

    printf("Enter course id: ");
    scanf("%d", &c_id);

    int courseFound = 0;
    int studentsInCourse = 0;

    printf("Students registered in this course: \n");
    for (int i = 0; i < student->counter; i++) {
        Item* Current_student = &student->base[i];

        for (int j = 0; j < 5; j++) {
            if (Current_student->student_courses_ids[j] == c_id) {
                printf("\tFirst Name: %s\n", Current_student->student_first_name);
                printf("\tLast Name: %s\n", Current_student->student_last_name);
                printf("\tID: %d\n", Current_student->student_ID);
                printf("\tGPA: %0.2f\n", Current_student->student_GPA);

                courseFound = 1;
                studentsInCourse++;
                break;
            }
        }
    }

    if (!courseFound) {
        printf("This course id [%d] is NOT Found \n", c_id);
    }
    else{
        printf("Total number in this course %d\n", studentsInCourse); // Display the correct count
    }

    printf("================================\n");
    printf("\n");
}



void Total_number_of_students(Fifo_buf* student)
{
    int count = student->counter;
    int size = student->length;

    printf("[NOTE] Total students: %d\n", count);
    printf("[NOTE] You can add %d more students.\n", size - count);
    printf("==================================\n");
    printf("\n");
}

void Search_By_ID(Fifo_buf* student)
{
    int id;

    if (List_is_empty(student) == FIFO_Empty)
        {
            printf("[NOTE] The student list is empty and your request can't achieve.\n");
            printf("\n");
            return;
        }

    printf("Enter an id: ");
    scanf("%d", &id);

    if (List_is_empty(student) == FIFO_Empty)
        {
            printf("[NOTE] The student list is empty and your request can't achieve.\n");
            printf("\n");
            return;
        }

    for (int i = 0; i < student->counter; i++)
    {
        if (student->base[i].student_ID== id)
        {
            printf("Detailed info related to id %d:\n", id);
            printf("ID: %d\n", student->base[i].student_ID);
            printf("First Name: %s\n", student->base[i].student_first_name);
            printf("Last Name: %s\n", student->base[i].student_last_name);
            printf("GPA: %.2f\n", student->base[i].student_GPA);
            for(int j=0 ; j<5 ;j++)
            {
                printf("course : %d\n",student->base[i].student_courses_ids[j]);
            }
            printf("=================================\n");
            printf("\n");
            return;
        }
    }

    printf(" This id [%d] is not found.\n", id);
    printf("\n");
}


void Delete_student_By_id(Fifo_buf* student)
{
    int id_delete;

    if (List_is_empty(student) == FIFO_Empty)
        {
            printf("[NOTE] The student list is empty and your request can't achieve.\n");
            printf("\n");
            return;
        }

    printf("Enter an id to delete: ");
    scanf("%d", &id_delete);

    for (int i = 0; i < student->counter; i++) {
        if (student->base[i].student_ID == id_delete) {
            // Move the last student to the deleted student's position
            student->base[i] = student->base[student->counter - 1];
            student->counter--;
            printf("Student with ID %d deleted \n", id_delete);
            printf("=============================\n");
            printf("\n");
            return;
        }
    }

    printf("This ID [%d]  is Not FOUND to delete it \n", id_delete);
    printf("\n");
}


void Update_student_info(Fifo_buf* student)
{
    int id, ch;
    Item *new_std = student->base;

    if (List_is_empty(student) == FIFO_Empty)
        {
            printf("[NOTE] The student list is empty and your request can't achieve.\n");
            printf("\n");
            return;
        }

    printf("Enter an id: ");
    scanf("%d", &id);

    for (int i = 0; i < student->counter; i++)
        {
        if (student->base[i].student_ID == id) {
            Item* up_std = &student->base[i];  // Pointer to the student for updating
            printf("1. First name\n");
            printf("2. Last name\n");
            printf("3. ID\n");
            printf("4. GPA\n");
            printf("5. courses id\n");
            printf("Please choose which data to update: ");
            scanf("%d", &ch);

            switch (ch) {
                case 1:
                    printf("Enter a first name: ");
                    scanf("%s", up_std->student_first_name);
                    printf("\tUpdate First Name [%s] is DONE Successfully \n",up_std->student_first_name);
                    printf("\t========================================================\n");
                    break;
                case 2:
                    printf("Enter a last name: ");
                    scanf("%s", up_std->student_last_name);
                    printf("\tUpdate Last Name [%s] is Done Successfully\n",up_std->student_last_name);
                    printf("\t======================================================== \n");
                    break;
                case 3:
                    int new_id;
                    int Is_unique;  //use it as a flag

                    do {
                        Is_unique = 1;
                        printf("Enter a new id: ");
                        scanf("%d", &new_id);

                        // Check if the new ID already exists in the list
                        for (int i = 0; i < student->counter; i++) {
                            if (i != up_std - student->base && student->base[i].student_ID == new_id) {
                                printf("This id is already taken. Please enter a different ID.\n");
                                Is_unique = 0; // Set the flag to indicate the ID is not unique
                    break;} }

                    } while (!Is_unique);

                    up_std->student_ID = new_id;

                    printf("\t Update New Id [%d] is Done Successfully\n", up_std->student_ID);
                    printf("\t======================================================== \n");
                    break;
                case 4:
                    printf("Enter a new GPA: ");
                    scanf("%f", &up_std->student_GPA);
                    printf("\tUpdate New Id [%f] is Done Successfully\n",up_std->student_GPA);
                    printf("\t======================================================== \n");
                    break;
                case 5:
                    printf("Enter the course ID number to update (1-5): ");
                    int NO_c;
                    scanf("%d", &NO_c);

                    if (NO_c < 1 || NO_c > 5) {
                        printf("[ERROR] Try Again !! \n");
                        break;
                    }

                    int new_c_id;
                    printf("Enter the new course id: ");
                    scanf("%d", &new_c_id);

                    // Check if the new course ID is already registered
                    int already_registered = 0;
                    for (int i = 0; i < 5; i++) {
                        if (i != NO_c - 1 && up_std->student_courses_ids[i] == new_c_id) {
                        printf("[NOTE] You are already registered in \n");
                        already_registered = 1;
                        break;}
                    }

                    if (!already_registered) {
                        up_std->student_courses_ids[NO_c - 1] = new_c_id;
                        printf("\tUpdate New Course id [%d] is DONE Successfully\n",new_c_id);
                        printf("\t======================================================== \n");
                    }


                    break;

                default:
                    printf("Wrong choice. update failed.\n");
            }
            return;
        }
    }

    printf("Student with id number [%d] not found.\n", id);
    printf("=========================================\n");
    printf("\n");
}

void Show_all_number(Fifo_buf* student)
{
    int count = 1;
    Item* travers = student->base;

    if(student->counter == 0)
    {
        printf("\tNo one registered yet .. The students list is empty \n");
    }
    for (int i = 0; i < student->counter; i++) {
        printf("==== data of student #%d ====\n",i+1);
        printf("first name : %s\n", travers->student_first_name);
        printf("last name : %s\n", travers->student_last_name);
        printf("id : %d\n", travers->student_ID);
        printf("gpa: %.2f\n", travers->student_GPA);
        printf("His courses ids that registered in: \n");
        for (int j = 0; j < 5; j++) {
            printf("course No.%d : %d\n", j+1 , travers->student_courses_ids[j]);
        }
        printf("________________________________________\n");
        travers++;
    }
    printf("\n");
}



void Top_students(Fifo_buf* student)
{
    int test=0;
    Item* top_std = student->base;

    if (List_is_empty(student) == FIFO_Empty)
        {
            printf("[NOTE] The student list is empty and your request can't achieve.\n");
            printf("\n");
            return;
        }

    printf("=== Our Honor Board ===\n");
    for (int i = 0; i < student->counter; i++)
    {
        if(top_std->student_GPA >= 3.5)
        {

            printf("**First name %s \n",top_std->student_first_name);
            printf("  Last name %s \n",top_std->student_last_name);
            printf("  ID %d \n",top_std->student_ID);
            printf("  GPA %0.2f \n",top_std->student_GPA);

            test = 1;
        }
        top_std++;
    }
    printf("=========================================\n");
    printf("\n");
    if(!test)
    {
        printf("Our students need more effort.\n");
        printf("\n");
    }

}


