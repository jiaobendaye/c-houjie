//calss template

//function template

//member template
template <class T1, class T2>
struct pair {
	T1 first;
	T2 second;
	pair() : first (T1()), second(T2()) {}
	pair(const T1& a, const T2& b) : first(a), second(b) {}
	
	template <class U1, class U2>
	pair(const pair<U1, U2> p) : first(p.first), second(p.second) {}
);
//using
class Base1 {};
class Derived1:public Base1 {};
class Base2 {};
class Derived2:public Base2 {};
pair<Derived1, Derived2> p;
pair<Base1, Base2> p2(p);//pair<Base1,Base2> p2(pair<Derived1, Derived2>());

//(full)specialization
template <calss key>//generation
struct hash {};

template<>
struct hash<int> {//speciaiazation
	size_t operator () (int x) const { return x;}
};//cout << hash<int>()(2);

//partical specilization
template<typename T, typename Alloc=..>
class vector
{
...
};
template<typename Alloc=..>
class vector<bool, Alloc>
{
....
};
template <typename T>//C<string> obj;
class C {...};

template <typename T>//C<string*> obj2;
class C<T*> {...};
//template template parameter
//design
template <typename T, 
					template <typename T> 
							class Container>
class XCls
{ 
private:
		Container<T> c;
public:
		....
};
//user
template <typename U>
using Lst = list<U, allocatior<U>>;
XCls<string, Lst> mylst;

