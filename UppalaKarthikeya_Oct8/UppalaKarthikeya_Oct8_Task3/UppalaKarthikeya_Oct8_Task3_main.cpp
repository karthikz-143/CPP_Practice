#include "UppalaKarthikeya_Oct8_Task3_classes.h"

int main() {
    Student student;
    student.addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    student.addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    student.addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));
    student.addScore(SubjectScore("History", 45, GradeLevel::Fail));
    student.addScore(SubjectScore("English", 88, GradeLevel::Distinction));

    // Display all scores
    std::cout << "\n--- All Subject Scores ---\n";
    student.displayAllScores();

    // Display average score
    std::cout << "\nAverage Score: " << student.computeAverage() << std::endl;

    // Count and display number of Distinction subjects
    std::cout << "Number of Distinction subjects: " << student.countDistinction() << std::endl;

    // Display top scores (Merit and Distinction)
    std::cout << "\n--- Top Scores (Merit & Distinction) ---\n";
    student.displayTopScores();

    return 0;
}
