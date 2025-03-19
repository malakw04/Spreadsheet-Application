#ifndef DATA_H
#define DATA_H

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int studentID;
    char lastName[MAX_NAME_LENGTH];
    char firstName[MAX_NAME_LENGTH];
    float assignment1;
    float assignment2;
    float assignment3;
    float midterm;
    float exam;
    float total;
    char grade;
} Student;

int readStudentsFromFile(Student *students,int maxStudents);

#endif 


