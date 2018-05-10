#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class dateAndTime
{
	private:
		int day;
		int mon;
		int yr;
		int hr;
		int min;
		int sec;
		string format;
	public:
		dateAndTime(int d, int mo, int y, int h, int mi, int s);
		~dateAndTime();
		void setDate(); 
		void setTime();
		void setDateAndTime();
		void updateDay(int day);
		void updateMonth(int mon);
		void updateYear(int yr);
		void updateHour(int hr);
		void updateMinute(int min);
		void updateSecond(int sec);
		void updateFormat(string str);
		void showDate();
		void showTime();
		void showDateAndTime();
		void showEnglishDate();
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getMinute();
		int getSecond();
		string getFormat();
		dateAndTime getDate();
		dateAndTime getTime();
		dateAndTime getDateAndTime();
		
			
};

////////////////////////////////////////////////////////////////////////////////


dateAndTime::dateAndTime(int d = 0, int mo = 0, int y = 0, int h = 0, int mi = 0, int s = 0)
{
	day = d;
	mon = mo;
	yr = y;
	hr = h;
	min = mi;
	sec = s;
}

//////////////////////////////////////////////////////////////////////////////


dateAndTime::~dateAndTime()
{
	day = 0;
	mon = 0;
	yr = 0;
	hr = 0;
	min = 0;
	sec = 0;
}


//////////////////////////////////////////////////////////////////////////

int string_to_int(string str);
int size(string s);

void dateAndTime::setDate()
{
	string str = "", sDay = "", sMon = "", sYr = "";
	int d = 0, m = 0, y = 0;
	cout<<"Enter date in this pattern DD-MM-YYYY"<<endl;
	cin>>str;
	if (size(str) == 10)
	{
		sDay = str[0];
		sDay += str [1];
		sMon = str[3]; 
		sMon += str[4];
		sYr = str[6];
		sYr += str[7];
		sYr += str[8]; 
		sYr += str[9];
		d = string_to_int(sDay);
		m = string_to_int(sMon);
		y = string_to_int(sYr);
		yr = y;
		if(m <= 12 && m > 0)
		{
			mon = m;
			if (d < 31 && (m == 4 || m == 6 || m == 9 || m == 11 ))
			{
				day = d;
				return;
			}
			else if (d < 32 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12  ))
			{
				day = d;
				return;
			}
			else if (d < 29 && m == 2)
			{
				day = d;
				return;
			}
			else
			{
				cout<<"Enter a valid Date"<<endl;
				return;
			}
				
		}
		else
		{
			cout<<"Enter a valid Date"<<endl;
			return;
		}
		 
	}
	else
	{
		cout<<"Enter a valid Date"<<endl;
		return;
	} 
}

///////////////////////////////////////////////////////////////

void dateAndTime::setTime()
{
	string str = "", sHr = "", sMin = "", sSec = "";
	int h = 0, m = 0, s = 0;
	cout<<"Enter Time in this 24 hour pattern HH:MM:SS"<<endl;
	cin>>str;
	if (size(str) == 8)
	{
		sHr = str[0];
		sHr += str [1];
		sMin = str[3]; 
		sMin += str[4];
		sSec = str[6];
		sSec += str[7];
		h = string_to_int(sHr);
		m = string_to_int(sMin);
		s = string_to_int(sSec);
		if(s < 60)
		{
			sec = s;
			if(m < 60)
			{
				min = m;
				if(h < 12 && h >= 0)
				{
					format = "AM";
					hr = h ;
				}
				else if(h <=24 && h > 12)
				{
					format = "PM";
					hr = h - 12;
				}
				else
				{
					cout<<"Enter a valid Time"<<endl;
				}
			}
			else
			{
				cout<<"Enter a valid Time"<<endl;
			}
		}
		else
		{
			cout<<"Enter a valid Time"<<endl;
		}
	}
	else
	{
		cout<<"Enter a valid Time"<<endl;
	}
}


//////////////////////////////////////////////////////////////////////

void dateAndTime::setDateAndTime()
{
	dateAndTime temp;
	temp.setDate();
	temp.setTime();
	yr = temp.getYear();
	mon = temp.getMonth();
	day = temp.getDay();
	hr = temp.getHour();
	min = temp.getMinute();
	sec = temp.getSecond();
	format = temp.getFormat();
}



//////////////////////////////////////////////////////////////////


void dateAndTime::updateDay(int d)
{
	day = d;
}



void dateAndTime::updateMonth(int m)
{
	mon = m;
}

void dateAndTime::updateYear(int y)
{
	yr = y;
}

void dateAndTime::updateHour(int h)
{
	hr = h;
}

void dateAndTime::updateMinute(int m)
{
	min = m;
}

void dateAndTime::updateSecond(int s)
{
	sec = s;
}

void dateAndTime::updateFormat(string str)
{
	format = str;
}

/////////////////////////////////////////////////////////////

int dateAndTime::getDay()
{
	return day;
}

int dateAndTime::getMonth()
{
	return mon;
}

int dateAndTime::getYear()
{
	return yr;
}

int dateAndTime::getHour()
{
	return hr;
}

int dateAndTime::getMinute()
{
	return min;
}

int dateAndTime::getSecond()
{
	return sec;
}

string dateAndTime::getFormat()
{
	return format;
}

///////////////////////////////////////////////////////////

void dateAndTime::showDate()
{
	cout<<"Date is : "<<day<<"-"<<mon<<"-"<<yr<<endl;
}

void dateAndTime::showTime()
{
	cout<<"Time is : "<<hr<<":"<<min<<":"<<sec<<" "<<format<<endl;
}

void dateAndTime::showDateAndTime()
{
	cout<<"Date is : "<<day<<"-"<<mon<<"-"<<yr<<endl;
	cout<<"Time is : "<<hr<<":"<<min<<":"<<sec<<" "<<format<<endl;
}


////////////////////////////////////////////////////////////

void dateAndTime::showEnglishDate()
{
	string arr[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	if(day == 1)
	{
		cout<<day<<"st "<<arr[mon-1]<<","<<yr<<endl;
	}
	if(day == 2)
	{
		cout<<day<<"nd "<<arr[mon-1]<<","<<yr<<endl;
	}
	if(day == 3)
	{
		cout<<day<<"rd "<<arr[mon-1]<<","<<yr<<endl;
	}
	else
	{
		cout<<day<<"th "<<arr[mon-1]<<","<<yr<<endl;
	}
}

//////////////////////////////////////////////////////////////////////////////


dateAndTime dateAndTime::getDate()
{
	dateAndTime temp;
	temp.updateDay(day);
	temp.updateMonth(mon);
	temp.updateYear(yr);
	return temp;
}




dateAndTime dateAndTime::getTime()
{
	dateAndTime temp;
	temp.updateHour(hr);
	temp.updateMinute(min);
	temp.updateSecond(sec);
	temp.updateFormat(format);
	return temp;
}



dateAndTime dateAndTime::getDateAndTime()
{
	dateAndTime temp;
	temp.updateDay(day);
	temp.updateMonth(mon);
	temp.updateYear(yr);
	temp.updateHour(hr);
	temp.updateMinute(min);
	temp.updateSecond(sec);
	temp.updateFormat(format);
	return temp;
}


//////////////////////////////////////////////////////////////

//Extra functions

int string_to_int(string str)
{
	stringstream geek(str);
	int num;
	geek >> num;
	return num;
}

int size(string s)
{
	int count = 0;
	int i = s[count];
	while(i != '\0')
	{
		count += 1;
		i = s[count];
	}
	
	return count;
}

int main(){

	dateAndTime obj1, obj2, obj3;
	//obj1.setDate();
	//obj1.setTime();
	obj1.setDateAndTime();
	obj1.showDateAndTime();
	obj1.showEnglishDate();
	obj2 = obj1.getDate();
	obj2.showDate();
	obj2 = obj1.getTime();
	obj2.showTime();
	return 0;
}
