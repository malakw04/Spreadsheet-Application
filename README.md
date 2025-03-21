# Spreadsheet-Application

# Student Grades Management System

## Overview
This is a simple C-based console application for managing student grades in a spreadsheet format. It allows users to:
- Load student data from a file
- Calculate and display student grades
- Sort students based on different criteria
- Update student records
- Display a histogram of grade distributions

## Features
- Load student data from `students.txt`.
- Display student grades in a formatted table.
- Sort students by ID, last name, exam grade, or total grade.
- Update student records, including last name and exam scores.
- Modify grading criteria dynamically.
- Remove students from the dataset.
- Display a grade histogram.

## File Structure
```
├── calc.c         # Implements grade calculations and displays spreadsheet/histogram
├── calc.h         # Header file for grade calculations
├── data.c         # Reads student data from a file
├── data.h         # Defines the Student structure and function prototypes
├── ordering.c     # Sorting functions for student data
├── ordering.h     # Header file for sorting functions
├── spreadsheet.c  # Main entry point, menu handling
├── spreadsheet.h  # Header file for menu functions
```

## Compilation Instructions
To compile the program, use the following command:
```bash
gcc -o student_grades spreadsheet.c calc.c data.c ordering.c -Wall -Wextra
```

## Running the Program
Execute the compiled binary:
```bash
./student_grades
```
Ensure that `students.txt` is present in the same directory.

## Usage
1. The program starts by loading student data from `students.txt`.
2. Users can interact with a menu to display data, modify records, and sort students.
3. Press `c` to continue after each operation.
4. To exit, select option `8`.

## Sample `students.txt` Format
```
12345|Doe|John|25|28|30|20|35
67890|Smith|Alice|24|22|30|18|40
```
Each line represents a student with:
```
StudentID|LastName|FirstName|Assignment1|Assignment2|Assignment3|Midterm|Exam
```

## Contributions
Feel free to fork and submit pull requests with improvements!
