#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <iostream>
#include <string>

enum class GradeLevel { Fail, Pass, Merit, Distinction };

// Utility function
std::string gradeToString(GradeLevel grade);


class SubjectScore {
private:
    std::string subjectName;
    int score;
    GradeLevel grade;

public:
    SubjectScore(const std::string& name, int s, GradeLevel g);
    void display() const;
    GradeLevel getGrade() const;
    int getScore() const;
};


class Student {
private:
    SubjectScore** scores;   // dynamic array of pointers to SubjectScore
    int currentCount;
    static const int MAX_SUBJECTS = 10;

public:
    Student();
    ~Student();

    void addScore(const SubjectScore& score);
    void displayAllScores() const;
    double computeAverage() const;
    int countDistinction() const;
    void displayTopScores() const;
};

#endif
