#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	
	int age;
	char name[50];
	char surname[50];
	struct Node* next;
	
};

struct Node* head = NULL;

void getValue(struct Node* temp){
	printf("Please enter the customer's name: ");
	scanf(" %s", temp->name);
	printf("Please enter the customer's surname: ");
	scanf(" %s", temp->surname);
	printf("Please enter the customer's age: ");
	scanf(" %d", &temp->age);
}

void addFirst(int* count, struct Node* val){
	struct Node* temp;
	val = (struct Node*)malloc(sizeof(struct Node));
	if(*count != 0){
	temp = head;
	while(temp->next != '\0'){
		temp = temp->next;
	}
		val->next = temp->next;
		temp->next = val;
		getValue(val);
	}else{
		getValue(val);
		val->next = head;
		head = val;
	}
	
}

void listValues(){
	int count = 1;
	struct Node* stemp = head;
	while(stemp != '\0'){
		printf("\n(%d) Name: %s ", count, stemp->name);
		printf("\n(%d) Surname: %s ", count, stemp->surname);
		printf("\n(%d) Name: %d\n ", count, stemp->age);
		printf("**************************\n");
		stemp = stemp->next;
		count++;
	}
}

int main(int argc, char *argv[]) {	
	int count = 0, option;
	char answer[50] = "yes";
	struct Node* start;
	
	while(1){
		printf("(1) Add Customer\n(2) List Customers\n(3) Exit\n");
		scanf(" %d", &option);
		if(option == 1){
			while(strcmp(answer, "no") != 0 && strcmp(answer, "NO") != 0){
			addFirst(&count, start);
			count++;	
			printf("Do you want to continue ?\n");
			scanf(" %s", answer);
			}
		}
		if(option == 2){
			listValues();
		}
		if(option == 3){
			break;
		}
	}
}
