/*
 ============================================================================
 Name        : main.c
 Author      : Ibrahim Abo Elhassan
 Description : program for student management system
 ============================================================================
 */

#include "Std_Management.h"

    FILE*File_data = NULL;
    char read_date[81];

int main()
{
    Item student_list[MAX_STUDENTS];
    Fifo_buf students;
    Fifo_status init_status  = System_init(&students, student_list, MAX_STUDENTS);

    int result;
    char read_date[81];


    if (init_status == FIFO_No_error) {
        int choice;

        while (1) {
            printf("  == Welcome in our system management ==\n");
            printf("\t\t## Our Menu ## \n");
            printf("\t1.  Add Student from file\n");
            printf("\t2.  Add Student Manually\n");
            printf("\t3.  Find student info from his first name\n");
            printf("\t4.  Find student info from his id\n");
            printf("\t5.  Find student registered in specific course id\n");
            printf("\t6.  Delete student by his id\n");
            printf("\t7.  Update student info \n");
            printf("\t8.  Show all number\n");
            printf("\t9.  Top students \n");
            printf("\t10. Total number of students\n");
            printf("\t11. Exit\n");
            printf("\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            printf("-----------------------\n");
            printf("\n");

            switch (choice) {
                case 1:
                    if (students.counter < students.length) {
                        FILE* File_data = fopen("info_data.txt", "r");
                        if (File_data) {
                            char read_date[81];
                            while (fgets(read_date, sizeof(read_date), File_data) != NULL) {
                                read_date[sizeof(read_date) - 1] = '\0';
                                Add_Data_From_File(&students, read_date);
                            }

                            int result = fclose(File_data);
                            if (result == 0) {
                            printf(" Data added from file successfully \n");
                            Total_number_of_students(&students);
                            printf("\n");
                            } else {
                            printf("Error closing the file.\n");
                            }
                        } else {
                        printf("File not opened successfully.\n");
                        }
                    } else {
                        printf("Cannot add more students, the list is full.\n");
                    }
                    break;
                case 2:
                    Add_Students_Manually(&students);
                    Total_number_of_students(&students);
                    break;
                case 3:
                    Search_By_first_name(&students);
                    break;
                case 4:
                    Search_By_ID(&students);
                    break;
                case 5:
                    Search_about_course_id(&students);
                    break;
                case 6:
                    Delete_student_By_id(&students);
                    break;
                case 7:
                    Update_student_info(&students);
                    break;
                case 8:
                    Show_all_number(&students);
                    break;
                case 9:
                    Top_students(&students);
                    break;
                case 10:
                    Total_number_of_students(&students);
                    break;

                case 11:
                    char cch;
                    printf("Are you sure you want to exit our system? (y/n): ");
                    getchar();
                    scanf("%c", &cch);
                    if (cch == 'y' || cch == 'Y') {
                        printf("== Goodbye ==\n");
                        return 0;
                    } else {
                        break;
                    }

                default:
                    printf("Wrong choice. Please choose again.\n");
                    printf("\n");
            }
        }
    } else {
        printf("Initialization failed.\n");
    }

    return 0;
}


