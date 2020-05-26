#define BEAR_H

using namespace std;

bool bearAlive = true;

class Bear
{
public:
	
	void eatOfHoney(int &amountOfHoney, mutex &mtx)
	{
		while (bearAlive)
		{
			mtx.lock();
			amountOfHoney -= 50;
			checkBearAlive(amountOfHoney);
			mtx.unlock();
			this_thread::sleep_for(chrono::milliseconds(5000));
		}	
	}
	void checkBearAlive(int &amountOfHoney)
	{
		if (bearHungry & (amountOfHoney < 0)) 
		{ 
			cout << "Bear is dead" << endl;
			
			bearAlive = false;
		}	else
		{
			bearHungry = false;
			if (amountOfHoney >= 0)
			{
				cout << "ID thread = " << this_thread::get_id() << "\t Baer was eaten! Honey left into box = " << amountOfHoney << endl;
			}
			else
			{
				amountOfHoney = 0;
				bearHungry = true;
				cout << "ID thread = " << this_thread::get_id() << "\t Bear is hungry, ADD honey to the box" << endl;
			}
		}
	}
	/*
	bool getBearAlive()
	{
		return bearAlive;	
	}
	*/

private:
	bool bearHungry = false;
	//bool bearAlive = true;
};

