//static

class Account {
public:
    static double m_rate;
    static void set_rate(const double& x) { m_rate = x;}

};
double Account::m_rate = 8.0;
void main(){
    Account::set_rate(5.0);
    Account a;
    a.set_rate(5.0);
}

//singleton
class A {
public:
    static A& getInstance();
    setup() {...}
private:
    A();
    A(const A& rhs);
    ...
};
A& A::getInstance()
{
    static A a;
    return a;
} 

int main(){
A::getInstance().setup();
}

//template
template<typename T> 
class complex
{
public:
    complex (T r = 0, T i = 9)
     : re (r), im (i)
    {}
private:
    T re, im;
}
int main{
complex<double> c1();
complex<int> c2;
}
//function template
class ston
{
public:
	stone(int w, int h, int we)
     : _w (w), _h(h), _weight(we)
	{}
	bool operator < (const stone& rhs)
	{ return _weight < rhs._weight; }
private:
    int _w, _h, _weight;
};
template <class T>
inline 
const T& min (const T& a, const T& b)
{
  return  b < a ? b : a;
}

int main(){
stone r1(2,3), r2(3,4), r3;
r3 = min(r1, r2);
}
//namespace
namespace std 
{
    ......
}
using namespace std;//using directive
using namespace std::cin;//using declaration
int main()
{
	cin <<;
	std::cin <<;
