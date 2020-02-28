#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#include <stdio.h>
//#include <sstream>
//const int NBIS = 10 ;
//int nob = 0;

using namespace std;

//void LoadBooks(string inFile);
class Book;
class Shelf;
class Bookcase;

class Bookcase{
	
private:
	int nos;
public:
	vector<Shelf> Library;
	Bookcase(){};

	void addBookcase(vector<Shelf> bookcasie, int nobc){
		Library.push_back(bookcasie[nobc]);
	};

	void printBookcase()
	{
		//books[0].print();
	};
};

class Shelf{
	friend class Bookcase;

private:
	int nob;
public:
	vector<Book> books;
	Shelf(){};

	void addBook(vector<Book> bookie, int nob)
	{
		books.push_back(bookie[nob]);
	};

	int getBook(vector<Book> book, string title){
		for(int i=0; i <= 10; i++){
			if (book[i].getTitle() == title) return i+1; //returing the index+1 for the title.
		}
	}
	void printshelf()
	{
		//books[0].print();
	}
	
};

class Book {
	friend class Shelf;
private:
	string title;
	string author;
	string ISBN;
	string year;
	int Num_of_Copies;

public:
	Book()
	{
		title = "";
		author = "";
		ISBN = "";
		year = "";
		Num_of_Copies = 0;
	};

	Book(string tit, string aut, string isbn, string yr,int noc){
		title = tit;
		author = aut;
		ISBN = isbn;
		year = yr;
		Num_of_Copies = noc;
	};

	~Book(){};
	
	const string getTitle(){
		return this->title;
	}

	void setTitle(string tit){
		title = tit;

	};

	void setAuthor(string aut){
		author = aut;           //add this-> to all
	};

	void setISBN(string isbn){
		ISBN = isbn;
	};

	void setYear(string YEAR){
		year = YEAR;
	};

	void setNum_of_Copies(int NoCopies){
		Num_of_Copies = NoCopies;
	};

	const string numCopies(){
		stringstream ss;
		ss << this->Num_of_Copies;
		return ss.str();
	}
	void print(){
		cout << "YOLO WORKING" << endl;
		cout << title << endl;
		cout << author << endl;
		cout << ISBN << endl;
		cout << year << endl;
		cout << Num_of_Copies << endl;
	};

};

int main(){
	string title1;
	string author1;
	string ISBN1;
	string year1;
	string value = " ";
	int noc = 0;
	int Num_of_Copies1;
	int booksinshelf = 0;
	int totalbooks = 0;

	int Atotalbooks = 0;
	int Btotalbooks = 0;
	int Ctotalbooks = 0;

	int Ashelfcount = 0;
	int Bshelfcount = 0;
	int Cshelfcount = 0;

	vector<Book> Abook;
	vector<Shelf> Ashelf;

	vector<Book> Bbook;
	vector<Shelf>Bshelf;

	vector<Book> Cbook;
	vector<Shelf> Cshelf;

	vector<Bookcase> bookcases;
	
	ifstream AFile("BookcaseA.csv", ios::in);

	if (AFile.fail()){
		cerr << "Error opening file.\n";
		exit(1);
	}
	getline(AFile, value);

	Ashelf.push_back(Shelf());
	
	while (!AFile.eof())
	{
		if (Ashelfcount > 5)
			break;

		getline(AFile, value, ',');
		title1 = value;
		//cout << "title" << title1 << endl;

		getline(AFile, value, ',');
		author1 = value;
		//cout << "Author" << author1 << endl;

		getline(AFile, value, ',');
		ISBN1 = value;
		//cout << "ISBN" << ISBN1 << endl;

		getline(AFile, value, ',');
		year1 = value;
		//cout << "Year" << year1 << endl;

		getline(AFile, value);
		noc = stoi(value);
		Num_of_Copies1 = noc;
		//cout << "NOC" << noc << endl;

		Abook.push_back(Book(title1, author1, ISBN1, year1, noc));
		Atotalbooks++;
		booksinshelf++;
		totalbooks++;

		if (noc > 1){
			for (int i = 0; i < noc - 1; i++){
				Abook.push_back(Book(title1, author1, ISBN1, year1, noc));
				Atotalbooks++;
				booksinshelf++;
				totalbooks++;
			}
		}
		if (booksinshelf == 10){
			Ashelf.push_back(Shelf());
			Ashelfcount++;
			booksinshelf = 0;
		}

	}

	booksinshelf = 0;
	for (int i = 0; i < Ashelfcount; i++){
		for (int j = 0; j < 10; j++){
			Ashelf[i].addBook(Abook, j);
			booksinshelf++;
			if (booksinshelf == Atotalbooks)
				break;
		}
	}

	for (int j = 0; j < Ashelfcount; j++){
		bookcases.push_back(Bookcase());
		bookcases[0].addBookcase(Ashelf, j);
	}
	
	cout << "ACount: " << Ashelfcount;
	cout << "ATotal: " << Atotalbooks << endl;

	AFile.close();

	ifstream BFile("BookcaseB.csv", ios::in);

	if (BFile.fail()){
		cerr << "Error opening file.\n";
		exit(1);
	}
	getline(BFile, value);

	Bshelf.push_back(Shelf());

	while (!BFile.eof())
	{
		if (Bshelfcount > 5)
			break;

		getline(BFile, value, ',');
		title1 = value;
		//cout << "title" << title1 << endl;

		getline(BFile, value, ',');
		author1 = value;
		//cout << "Author" << author1 << endl;

		getline(BFile, value, ',');
		ISBN1 = value;
		//cout << "ISBN" << ISBN1 << endl;

		getline(BFile, value, ',');
		year1 = value;
		//cout << "Year" << year1 << endl;

		getline(BFile, value);
		noc = stoi(value);
		Num_of_Copies1 = noc;
		//cout << "NOC" << noc << endl;

		Bbook.push_back(Book(title1, author1, ISBN1, year1, noc));
		Btotalbooks++;
		booksinshelf++;
		totalbooks++;

		if (noc > 1){
			for (int i = 0; i < noc - 1; i++){
				Bbook.push_back(Book(title1, author1, ISBN1, year1, noc));
				Btotalbooks++;
				booksinshelf++;
				totalbooks++;
			}
		}
		if (booksinshelf == 10){
			Bshelf.push_back(Shelf());
			Bshelfcount++;
			booksinshelf = 0;
		}

	}

	booksinshelf = 0;
	for (int i = 0; i < Bshelfcount; i++){
		for (int j = 0; j < 10; j++){
			Bshelf[i].addBook(Bbook, j);
			booksinshelf++;
			if (booksinshelf == Btotalbooks)
				break;
		}
	}

	for (int j = 0; j < Bshelfcount; j++){
		bookcases.push_back(Bookcase());
		bookcases[1].addBookcase(Bshelf, j);
	}

	//cout << Ashelfcount;

	BFile.close();

	cout << Bshelfcount << endl;
	cout << Btotalbooks << endl;

	ifstream CFile("BookcaseC.csv", ios::in);

	if (CFile.fail()){
		cerr << "Error opening file.\n";
		exit(1);
	}
	getline(CFile, value);

	Cshelf.push_back(Shelf());

	while (!CFile.eof())
	{
		if (Cshelfcount > 5)
			break;

		getline(CFile, value, ',');
		title1 = value;
		//cout << "title" << title1 << endl;

		getline(CFile, value, ',');
		author1 = value;
		//cout << "Author" << author1 << endl;

		getline(CFile, value, ',');
		ISBN1 = value;
		//cout << "ISBN" << ISBN1 << endl;

		getline(CFile, value, ',');
		year1 = value;
		//cout << "Year" << year1 << endl;

		getline(CFile, value);
		if (value != "")
			noc = stoi(value);
		else
			noc = 0;
		Num_of_Copies1 = noc;
		//cout << "NOC" << noc << endl;

		Cbook.push_back(Book(title1, author1, ISBN1, year1, noc));
		Ctotalbooks++;
		booksinshelf++;
		totalbooks++;

		if (noc > 1){
			for (int i = 0; i < noc - 1; i++){
				Cbook.push_back(Book(title1, author1, ISBN1, year1, noc));
				Ctotalbooks++;
				booksinshelf++;
				totalbooks++;
			}
		}
		if (booksinshelf == 10){
			Cshelf.push_back(Shelf());
			Cshelfcount++;
			booksinshelf = 0;
		}

	}

	booksinshelf = 0;
	for (int i = 0; i < Cshelfcount; i++){
		for (int j = 0; j < 10; j++){
			Cshelf[i].addBook(Cbook, j);
			booksinshelf++;
			if (booksinshelf == Ctotalbooks)
				break;
		}
	}

	for (int j = 0; j < Cshelfcount; j++){
		bookcases.push_back(Bookcase());
		bookcases[2].addBookcase(Cshelf, j);
	}

	
	cout << Cshelfcount << endl;
	cout << Ctotalbooks << endl;

	CFile.close();

	
	return 0;
}



/*void LoadFile(){
	
}*/


/*const int ShelvesPerBookcase = 5;
const int BooksPerShelf = 10;
const string CorrPassword = "NYUADlib";

void printmenu();
void enterpassword();
void search();
void add();
void remove();
void rearrange();
void copiesonshelf();
void numofbookcases();

int main(){

	int totbooks;

	cout << "Welcome to the Library System!" << endl;
	cout << "There are " << totbooks << " in the library" << endl;
	
	printmenu();

	return 0;
}

void printmenu()
{
	int choice;

	cout << "Please choose one of the following options: " << endl;

	cout << "1: Search for a book." << endl;
	cout << "2: Add a new book." << endl;
	cout << "3: Remove an existing book." << endl;
	cout << "4: Rearrange books." << endl;
	cout << "5: Access number of books on a shelf." << endl;
	cout << "6: Access number of bookcases in the library." << endl;
	cout << "7: Exit the system." << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
		search();
		break;
	case 2:
		add();
		break;
	case 3:
		remove();
		break;
	case 4:
		rearrange();
		break;
	case 5:
		copiesonshelf();
		break;
	case 6:
		numofbookcases();
		break;
	case 7:
		exit(0);
	}
}

void enterpassword()
{
	string password;
	int choice;

	cout << "Please enter the password." << endl;
	cin >> password;

	if (password != CorrPassword)
	{
		for (int i = 0; i < 2; i++)
		{

			cout << "Incorrect password. Please re-enter." << endl;
			cin >> password;

			if (password == CorrPassword)
				break;

			if (i == 1 && password != CorrPassword)
			{
				cout << "Sorry you do not have access to the database. " << endl;
				cout << "Press 1 to return to main menu or 2 to exit the system." << endl;
				cin >> choice;

				if (choice == 1)
					main();
				else
					exit(0);
				
			}
		}
	}

}
*/