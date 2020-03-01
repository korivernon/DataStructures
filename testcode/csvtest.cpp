//testingcsv
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
//open file function 
void openFile() {
    //attempt to open in each file.
    //if file fails, then an error should be printed on the screen
    //then the program closes automatically
    //filestream object
    ifstream ifs;
    vector<string> files;
    files.push_back("BookCaseA");
    files.push_back("BookCaseB");
    files.push_back("BookCaseC");
    for(const string& bookCaseName : files) {
        cout << bookCaseName << endl;
        ifs.open(bookCaseName);
        if (!ifs) {
            cerr << "Couldn't open this file! Sorry!\n";
            //cerr closes the program automatically.
        }
    }
}
//if you use the openFile function anywhere else, remember you opened the filestream
//close the filestream once you are done streaming from files, using the syntax ifs.close();
//ifs is the name of the ifstream object.
void loadLibrary(){
    vector<string> files;
    files.push_back("BookCaseA");
    files.push_back("BookCaseB");
    files.push_back("BookCaseC");
    cout << files[0] << endl;
}
class Book{
    //ostream allows you to print object directly! it is made a friend so it can access private fields for
    //theBook, but it is not made public so that the output operator can't be modified by any external code.
    //book is passed by constant reference and this is a unary operation (operaion that only has one bound
    //this is an operator overload!
    friend ostream& operator << (ostream& os, const Book& theBook) {
        os << "The title of the book is: " << theBook.title << endl;
        os << "Author: " << theBook.author << "ISBN: " << theBook.isbn << "Published: " <<
        theBook.year;
        return os;
    }
    //Title, Author	ISBN	Year	Number_of_copies
    private:
        string title, author, isbn, year;
        int copies;
    public:
        //Hellen:
        //Pass strings by constant reference in constructor since strings aren't primitive to c++
        //we use an initialization list to INITIALIZE the values, therefore we don't have to set
        //the values manually ourselves.
        Book(const string& ti, const string& au, const string& isb, const string& yr, int c) :
        title(ti), author(au), year(yr), isbn(isb), copies(c) {} //something so complex that you would have to initialize it in an initialization list
        // initializing private fields... your private field title is going to be initiialized to what title year is.
        
        // Book(const vector<Book*>& books) : 
};

//create outside class to load books in inside of the class.. 
class BookShelf{
    private:
        vector<Book*> bookshelf;
        //syntax for pointer objects are : objectName*
        // allocating books on the heap. Book* = new Book
        int books;
        int shelfnum;
    public:
        ~BookShelf;
        bool addBook(const string & ti, const string & au, const string & isb, const string & yr, int c){
            
            Book* bookName = new Book(ti, au, isb, yr, c);
            
            bookshelf.push_back(bookName);

            if (bookshelf.size() != 10) {
                cout << "Bookshelf is full\n";

                cout << "Bookshelf added to shelf number: " << shelfnum << endl;
                for (const Book & book: bookshelf) {
                    
                    cout << book;
                }
                cout << endl;
                return true;
                //BookCase.incrementShelf();
            }
        }

        const Book & getBook(const string & title){
            //is this the correct placement ????
            int counter = 0;
            for(const Book & book : bookshelf ){
                //for book in bookshelf
                counter ++;
                //counter to 
                if (book.title == title){
                    cout << "This is book number: " << counter << endl;
                    return true;
                    //return the book object in the vector if it's correct 
                }
            }
        }

        /*
        const Book & getBookCode(string call) const{
            return bookshelf[call]; //'a1.1' 1
        }
        const Book & findTitle(string title) const{ //returns index of book if found
            for(int i = 0; i < 10; i++){ //iterating through the bookshelves
                if (title == bookshelf[i].getTitle()) return i+1; // if you find it here then return it +1
            }
        }*/
};

class BookCase {
    int shelf; 
    // when something is a static, it belongs to the class type ... it doesnt belong to the instance of the object
    vector<Book*> bs;
    vector<BookShelf*> bookcase;
    public:
        //WRONG SYNTAX
        //HELLEN IS CHANGING THIS!
        bool addBookShelf(const vector<Book*>& newBookShelf){
            //Kori changed variable name ^^
            if(shelf == 5) {

                bookcase.push_back(newBookShelf);

                cout << "Error!\n Couldn't add book :(\n;";

                return false;
            }
            

            //bookcase[shelf] = bs; //add bookshelf to the bookcase at index shelf
            //shelf++; //increment shelf after
            //bs = new BookShelf;
        }

        const Book & getBookFromShelf(const string & title ){
            int counter  = 0;
            for(const BookShelf & bs : bookcase){
                //for bookshelf in bookcase...
                if (getBook(title).title == title){
                    cout << "Shelf Number: " << counter << endl; 
                }
                return getBook(title);
                // returning the book at this point... 
            }
        }


        /*
        const Book & getBook(string code)const {
            return bookcase[code[1]].getBookCode(code[3]); //take 'a1.1' for example.
        }
        const Book getBookByTitle(string title){
            for (int i=0; i<5; i++) {
                 if (bookcase[i].findTitle(title)){
                     //assign code once object is created
                 }
            }
        }*/

};

int main(){
    cout<< "hi" << endl;
    return 0;
}
