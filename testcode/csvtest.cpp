//testingcsv
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void loadLibrary(){
    vector<string> files;
    files.push_back("BookCaseA");
    files.push_back("BookCaseB");
    files.push_back("BookCaseC");
    cout << files[0] << endl;
}
class Book{
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
        title(ti), author(au), year(yr), isbn(isb), copies(c) {}
};
class BookShelf{
    private:
        vector<Book>* bookshelf;
        int books;
    public:
        void addBook(const Book & bookie){
            
            bookshelf.push_back(& bookie);
            if (bookshelf.size() == 10) {
                cout << "Bookcase is full\n";
                //BookCase.incrementShelf();
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
    vector<Book>* bs;
    vector<BookShelf>* bookcase;
    public:
        void addBookShelf(<Book> & bs){
            if(shelf == 5) cout << "Error\n";
            bookcase[shelf] = bs; //add bookshelf to the bookcase at index shelf
            shelf++; //increment shelf after
            bs = new BookShelf;
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
