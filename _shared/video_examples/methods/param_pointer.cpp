#include <iostream>

using namespace std;

//A parameter example featuring pass by pointer

struct Clock{
	int hour;
	int minute;
	int second;
};

int getTime(Clock c){
	return (c.hour * 10000) + (c.minute * 100) + c.second;
}

void printTime(Clock c){
	int time = getTime(c);
	cout << time/10000 << ":" << (time%10000)/100 << ":" << time % 100 << endl;
}

//simple pointer wrapper method
void printTime(Clock * c){
	printTime(*c);
}

//Run up the clock by a minute
void incrementMinute(Clock * c){
	c->minute++;
	if(c->minute == 60){
		c->minute = 0;
		c->hour++;
		if(c->hour == 24) c->hour = 0;
	}	
}

//(Attempt to) delete the parameter clock
//Not something you'd ever really use, but it proves a point.
void deleteClock(Clock * c){
	delete c;
	//We can set the local pointer to NULL, but not the actual parameter!
	//This is a shortcoming of passing by pointer
	c = NULL;
}

int main(){
	//Initialize digital
	Clock digital;
	digital.hour = 3;
	digital.minute = 14;
	digital.second = 15;

	//Create a pointer to digital
	//Clocks have no dynamic memory, so we can use the default constructor
	Clock * stackPointer = new Clock(digital);
	printTime(stackPointer);
	//The memory address is passed in. We directly modify the Clock
	incrementMinute(stackPointer);
	printTime(stackPointer);

	//True for clocks on the stack and the heap
	Clock * heapPointer = new Clock();
	heapPointer->hour = 10;
	heapPointer->minute = 23;
	heapPointer->second = 14;
	printTime(heapPointer);
	incrementMinute(heapPointer);
	printTime(heapPointer);

	//Using deleteClock
	deleteClock(heapPointer);
	if(heapPointer != NULL){
		cout << "heapPointer points to memory we no longer own!" << endl;
		heapPointer = NULL;
	}
	return 0;
}
