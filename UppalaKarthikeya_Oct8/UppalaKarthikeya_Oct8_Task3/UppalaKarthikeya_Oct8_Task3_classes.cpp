#include "UppalaKarthikeya_Oct8_Task3_classes.h"

// Utility Function 
std::string gradeToString(GradeLevel grade) {
    switch (grade) {
        case GradeLevel::Fail: return "Fail";
        case GradeLevel::Pass: return "Pass";
        case GradeLevel::Merit: return "Merit";
        case GradeLevel::Distinction: return "Distinction";
    }
    return "Unknown";
}

// SubjectScore Implementation 
SubjectScore::SubjectScore(const std::string& name, int s, GradeLevel g)
    : subjectName(name), score(s), grade(g) {}

void SubjectScore::display() const {
    std::cout << "Subject: " << subjectName
              << " | Score: " << score
              << " | Grade: " << gradeToString(grade) << std::endl;
}

GradeLevel SubjectScore::getGrade() const {
    return grade;
}

int SubjectScore::getScore() const {
    return score;
}

//  Student Implementation 
Student::Student() {
    scores = new SubjectScore*[MAX_SUBJECTS];
    currentCount = 0;
}

Student::~Student() {
    for (int i = 0; i < currentCount; i++) {
        delete scores[i];
    }
    delete[] scores;
}

void Student::addScore(const SubjectScore& score) {
    if (currentCount < MAX_SUBJECTS) {
        scores[currentCount++] = new SubjectScore(score);
    } else {
        std::cout << "Cannot add more subjects. Max limit reached.\n";
    }
}

void Student::displayAllScores() const {
    for (int i = 0; i < currentCount; i++) {
        scores[i]->display();
    }
}

double Student::computeAverage() const {
    if (currentCount == 0) return 0.0;
    int total = 0;
    for (int i = 0; i < currentCount; i++) {
        total += scores[i]->getScore();
    }
    return static_cast<double>(total) / currentCount;
}

int Student::countDistinction() const {
    int count = 0;
    for (int i = 0; i < currentCount; i++) {
        if (scores[i]->getGrade() == GradeLevel::Distinction) {
            count++;
        }
    }
    return count;
}

void Student::displayTopScores() const {
    for (int i = 0; i < currentCount; i++) {
        GradeLevel g = scores[i]->getGrade();
        if (g == GradeLevel::Merit || g == GradeLevel::Distinction) {
            scores[i]->display();
        }
    }
}
