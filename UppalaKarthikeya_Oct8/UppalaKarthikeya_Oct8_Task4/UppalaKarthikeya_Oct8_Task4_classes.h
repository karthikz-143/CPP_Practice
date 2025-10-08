#ifndef TASK4_CLASSES_H
#define TASK4_CLASSES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


enum class GradeLevel { Fail, Pass, Merit, Distinction };

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
    const std::string& getName() const;
};


class Student {
private:
    SubjectScore** scores;   // dynamic array of pointers
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

    // Provide access to scores
    int getScoreCount() const;
    SubjectScore* getScoreAt(int index) const;
};

// Global function declarations
void summarizeGrades(Student* students[], int studentCount);
const SubjectScore* findTopScorer(Student* students[], int studentCount, const std::string& subject);
void exportAllDistinctions(Student* students[], int studentCount, const std::string& filename);

#endif
