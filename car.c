//Car.c contains all the functions related to operations on the list of cars.
//The prototypes for the functions are in "car.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "car.h"
#include "readline.h"

//append_to_list receives the pointer to a list, it will add a car struct to the list. If the list doesn't exist it will return a pointer to the car struct added.
//The function will return a pointer to the beginning of the list.
//It will check if the car already exists.
struct car *append_to_list(struct car *list)
{
	char make[LEN + 1];
	char model[LEN + 1];	
	char color[LEN + 1];
	int year = 0;
	int city_mpg = 0;
	int highway_mpg = 0;
	int quantity = 0;

	//Enter the car information	
	printf("Enter the make of the car: ");
	read_line(make, LEN);
	printf("Enter the model of the car: ");
	read_line(model, LEN);
	printf("Enter the color of the car: ");
	read_line(color, LEN);
	printf("Enter the manufacture year: ");
	scanf("%d", &year);
	printf("Enter the city mpg: ");
	scanf("%d", &city_mpg);
	printf("Enter the highway mpg: ");
	scanf("%d", &highway_mpg);
	printf("Enter the quantity: ");
	scanf("%d", &quantity);
	
	//Create the input car pointer
	struct car *input_car = malloc(sizeof(struct car));
	strcpy(input_car->make,make);
	strcpy(input_car->model,model);
	strcpy(input_car->color,color);
	input_car->year = year;
	input_car->city_mpg = city_mpg;
	input_car->highway_mpg = highway_mpg;
	input_car->quantity = quantity;

	if(list == NULL){
		return input_car;
	}
	
	struct car * prev;
	struct car *cur;
	for(prev = NULL, cur = list; cur!=NULL; prev = cur, cur = cur->next ){
		//Check if the car already exists
		if((strcmp(cur->make, make) == 0) && (strcmp(cur->model, model)== 0) &&(strcmp(cur->color,color) == 0) &&(cur->year == year)){
			printf("This car already exists in the list");
			return list;
		}

		//Different make
		if(strcmp(cur->make,make) > 0){
			if(prev == NULL){
				input_car->next = cur;
				list = input_car;	
				break;
			}else{
				prev->next = input_car;
				input_car->next = cur;
				break;
			}

		}	
		//Same make
		if(strcmp(cur->make,make) == 0){
			if(strcmp(cur->model,model) > 0){
				if(prev == NULL){
					input_car->next = cur;
					list = input_car;
					break;
				}else{
					prev->next = input_car;
					input_car->next = cur;
					break;
				}
			//Same model
			}else if(strcmp(cur->model,model) == 0){
				input_car->next = cur->next;
				cur->next = input_car;
				break;
			}

		}
	

	}
	if(cur == NULL && prev != NULL){
		prev->next = input_car;
		input_car->next = cur;
	}


	return list;
	
}


//find_car will receive a pointer to the list.The function will ask for the make and model of the car that the user is searching for.
////The function will search for the car in the list.
void find_car(struct car * list)
{	
	char make[LEN + 1];
	char model[LEN + 1];
	int found = 0;
	printf("What is the make of the car you are looking for?");
	read_line(make,LEN);

	printf("What is the model of the car you are looking for?");
	read_line(model,LEN);
	
	struct car *p;
	for(p = list; p !=NULL; p = p->next){
		if((!strcmp(p->model, model)) && (!strcmp(p->make, make))){
			printf("color:%s, manufacture year:%d, city mpg:%d, highway mpg:%d, quantity:%d\n", p->color, p->year, p->city_mpg, p->highway_mpg, p->quantity );
			found = 1;
		}

	}

	//Car not found
	if(!found){
		printf("Car not found\n");
	}

}

//printList will receive the pointer to the list and it will print the entire list
void printList(struct car *list)
{
	struct car *p;
  printf("Make%30sModel%30sColor%30sYear%10sCity%10sHighway%10sQuantity\n","","","","","","");	
	for(p = list; p != NULL; p = p->next){
		printf("%-34s%-35s%-35s%-14d%-14d%-17d%-18d\n", p->make, p->model, p->color, p->year, p->city_mpg, p->highway_mpg, p->quantity);
	}

}
//clearList will receive a pointer to the list.
//It will dealocate the memory used for the list when the user exits the program.
void clearList(struct car *list)
{
	struct car *p;
	while(list != NULL){
		p =list;
		list = list->next;
		if(p != NULL){
			free(p);
		}
	}	

}

//delete_from_list will receive a pointer to the list. It's going to delete a car from the list by the its make, model, color, and manufacture year.
//The previous->next is going to point to current->next(prev->next = cur->next)
struct car *delete_from_list(struct car *list){
	struct car *prev;
	struct car *cur;
	char make[LEN + 1];	
	char model[LEN + 1];
	char color[LEN + 1];
	int year = 0;
	printf("Enter the make of the car that you want to delete: ");
	read_line(make, LEN);
	printf("Enter the model of the car: ");
	read_line(model, LEN);
	printf("Enter the color of the car: ");
	read_line(color, LEN);
	printf("Enter the manufacture year of the car: ");
	scanf("%d", &year);

	for(prev = NULL, cur = list; (cur != NULL) && ( (strcmp(cur->make, make) != 0) || (strcmp(cur->model, model) != 0)|| (strcmp(cur->color, color) != 0) || (cur->year != year));
	 prev = cur, cur = cur->next); 			
	
	//Car not found
	if(cur == NULL){
		printf("Couldn't find this car on the list\n");
		return list;
	
	//Delete first car	
	}else if(prev == NULL){
		printf("Deleting %s, %s, %s, %d\n", cur->make, cur->model,cur->color ,cur->year);
		list = list->next;	
		free(cur);
		return list;
	}else{
		printf("Deleting %s, %s,%s, %d\n", cur->make, cur->model, cur->color ,cur->year);
		prev->next = cur->next;
		free(cur);
		return list;		
	}
	return list;
}
