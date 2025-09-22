
#include <iostream>
#include "GradeBook.h"

// Constructor 
GradeBook::GradeBook(std::string course, std::string instructor) {
    setCourseName(course);
    setInstructorName(instructor);
}

// Set the course name
void GradeBook::setCourseName(std::string course) {
    courseName = course;
}

// Get the course name
std::string GradeBook::getCourseName() {
    return courseName;
}

// Set the instructor's name
void GradeBook::setInstructorName(std::string instructor) {
    instructorName = instructor;
}

// Get the instructor's name
std::string GradeBook::getInstructorName() {
    return instructorName;
}
void GradeBook::displayMessage() {
    std::cout << "Welcome to the grade book for\n"
              << getCourseName() << "!" << std::endl;
    std::cout << "This course is presented by: "
              << getInstructorName() << std::endl;
}
