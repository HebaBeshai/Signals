#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#define N 64

// Prototypes

void alarmHandler(int);
void quitHandler(int);
int main () {

// set signal handlers

signal ( SIGALRM, alarmHandler );
signal ( SIGINT, quitHandler );
    
    char quit[5] = {'e','x','i','t','\0'};
    char user[N]= {'\0'};
    alarm(30);
    printf("Enter user Name: ");
    scanf("%s", user);
  
   while( strcmp(user,quit)!=0){
    printf("Your Username is: %s\n\n", user);
    printf("Enter Username: ");
    scanf("%s", user);
    alarm(10);
   }
    exit(0);
}

void alarmHandler( int Alarm ) {
  printf("\nTime up\n");
  printf("\nEnter Username: ");
  fflush(stdout);
  alarm(10);
  return;
 }
void quitHandler ( int Int) {
  printf("\nEnter exit to quit\n");
  printf("Enter Username: ");
  fflush(stdout);
  alarm(10);
  return;
}