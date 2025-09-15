#include "Book.h"
#include <iomanip> // for setw, setprecision

// Convert enum to string
std::string genreToString(Genre g) {
    switch (g) {
        case FICTION: return "Fiction";
        case NONFICTION: return "Non-Fiction";
        case SCIENCE: return "Science";
        case HISTORY: return "History";
        case TECHNOLOGY: return "Technology";
        default: return "Unknown";
    }
}

//Constructors 
Book::Book()
    : bookID(0), rating(0.0f), price(0.0),
      availabilityStatus('A'), isReferenceOnly(false),
      title("Untitled"), genre(FICTION) {}

Book::Book(int id, float rating, double price, char status,
           bool reference, const std::string& title, Genre genre)
    : bookID(id), rating(rating), price(price),
      availabilityStatus(status), isReferenceOnly(reference),
      title(title), genre(genre) {}

Book::~Book() {
    std::cout << "Book (ID " << bookID << ") destroyed.\n";
}

//Getters
int Book::getBookID() const { return bookID; }
float Book::getRating() const { return rating; }
double Book::getPrice() const { return price; }
char Book::getAvailabilityStatus() const { return availabilityStatus; }
bool Book::getIsReferenceOnly() const { return isReferenceOnly; }
std::string Book::getTitle() const { return title; }
Genre Book::getGenre() const { return genre; }

//Setters 
void Book::setBookID(int id) { bookID = id; }
void Book::setRating(float r) { rating = r; }
void Book::setPrice(double p) { price = p; }
void Book::setAvailabilityStatus(char s) { availabilityStatus = s; }
void Book::setIsReferenceOnly(bool ref) { isReferenceOnly = ref; }
void Book::setTitle(const std::string& t) { title = t; }
void Book::setGenre(Genre g) { genre = g; }

//Other Member Functions 
void Book::updateAvailability(bool isBorrowed) {
    availabilityStatus = isBorrowed ? 'B' : 'A';
    std::cout << "Book " << bookID << " is now "
              << (availabilityStatus == 'A' ? "Available" : "Borrowed") << ".\n";
}

void Book::displayDetails() const {
    std::cout << "\n--- Book Details ---\n"
              << "ID: " << bookID << "\n"
              << "Title: " << title << "\n"
              << std::fixed << std::setprecision(2)
              << "Price: $" << price << "\n"
              << "Rating: " << rating << "/5\n"
              << "Status: " << (availabilityStatus == 'A' ? "Available" : "Borrowed") << "\n"
              << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << "\n"
              << "Genre: " << genreToString(genre) << "\n";
}

//Global Functions 
void markAsReference(Book& book) {
    book.setIsReferenceOnly(true);
    std::cout << "Book '" << book.getTitle() << "' marked as Reference Only.\n";
}

bool isAffordable(const Book& book, double budget) {
    return book.getPrice() <= budget;
}

void printFormattedBookList(const Book books[], int size) {
    std::cout << "\n--- Library Book List ---\n";
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(25) << "Title"
              << std::setw(10) << "Price"
              << std::setw(8) << "Rating"
              << std::setw(10) << "Status"
              << std::setw(12) << "Reference"
              << std::setw(12) << "Genre" << "\n";
    std::cout << std::string(80, '-') << "\n";

    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(5) << books[i].getBookID()
                  << std::setw(25) << books[i].getTitle().substr(0, 24)
                  << std::setw(10) << books[i].getPrice()
                  << std::setw(8) << books[i].getRating()
                  << std::setw(10) << (books[i].getAvailabilityStatus() == 'A' ? "Avail" : "Borrowed")
                  << std::setw(12) << (books[i].getIsReferenceOnly() ? "Yes" : "No")
                  << std::setw(12) << genreToString(books[i].getGenre()) << "\n";
    }
}
