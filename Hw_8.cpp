/**

ARRAYS and FUNCTIONS: SORTING and SEARCHING

Project: Midterm Scores ñ Sort, Search, Average

*/



//  UYEN VO



#include <iostream>
#include <fstream>
#include <iomanip>



using namespace std;


void welcomeMessage();
void createArray(int& students, int id[], double averageScore[]);
void selectionSort(double averageScore[], int id[], int arraySize);
double getAverage(double averageScore[], int arraySize);
int searchList(int id[], int arraySize, int target);
int getValidNum();
int validateConitnue();
void printOutput(int id[], double averageScore[], int arraySize);
void result(double classAverage, int students, int arraySize, double averageScore[]);
void fairwell(void);

int main()

{

	const int SIZE = 50;
	//Unassigned elements would be set to 0
	int id[SIZE] = { 0 };
	double averageScore[SIZE] = { 0 };

	//int target = 80;

	int target = 80;
	int students = 0;
	int location, choice;
	ifstream inFile;
	ofstream outFile;

	double classAverage;
	inFile.open("midterm_scores.txt");
	outFile.open("sorted.txt");

	welcomeMessage();
	createArray(students, id, averageScore);
	int arraySize = students + 1;
	cout << fixed << setprecision(1) << endl;
	if (students > 50)
	{
		cout << "There are more than 50 students." << endl;
		return 0;
	}

	classAverage = getAverage(averageScore, arraySize);
	selectionSort(averageScore, id, arraySize);
	do
	{
		target = getValidNum();
		location = searchList(id, arraySize, target);
		if (location != -1)
		{
			cout << target << " is found at location:" << location << endl;
			cout << "The corresponding score is: " << averageScore[location] << endl << endl;
		}
		else
		{
			cout << target << " NOT found!\n";
		}
		choice = validateConitnue();

	} while (choice != -1);
	printOutput(id, averageScore, arraySize);
	fairwell();
	return 0;
}


/*****
This function displays
a welcome message
to the users.
*/
void welcomeMessage()
{
	cout << " Welcome to the Midterm Scores Project.\n";
	cout << " This program helps read the students' midterm scores from a file"
		<< " into two parallel arrays.\n";
	cout << " It calculates the class average, sorts the parallel arrays"
		<< " in descending order.\n";
	cout << " Finally the program will display the class average, the number of students,"
		<< " the highest and lowest averages, and the results.\n";
}

/***
This fuction helps to read
the student's ID and scores
from the input file.
*/
void createArray(int& students, int id[], double averageScore[])
{
	ifstream inFile;
	inFile.open("midterm_scores.txt");
	double averageScore_variable;
	int readID, readScore1, readScore2;
	if (inFile.is_open()){
		while (inFile)
		{
			inFile >> readID >> readScore1 >> readScore2;
			id[students] = readID;
			averageScore_variable = (readScore1 + readScore2) / 2.0;
			averageScore[students] = averageScore_variable;
			students++;
		}
		inFile.close();
	}
	else
		cout << "Cannot the open the midterm_scores.txt" << endl;
}


/***
This functions helps
calculate the class average.
*/
double getAverage(double averageScore[], int arraySize)
{
	double classAverage = 0, total = 0;
	for (int i = 0; i < arraySize; i++)
	{
		total += averageScore[i];
	}
	classAverage = total / (arraySize - 1);
	return classAverage;
}


/***
This funcion helps figure out
which ID are looked for.
*/

int searchList(int id[], int arraySize, int target)

{
	bool found = false;

	int index = 0;   // Used as a subscript to search array

	int pos = -1;  // To record position of search value: -1 means not found



	while (index < arraySize && pos == -1 && found == false)

	{

		if (id[index] == target) // If the value is found

		{
			found = true;

			pos = index; // Record the value's subscript

		}

		index++; // Go to the next element

	}

	return pos; // Return the position, or -1

}



/***
This functions shows the selections sort
for 2 arrays. It arranges the average scores array in
descending order and swaps the ID array that goes with
the score array.
*/

void selectionSort(double averageScore[], int id[], int arraySize)

{



	for (int startScan = 0; startScan < (arraySize - 1); startScan++)

	{

		// look for largest

		int maxIndex = startScan;

		for (int index = startScan + 1; index < arraySize; index++)

		{

			if (averageScore[index] > averageScore[maxIndex])

				maxIndex = index;

		}

		// swap

		double hold = averageScore[maxIndex];

		averageScore[maxIndex] = averageScore[startScan];

		averageScore[startScan] = hold;
		double hold2 = id[maxIndex];
		id[maxIndex] = id[startScan];
		id[startScan] = hold2;

	}

}

/*** This function helps print out
the student ID and average score array
to the output file.
*/
void printOutput(int id[], double averageScore[], int arraySize)
{
	ofstream outFile;
	outFile.open("sorted.txt");
	outFile << fixed << setprecision(1) << endl;
	for (int j = 0; j < arraySize; j++)
	{
		outFile << "Id = " << id[1] << " Ave = " << averageScore[1] <<endl ;
		if ((j % 4) == 3)
		{
			outFile << endl;
		}
	}
	outFile.close();
}

/***
This functions prints out the results that contain
the class average, the number of students,
the highest and lowest averages, and the search results.
*/
void result(double classAverage, int students, int arraySize, double averageScore[])
{
	cout << "The class average is " << classAverage << endl;
	cout << "The number of students is " << students << endl;
	cout << "The highest midterm score is " << averageScore[0] << endl;
	cout << "The lowest midterm score is " << averageScore[students - 1] << endl;
}

/****
This function helps
get the Valid Number.
*/
int getValidNum()
{
	int n;
	bool success = false;
	do
	{
		cout << "Enter the student ID number: ";
		cin >> n;
		if (cin.good())
		{
			success = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input; please re-enter Integer ONLY." << endl;
		}
	} while (success == false);
	return n;
}
/****
This function helps
get the Valid number if user want to continue.
*/
int validateConitnue(){
	int n;
	bool success = false;
	do
	{
		cout << "Enter any int number to continue (Enter -1 to stop): ";
		cin >> n;
		if (cin.good())
		{
			success = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input; please re-enter Integer ONLY." << endl;
		}
	} while (success == false);
	return n;
}
/*** This function is a fairwell function
to tell the user the Midterm Score Project
is finished.
*/
void fairwell()
{
	cout << "\n\n End of Midterm Score Project.\n";
	cout << " Thanks for using the program\n";
	cout << " ------Have a nice day.------\n";
}

/******
SAVE THE OUTPUT HERE:

 Welcome to the Midterm Scores Project.
 This program helps read the students' midterm scores from a file into two parallel arrays.
 It calculates the class average, sorts the parallel arrays in descending order.
 Finally the program will display the class average, the number of students, the highest and lowest averages, and the results.

Enter the student ID number: 2000
2000 is found at location:18
The corresponding score is: 90.0

Enter any int number to continue (Enter -1 to stop): 1
Enter the student ID number: 7788
7788 is found at location:35
The corresponding score is: 63.0

Enter any int number to continue (Enter -1 to stop): 2
Enter the student ID number: 8280
8280 is found at location:14
The corresponding score is: 92.5

Enter any int number to continue (Enter -1 to stop): 3
Enter the student ID number: 9088
9088 is found at location:34
The corresponding score is: 64.5

Enter any int number to continue (Enter -1 to stop): Project
Invalid input; please re-enter Integer ONLY.
Enter any int number to continue (Enter -1 to stop): 4
Enter the student ID number: Midterm
Invalid input; please re-enter Integer ONLY.
Enter the student ID number: 5123
5123 is found at location:27
The corresponding score is: 79.0

Enter any int number to continue (Enter -1 to stop): -1


End of Midterm Score Project.
Thanks for using the program
------Have a nice day.------
*/
