#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

#include "data.h"
#include "ordering.h"



int compareStudents(const void *a, const void *b) {
    return ((Student *)a)->studentID - ((Student *)b)->studentID;
}

void sortStudents(Student students[], int count) {
    qsort(students, count, sizeof(Student), compareStudents);
}




//helper function
void swapStudents(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}


void sortByStudentID(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].studentID > students[j + 1].studentID) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}


void sortByLastName(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].lastName, students[j + 1].lastName) > 0) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}


void sortByExamGrade(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].exam < students[j + 1].exam) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}


void sortByTotalGrade(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].total < students[j + 1].total) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}




