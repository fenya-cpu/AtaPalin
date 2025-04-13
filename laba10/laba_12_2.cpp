#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Book 
{
    string name;
    string janr;
    int price;
    int popul;
    string data;
    bool sold;
};

void addBook(vector<Book>& books) 
{
    Book book;
    cout<<"Nazva knygy: ";
    cin>>book.name;
	cout<<"Janr: ";
    cin>>book.janr;
    cout<<"Price: ";
    cin>>book.price;
    cout<<"Populiarnisti (0-100): ";
    cin>>book.popul;
    cout<<"Data nathodjenia (YYYY-MM-DD): ";
    cin>>book.data;
    book.sold=false;
    books.push_back(book);
}

void del(vector<Book>& books) 
{
    for (int i=0;i<books.size(); ) 
	{
        if(books[i].sold) 
		{
            books.erase(books.begin()+i);
        } 
		else
		{
            i++;
        }
    }
    cout<<"Rozprodani vydaleno.\n";
}

bool porivprice(Book a, Book b) 
{
    return a.price<b.price;
}

bool porivpopul(Book a, Book b) 
{
    return a.popul>b.popul;
}

bool porivdata(Book a, Book b) 
{
    return a.data<b.data;
}

void filtjanr(vector<Book>& books, string janr) 
{
    bool f=false;
    for(int i=0;i<books.size();i++)
	{
        if(books[i].janr==janr) 
		{
            cout<<"Knyga: "<<books[i].name<<", Price: "<<books[i].price<<endl;
            f=true;
        }
    }
    if(!f) 
	cout << "Nemae knyg takogo janru.\n";
}

void filtprice(vector<Book>& books,int min,int max) 
{
    bool f=false;
    for (int i=0;i<books.size();i++) 
	{
        if(books[i].price>=min && books[i].price<=max) 
		{
            cout<<"Knygа: "<<books[i].name<<", price: "<<books[i].price<<endl;
            f=true;
        }
    }
    if(!f) 
	cout<<"Knygy v tiomu diapazoni ne znaideno.\n";
}

void search(vector<Book>& books, string slovo) 
{
    bool f=false;
    for (int i=0;i<books.size();i++) 
	{
        if(books[i].name==slovo) 
		{
            cout<<"Znaideno: "<<books[i].name<<", price: "<<books[i].price<<endl;
            f=true;
        }
    }
    if(!f) 
	cout<<"Knygy ne znaideno.\n";
}

void printl(vector<Book>& books) {
	
    if(books.empty()) 
	{
        cout<<"Spysok porojniy.\n";
        return;
	}
    for(int i=0;i<books.size();i++) 
	{
        cout<<i+1<<") "<<books[i].name<<", janr: "<<books[i].janr<<", price: "<<books[i].price<<", populiarnisti: "<<books[i].popul<<", data: "<<books[i].data<<", rozprodano: "<<(books[i].sold ? "yes" : "no")<<endl;
    }
}

int main() 
{
    vector<Book> books;
    int choice;

    do {
        cout<<"\n---Meniy knyjnoho magazinu ---\n";
        cout<<"1. dodaty knyjku\n";
        cout<<"2. vydalyty rozprodani kyjky\n";
        cout<<"3. sortuvaty za tsinoiu\n";
        cout<<"4. Sortuvaty za populiarnostiu\n";
        cout<<"5. Sortuvaty za datoiu nadhodjenia\n";
        cout<<"6. Filtratia za janrom\n";
        cout<<"7. Filtratia za tsinoiu (min ta max)\n";
        cout<<"8. Poshuk knygy za nazvoiu\n";
        cout<<"9. Pokazaty usi knygy\n";
        cout<<"0. Exit\n";
        cout<<"Vediti: ";
        cin>>choice;

        if (choice==1) 
		{
            addBook(books);
        } 
		else if(choice==2) 
		{
            del(books);
        } 
		else if(choice==3) 
		{
            sort(books.begin(), books.end(), porivprice);
            cout<<"Vidsortovano za tsinoiu\n";
        } 
		else if(choice==4) 
		{
            sort(books.begin(), books.end(), porivpopul);
            cout<<"Vidsortovano za populiarnostiu.\n";
        } 
		else if(choice==5) 
		{
            sort(books.begin(), books.end(), porivdata);
            cout<<"Vidsortovano za datoiu.\n";
        } 
		else if(choice==6) 
		{
            string janr;
            cout<<"Vediti janr: ";
            cin>>janr;
            filtjanr(books,janr);
        } 
		else if(choice==7) 
		{
            int min, max;
            cout<<"minprice: ";
            cin>>min;
            cout<<"maxprice: ";
            cin>>max;
            filtprice(books,min,max);
        } 
		else if(choice==8) 
		{
            string slovo;
            cout<<"Vediti nazvu: ";
            cin>>slovo;
            search(books,slovo);
        } 
		else if(choice==9) 
		{
            printl(books);
        } 
		else if(choice==0) 
		{
            cout<<"Exit\n";
        } 
		else 
		{
            cout<<"Nevirno\n";
        }

    }while(choice!=0);

    return 0;
}
