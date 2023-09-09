/*
 * linkedlist.c
 *
 *  Created on: Aug 24, 2023
 *      Author: ibrahim
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Snode_t* gpFirstStudent = NULL;


/*Prints all Database options*/
void Print_Options(){
	printf("\n===================================\n");
	printf("\tChoose one option\n");

	printf(" 1: Add student\n");
	printf(" 2: Delete student\n");
	printf(" 3: Print all students\n");
	printf(" 4: Delete all students\n");
	printf(" 5: Print Number of students\n");
	printf(" 6: Get Nth student\n");
	printf(" 7: Get Middle student\n");
	printf(" 8: Get Nth student from the end\n");
	printf(" 9: Reverse students\n");
	printf(" 10: Exit\n");

	printf("Enter Option Number: ");
}

Operation_status Fill_the_record(Snode_t* newStudent);
void Print_Data_Of(Snode_t* pCurrentStudent, uint32_t count);
Operation_status DatabaseIsEmpty();

void Add_Student(){


	Snode_t* pNewStudent;
	Snode_t* pLastStudent;

	//check if first time to add student
	if(!gpFirstStudent){
		pNewStudent =(Snode_t*)malloc(sizeof(Snode_t));
		gpFirstStudent = pNewStudent;
		pNewStudent->pNextStudent = NULL;
	}else{

		//Navigate to the last record
		pLastStudent = gpFirstStudent ;
		while(pLastStudent->pNextStudent)
			pLastStudent = pLastStudent->pNextStudent;

		//Add new record
		pNewStudent =(Snode_t*)malloc(sizeof(Snode_t));
		pLastStudent->pNextStudent = pNewStudent ;
		pNewStudent->pNextStudent = NULL;
	}

	//Get student Data and test id existence
	if(Fill_the_record(pNewStudent) == failed){

		//delete record
		pLastStudent->pNextStudent = NULL ;
		free(pNewStudent);

	}

}


void Delete_Student(){


	char temp_cahr[40];
	uint32_t selected_id;
	uint8_t id_found = 0;

	if(DatabaseIsEmpty() == empty)
		printf("\n=== Database is Empty ===");

	else{

		printf("\n Enter student ID: ");
		gets(temp_cahr);
		selected_id = atoi(temp_cahr);

		Snode_t* pPreviousStudent = NULL;
		Snode_t* pSelectedStudent = gpFirstStudent;

		//loop on all records to find given ID
		while(pSelectedStudent){

			if(pSelectedStudent->student.ID ==selected_id){

				id_found = 1;

				if(pPreviousStudent)
					pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
				else
					gpFirstStudent = pSelectedStudent->pNextStudent;

				//Clean the id
				pSelectedStudent->student.ID = 0;
				//free Previous record
				free((Snode_t*)pSelectedStudent);

				//inform the user of process success
				printf("\n=== student Data deleted successfully ===");
			}

			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNextStudent;
		}

		if(!id_found)printf("\n=== Wrong student ID ===");


	}

}


void Print_Students(){

	if(DatabaseIsEmpty() == empty){
		printf("\n=== Database is Empty ===");
		printf("\n=== Try Adding students to Database ===");
	}else{

		Snode_t* pCurrentStudent = gpFirstStudent;
		uint32_t count=1;
		printf("\n=== Students available in database ===");

		//Navigate on all records
		while(pCurrentStudent){

			//Display students Data
			Print_Data_Of(pCurrentStudent,count);


			//increase count
			count++;

			//move to next record
			pCurrentStudent = pCurrentStudent->pNextStudent;

		}
	}

}


void Delete_All_Students(){

	if(DatabaseIsEmpty() == empty){
		printf("\n=== Database is Empty ===");
		printf("\n=== Try Adding students to Database ===");
	}else{

		Snode_t* pCurrentStudent = gpFirstStudent;

		gpFirstStudent->pNextStudent=NULL;
		gpFirstStudent = NULL;

		while(pCurrentStudent){

			//create new pointer to be freed
			Snode_t* pPreviousStudent= pCurrentStudent;

			//move current pointer to next record
			pCurrentStudent = pCurrentStudent->pNextStudent;

			//Clean the id
			pPreviousStudent->student.ID = 0;
			//free Previous record
			free((Snode_t*)pPreviousStudent);
		}



		printf("\n       === Database Is Cleaned ===");
		printf("\n=== All Students Data Were Removed ===");
	}

}


void Print_Students_Num(){

	if(DatabaseIsEmpty() == empty){
		printf("\n=== Database is Empty ===");
		printf("\n=== Try Adding students to Database ===");
	}else{

		Snode_t* pCurrentStudent = gpFirstStudent;
		uint32_t count=0;

		//Navigate on all records
		while(pCurrentStudent){

			//increase count
			count++;

			//move to next record
			pCurrentStudent = pCurrentStudent->pNextStudent;

		}

		//print the number of students
		printf("\n=== Number Of Students In Database Is [ %d ] ===",count);

	}

}





void Get_Nth_Student(){


	if(DatabaseIsEmpty() == empty)
		printf("\n=== Database is Empty ===");

	else{

		//required variables
		char temp_cahr[40];
		uint32_t count = 1 , selected_index;
		Snode_t* pCurrentStudent = gpFirstStudent;

		//ask user for index
		printf("\n Enter student order (index) : ");
		gets(temp_cahr);
		selected_index = atoi(temp_cahr);



		//Navigate on all records to find record with given index
		while(pCurrentStudent){


			if(selected_index == count )
				break;

			//increase count
			count++;

			//move to next record
			pCurrentStudent = pCurrentStudent->pNextStudent;
		}

		if(selected_index == count ){

			printf("\n === Student Found ===\n");
			Print_Data_Of(pCurrentStudent,count);
		}else{

			printf("\n === Wrong index ===");

		}

	}
}


void Get_Mid_Student(){

	if(DatabaseIsEmpty() == empty)
		printf("\n=== Database is Empty ===");

	else{

		//required variables
		uint32_t count = 1 , middle=1;

		Snode_t* pFast = gpFirstStudent;
		Snode_t* pSlow = gpFirstStudent;


		while(pFast->pNextStudent){
			if(pFast->pNextStudent->pNextStudent){
				pFast = pFast->pNextStudent;
				pFast = pFast->pNextStudent;
				pSlow = pSlow->pNextStudent;
				count += 2;
				middle++;
			}else{
				pFast = pFast->pNextStudent;
				pSlow = pSlow->pNextStudent;
				count += 1;
				middle++;
			}

		}

		if(count > 2){

			printf("\n === Middle Student Found ===\n");
			Print_Data_Of(pSlow,middle);

		}else
			printf("\n === Minimum Number Of Students In Database ===\n=== To Find The Middle is 3 ===");

	}
}


void Get_Nth_From_End(){

	if(DatabaseIsEmpty() == empty)
		printf("\n=== Database is Empty ===");

	else{

		//required variables
		char temp_cahr[40];
		uint32_t i,count = 1 ,Num =0, selected_index;

		Snode_t* pFront = gpFirstStudent;
		Snode_t* pBack = gpFirstStudent;
		Snode_t* pTemp = gpFirstStudent;

		//ask user for index
		printf("\n Enter student order (index) : ");
		gets(temp_cahr);
		selected_index = atoi(temp_cahr);

		//get total number of students
		while(pTemp){

			//increase count
			Num++;

			//move to next record
			pTemp = pTemp->pNextStudent;

		}
		if(selected_index <= Num && selected_index > 0){

			//add distance between two pointers
			for(i=1;i<selected_index;i++){

				if(pFront){
					pFront = pFront->pNextStudent;
					count++;
				}
			}

			//Navigate on all records to find record with given index
			while(pFront->pNextStudent){

				pFront = pFront->pNextStudent;
				pBack = pBack->pNextStudent;

			}

			printf("\n === Student Found ===\n");
			Print_Data_Of(pBack,count);

		}else printf("\n === Wrong index ===");

	}

}


void Reverse_Students(){

	if(DatabaseIsEmpty() == empty){
		printf("\n=== Database is Empty ===");
		printf("\n=== Try Adding students to Database ===");
	}else{

		Snode_t* pCurrentStudent = gpFirstStudent;
		Snode_t* pPreviousStudent= pCurrentStudent;
		Snode_t* pTemp =pCurrentStudent->pNextStudent;


		while(pCurrentStudent){

			//check if database has only one record
			if(!(gpFirstStudent->pNextStudent))
				break;


			pCurrentStudent = pTemp;
			pTemp = pTemp->pNextStudent;


			if(pTemp){
				pCurrentStudent->pNextStudent = pPreviousStudent;

				if(pPreviousStudent == gpFirstStudent)
					pPreviousStudent->pNextStudent = NULL;


				pPreviousStudent = pCurrentStudent;


			}else{

				if(pPreviousStudent == gpFirstStudent)
					pPreviousStudent->pNextStudent = NULL;

				//make the end the beginning
				gpFirstStudent = pCurrentStudent;

				//reverse
				pCurrentStudent->pNextStudent = pPreviousStudent;

				break;
			}

		}


		printf("\n=== Database Is Reversed ===");
	}

}



Operation_status Fill_the_record(Snode_t* newStudent){

	char temp_char[40];
	uint32_t temp_ID;
	Snode_t* pCheck = gpFirstStudent;
	Operation_status fill_process_status = No_error;


	printf("\n Enter student ID: ");
	gets(temp_char);
	temp_ID = atoi(temp_char);

	//Check if the ID already exists before adding it
	while(pCheck){

		if(pCheck->student.ID == temp_ID){
			printf("\nID Already EXists. Try again ");
			printf("\n===================================");
			fill_process_status = failed;
			return fill_process_status;
		}else
			pCheck = pCheck->pNextStudent;
	}

	if(fill_process_status == No_error){
		//Add new ID
		newStudent->student.ID = temp_ID;

		printf("\n Enter student Name: ");
		gets(newStudent->student.name);

		printf("\n Enter student Height in cm: ");
		gets(temp_char);
		newStudent->student.height = atof(temp_char);


		printf("\n=== Student Data are added successfully ===");

	}

	return fill_process_status;

}

void Print_Data_Of(Snode_t* pCurrentStudent, uint32_t count){

	printf("\n\tStudent #%d: ",count);
	printf("\nID: %d",pCurrentStudent->student.ID);
	printf("\nName: %s",pCurrentStudent->student.name);
	printf("\nHeight: %0.3f cm",pCurrentStudent->student.height);
	printf("\n===================");

}

Operation_status DatabaseIsEmpty(){

	if(!gpFirstStudent)
		return empty;

	else
		return No_error;
}

