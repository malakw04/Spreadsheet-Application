#ifndef CALC_H
#define CALC_H

#include "spreadsheet.h"
#include "data.h"
#include "calc.h"
#include "ordering.h"

void calculateGrades(Student *student);

void displaySpreadsheet(Student students[], int count); 

void displayHistogram(Student students[], int count); 

void handleSortOption(Student students[], int count); 

void updateLastName(Student students[], int count);

void updateExamGrade(Student students[], int count);  

void updateGradeMapping();  
void applyNewGradeMapping(Student students[], int count);

void removeStudent(Student students[], int *count);


#endif

