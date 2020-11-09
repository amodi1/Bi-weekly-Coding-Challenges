#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    
    srand(time(NULL));
    int value = 1+ rand() %100 +1;
    printf("Hi %s, I have chosen a number between 1 and 100 inclusive. Try and guess what it is.\n", name);
    
    int guess = get_int("Guess: ");
    int tries = 1;
    
    for (int i = 0; guess != value; i++)
    {
        if (guess > 100 || guess < 1)
        {
            printf("Your guess has to be in the range of 1-100, guess again.\n");
            guess = get_int ("Guess: ");
        }
        else if (guess > value)
        {
            printf("Your guess is too high\n");
            tries++;
            guess = get_int ("Guess: ");
        }
        else if (guess < value)
        {
            printf("Your guess is too low\n");
            tries++;
            guess = get_int ("Guess: ");
        }
    }

    if (guess == value)
    {
        printf("Good job %s, you have guessed my secret number!\n", name);
        printf("Number of tries: %d\n", tries);
    }
}