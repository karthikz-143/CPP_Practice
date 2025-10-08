#include "UppalaKarthikeya_Oct8_Task4_classes.h"

int main() {
    // Create an array 
    const int studentCount = 3;
    Student* students[studentCount];

    // Populate students 
    students[0] = new Student();
    students[0]->addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    students[0]->addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    students[0]->addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));

    students[1] = new Student();
    students[1]->addScore(SubjectScore("Math", 85, GradeLevel::Merit));
    students[1]->addScore(SubjectScore("History", 45, GradeLevel::Fail));
    students[1]->addScore(SubjectScore("English", 88, GradeLevel::Distinction));

    students[2] = new Student();
    students[2]->addScore(SubjectScore("Math", 95, GradeLevel::Distinction));
    students[2]->addScore(SubjectScore("Physics", 82, GradeLevel::Merit));
    students[2]->addScore(SubjectScore("Chemistry", 70, GradeLevel::Pass));

    // Call global functions
    std::cout << "\n--- Grade Summary Across All Students ---\n";
    summarizeGrades(students, studentCount);

    std::cout << "\n--- Top Scorer in Math ---\n";
    const SubjectScore* topMath = findTopScorer(students, studentCount, "Math");
    if (topMath) topMath->display();
    else std::cout << "No Math scores found.\n";

    std::cout << "\n--- Export All Distinctions ---\n";
    exportAllDistinctions(students, studentCount, "distinctions.txt");

    // Clean up dynamic memory
    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }

    return 0;
}
