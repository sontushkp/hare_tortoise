//This is simulation of classic race of the tortoise and the here
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// fuction prototypes
void moveTortoise( int *tortoisePositionPtr );
void moveHare( int *harePositionPtr);
void printCurrentPositions(int *tortoisePositionPtr, int *harePositionPtr );

//main function of the program
int main(void) 
{
	int tortoisePosition = 1, harePosition = 1;  //starting position
	int clockTick = 0;		// timer
	int finishLine = 70;		
	
	
	int *tortoisePositionPtr = &tortoisePosition;     // points to tortoisePosition address 
	int *harePositionPtr = &harePosition;	 // points to harePositionPtr address 
	int *finishLinePtr = &finishLine;      // points to finishLine address 
	
	srand( time( 0 ) );
	
	
	// Start the game 
	puts("BANG !!!!!");
	puts("AND THEY'RE OFF !!!!!");
	
	
	// continue the loop until the finishLine is reached at least one constentant
	
	while(*tortoisePositionPtr != *finishLinePtr && *harePositionPtr != *finishLinePtr) {
		moveTortoise(tortoisePositionPtr);   //move the tortoise position
      		moveHare(harePositionPtr);   //move the hare position
      		printCurrentPositions(tortoisePositionPtr,harePositionPtr);  //print current positions
      		clockTick++;   //increment clockTick
      		
      		// If the it takes more than 500 clockTicks to complete the game it will start over the game  
      		if(clockTick > 500){
      			
      			tortoisePosition = 1, 
      			harePosition = 1;
      			clockTick = 0;
      		}
	
	}
	
	//Final result of game   
   	if(*tortoisePositionPtr > *harePositionPtr)
   	{
      		puts("TORTOISE WIN!!! YAY!!!");         
   	}
   	else if(*tortoisePositionPtr < *harePositionPtr)
   	{
      		puts("HARE WIN!!! YUCH!!!");      
   	}
   	else if(*tortoisePositionPtr == *harePositionPtr) 
   	{
   		puts("It's a tie!!!"); 
   	}
   	
   	
   	//print the number of ticks as seconds
   	printf("Time Elapsed: %d seconds\n", clockTick);
   
   

}

// move Tortoise current position based on random numbers
void moveTortoise( int *tortoisePositionPtr) 
{
	int i = 1 + rand() % 10;  // random number from 1 to 10
	
	
	if(*tortoisePositionPtr < 70){
	if(i >= 1 && i <= 5)
	{
		//Fast plod  
		*tortoisePositionPtr += 3;   //move 3 squares forward
        }
        else if(i >= 6 && i <= 7)
        {
		//Slip      
		*tortoisePositionPtr -= 6;   //move 6 square backward
        }
        else
        {
		//Slow plod      
		*tortoisePositionPtr += 1;   //move 1 square forward
        }
        }  // end of first if
        else
        {	
        	//if tortoise position is more than 70 
        	*tortoisePositionPtr = 70;
        }
	
	// position can not be negative 
	if(*tortoisePositionPtr < 1){
		*tortoisePositionPtr = 1;
	}
      

}

// move Hare current position based on random number
void moveHare( int *harePositionPtr)
{
	int i = 1 + rand() % 10;  // random number from 1 to 10
	
	if(*harePositionPtr < 70){
	if(i >= 1 && i <= 2)
	{
		//Sleep   
		*harePositionPtr += 0;   // No move at all
	}
	else if(i >= 3 && i <= 4)
	{
		//Big hop   
		*harePositionPtr += 9;     // move 9 squares forward
	}
	else if(i == 5)
	{
		//Big slip
		*harePositionPtr -= 12;   //move 12 squares backward
	}
	else if(i >= 6 && i<= 8)
	{
		//Small hop
		*harePositionPtr += 1;   //move 1 square forward
	}
	else
	{
		//Small slip
		*harePositionPtr -= 2;      //move 2 squares backward
	}
	}  // end of first if
	else
        {
        	//if hare position is more than 70 
        	*harePositionPtr = 70;
        }
	
	// position can not be negative 
	if(*harePositionPtr < 1){
		*harePositionPtr = 1;
	}

}

//Print the current position of tortoise and hare 
void printCurrentPositions(int *tortoisePositionPtr, int *harePositionPtr){
   
   
	if(*tortoisePositionPtr < *harePositionPtr)
	{
		for(int i = 1; i < *tortoisePositionPtr; i++ ){
			printf("%s"," ");
		}   
		printf("T");
      
		for(int i = 1; i < *harePositionPtr - *tortoisePositionPtr; i++){
			printf("%s"," ");
		}
		printf("H");
	}
	else if(*tortoisePositionPtr == *harePositionPtr)
	{
		for(int i = 1; i < *tortoisePositionPtr; i++){
			printf("%s"," ");
		}
		printf("OUCH!!!");                
	}
	else if(*tortoisePositionPtr > *harePositionPtr )
	{
		for(int i = 1; i < *harePositionPtr; i++){
			printf("%s"," ");      
		}     
      		printf("H");
      
      		for(int i = 0; i < *tortoisePositionPtr - *harePositionPtr; i++){
         		printf("%s"," ");     
      		}
      		printf("T");
	}
   
   puts("");
}
