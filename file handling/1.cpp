#include<iostream>
#include<fstream>
using namespace std;



int main()
{
   /*char data[100];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();
   */

   // open a file in read mode.
   string data;
   char a;
   int c;
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   //infile >> data;
   while(!infile.eof())
   { 
   //a = infile.get();
   infile >> data;
   cout << data << endl;
   //cout<<a;
   //if (a == '\t')
   //{cout<<"ok";}
   //cout<<infile.tellg()<<endl;
   // write the data at the screen.
   //cout << data << endl;
   }
   // again read the data from the file and display it.
   //infile >> data; 
   //cout << data << endl;
   //cout<<infile.tellg()<<endl;
   //c = infile.get();
   //cout<<c<<endl; 

   // close the opened file.
   infile.close();
   //cout<<char(77)<<endl;
	
	
	
	return 0;
}


/*

int string_to_int(string str)
{
	stringstream geek(str);
	int num;
	geek >> num;
	return num;
}


string int_To_string(int num)
{
	stringstream ss;
	ss << num;
	string s = ss.str();
	return s;
}

*/
