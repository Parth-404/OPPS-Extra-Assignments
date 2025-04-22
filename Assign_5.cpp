/* A bookshop maintains the inventory of books that are being sold at the shop. The list includes details
 such as author, title, price, publisher and stock position. Whenever a customer wants a book, the
 salesperson inputs the title and author and the system searches the list and displays whether it is
 available or not. If it is not, an appropriate message is displayed. If it is, then the system displays the
 book details and requests for the number of copies required. If the requested copies are available, the
 total cost of the requested copies is displayed; otherwise �Required copies not in stock� is displayed.
 Design a system using a class called books with suitable member functions and constructors. Use new
 operators in constructors to allocate the memory space required*/
#include <iostream>
#include<string.h>
using namespace std;
class books{
	private:
		char *author, *title, *publisher;
		int price, stock_position;
	public:
		books(){}
		books(const char *a, const char *t, int pri, const char *p, int stock){
			author = new char[strlen(a)+1];
			strcpy(author,a);
			
			title = new char[strlen(title)+1];
			strcpy(title,t);
			
			price = pri;
			stock_position = stock;
			
			publisher = new char[strlen(p)+1];
			strcpy(publisher,p);
		}
		int find(char *t, char *a){
			if(strcmp(title,t)==0 && strcmp(author,a)==0){
				return 1;
			}
			else{
				return 0;
			}
		}
		void display(){
			cout<<"Book available, details are: "<<endl;
			cout<<"Title : "<<title<<endl;
			cout<<"Author : "<<author<<endl;
			cout<<"Publisher : "<<publisher<<endl;
			cout<<"Price : "<<price<<endl;
			
		}
		void check_copies(int c){
			if(stock_position>c){
				cout<<"\nTotal price : "<<c*price;
			}
			else{
				cout<<"\nRequired copies are not in stock";
			}
		}
		~books() {
        	delete[] author;
        	delete[] title;
        	delete[] publisher;
   		}
};
int main()
{
	books obj1("author1","book1",250,"xyz",10);
	books obj2("author2","book2",300,"pqr",5);
	char title[100],author[100];
	int copies;
	
	cout<<"Enter title and author of book to find : "<<endl;
	cin.getline(title,100);
	cin.getline(author,100);
	
	if(obj1.find(title,author)){
		obj1.display();
		cout<<"\nEnter number of copies required : ";
		cin>>copies;
		obj1.check_copies(copies);
	}else if(obj2.find(title,author)){
		obj2.display();
		cout<<"\nEnter number of copies required : ";
		cin>>copies;
		obj2.check_copies(copies);
	}else{
		cout<<"\nBook not in list.";
	}
 	return 0;
}

