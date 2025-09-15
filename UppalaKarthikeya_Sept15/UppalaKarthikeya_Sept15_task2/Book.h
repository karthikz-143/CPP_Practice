#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

// ENUM
enum Genre {
    FICTION,
    NONFICTION,
    SCIENCE,
    HISTORY,
    TECHNOLOGY,
    UNKNOWN_GENRE
};

// Convert enum to string
std::string genreToString(Genre g);

// CLASS 
class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;   // 'A' = Available, 'B' = Borrowed
    bool isReferenceOnly;
    std::string title;
    Genre genre;

public:
    // Constructors & Destructor
    Book(); // default
    Book(int id, float rating, double price, char status,
         bool reference, const std::string& title, Genre genre); // parameterized
    ~Book();

    // Getters
    int getBookID() const;
    float getRating() const;
    double getPrice() const;
    char getAvailabilityStatus() const;
    bool getIsReferenceOnly() const;
    std::string getTitle() const;
    Genre getGenre() const;

    // Setters
    void setBookID(int id);
    void setRating(float rating);
    void setPrice(double price);
    void setAvailabilityStatus(char status);
    void setIsReferenceOnly(bool reference);
    void setTitle(const std::string& title);
    void setGenre(Genre genre);

    // Other Member Functions
    void updateAvailability(bool isBorrowed);
    void displayDetails() const;
};

// GLOBAL FUNCTIONS 
void markAsReference(Book& book);
bool isAffordable(const Book& book, double budget);
void printFormattedBookList(const Book books[], int size);

#endif
