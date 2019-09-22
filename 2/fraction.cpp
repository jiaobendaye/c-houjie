class Fraction
{
public:
		Fraction(int num, int den=1) //non-explicit-one-argument ctor
			: m_numertor(nums), m_denominator(den) {}
		explicit Fraction(int num, int den=1) //explicit-one-argument ctor, can't be auto called 
			: m_numertor(nums), m_denominator(den) {}
		operator double() const { //conversion function, no return type
			return (double) (m_numerator / m_denominator)
		}
		Fraction operator + (const Fraction& f) {
			return Fraction(...);
		}
/*
Fraction f(3,5);
double d = 4+f; //conversion; 3/5 -> 0.6
Fraction d2 = f+4;//non-explicit ctor; 4 -> 4/1,if there is conversion function, compiler will confuse and return error

*/
private:
		int m_numerator;
		int m_denominator;
};
