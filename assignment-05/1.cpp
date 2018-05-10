#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
using namespace std;
const int index = 5;

class fraction
{
	protected:
		int numerator;
		int denumerator;
	public:
		void simplfy();
		fraction(int num, int denum);
		~fraction();
		void setValues(int num, int denum);
		void setValues();
		void updateNumerator(int num);
		void updateDenumerator(int denum);
		int getNumerator();
		int getDenumerator();
		fraction get();
		void print();
		friend istream& operator>>(istream& cin, fraction& fract);
		friend ostream& operator<<(ostream& cout, fraction& fract);

		fraction operator ++();
		fraction operator ++(int);
		fraction operator --();
		fraction operator --(int);
		
		fraction operator +(fraction fract);
		fraction operator -(fraction fract);
		fraction operator *(fraction fract);
		fraction operator /(fraction fract);
		
		
		bool operator ==(fraction fract);
		bool operator !=(fraction fract);
		bool operator >(fraction fract);
		bool operator <(fraction fract);
		bool operator >=(fraction fract);
		bool operator <=(fraction fract);
		
		fraction operator =(fraction fract);
		void operator +=(fraction fract);
		void operator -=(fraction fract);
		void operator *=(fraction fract);
		void operator /=(fraction fract);
		
};

//////Extra function

int string_to_int(string str);


// constructor

fraction::fraction(int num = 0, int denum = 1)
{
	numerator = num;
	denumerator = denum;
}





// destructor

fraction::~fraction()
{
	numerator = 0;
	denumerator = 1;
}





// Mutator


void fraction::setValues(int num, int denum)
{
	numerator = num;
	if(denum != 0)
	{
		denumerator = denum;
		simplfy();
	}
	else
		cout<<"Denumerator should not be zero"<<endl;
	
}

void fraction::setValues()
{
	int num = 0;
	int denum = 0;
	char character;
	cout<<"Enter a Fraction: ";
	cin>>num>>character>>denum;
	numerator = num;
	if(denum != 0)
	{
		denumerator = denum;
		simplfy();
	}
	else
		cout<<"Denumerator should not be zero"<<endl;
	
}


void fraction::updateNumerator(int num)
{
	numerator = num;
	simplfy();
}


void fraction::updateDenumerator(int denum)
{
	if(denum != 0) 
	{
		denumerator = denum;
		simplfy();
	}		
	else
		cout<<"Denumerator should not be zero"<<endl;
}




// Accesser

int  fraction::getNumerator()
{
	return numerator;	
}

int fraction::getDenumerator()
{
	return denumerator;
}

fraction fraction::get()
{
	fraction temp;
	temp.updateNumerator(numerator);
	temp.updateDenumerator(denumerator);
	return temp;
}

void fraction::print()
{
	simplfy();
	cout<<"Fraction is : "<<numerator <<"/"<<denumerator<<endl;
}


// Unary operator ++ & -- prefix

fraction fraction:: operator ++()
{
	numerator += denumerator;
	return fraction(numerator, denumerator);
}

fraction fraction:: operator --()
{
	
	numerator -= denumerator;
	return fraction(numerator, denumerator);
}

// Unary operator ++ & -- postfix

fraction fraction::operator ++(int)
{
	fraction fract;
	fract.updateNumerator(numerator);
	fract.updateDenumerator(denumerator);
	numerator += denumerator;
	return fract;
}

fraction fraction::operator --(int)
{
	fraction fract;
	fract.updateNumerator(numerator);
	fract.updateDenumerator(denumerator);
	numerator -= denumerator;
	return fract;
}



// Binary Operator +, - , *, /

fraction fraction:: operator +(fraction fract)
{
	fraction temp;
	temp.updateDenumerator(fract.getDenumerator() * denumerator);
	temp.updateNumerator(((temp.getDenumerator() / denumerator)*numerator) + ((temp.getDenumerator() / fract.getDenumerator()) * fract.getNumerator()));
	temp.simplfy();
	return temp;
	 
}


fraction fraction:: operator -(fraction fract)
{
	fraction temp;
	temp.updateDenumerator(fract.getDenumerator() * denumerator);
	temp.updateNumerator(((temp.getDenumerator() / denumerator)*numerator) - ((temp.getDenumerator() / fract.getDenumerator()) * fract.getNumerator()));
	temp.simplfy();
	return temp;
	 
}


fraction fraction::operator *(fraction fract)
{
	fraction temp;
	temp.updateDenumerator(fract.denumerator * denumerator);
	temp.updateNumerator(fract.numerator * numerator);
	temp.simplfy();
	return temp;
}


fraction fraction::operator /(fraction fract)
{
	fraction temp;
	temp.updateDenumerator(denumerator * fract.numerator);
	temp.updateNumerator(numerator * fract.denumerator);
	temp.simplfy();
	return temp;
}


//// Special Function

void fraction::simplfy()
{
	if (numerator < 0 && denumerator < 0)
	{
		numerator *= -1;
		denumerator *= -1;
	}
	else if (denumerator < 0 && numerator > 0)
	{
		numerator *= -1;
		denumerator *= -1;
	}
	else
	{
		numerator = numerator;
		denumerator = denumerator;
	}
	int n = 2;
	int limit = 0;
	if (numerator >= denumerator)
		limit = denumerator;
	else
		limit = numerator;
	 
	while (n <= limit)  
		if (numerator % n == 0 && denumerator % n == 0)
		{
			numerator = numerator / n;
			denumerator = denumerator / n;
		} 
		else
		{
			n += 1;
		}
}






////Relational Operator ==, !=, >, >=, <, <=


bool fraction:: operator ==(fraction fract)
{
	if (numerator == fract.numerator && denumerator == fract.denumerator)
		return true;
	else
		return false;
}

bool fraction:: operator !=(fraction fract)
{
	if (numerator == fract.numerator && denumerator == fract.denumerator)
		return false;
	else
		return true;
}


bool fraction:: operator >(fraction fract)
{
	if (numerator == fract.numerator && denumerator == fract.denumerator)
		return false;
	else
	{
		float num1 = numerator;
		float denum1 = denumerator;
		float num2 = fract.numerator;
		float denum2 = fract.denumerator;
		float Num1 = num1 / denum1;
		float Num2 = num2 / denum2;
		if(Num1 > Num2)
			return true;
		else
			return false;
	}
		
}


bool fraction:: operator >=(fraction fract)
{
	if (numerator == fract.numerator && denumerator == fract.denumerator)
		return true;
	else
	{
		float num1 = numerator ;
		float denum1 = denumerator ;
		float num2 = fract.numerator ;
		float denum2 = fract.denumerator;
		float Num1 = num1 / denum1;
		float Num2 = num2 / denum2;
		if(Num1 > Num2)
			return true;
		else
			return false;
	}
		
}


bool fraction:: operator <(fraction fract)
{
	if (numerator == fract.numerator && denumerator == fract.denumerator)
		return false;
	else
	{
		float num1 = numerator;
		float denum1 = denumerator;
		float num2 = fract.numerator;
		float denum2 = fract.denumerator;
		float Num1 = num1 / denum1;
		float Num2 = num2 / denum2;
		if(Num1 < Num2)
			return true;
		else
			return false;
	}
		
}






bool fraction:: operator <=(fraction fract)
{
	if (numerator == fract.numerator && denumerator == fract.denumerator)
		return true;
	else
	{
		float num1 = numerator ;
		float denum1 = denumerator ;
		float num2 = fract.numerator ;
		float denum2 = fract.denumerator ;
		float Num1 = num1 / denum1;
		float Num2 = num2 / denum2;
		if(Num1 < Num2)
			return true;
		else
			return false;
	}		
}



//// Assignment Operator


fraction fraction:: operator=(fraction fract)
{
	numerator = fract.numerator; 
	denumerator = fract.denumerator;
	simplfy();
} 


void fraction::operator += (fraction fract)
{
	int denum = denumerator;
	denumerator = denumerator * fract.denumerator;
	numerator =  (numerator * (denumerator /denum)) + (fract.numerator * (denumerator / fract.denumerator));
	simplfy();
}

void fraction::operator -= (fraction fract)
{
	int denum = denumerator;
	denumerator = denumerator * fract.denumerator;
	numerator =  (numerator * (denumerator /denum)) - (fract.numerator * (denumerator / fract.denumerator));
	simplfy();
}

void fraction::operator *= (fraction fract)
{
	
	denumerator = denumerator * fract.denumerator;
	numerator =  numerator*fract.numerator;
	simplfy();
}


void fraction::operator /= (fraction fract)
{
	
	denumerator = denumerator * fract.numerator;
	numerator =  numerator*fract.denumerator;
	simplfy();
}






///////Friend Function

istream& operator>>(istream& c, fraction& fract)
{
	int num,denum;
	char d;
	scanf("%d %c %d", &num, &d, &denum);
	fract.numerator = num;
	fract.denumerator = denum;	
}
ostream& operator<<(ostream& c, fraction &fract)
{
	if (fract.denumerator == 1)
		c<<"Fraction is : "<<fract.numerator;
	else
		c<<"Fraction is : "<<fract.numerator<<"/"<<fract.denumerator;
	return c;
}



////////////////// extra function


int string_to_int(string str)
{
	stringstream geek(str);
	int num;
	geek >> num;
	return num;
}







int main()
{
	fraction fract1,fract2,fract3;
	cin>>fract1;
	cin>>fract2;
	//fract1.setValues(3,1);
	//fract1.print();
	//fract2.setValues();
	
	
	fract2 = ++fract1;
	fract3 = fract2++;
	//fract2.print();
	//fract3.print();
	cout<<fract2<<endl;
	cout<<fract3<<endl;
	/*
	fract2 = --fract1;
	fract3 = fract1--;
	cout<<fract3<<endl;
	cout<<fract2<<endl;
	
	/*
	fract3 = fract1 + fract2;
	cout<<fract3<<endl;
	fract3 = fract1 - fract2;
	cout<<fract3<<endl;
	fract3 = fract1 * fract2;
	cout<<fract3<<endl;
	fract3 = fract1 / fract2;
	cout<<fract3<<endl;
	
	/*
	fract3 += fract1;
	cout<<fract3<<endl;
	fract3 -= fract2;
	fract3 *= fract1;
	cout<<fract3<<endl;
	fract3 /= fract2;
	cout<<fract3<<endl;
	*/
	/*
	fract1 += 5;
	fract1 -= 5;
	fract1 *= 5;
	fract1 /= 5;
	*/
	/*cin>>fract4[2];
	cout<<fract4[2]<<endl;
	
	cout<<fract1<<"  "<<fract2<<endl;
	if(fract1 >= fract2)
		cout<<"good"<<endl;
	else
		cout<<"ok"<<endl;
	
	*/
	return 0;
}
