#include "course.h"
#include <stdlib.h>
#include <stdio.h>
 
 /**
  * @brief Adds a Student Structure into the defined course
  * 
  * @param course 
  * @param student 
  */
void enroll_student(Course *course, Student *student)
{
  //Increase Student Array (Represented) Size
  course->total_students++;

  //Allocate memory for the Student array 
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }

  //Set the new index as the inputted student. 
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Formats a Course data structure and prints it to the console.
 * 
 * @param course 
 */
void print_course(Course* course)
{
  //Print Course Info
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");

  //Print Student Info
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief Goes through the course and finds the student with the highest mark
 * 
 * @param course 
 * @return Student* 
 */
Student* top_student(Course* course)
{
  //Exit
  if (course->total_students == 0) return NULL;
 

  //Get Baseline for Average
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  //Find the student with the highest average
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      //Keep track of the student with the highest average and their average
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  //Return that student
  return student;
}


/**
 * @brief Returns an array of students who are passing a given course.
 * Also takes in the address of an integer and updates it's value with the length of the returned array.
 * 
 * @param course 
 * @param total_passing 
 * @return Student* 
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  //Get Count of students passing grade
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;

  //Allocate size for array for X amount of students
  passing = calloc(count, sizeof(Student));

  //Save the students who are passing to an array
  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      //Save to position j and keep searching; increment j
      passing[j] = course->students[i];
      j++;
    }
  }

  //Update the address of the array size, wherever that may be
  *total_passing = count;

  //Return the array of passing students
  return passing;
}