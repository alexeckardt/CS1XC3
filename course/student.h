/**
 * @file student.h
 * @author Sharmin Ahmed (ahmes179@mcmaster.ca)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Defines a student with a first and last name, a student ID, an array of grades and an int representing the length of that array.
 * 
 */
typedef struct _student 
{ 
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades; 
  int num_grades; 
} Student;

//Functions
void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
