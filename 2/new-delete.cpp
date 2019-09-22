//new delete override; global; ::new, ::delete
void* myAlloc(size_t size)
{ return malloc(size); }
void myFree(void* ptr)
{ return free(ptr); }
//they are not supposed be decalred in one namespace
inline void* 
operator new(size_t size(
{ cout<< "jjhou global new() \n"; return myAlloc(size);}
inline void* 
operator new[](size_t size(
{ cout<< "jjhou global new[]() \n"; return myAlloc(size);}
inline void
operator delete(void* ptr)
{ cout<< "jjhou global delete() \n"; myFree(ptr); }
inline void
operator delete[](void* ptr)
{ cout<< "jjhou global delete[]() \n"; myFree(ptr); }

//override; member 
class Foo {
public:
	void* operator new(size_t);//
	void  operator delete(void*, size_t); //size_t is optinoal		
	//...
};
//user
Foo* p = new Foo;
/*
void* mem = operator new(sizeof(Foo));
p = static_cast<Foo*>(mem);
p->Foo::Foo(); 
*/
delete p;
/*
p->~Foo();
operator delete(p);
*/
//design
class Foo {
public:
	void* operator new[](size_t);//
	void  operator delete[](void*, size_t); //size_t is optinoal			
	//...
};
//user
Foo* p = new Foo[N];
/*
void* mem = operator new(sizeof(Foo) * N + 4);//4 bytes is uesd for record the lengh of array(counter)
p = static_cast<Foo*>(mem);
p->Foo::Foo(); //N times
*/
delete [] p;
/*
p->~Foo();//N times
operator delete(p);
*/

//palcement new() delete()
class Foo {
public:
	void* operator new(size_t size);//
	void* operator new(size_t size, void* start);//
	void* operator new(size_t size, long extra);//
	void* operator new(size_t size, long extra, char init);// Foo* p = new (199, 'c') Foo;
	void  operator delete(void*, size_t); //size_t is optinoal	
	void* operator delete(void*, void*);//
	void* operator delete(void*, long);//
	void* operator delete(void*, long, char);	
	//...
};
