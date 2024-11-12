#include <iostream>
#include <string>
using namespace std;

const int MAX_AUTHORS = 10;

class Topic {
private:
    string code;
    string name;

public:
    Topic() : code(""), name("") {}

    Topic(string code, string name) : code(code), name(name) {}

    string getCode() const { return code; }
    string getName() const { return name; }

    bool operator==(const Topic& other) const {
        return code == other.code && name == other.name;
    }

    friend ostream& operator<<(ostream& os, const Topic& topic) {
        os << topic.name;
        return os;
    }
};

class Author {
private:
    string firstName;
    string lastName;
    Topic bestTopic;
    int booksWritten;

public:
    Author() : firstName(""), lastName(""), booksWritten(0) {}

    Author(string firstName, string lastName, Topic bestTopic, int booksWritten)
        : firstName(firstName), lastName(lastName), bestTopic(bestTopic), booksWritten(booksWritten) {}

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Topic getBestTopic() const { return bestTopic; }
    int getBooksWritten() const { return booksWritten; }

    bool operator==(const Author& other) const {
        return firstName == other.firstName && lastName == other.lastName;
    }

    Author& operator=(const Author& other) {
        if (this != &other) { 
            firstName = other.firstName;
            lastName = other.lastName;
            bestTopic = other.bestTopic;
            booksWritten = other.booksWritten;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Author& author) {
        os << author.firstName << " " << author.lastName;
        return os;
    }

    bool matchesName(const string& first, const string& last) const {
        return firstName == first && lastName == last;
    }
};

class Book {
private:
    string title;
    Topic topic;
    Author* authors[MAX_AUTHORS];
    int authorCount;

public:
  
    Book() : title(""), authorCount(0) {}

    Book(string title, Topic topic)
        : title(title), topic(topic), authorCount(0) {}

    ~Book() {
        for (int i = 0; i < authorCount; ++i) {
            delete authors[i]; 
        }
    }


    string getTitle() const { return title; }
    string getTopicName() const { return topic.getName(); }

    bool addAuthor(Author* newAuthor) {
        if (authorCount < MAX_AUTHORS) {
            authors[authorCount++] = newAuthor;
            return true;
        }
        return false;
    }

    bool removeAuthor(const string& firstName, const string& lastName) {
        for (int i = 0; i < authorCount; i++) {
            if (authors[i]->matchesName(firstName, lastName)) {
                for (int j = i; j < authorCount - 1; j++) {
                    authors[j] = authors[j + 1];
                }
                authorCount--;
                return true;
            }
        }
        return false;
    }

    bool isAuthorOfBook(const string& firstName, const string& lastName) const {
        for (int i = 0; i < authorCount; i++) {
            if (authors[i]->matchesName(firstName, lastName)) {
                return true;
            }
        }
        return false;
    }

    double getAverageBooksWritten() const {
        if (authorCount == 0) return 0.0;

        int totalBooks = 0;
        for (int i = 0; i < authorCount; i++) {
            totalBooks += authors[i]->getBooksWritten();
        }
        return static_cast<double>(totalBooks) / authorCount;
    }

    Author* getTopAuthor() const {
        if (authorCount == 0) return nullptr;

        Author* topAuthor = authors[0];
        for (int i = 1; i < authorCount; i++) {
            if (authors[i]->getBooksWritten() > topAuthor->getBooksWritten()) {
                topAuthor = authors[i];
            }
        }
        return topAuthor;
    }

    int countMatchingBestTopic() const {
        int count = 0;
        for (int i = 0; i < authorCount; i++) {
            if (authors[i]->getBestTopic().getCode() == topic.getCode()) {
                count++;
            }
        }
        return count;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << book.title << " (" << book.topic << ")";
        return os;
    }
};

int main() {
    Topic fiction("FIC", "Fiction");
    Topic science("SCI", "Science");

    Author author1("John", "Doe", fiction, 10);
    Author author2("Jane", "Smith", science, 15);
    Author author3("Emily", "White", fiction, 5);

    Book book("Amazing Stories", fiction);
    book.addAuthor(&author1);
    book.addAuthor(&author3);

    cout << "Book title: " << book.getTitle() << "\n";
    cout << "Book topic: " << book.getTopicName() << "\n";

    cout << "Is 'John Doe' an author of this book? "
        << (book.isAuthorOfBook("John", "Doe") ? "Yes" : "No") << "\n";

    cout << "Average number of books written by authors: "
        << book.getAverageBooksWritten() << "\n";

    cout << "Removing author 'Emily White'...\n";
    book.removeAuthor("Emily", "White");

    cout << "Is 'Emily White' an author of this book? "
        << (book.isAuthorOfBook("Emily", "White") ? "Yes" : "No") << "\n";

    Author* topAuthor = book.getTopAuthor();
    if (topAuthor != nullptr) {
        cout << "Author with the most books written: "
            << topAuthor->getFirstName() << " " << topAuthor->getLastName()
            << " (" << topAuthor->getBooksWritten() << " books)\n";
    }

    cout << "Number of authors whose best topic matches the book's topic: "
        << book.countMatchingBestTopic() << "\n";

    return 0;
}
