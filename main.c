    //Group 21 class A
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <wchar.h>

    #include "define.h"
    #include "oldest_student.h"
    #include "youngest_student.h"
    #include "f_function.h"
    
    int main(){

        FILE *fp;
        char ch;

        fp = fopen("input.txt", "r");   
        if (fp == NULL) {
            printf("Cannot open to file");
            return 1;
        }

        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        fclose(fp);

        printf("\n");
        char c;
        printf("Press Enter to continue...");
        scanf("%c", &c);
        printf("Start the final project %c\n", c);
        
        int numOfStudents;

    // check that the input is valid
        do{
            printf("Enter the number of students: ");
            scanf("%d", &numOfStudents);
        }while(numOfStudents > 1000);

    // create an array of structures to hold student data
        struct student* students = (struct student*) malloc(numOfStudents * sizeof(struct student));

    // loop through the array, prompting the user to enter student information
        for (int i = 0; i < numOfStudents; i++) {
        printf("\nEnter information for student %d:\n", i+1);
        printf("Student ID: ");
        scanf("%s", students[i].studentID);
        printf("Full Name: ");
        scanf(" %[^\n]s", students[i].fullName);
        printf("Birthdate (dd mm yyyy): ");
        scanf("%d %d %d", &students[i].birthdate.bir, &students[i].birthdate.thd, &students[i].birthdate.ate);
        do
        {
            printf("Algebra grade: ");
            scanf("%f", &students[i].algebraGrade);

        } while (students[i].algebraGrade > 20);
        do
        {
            printf("Calculus grade: ");
            scanf("%f", &students[i].calculusGrade);

        } while (students[i].calculusGrade > 20);
        do
        {
            printf("Programming grade: ");
            scanf("%f", &students[i].programmingGrade);

        } while (students[i].programmingGrade > 20);
        
        
        printf("\n");

        // calculate GPA for this student
        students[i].gpa = (students[i].algebraGrade + students[i].calculusGrade + students[i].programmingGrade) / 3.0;
    }

    // free the memory used by the students array
        // show functions
        while (1)
        {
            printf("\nOption: \n1. Show students list (task 3) \n2. Print students_list.txt (task 4) \n3. Highest GPA (task 5)\n4. Lowest GPA (task 5)\n");
            printf("5. Highest BP (task 5)\n6. Oldest student (task 7)\n7. Youngest student(task 8)\n");
            int opt = 0;
            scanf("%d",&opt);
            switch (opt)
            {
            case 1:
                //Print student list as a table to screen
                show_list(students, numOfStudents);
                break;
            case 2:;
                //Print student list as a table to a text file
                print_list(students, numOfStudents);
                printf("\nSuccess!\n");
                break;
            case 3:;
                //Print the student with highest GPA
                struct student highestGPAStudent = findHighestGPA(students, numOfStudents);
                for (int i = 0; i < numOfStudents; i++) {
                    if ( students[i].gpa == highestGPAStudent.gpa ) {
                        printf("Student with highest GPA:\n");  
                        printf("ID: %s\n", students[i].studentID);
                        printf("Name: %s \n", students[i].fullName);
                        printf("GPA: %.2f\n", students[i].gpa);
                        printf("\n");
                    }
                }
                break;
            case 4:;
                //Print the student with lowest GPA
                struct student lowestGPAStudent = findLowestGPA(students, numOfStudents);
                for (int i = 0; i < numOfStudents; i++) {
                    if ( students[i].gpa == lowestGPAStudent.gpa ) {    
                        printf("Student with lowest GPA:\n");
                        printf("ID: %s\n", students[i].studentID);
                        printf("Name: %s \n", students[i].fullName);
                        printf("GPA: %.2f\n", students[i].gpa);
                        printf("\n");
                    }
                }
                break;
            case 5:;
                //Print the student with highest BP grade
                struct student highestBPStudent = findHighestBP(students, numOfStudents);
                for (int i = 0; i < numOfStudents; i++) {
                    if ( students[i].programmingGrade == highestBPStudent.programmingGrade ){
                        printf("Student with highest BP grade:\n");
                        printf("ID: %s\n", students[i].studentID);
                        printf("Name: %s \n", students[i].fullName);
                        printf("Basic Programming grade: %.2f\n", students[i].programmingGrade);
                        printf("\n");
                    }
                }
                break;
            case 6:;
                //Print the Oldest Student
                struct student oldestStudent = findOldestStudent(students, numOfStudents);
                for (int i = 0; i < numOfStudents; i++) {
                    if ( students[i].birthdate.ate == oldestStudent.birthdate.ate 
                    && students[i].birthdate.thd == oldestStudent.birthdate.thd 
                    && students[i].birthdate.bir == oldestStudent.birthdate.bir){
                        printf("Oldest student:\n");
                        printf("ID: %s\n", students[i].studentID);
                        printf("Name: %s \n", students[i].fullName);
                        printf("Birthdate: %d %d %d\n", students[i].birthdate.bir, students[i].birthdate.thd, students[i].birthdate.ate);
                        printf("\n");}
                }
                break;
            case 7:;
                //Print the Youngest Student
                struct student youngestStudent = findYoungestStudent(students, numOfStudents);
                for (int i = 0; i < numOfStudents; i++) {
                    if ( students[i].birthdate.ate == youngestStudent.birthdate.ate && students[i].birthdate.thd == youngestStudent.birthdate.thd && students[i].birthdate.bir == youngestStudent.birthdate.bir){
                        printf("Youngest student:\n");
                        printf("ID: %s\n", students[i].studentID);
                        printf("Name: %s \n", students[i].fullName);
                        printf("Birthdate: %d %d %d\n", students[i].birthdate.bir, students[i].birthdate.thd, students[i].birthdate.ate);
                        printf("\n");}
                }
                break;
            default:
                printf("Reselect!\n");
                break;
            }
        
        }

    }

