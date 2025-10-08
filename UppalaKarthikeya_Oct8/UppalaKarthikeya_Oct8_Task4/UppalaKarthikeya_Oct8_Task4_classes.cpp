#include "UppalaKarthikeya_Oct8_Task4_classes.h"

// Utility 
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
              << " | Grade: " << gradeToString(grade)
              << std::endl;
}

GradeLevel SubjectScore::getGrade() const { return grade; }
int SubjectScore::getScore() const { return score; }
const std::string& SubjectScore::getName() const { return subjectName; }

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
        if (scores[i]->getGrade() == GradeLevel::Distinction) count++;
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

int Student::getScoreCount() const { return currentCount; }
SubjectScore* Student::getScoreAt(int index) const { 
    if (index >= 0 && index < currentCount) return scores[index];
    return nullptr;
}

// Global Functions

// Summarize Grades
void summarizeGrades(Student* students[], int studentCount) {
    int counts[4] = {0, 0, 0, 0}; // Fail, Pass, Merit, Distinction
    for (int i = 0; i < studentCount; i++) {
        if (!students[i]) continue;
        for (int j = 0; j < students[i]->getScoreCount(); j++) {
            SubjectScore* s = students[i]->getScoreAt(j);
            if (!s) continue;
            counts[static_cast<int>(s->getGrade())]++;
        }
    }
    std::cout << "Fail: " << counts[0] << "\n";
    std::cout << "Pass: " << counts[1] << "\n";
    std::cout << "Merit: " << counts[2] << "\n";
    std::cout << "Distinction: " << counts[3] << "\n";
}

// Find top scorer by subject
const SubjectScore* findTopScorer(Student* students[], int studentCount, const std::string& subject) {
    const SubjectScore* top = nullptr;
    for (int i = 0; i < studentCount; i++) {
        if (!students[i]) continue;
        for (int j = 0; j < students[i]->getScoreCount(); j++) {
            SubjectScore* s = students[i]->getScoreAt(j);
            if (!s) continue;
            if (s->getName() == subject) {
                if (!top || s->getScore() > top->getScore()) top = s;
            }
        }
    }
    return top;
}

// Export all distinctions
void exportAllDistinctions(Student* students[], int studentCount, const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout) {
        std::cout << "Cannot open file: " << filename << "\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        if (!students[i]) continue;
        for (int j = 0; j < students[i]->getScoreCount(); j++) {
            SubjectScore* s = students[i]->getScoreAt(j);
            if (!s) continue;
            if (s->getGrade() == GradeLevel::Distinction) {
                fout << "Student " << i+1 << " | Subject: " << s->getName()
                     << " | Score: " << s->getScore() << "\n";
                std::cout << "Student " << i+1 << " | Subject: " << s->getName()
                          << " | Score: " << s->getScore() << "\n";
            }
        }
    }
    fout.close();
}
