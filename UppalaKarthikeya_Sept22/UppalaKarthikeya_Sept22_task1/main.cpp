#include <iostream>
#include "GradeBook.h"

int main() {
    // Create GradeBook object and display welcome message
    GradeBook gradeBook1("Introduction to C++ Programming", "Dr. Smith");
    gradeBook1.displayMessage();

    std::cout << "\nChanging instructor name...\n" << std::endl;
    // Change the instructor name using set function
    gradeBook1.setInstructorName("Prof. Karthikeya ");
    gradeBook1.displayMessage();

    return 0;
}
