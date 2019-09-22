//designer pointer
template<class T>
class shared_ptr
{
public:
		T& operator* () const
		{ return *px; }
		
		T* operator->() const
		{ return px; }

		shared_ptr(T* p) : px(p) {}
private:
	T*    px;
	long* pn;
...
};
//user
struct Foo
{
.........
	void method (void) {...}
};

shared_ptr<Foo> sp(new Foo);

Foo f(*sp);
sp->method();//px->method();


//designer iter; need ++/--
template<cass T>;
struct __list_node {
	void* prev;
	void* next;
	T data;
};
template<class T, class Ref, class Ptr>
struct __list_iterator{
	typedef __list_iterator<T, Ref,Ptr> self;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef __list_node<T>* link_type;
	link_type node;
	bool operator==(const self& x) const (return node == x.node;}
	bool operator!=(const self& x) const (return node != x.node;}
	reference operator*() const { return (*node).data;} 
	pointer operator->() const { return &(operator*()); }	
	self& operator++() { node = (link_type) ((*node).next);return *this;}
	self operator++(int) { self tmp = *this; ++*this; return tmp;}
	self& operator--() { node = (link_type) ((*node).prev);return *this;}
	self operator--(int) { self tmp = *this; --*this; return tmp;}
};
//user
list<Foo>::iterator iter;
*iter;//get a Foo
iter->method();//Foo::method(); (*iter).method(); (&(*iter))->method();

