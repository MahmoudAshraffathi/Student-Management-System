/*
 ============================================================================
 Name        : Project_C.c
 Author      : Mahmoud Ashraf 
 Version     :
 Copyright   : Abo_Ashraf
 Description : Project_C
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/*          Decleration Variable             */

struct Student_t{
	int id ;
	char name[50];
	int age ;
	float gpa ;
};

struct node {
	struct Student_t data ;
	struct node *next ;
};
struct node *head = NULL ;
/*          function decleration               */
void addStudent(const struct Student_t *const ptr);
void displayStudent(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);

int main(void) {
	char choice = 0 ;
	while(1){

		printf("------------------------------------------------\n");
		printf("1. Add Student \n");
		printf("2. Display Student \n");
		printf("3. Search Student \n");
		printf("4. Delete Student \n");
		printf("5. Calculate Avarage GPA \n");
		printf("6. Search for Student with Highest GPA \n");
		printf("7. Update student : \n");
		printf("8. Exit \n");
		printf("------------------------------------------------\n");
		fflush(stdout);
		scanf("%d",&choice);
		switch(choice){
		case 1:
			struct Student_t new_Data ;
			printf("enter student Name :\n");
			fflush(stdout);
			scanf("%s",new_Data.name);
			printf("enter Student age :\n ");
			fflush(stdout);
			scanf("%d",&new_Data.age);
			printf("enter Student ID :\n ");
			fflush(stdout);
			scanf("%d",&new_Data.id);
			printf("please enter Student GPA :\n");
			fflush(stdout);
			scanf("%f",&new_Data.gpa);
			addStudent(&new_Data);
			break ;
		case 2:
			displayStudent();
			break ;
		case 3 :
			int id ;
			printf("Enter ID \n ");
			fflush(stdout);
			scanf("%d",&id);
			searchStudentByID(id);
			break ;
		case 4 :
			int enterd_ID = 0 ;
			printf("Enter new ID \n ");
			fflush(stdout);
			scanf("%d",&enterd_ID);
			deleteStudent(enterd_ID);
			break ;
		case 5 :
			float avarage =0.0 ;
			avarage= calculateAverageGPA();
			printf("Avarge GPA :%f\n ",avarage);
			break ;
		case 6 :
			searchHighestGPA();
			break ;
		case 7 :
			int ID_Student ;
			printf("enter student ID : \n");
			fflush(stdout);
			scanf("%d",&ID_Student);
			updateStudent(ID_Student);
			break ;
		case 8 :
			exit(1);
			break ;
		default :
			printf("your choice is incorrect !! \n ");
			break ;

		}

	}
	return EXIT_SUCCESS;
}
/*
 **arguments constant pointer to struct Student_t
 **variable New_Student , checkStudentID
 **this function use for adding student in linked list
 **return void
 */
void addStudent(const struct Student_t *const ptr){

	struct node *New_Student = NULL ;
	struct node *checkStudentID = head ;
	New_Student = (struct node*) malloc(sizeof(struct node));
	New_Student->data.gpa = ptr->gpa ;
	New_Student->data.age = ptr->age ;
	New_Student->data.id = ptr->id ;
	if(head == NULL){
		head =New_Student ;
		New_Student->next = NULL ;

	}else{

		while(checkStudentID != NULL){   // check about duplicated ID
			if( checkStudentID->data.id == New_Student->data.id  ){
				printf("Error duplicated ID \n");
				free(New_Student);
				return ;
			}

			checkStudentID = checkStudentID->next ;/*use to move on linked list */
		}

		checkStudentID->next = New_Student ; /*use for adding new struct at the end of linked list */
		New_Student->next = NULL ;
	}

}
/*
 **arguments void
 **variable listStudent , checkStudentID
 **this function use for displaying elements of linked list
 **return void
 */
void displayStudent(void){
	struct node *listStudent = head ;
	while(listStudent != NULL){
		printf("student name is %s,",listStudent->data.name );
		printf(" age is %d , ",listStudent->data.age);
		printf(" id is %d , ",listStudent->data.id);
		printf(" GPA is %f\n",listStudent->data.gpa);

		listStudent = listStudent->next ;
	}
}
/*
 **arguments int id
 **variable pointer of targetnode
 **this function use for searching Student By ID
 **return void
 */
void searchStudentByID(int id){
	struct node *targetnode = head ;
	while(targetnode != NULL){
		if(targetnode->data.id == id){
			break ;
		}/*here return selected node */
		targetnode = targetnode->next ;
	}
	if(targetnode == NULL){
		printf("this Id not found\n");
	}else{
		printf("student name is %s , ",targetnode->data.name );
		printf(" age is %d , ",targetnode->data.age);
		printf(" id is %d , ",targetnode->data.id);
		printf(" GPA is %f\n",targetnode->data.gpa);
	}
}
/*
 **arguments int id
 **variable pointer of target_node
 **this function use for updating elements of certain Student
 **return void
 */
void updateStudent(int id){
	struct node *target_node = head ;
	while(target_node != NULL){
		if(target_node->data.id == id){/*check student id */
			printf("enter student Name :\n");
			fflush(stdout);
			scanf("%s",target_node->data.name);
			printf("enter Student age :\n ");
			fflush(stdout);
			scanf("%d",&target_node->data.age);
			printf("enter Student ID :\n ");
			fflush(stdout);
			scanf("%d",&target_node->data.id);
			printf("please enter Student GPA :\n");
			fflush(stdout);
			scanf("%f",&target_node->data.gpa);
			return ;
		}
		target_node = target_node->next ;
	}
	if(target_node == NULL){
		printf("this Id not found\n");
	}else{
		/* nothing */
	}

}
/*
 **arguments void
 **variable Avarage, sum, counter pointer of struct node
 **this function use for calculating Average GPA
 **return float
 */
float calculateAverageGPA(void){
	float Avarage = 0.0 ;
	float sum = 0.0 ; /*summation of all GPA*/
	int counter = 0 ; /*# of elements of linked list */
	struct node *loop = head ;
	if(NULL == head){
		printf("the list is empty\n");
	}else{
		while(loop != NULL){
			sum += loop->data.gpa ;
			loop = loop->next ;
			counter++ ;
		}
		Avarage = sum /counter ;

	}
	return (Avarage);
}
/*
 **arguments void
 **variable counter pointer of struct node(HighestGpa,selected_Student)
 **this function use for calculating Average GPA
 **return float
 */
void searchHighestGPA(void){
	struct node *HighestGpa = head ;
	struct node *selected_Student = head ;
	float max = 0 ;
	if(head == NULL){ // check if linked is empty
		printf("List is empty \n");
		return ;
	}else{
		while(HighestGpa != NULL){
			if(HighestGpa->data.gpa > max){
				max = HighestGpa->data.gpa ;
			}
			HighestGpa = HighestGpa->next ;
		} // find the max value of GPA

		while(selected_Student != NULL){
			if(max ==selected_Student->data.gpa ){
				break ;
			}
			selected_Student = selected_Student->next ;
		} // search for the student who has the max GPA
		printf("student name is %s , ",selected_Student->data.name );
		printf(" age is %d , ",selected_Student->data.age);
		printf(" id is %d , ",selected_Student->data.id);
		printf(" GPA is %f\n",selected_Student->data.gpa);
	}
}
/*
 **arguments int id
 **variable counter pointer of struct node(targetnode,prevnode)
 **this function use for calculating Average GPA
 **return void
 */
void deleteStudent(int id){
	struct node *targetnode = head ;
	struct node *prevnode = head ;
	if(head == NULL){
		printf("list is Empty!!\n");
		return ;
	}else{
		while(targetnode != NULL){
			if(targetnode->data.id == id){
				break ;
			}	// find the previous node of student that i want to delet him
			prevnode = targetnode ;
			targetnode = targetnode->next ;
		}
		if(targetnode == NULL){   // check if i found certain id
			printf("this Id not found\n");
		}else{  //delete this node
			prevnode->next= targetnode->next ;
			free(targetnode);
		}
	}
}
