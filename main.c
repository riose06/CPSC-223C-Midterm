/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: March 11 @ 11:59pm
 * CPSC 223C Midterm
 */

// First, run "chmod u+x r.sh" in the terminal to gain access to the bash file
// Then, run "r.sh" in the terminal to run the bash program!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "show.c"
#include "bubble.c"

#define MAX_LINES 100 
#define MAX_LINE_LENGTH 256 

// Removes the built-in next line (\n) when using the fgets() function
void trim(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

int main() 
{
    FILE* file_ptr;        // Internal name of the text file
    char file_name[50];    // External name of the text file
    char* file_data;       // Array of char from the text file
    char* my_data[MAX_LINES];
    int line_count = 0;
    
    // Get the current time and update the broken time
    time_t current_time = time(NULL);
    struct tm * broken = localtime(&current_time);

    printf("\nWelcome to Length Sorted Data by Ethan Rios.\n");

    printf("The time is now %02d:%02d%s.\n\n",
                                        (broken->tm_hour % 12) == 0 ? 12 : broken->tm_hour % 12, // 12 hour system
                                        broken->tm_min, // Minute
                                        broken->tm_hour < 12 ? "am" : "pm"); // am or pm

    // Gives user multiple chances to enter a text file in case of a typing mistake
    do 
    {
        printf("Please enter the name of a text file: ");
        fgets(file_name, 49, stdin);
        trim(file_name);

    }
    while ((file_ptr = fopen(file_name, "r")) == NULL);

    // Set file_ptr to the end of the text file
    // Use malloc to copy the size of the text file to file_data (create space)
    fseek(file_ptr, 0, SEEK_END);
    file_data = (char*) malloc ((ftell(file_ptr) + 1) * sizeof(char));

    // Set file_ptr to the start of the text file
    rewind(file_ptr);

    char c;
    int i;

    for (i = 0; (c = fgetc(file_ptr)) != EOF; i++) 
    {
        file_data[i] = c;
        if (c == '\n'){
            line_count++;
        }
    }

    fclose(file_ptr);

    char *token = strtok(file_data, "\n");
    while (token != NULL && line_count < MAX_LINES) {
        my_data[line_count] = token; 
        line_count++;
        token = strtok(NULL, "\n");
    }

    file_data[i] = '\0';

    if (line_count == 0 && i > 0) {
        line_count++;
    }

    printf("\nThe file data were copied to an array of char of size %d rows", line_count);
    printf("\nFor your information here are the contents of that array.\n\n");
    show(my_data, line_count);
    






    return 0;
}
