//Consider the following incomplete class definitions.
//Fill in the missing code as described in the comments.
//Your solution should call the appropriate set and get functions on a Book object.
class Book {
public:
	//Provide:
	void display();
	virtual void set(......) = 0;
	virtual int get()const = 0;
	
	// - a pure virtual function to set the ISBN/eISBN
	// - a pure virtual function to get the ISBN/eISBN
};
// create an EBook class that inherits from Book

class EBook:public Book
{
	int eISBN;
public:
	void set(const int _eISBN) { eISBN = _eISBN; };
	int get() const { return eISBN; };
};
//