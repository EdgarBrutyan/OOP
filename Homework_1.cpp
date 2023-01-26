#include<iostream>
#include<vector>
#include<unordered_map>

class Book {
private:
    std::string title;
    std::string author;

public:
    void set_title(const std::string& title)
    {
        this->title = title;
    }

    void set_author(const std::string& author)
    {
        this->author = author;
    }

    const std::string& get_name() const
    {
        return title;
    }

    const std::string& get_author() const
    {
        return author;
    }

    const bool operator ==(const Book& book) const
    {
        return (this->title == book.get_name() && this->author == book.get_author());
    }

};

namespace std {

    template<>
    struct hash<Book>
    {
        std::size_t operator()(const Book& book) const
        {
            using std::hash;
            using std::size_t;

            return(hash<string>()(book.get_name()));
        }
    };
}

class Library {
private:
    std::unordered_map<Book, int> library;

public:
    void add_book(const Book& book)
    {
        if (library.find(book) == library.end())
        {
            library.insert({ book, 1 });
        }
        else
        {
            auto it = library.find(book);
            (it->second)++;
        }
    }

    void giving_book(const Book& book)
    {
        if (library.find(book) == library.end())
        {
            std::cout << "There is no such book in library";
            return;
        }
        else
        {
            auto it = library.find(book);

            if (it->second == 1)
            {
                library.erase(book);
            }

            std::cout << "Thank you for comming";
        }
    }
};

class Person {
private:
    const std::string name;
    const std::string surname;
    int count{ 5 };

public:
    explicit Person(const std::string& _name, const std::string& _surname)
        : name(_name), surname(_surname) {}

    void visit(Library& lib)
    {
        std::cout << "Do you wanna get the book ? ps: Yes or No" << "\n";

        std::string patasxan;
        std::cin >> patasxan;

        if (patasxan == "Yes")
        {
            Book book; 
            std::cout << "enter the titile of book and its author";

            std::string title, author;
            std::cin >> title >> author;
            lib.giving_book(book);
        }

        else if (patasxan == "No")
        {
            Book book;
            std::cout << "What book you want to return, say the title and author";
            std::string title, author;
            std::cin >> title >> author;

            std::cout << "So, I guess, you want to return book" << "\n";
            std::cout << "Thank you for backing";
            lib.add_book(book);
        }
    }
    void read(const Book& book)
    {
        std::cout << "The student is reading the" << book.get_name() << "of" << book.get_author();
    }
};

int main()
{
    Book book1;
    book1.set_title("War and Piece");
    book1.set_author("Lev Tolstoi");

    Book book2;
    book2.set_title("Chaous");
    book2.set_author("Alexander Shirvanzade");

    Library library;
    library.add_book(book1);
    library.add_book(book2);

    Person a1("Harut", "Stepanyan");
    a1.visit(library);

    return 0;
}