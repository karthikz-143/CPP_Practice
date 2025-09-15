#include "Book.h"
#include <limits>   // for input validation

// Flush unwanted input
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Get genre choice from user
Genre getGenreFromUser() {
    int choice;
    std::cout << "Choose Genre:\n"
              << "1. Fiction\n2. Non-Fiction\n3. Science\n4. History\n5. Technology\n"
              << "Enter choice (1-5): ";
    std::cin >> choice;

    while (std::cin.fail() || choice < 1 || choice > 5) {
        std::cout << "Invalid choice. Try again (1-5): ";
        std::cin.clear();
        clearInputBuffer();
        std::cin >> choice;
    }
    clearInputBuffer();

    switch (choice) {
        case 1: return FICTION;
        case 2: return NONFICTION;
        case 3: return SCIENCE;
        case 4: return HISTORY;
        case 5: return TECHNOLOGY;
        default: return UNKNOWN_GENRE;
    }
}

int main() {
    Book libraryBooks[3]; // array of 3 books

    // sample data
    libraryBooks[0] = Book(101, 4.5f, 299.99, 'A', false, "C++ Primer", TECHNOLOGY);
    libraryBooks[1] = Book(102, 3.8f, 150.00, 'B', true, "Design Patterns", SCIENCE);
    // libraryBooks[2] uses default constructor

    int choice;
    do {
        std::cout << "\n--- Library Menu ---\n"
                  << "1. Add/Update Book\n"
                  << "2. Mark as Reference\n"
                  << "3. Check Affordability\n"
                  << "4. Update Availability\n"
                  << "5. Show Book Details\n"
                  << "6. Show All Books\n"
                  << "7. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        if (choice < 1 || choice > 7) {
            std::cout << "Invalid option. Try again.\n";
            continue;
        }

        if (choice == 7) {
            std::cout << "Goodbye!\n";
            break;
        }

        int idx;
        std::cout << "Enter book index (0-2): ";
        std::cin >> idx;

        if (idx < 0 || idx >= 3) {
            std::cout << "Invalid index.\n";
            continue;
        }

        switch (choice) {
            case 1: { // Add/Update
                int id; float rating; double price; char status; bool ref;
                std::string title;
                std::cout << "Enter ID: "; std::cin >> id;
                std::cout << "Enter Rating (0-5): "; std::cin >> rating;
                std::cout << "Enter Price: "; std::cin >> price;
                std::cout << "Status (A/B): "; std::cin >> status;
                std::cout << "Reference only (1/0): "; std::cin >> ref;
                clearInputBuffer();
                std::cout << "Enter Title: "; std::getline(std::cin, title);
                Genre g = getGenreFromUser();

                libraryBooks[idx] = Book(id, rating, price, status, ref, title, g);
                break;
            }
            case 2: markAsReference(libraryBooks[idx]); break;
            case 3: {
                double budget;
                std::cout << "Enter budget: $"; std::cin >> budget;
                if (isAffordable(libraryBooks[idx], budget))
                    std::cout << "Book is affordable.\n";
                else
                    std::cout << "Book is NOT affordable.\n";
                break;
            }
            case 4: {
                bool borrowed;
                std::cout << "Borrowed? (1/0): "; std::cin >> borrowed;
                libraryBooks[idx].updateAvailability(borrowed);
                break;
            }
            case 5: libraryBooks[idx].displayDetails(); break;
            case 6: printFormattedBookList(libraryBooks, 3); break;
        }
    } while (true);

    return 0;
}
