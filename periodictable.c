#include <stdio.h>
#include <stdlib.h>

typedef struct periodic_table {
char name[10];
char symb[2];
char atomicWeight[10];
struct periodic_table *next;
} PERIODIC_TABLE;

int main(){
void printPeriodicTable();
PERIODIC_TABLE *readElement(), *start;
start = readElement();
printPeriodicTable(start);
return(0);
}

//Function for reading elements into periodic table
PERIODIC_TABLE *readElement()
{
	PERIODIC_TABLE *firstElement, *currentElement;
	int readAnother;
//Allocate first element in memory
	currentElement = firstElement = (PERIODIC_TABLE * ) malloc(sizeof(PERIODIC_TABLE));
//Read element
	printf("\n\n\tNAME:\t");
	scanf("%s",currentElement->name);
	printf("\n\n\tSYMBOL:\t");
	scanf("%s",currentElement->symb);
	printf("\n\n\tATOMIC_WEIGHT:\t");
	scanf("%s",currentElement->atomicWeight);
//Ask for another element
	printf("\n\n\n\tWant to add another element?(1==yes,0==no)\n");
	scanf("%d",&readAnother);
//Add element to linked list
	while(readAnother)
	{
		if (( currentElement -> next = (PERIODIC_TABLE *) malloc(sizeof(PERIODIC_TABLE))) == NULL) {
			printf("System out of memory; Cannot allocate more elements");
			return(firstElement);
		}
		currentElement = currentElement->next;
//Read next element

		printf("\n\n\tNAME:\t");
		scanf("%s",currentElement->name);
		printf("\n\n\tSYMBOL:\t");
		scanf("%s",currentElement->symb);
		printf("\n\n\tATOMIC_WEIGHT:\t");
		scanf("%s",currentElement->atomicWeight);

		//Ask for another element

		printf("\n\n\n\tWant to add another element?(1==yes,0==no)\n");
		scanf("%d",&readAnother);
	}
	//End list
	currentElement -> next = NULL;
	return(firstElement);
}

//Function to print periodic table
void printPeriodicTable(ptr)
PERIODIC_TABLE *ptr;
{
	printf("\n\n\n\tPERIODIC TABLE");
	printf("\n\n\tNAME|\t");
	printf("SYMBOL|\t");
	printf("ATOMIC WEIGHT|\n");
	while (ptr !=NULL){
		printf("\t%s|\t%s|\t%s|\n",ptr->name, ptr->symb,ptr->atomicWeight);
		ptr = ptr -> next;
	}
}
