#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

#include "spreadsheet.h"
#include "data.h"
#include "calc.h"
#include "ordering.h"

extern int gradeMappingA;
extern int gradeMappingB;
extern int gradeMappingC;
extern int gradeMappingD;


void calculateGrades(Student *student) {

float assignmentScore = ((student->assignment1 + student->assignment2 + student->assignment3) / 120) * 100;
float midtermScore = (student->midterm / 25) * 100;
float examScore = (student->exam / 40) * 100;

student->total = (assignmentScore * 0.25) + (midtermScore * 0.25) + (examScore * 0.5);

    if (student->total >= gradeMappingA) {
        student->grade = 'A';
    } else if (student->total >= gradeMappingB) {
        student->grade = 'B';
    } else if (student->total >= gradeMappingC) {
        student->grade = 'C';
    } else if (student->total >= gradeMappingD) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}


//Option 1
void displaySpreadsheet(Student students[], int count) {

    printf("\nCOMP 348 Grade Sheet\n");
    printf("--------------------\n");

    printf("\n| Student ID | Last Name | First Name | A1 | A2 | A3 | Midterm | Exam | Total | Grade |\n");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) 
    {
        printf("| %-11d | %-9s | %-10s | %-2.0f | %-2.0f | %-2.0f | %-7.0f | %-4.0f | %-5.2f | %-4c |\n",
               students[i].studentID, students[i].lastName, students[i].firstName,
               students[i].assignment1, students[i].assignment2, students[i].assignment3,
               students[i].midterm, students[i].exam, students[i].total, students[i].grade);
    }

    printf("---------------------------------------------------------------------------------------\n");
    
}

//Option 2
void displayHistogram(Student students[], int count) {

    int gradeDistribution[5] = {0}; // A, B, C, D, F

    // Count the grades
    for (int i = 0; i < count; i++) 
    {
        switch (students[i].grade) {
            case 'A':
                gradeDistribution[0]++;
                break;
            case 'B':
                gradeDistribution[1]++;
                break;
            case 'C':
                gradeDistribution[2]++;
                break;
            case 'D':
                gradeDistribution[3]++;
                break;
            case 'F':
                gradeDistribution[4]++;
                break;
        }
    }

    //Histogram
    printf("\nCOMP 348 Grade Distribution\n");
    printf("---------------------------\n");

    printf("A: ");
    for (int i = 0; i < gradeDistribution[0]; i++) {
        printf("*");
    }
    printf("\nB: ");
    for (int i = 0; i < gradeDistribution[1]; i++) {
        printf("*");
    }
    printf("\nC: ");
    for (int i = 0; i < gradeDistribution[2]; i++) {
        printf("*");
    }
    printf("\nD: ");
    for (int i = 0; i < gradeDistribution[3]; i++) {
        printf("*");
    }
    printf("\nF: ");
    for (int i = 0; i < gradeDistribution[4]; i++) {
        printf("*");
    }
   
    ////////////////////
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do{
        scanf("%c", &proceed);
    } while ( (proceed != 'c') && (proceed != 'C'));

}

int currentSortOption = 1; // Default: Sort by Student ID

//Option 3
void handleSortOption(Student students[], int count) {

    displaySortMenu();
    
    int sortChoice;
    scanf("%d", &sortChoice);
    getchar();  

    switch (sortChoice) {
        case 1:
            currentSortOption = 1;  
            sortByStudentID(students, count);
            printf("\nSort column updated\n");
            break;
        case 2:
            currentSortOption = 2;  
            sortByLastName(students, count);
            printf("\nSort column updated\n");
            break;
        case 3:
            currentSortOption = 3; 
            sortByExamGrade(students, count);
            printf("\nSort column updated\n");
            break;
        case 4:
            currentSortOption = 4;  
            sortByTotalGrade(students, count);
            printf("\nSort column updated\n");
            break;
        default:
            printf("Invalid choice. Please select a valid sorting option.\n");
            break;
    }

    ////////////////////
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do{
        scanf("%c", &proceed);
    } while ( (proceed != 'c') && (proceed != 'C'));

}

//Option 4
void updateLastName(Student students[], int count) {

    int studentID;
    char newLastName[50];
    
    displaySpreadsheet(students, count);

    printf("\nEnter Student ID: ");
    scanf("%d", &studentID);

    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (students[i].studentID == studentID) {
            
            printf("\nEnter updated Last Name: ");
            scanf("%s", newLastName);
            
            strcpy(students[i].lastName, newLastName);
            found = 1;

            printf("Last name updated\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", studentID);
    }
     
    ////////////////////
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do{
        scanf("%c", &proceed);
    } while ( (proceed != 'c') && (proceed != 'C'));

}

//Option 5
void updateExamGrade(Student students[], int count) {

    int studentID;
    int newExamGrade;
    
    displaySpreadsheet(students, count);

    printf("\nEnter Student ID: ");
    scanf("%d", &studentID);

    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (students[i].studentID == studentID) {
            
            printf("\nEnter updated exam grade: ");
            scanf("%d", &newExamGrade);

            if (newExamGrade < 0 || newExamGrade > 40) {
                printf("Invalid grade. The exam grade must be between 0 and 40.\n");
                return;
            }
            
            students[i].exam = newExamGrade;

            calculateGrades(&students[i]);
            found = 1;

            printf("\nExam grade updated\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", studentID);
    }

    ////////////////////
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do{
        scanf("%c", &proceed);
    } while ( (proceed != 'c') && (proceed != 'C'));

}

//Variables for Option 6
int gradeMappingA = 80;
int gradeMappingB = 70;
int gradeMappingC = 60;
int gradeMappingD = 50; 

//Option 6
void updateGradeMapping() {

    printf("Current Mapping:\n");
    printf("A: >= %d\n", gradeMappingA);
    printf("B: >= %d\n", gradeMappingB);
    printf("C: >= %d\n", gradeMappingC);
    printf("D: >= %d\n", gradeMappingD);
    printf("F:  < %d\n", gradeMappingD);

    
    printf("\nEnter new A baseline: ");
    scanf("%d", &gradeMappingA);

    printf("Enter new B baseline: ");
    scanf("%d", &gradeMappingB);

    printf("Enter new C baseline: ");
    scanf("%d", &gradeMappingC);

    printf("Enter new D baseline: ");
    scanf("%d", &gradeMappingD);

    
    if (gradeMappingA <= gradeMappingB || gradeMappingB <= gradeMappingC || gradeMappingC <= gradeMappingD) {
        printf("Invalid grade mapping.\n");
        return;
    }


    printf("\nNew Mapping:\n");
    printf("A: >= %d\n", gradeMappingA);
    printf("B: >= %d\n", gradeMappingB);
    printf("C: >= %d\n", gradeMappingC);
    printf("D: >= %d\n", gradeMappingD);
    printf("F:  < %d\n", gradeMappingD);
}

//Option 6
void applyNewGradeMapping(Student students[], int count) {

    for (int i = 0; i < count; i++) {
        calculateGrades(&students[i]);
    }
}

//Option7
void removeStudent(Student students[], int *count) {

    int studentID;
    int indexToRemove = -1;

    displaySpreadsheet(students, *count);

    printf("Enter Student ID: ");
    scanf("%d", &studentID);

    for (int i = 0; i < *count; i++) {
        if (students[i].studentID == studentID) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Student with ID %d not found.\n", studentID);
        return;
    }

    for (int i = indexToRemove; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;

    printf("Student successfully deleted\n");

    ////////////////////
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do{
        scanf("%c", &proceed);
    } while ( (proceed != 'c') && (proceed != 'C'));

}
