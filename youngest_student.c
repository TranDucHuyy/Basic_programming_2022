#include "youngest_student.h"
#include <stdio.h>
#include "define.h"

//Check in turn from year, month, day. If greater than will get the value.
struct student findYoungestStudent( struct student *students, int numOfStudents) {
    struct student youngestStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].birthdate.ate > youngestStudent.birthdate.ate) {
            youngestStudent = students[i];
        } else if ((students[i].birthdate.ate == youngestStudent.birthdate.ate)
        && (students[i].birthdate.thd > youngestStudent.birthdate.thd)) {
            youngestStudent = students[i];
        } else if ((students[i].birthdate.ate == youngestStudent.birthdate.ate)
        && (students[i].birthdate.thd == youngestStudent.birthdate.thd)
        && (students[i].birthdate.bir > youngestStudent.birthdate.bir)){
            youngestStudent = students[i];
        }
    }    
    return youngestStudent;
}