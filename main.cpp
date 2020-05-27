#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>
#include <experimental/filesystem>

using namespace std;




int main()
{	
	char buff[50];
	int stealHoney=3;
	int amountOfHoney;
	
	pid_t temp;
	temp = fork();
	if (temp == 0){
	while (amountOfHoney > 0)
	{
	cout<< "I am bear and I am stealing honey   "<< endl;
            ifstream fin("file.txt");  // open file
    		fin >> buff; // read all information from file into buffer
    		fin.close(); //close file

    		amountOfHoney=atoi(buff);
    		//cout << "I am created honey and now it's =     "<< amountHoney<<endl;
    		amountOfHoney -= stealHoney;
    		cout << "After me into box =   "<< amountOfHoney<<"  honey "<< endl;
    		sprintf(buff, "%d", amountOfHoney);  // put honey from number into string (our buffer)
			ofstream fout("file.txt");  // created an object and open file
    		fout << buff; // write buffer into file
    		fout.close(); // closed file

            sleep(10);
	}
	
	} else if (temp > 0)
{
	
	pid_t  proc_child[3];	
while (amountOfHoney > 0){
    for (int i = 0; i < 3; i++)

    {

       
       	

        proc_child[i] = fork();

        wait(0);

        switch (proc_child[i])

        {

        case 0:

            cout << "I'm a child with pid " << getpid() << ", my parent's pid is " << getppid() << endl;
            execl("bee", " " ,  NULL);
            kill(getpid(), SIGKILL);


            break;

        default:
	cout << "Proc END";
        
        break;

        }

        cout << endl << endl;
    	}
    }
	
	
}
		
	



return 0;
}	
