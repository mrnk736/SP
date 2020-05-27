#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
//#include "stdafx.h"
#include <sys/wait.h>
#include <algorithm>
#include <experimental/filesystem>



using namespace std;



int main(int argc, char *argv[])
{
	srand(time(NULL)); 
	
	cout << "I am a bee and I am creating honey into my programm"<<endl;
	char buffer[50]; // created a buffer for writting into file
	

	int amountHoney; //amount honey
	int honeyOfBee = 5;

    ifstream fin("file.txt");
    fin >> buffer;
    fin.close();

    amountHoney=atoi(buffer);
    amountHoney += honeyOfBee;
    cout << "I am created honey and now it's =     "<< amountHoney<<endl;
    sprintf(buffer, "%d", amountHoney);  // put honey from number into string (our buffer)
	ofstream fout("file.txt");  // created an object and open file
    fout << buffer; // write buffer into file
    fout.close(); // closed file
    sleep(2);


}	 
