/*Jordano Baer
 *The program will create a linked list of cars.
 *The user can append a car to the list, find a car, delete a car, print the list and clear the list when he wants to quit the program.
 *Struct car will contain the make, model, color, manufacture year, city mpg, highway mpg, quantity of the car and the pointer "next".
*/

//dealer.c contains the main function of the program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"  //include readline function
#include "car.h"   //include functions related to the cars

//Main function, shows the operation codes to the user.
int main(void){
  char code;

  struct car *car_list = NULL;  
  printf("Operation Code: a for appending to the list,d for deleting a car from the list, f for finding a car"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': car_list = append_to_list(car_list);
                break;
      case 'd': car_list = delete_from_list(car_list);
		break;
      case 'f': find_car(car_list);
                break;
      case 'p': printList(car_list);
                break;
      case 'q': clearList(car_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
