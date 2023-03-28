//***********************************************************************
//******		STUDENT NAME : OZAN GÜL							*********
//****			STUDENT NUMBER : B211202036						*********
//******		ASSIGNMENT#3: Write a c++ code which creates    *********
//******		random alphabet matrix, requests words from user ********
//******		and color red the words which requested in matrix *******
//******		HONOR CODE : I have done it myself without any cheating. *
//***********************************************************************
//SAKARYA UNIVERSITY PROJECT
#include <iostream> 
#include <ctime> 
#include <windows.h> 
#define color_red 12
#define color_white 15
using namespace std;
const int MAX = 12;
bool checkAlphabet(char[], char[]); // Bool function prototype
void checkAndPrintMatrix(char RandomMatrix[MAX][MAX], char word[]); // Void function prototype.(This function does not return anything.)
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main() {
	FlushConsoleInputBuffer(hConsole);
	srand(time(NULL));
	char Alphabet[MAX]; // A char array with MAX elements, name it as Alphabet and initialized their values randomly
	//from uppercase letters of English alphabet.
	for (int i = 0; i < MAX; i++) {
		Alphabet[i] = 'A' + rand() % 26; // From starting 'A' randomly add number between 0 and 26. (ASCII)

	}

	for (int a = 0; a < MAX; a++) { //This is additional loop for creating different words like bubble sort.
		//Sometimes the words which assigned may be the same word. I used these for loops to prevent it.
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++) {
				if (i == j)
					continue;
				if (Alphabet[i] == Alphabet[j]) { // If 2 words are equal each other, change it.
					Alphabet[j] = 'A' + rand() % 26; // To create new words which is different each other.
				}
			}
		}
	}
	cout << "Generated Alphabet is:";
	for (int i = 0; i < MAX; i++) { // This is a loop which prints generated random alphabet.
		cout << Alphabet[i] << "-";
	}
	cout << endl;

	char RandomMatrix[MAX][MAX]; //Matrix with size MAXxMAX which their values from the
	//randomly generated Alphabet array.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			RandomMatrix[i][j] = Alphabet[rand() % MAX]; //To choose random matrix values from randomly generated alphabet randomly.
		}
	}
	cout << "******************";
	cout << endl;

	for (int i = 0; i < MAX; i++) { //Print the matrix which include random words.
		for (int j = 0; j < MAX; j++) {
			cout << RandomMatrix[i][j];
		}
		cout << endl;
	}
	cout << "******************";
	//Ask and force the user to enter a word using the generated Alphabet.
	char EnteredWord[MAX];
	cout << endl;
	bool checkEnteredWord;
	do { // This is a loop which requested word(s) again if they are not in generated alphabet.
		checkEnteredWord = checkAlphabet(Alphabet, EnteredWord);
		if (!checkAlphabet(Alphabet, EnteredWord)) // Calling the function which is bool.
		{
			cout << "Enter a word of using the alphabet:";
			cin >> EnteredWord;
		}
	} while (checkEnteredWord == false);
	checkAndPrintMatrix(RandomMatrix, EnteredWord); // Calling function which checks the matrix and print it with red foreground
}
bool checkAlphabet(char Alphabet[], char word[]) { //Function that checks whether the entered word is in the generated alphabet.
	//This function return true or false.
	int len = strlen(word);
	int check = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < len; j++)
		{
			if (Alphabet[i] == word[j])
			{
				check++;
			}
		}
	}
	if (check == len) {
		return true;
	}
	else return false;
}

void checkAndPrintMatrix(char RandomMatrix[MAX][MAX], char enteredWord[]) //Function which scans the matrix line by line
//and finds the entered word(s) from each line of the matrix and rewrites
//the matrix on the screen with the found words in red foreground
{
	int check = 0;
	int len = strlen(enteredWord); // I used strlen	functions to calculate length entered word.
	bool ScanLine = false;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (!ScanLine)
			{
				for (int k = 0; k < len; k++)
				{
					if (enteredWord[k] == RandomMatrix[i][j + k])
					{
						if (j + k < MAX)
							check++;
					}
				}
				if (check == len)
					ScanLine = true;
				else
					check = 0;
			}
			if (ScanLine)
			{
				SetConsoleTextAttribute(hConsole, color_red); //To color words which is entered red foregrounds.
				cout << RandomMatrix[i][j];
				SetConsoleTextAttribute(hConsole, color_white);//Again we should color white the other words.
				check--;

				if (check == 0)
					ScanLine = false;
			}
			else
				cout << RandomMatrix[i][j];

		}
		check = 0;
		ScanLine = false;
		cout << endl;
	}

}
