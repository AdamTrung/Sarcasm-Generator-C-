#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

int main()
{
    string file_string;
	ifstream inFile;
	inFile.open("Text.txt");
	
	if (!inFile)
	{
		cout << "Input file cannot be opened" << endl;
           return 0;
	}
	
	stringstream buffer;
	buffer << inFile.rdbuf();
	file_string = buffer.str();
    
	for (int i = 0; i < file_string.length(); i += 1)
	{
    	cout << file_string[i];
    }
   	
   	cout << "\n\n\n";
   	
   	string st = file_string;
   	
   	srand(time(NULL));
   	
   	st[0] = tolower(file_string[0]);
    st[1] = toupper(file_string[1]); 	
   	
   	for (int i = 2; i < file_string.length(); i++)
   	{
   	    int chance = rand() % 2;
   	    if (chance == 0) 
   	    {
   	        st[i] = toupper(file_string[i]);
   	    }
   	    else
   	    {
   	        st[i] = tolower(file_string[i]);
   	    }
   	    
   	    if ((islower(st[i]-1)) && (islower(st[i-2])))
   	    {
   	        st[i] = toupper(st[i]);
   	    }
   	    if ((isupper(st[i]-1)) && (isupper(st[i-2])))
   	    {
   	        st[i] = tolower(st[i]);
   	    }
   	    
   	    if (st[i] == 'I')
   	    {
   	        st[i] = 'i';
   	    }
   	    if (st[i] == 'l')
   	    {
   	        st[i] = 'L';
   	    }
   	}
   	
   	for (int i = 0; i < file_string.length(); i += 1)
	{
    	cout << st[i];
    }
    return 0;
}


