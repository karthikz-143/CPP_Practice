
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
class GradeBook {
public:
    // Constructor
    GradeBook(std::string course, std::string instructor);

    // Function to set the course name
    void setCourseName(std::string course);

    // Function to get the course name
    std::string getCourseName();

    // Function to set the instructor's name
    void setInstructorName(std::string instructor);

    // Function to get the instructor's name
    std::string getInstructorName();
    void displayMessage();

private:
    std::string courseName;      
    std::string instructorName;  
};

#endif // GRADEBOOK_H
