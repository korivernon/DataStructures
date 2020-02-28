// (Main Operations 1) 
//Inside of Bookcase
	vector<string> getBookFromtitle(vector<Shelf> shelf, string title){ 
		//having issues with incomplete access type
		//return the title and number of copies 
		vector<string> retVec;
		string search = tolower(title); //making the title lowercase 
		for(int i=0; i <= 3; i++){ //iterating through the bookcases
			if (shelf[i].getBook(shelf[i],title) == title){
				retVec.push_back(shelf[i].getBook(shelf[i],title).getTitle());
				retVec.push_back(shelf[i].getBook(shelf[i],title).numCopies());
				cout << "Successful!\nTitle: " << retVec[0] << "\nCopies " << retVec[1] << endl;
				return retVec;
			}
		cerr << "Error finding title, check spelling .\n";
		exit(1);
		}
	}
// Inside of Shelf 
int getBook(vector<Book> book, string title){
		for(int i=0; i <= 10; i++){
			if (book[i].getTitle() == title) return i+1; //returing the index+1 for the title.
		}
	}