
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief Demonstrate functions of the other libraries and files
 * 
 * @return int 
 */
int main()
{
  //Set random seed
  srand((unsigned) time(NULL));

  //Create Course Math101
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  //Enroll 20 random students into the course
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  //Print
  print_course(MATH101);

  //Get & Print the top student
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  //Find all the students who are passing
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  //Print the students who are passing, along with the amount passing
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  //Good Ending
  return 0;
}