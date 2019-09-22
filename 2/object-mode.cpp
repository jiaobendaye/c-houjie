//vptr and vtbl
class A {
public:
	virtual void vfunc1();
	virtual void vfunc2();
	void func1();
	void func2();
private:
	int m_data1, m_data2;
};
class B : public: A{
public:
	virtual void vfunc1();
	void func2();
private:
	int m_data3;
};
class C : public B{
public:
	virtual void vfunc1();
	void func2();
private:
	int m_data1, m_data4;
};
/*
non-virtual member functions
A::func1() A::func2() B::func2() C::func2()
virtual member functions
A::vfunc1() A::vfunc2() B::vfunc1() C::func1()
*/
// (*(p->vptr)[n])(p); (* p->vptr[n] )(p);

list<A*> myLst;
/*
dynamic binding
1 pointer
2 up cast
3 virtual function

*/

//this
