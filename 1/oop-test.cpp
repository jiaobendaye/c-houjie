#include <iostream>
using namespace std;

class Base
{
public:
	Base(){cout << "Base constructor" << endl;}
	~Base(){cout << "Base destroy"<< endl;}
};

class Componet
{
public:
	Componet(){cout << "Componet constructor "<< endl;}
	~Componet(){cout << "Componet destroy "<< endl;}
};


class Derived :public Base
{
public:
	Derived(){cout << "Derived constructor"<< endl;}
	~Derived(){cout << "Derived destroy"<< endl;}
private:
	Componet temp;
};

void main()
{
	Derived test();

}
