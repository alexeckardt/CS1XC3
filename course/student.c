#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Adds a grade to the student's record of grades.
 * Uses calloc or realloc to dynamically allocate memory for the array holding the grades
 * 
 * @param student 
 * @param grade 
 */
void add_grade(Student* student, double grade)
{
  //Increment the array count
  student->num_grades++;

  //Allocate memory for the grade array
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }

  //Save the new grade to the new index in the grade array
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief Returns the Student's average grade
 * 
 * @param student 
 * @return double 
 */
double average(Student* student)
{
  //Exit Case (bypass divide by zero)
  if (student->num_grades == 0) return 0;

  //Get sum of all grades
  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];

  //Return Mean Average
  return total / ((double) student->num_grades);
}


/**
 * @brief Prints the student's information in a formated way
 * 
 * @param student 
 */
void print_student(Student* student)
{
  //Print Info
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");

  //Print Grade Value (2 decimal places)
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief Generates and Returns a random student with a specified number of grades.  
 * 
 * @param grades 
 * @return Student* 
 */
Student* generate_random_student(int grades)
{

  //Pool of First Names
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  //Pool of First Names
  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  //Allocate memory for new student
  Student *new_student = calloc(1, sizeof(Student));

  //Save copy of name string as student's name
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  //Generate new string ID
                                                            //what does this 48 mean?? Needs a magic number.
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48); 
  //End the string
  new_student->id[10] = '\0';

  //Add X random grades
  for (int i = 0; i < grades; i++) 
  {
    //Range of grades between 25 and 99 (75 % 75 = 0)
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  //Return the new student
  return new_student;
}