// C Program to demonstrate 
// use of nanosleep 
#include <stdio.h> 
#include <time.h> 

int main() 
{ 
	struct timespec remaining, request = { 1, 100 }; 

    nanosleep(&request, &remaining); 
    return 0;
}
