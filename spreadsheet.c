#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

#include "spreadsheet.h"
#include "data.h"
#include "calc.h"
#include "ordering.h"

//Main Menu
void displayMenu() {
    
    system("clear");

    printf("Spreadsheet Menu\n");
    printf("----------------\n");

    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Set Sort Column\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Update Grade Mapping\n");
    printf("7. Delete Student\n");
    printf("8. Exit\n");
   
}


//Menu for Option 3
void displaySortMenu() {

    printf("\nColumn Options\n");
    printf("--------------\n");

    printf("1. Student ID\n");
    printf("2. Last Name\n");
    printf("3. Exam \n");
    printf("4. Total\n");
   
    printf("\nSort Column: ");
}




int main() {

Student *students = malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

//Read file at the start
    int studentCount = readStudentsFromFile(students, MAX_STUDENTS);
    if (studentCount > 0) 
    {
        for (int i = 0; i < studentCount; i++) {
            calculateGrades(&students[i]); //Calculate grades at the start
        }
    
         sortStudents(students, studentCount); //Sort students at the start 

//Main Menu functions
        
        int choice;
        char proceed;

        do {

            displayMenu();

            printf("\nSelection: ");
            scanf("%d", &choice);
            getchar(); 

            switch (choice) {
                
                case 1:
                system("clear");
                displaySpreadsheet(students, studentCount);

                /////////////    
                printf("\nPress 'c' or 'C' to continue ");
                do{
                scanf("%c", &proceed);
                } while ( (proceed != 'c') && (proceed != 'C'));

                break;

                case 2:
                system("clear");
                displayHistogram(students, studentCount);
                break;

                case 3:
                system("clear");
                handleSortOption(students, studentCount);
                break;

                case 4:
                system("clear");
                updateLastName(students, studentCount);
                break;

                case 5:
                system("clear");
                updateExamGrade(students, studentCount);
                break;

                case 6:
                system("clear");
                updateGradeMapping();
                applyNewGradeMapping(students, studentCount);

                /////////////
                printf("\nPress 'c' or 'C' to continue ");
                do{
                scanf("%c", &proceed);
                } while ( (proceed != 'c') && (proceed != 'C'));
                    
                break;

                case 7:
                system("clear");
                removeStudent(students, &studentCount);
                break;

                case 8:
                system("clear");
                printf("Goodbye and thanks for using our spreadsheet app.\n");
                system("exit"); 
                break;

                default:
                printf("Invalid choice. Please select a number between 1 and 8.\n");
            }
        } while (choice != 8);
        
    } 
    
    else {
        printf("No students found or unable to read from file.\n");
    }

    free(students);
    return 0;
}
