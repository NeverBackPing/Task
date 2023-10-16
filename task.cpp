#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	std::vector<std::string> stringVector;

	std::ofstream outputFile("task.txt"); // name you task
	
	while (true) 
	{
		int chose;

		cout << " - - - - - Menu - - - - - -" << endl;  // menu 
		cout						  << endl;//Scape

		cout << "|    1. Create a task      |"<< endl;//Option 1
		cout                          << endl;//Scape

		cout << "|     2. Read              |"         << endl;//Option 2
		cout                          << endl;//Scape

		cout << "|     3. Edit a task       |" << endl;//Option 3
		cout                          << endl;//Scape

		cout << "|     4. delete task       |" << endl;//Option 4
		cout                          << endl;//Scape
		
		cout << "|     5. Exit              |"		  << endl;//Option 5
		cout                          << endl;//Scape

		cout <<  " - - - - - - - - - - - - -" << endl;//Scape
		
		cout                          << endl;//Scape

		cout << "Choisissez une option : ";
		cin >> chose;





		switch (chose)
		{
		case 1:
		{
			cout << endl; //Scape
			std::cout << " - - - - - New note - - - - - " << std::endl;
			cout << endl; //Scape

			string note; // For make list task
			cin >> note;
			stringVector.push_back(note);

			for (const std::string& str : stringVector) 
			{
				outputFile << str << std::endl;
			}
			
			break;
			}
			
		case 2: 
		{ 
			cout << endl; //Scape
			std::cout << " - - - - - Read note - - - - - " << std::endl; // Read
			cout << endl; //Scape

			for (const std::string& str : stringVector) 
			{
				std::cout << str << std::endl;
				cout << endl; //Scape
			}
			
			break;
		}


			
		case 3:
			break;
		case 4:
			break;
		case 5:
			return 0;
		default:
			cout << "Option non valide." << endl;
			break;
		}
	}
}
