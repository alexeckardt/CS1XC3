/**
 * @file course.h
 * @author Sharmin Ahmed (ahmes179@mcmaster.ca)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "student.h"
#include <stdbool.h>

/**
 * @brief Defines a course data structure which contains a Name, Code, 
 * A List of students enrolled in said course, and a count for the amount of students enrolled.
 * 
 */
typedef struct _course 
{
  char name[100];
  char code[10];
  Student *students;
  int total_students;
} Course;

//Functions
void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


