#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    string name;
    printf("What is your first name: ");
    scanf("%100s", name);
    
    srand(time(NULL));
    int value = 2+ rand() %100 +1;
    printf("Hi %s, I have chosen a number between 1 and 100 inclusive. Try and guess what it is.\n",name); 
    printf("**make sure to enter the same guess again after typing it once so that you get a hint of how close you are to the secret number and to ensure your guess is valid.**\n");
    
    int guess = 1;
    
    int tries = 1;
    
    for (int i = 0; guess != value; i++)
    {
        printf("Guess: ");
        scanf("%d\n", &guess);
        if (guess > 100 || guess < 1)
        {
            printf("Your guess has to be in the range of 1-100, guess again.\n");
            printf("Guess: ");
            scanf("%d\n", &guess);
        }
        else if (guess > value)
        {
            printf("Your guess is too high\n");
            tries++;
            printf("Guess: ");
            scanf("%d\n", &guess);
        }
        else if (guess < value)
        {
            printf("Your guess is too low\n");
            tries++;
            printf("Guess: ");
            scanf("%d\n", &guess);
        }
    }

    if (guess == value)
    {
        printf("Good job, you have guessed my secret number!\n");
        printf("Number of tries: %d\n", tries);
        return 0;
    }
}
