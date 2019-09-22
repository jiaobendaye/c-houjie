int x=0;
int* p = &x;
int& r = x;//r is a reference to x, complier use a opinter to  impletement it
int x2 =5;
// sizeof(r) == sizeof(x); &x == &r; this is just be maked by compiler
r= x2;// r can't reference to others, so r and x are 5 both.
int& r2 = r;//r2 is a reference to r,also means  reference to x
//reference use	:pass
//design
void func1 (Cls* pobj) { pobj->xx(); }
void func2 (Cls obj) { obj.xx(); }
void func3 (Cls& obj) { obj.xx(); }
//call
Cls obj;
func1(&obj);
func2(obj);
func3(obj);
			|			signature				  		  |//const is a part of signature
double imag(const double& im) const {...}//same signature
double imag(const double im) const  {...} //Ambiguity
