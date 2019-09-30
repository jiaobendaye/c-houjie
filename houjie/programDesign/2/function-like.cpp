//designer
template<class Arg, class Result>//base classes
struct unary_functio {
	typedef Arg argument_type;
	typedef Result result_type;
};

template <class T>
struct identity : public unary_function<T,T> {
	const T&
	operator() (const T& x) const {return x;}
};

template <class T1, class T2>
struct pair {
	T1 first;
	T2 second;
	pair() : first (T1()), second(T2()) {}
	pair(const T1& a, const T2& b) : first(a), second(b) {}
...
);

template <class Pair>
struct select1st : public unary_function<Pair,type Pair::first_type> {
	const typename Pair::first_type&
	operator () (const Pair& x) const
	{ return x.first;}
};

template <calss Pair>
struct select2nd : public unary_function<Pair,type Pair::second_type> {
	const typename Pair::second_type&
	operator () (const Pair& x) const
	{ return x.second;}
};

//user
pair p(1,2);
select1st()(p);
