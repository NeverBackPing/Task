#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

int main()
{
	std::vector<std::string> stringVector;

	std::ofstream outputFile("task.txt"); // name you task

	while (true)
	{
		int chose;

		cout << " - - - - - Menu - - - - - -" << endl;  // menu
		cout                          << endl;//Scape

		cout << "|    1. Create a task      |"<< endl;//Option 1
		cout                          << endl;//Scape

		cout << "|     2. Read              |"         << endl;//Option 2
		cout                          << endl;//Scape

		cout << "|     3. Edit a task       |" << endl;//Option 3
		cout                          << endl;//Scape

		cout << "|     4. delete task       |" << endl;//Option 4
		cout                          << endl;//Scape

		cout << "|     5. Exit              |"         << endl;//Option 5
		cout                          << endl;//Scape

		cout <<  " - - - - - - - - - - - - -" << endl;//Scape

		cout                          << endl;//Scape

		cout << "Choisissez une option : ";

		while (!(cin >> chose)) {
			cout << "Invalid input.\nChoisissez une option : " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}



		switch (chose)
		{
		case 1:
		{
			cout << endl; //Scape
			std::cout << " - - - - - New note - - - - - " << std::endl;
			cout << endl; //Scape

			string note; // For make list task
			cin.ignore(); // Clear the newline character from the buffer
			getline(cin, note);
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
		{
			cout << endl; //Scape
			std::cout << " - - - - - Edit note - - - - - " << std::endl;
			cout << endl; //Scape

			int index;
			cout << "Enter the index of the task to edit: ";
			cin >> index;

			if (index >= 0 && index < stringVector.size()) {
				cout << "Enter the new task: ";
				cin.ignore(); // Clear the newline character from the buffer
				string newTask;
				getline(cin, newTask);
				stringVector[index] = newTask;

				// Update the file
				outputFile.close();
				outputFile.open("task.txt");
				for (const std::string& str : stringVector)
				{
					outputFile << str << std::endl;
				}
			} else {
				cout << "Invalid index." << endl;
			}

			break;
		}

		case 4:
		{
			cout << endl; //Scape
			std::cout << " - - - - - Delete note - - - - - " << std::endl;
			cout << endl; //Scape

			int index;
			cout << "Enter the index of the task to delete: ";
			cin >> index;

			if (index >= 0 && index < stringVector.size()) {
				stringVector.erase(stringVector.begin() + index);

				// Update the file
				outputFile.close();
				outputFile.open("task.txt");
				for (const std::string& str : stringVector)
				{
					outputFile << str << std::endl;
				}
			} else {
				cout << "Invalid index." << endl;
			}

			break;
		}

		case 5:
			return 0;

		default:
			cout << "Option non valide." << endl;
			break;
		}
	}
}