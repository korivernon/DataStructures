//testingcsv
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
class Book{
    //Title, Author	ISBN	Year	Number_of_copies
    private:
        string title, author, isbn, year;
        int copies;
    public:
        Book(string ti, string au, string isb, string yr, int c, string code = ''){
            title = ti;
            author = au;
            year = yr;
            isbn = isb;
            copies = c
        }
        const string getTitle(){
            return this->title;
        }
};
class BookShelf{
    private:
        vector<Book> bookshelf;
        int books;
    public:
        void addBook(const Book & bookie){
            
            bookshelf.pushback(bookie);
            if (bookshelf.size() == 10) {
                cout << "Bookcase is full\n";
                //BookCase.incrementShelf();
            }
        const Book & getBookCode(string call) const{
            return bookshelf[call]; //'a1.1' 1
        }
        const Book & findTitle(string title) const{ //returns index of book if found
            for(int i = 0; i < 10; i++){ //iterating through the bookshelves
                if (title == bookshelf[i].getTitle()) return i+1; // if you find it here then return it +1
            }
        }
};
class BookCase {
    int shelf=0;
    bookcase <vector<BookShelf>;
    public:
        void addBookShelf(<Book> bs){
            if(shelf == 5) cout << "Error\n";
            bookcase[shelf].pushback(bs); //add bookshelf to the bookcase at index shelf
            shelf+=1; //increment shelf after
        }
        const Book & getBook(string code)const {
            return bookcase[code[1]].getBookCode(code[3]); //take 'a1.1' for example.
        }
        const Book & getBookByTitle(string title)const{
            for (int i=0; i<5; i++) {
                 if (bookcase[i].findTitle(title)){
                     //assign code once object is created
                 }
            }
        }

}
int main(){
    Book book;
    return 0;
}