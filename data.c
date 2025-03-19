#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

#include "data.h"

#define MAX_STUDENTS 100 

int readStudentsFromFile(Student *students, int maxStudents) {

    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open students.txt\n");
        return 0; // Return 0 if no students are loaded
    }

    int count = 0;
    while (count < maxStudents && fscanf(file, "%d|%49[^|]|%49[^|]|%f|%f|%f|%f|%f",
                                          &students[count].studentID,
                                          students[count].lastName,
                                          students[count].firstName,
                                          &students[count].assignment1,
                                          &students[count].assignment2,
                                          &students[count].assignment3,
                                          &students[count].midterm,
                                          &students[count].exam) == 8) {
        count++;
    }

    fclose(file);
    return count;
}


