#include<iostream>
#include<iomanip>
#include <array>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void Multiplication(vector<vector<float>>A, vector<vector<float>>B, int nAr, int nAc, int nBr, int nBc) // A and B are the matrices to be multiplied
{
	if (nAc == nBr)
	{
		int nCr = nAr, nCc = nBc;
		vector<vector<float>>C(nCr, vector<float>(nCc,0)); // The result matrix
		int rowA = 0, colB = 0; // These variables are for pointing in A and B
		
		cout << "The multiplication is: \n";
		for (int rowC = 0; rowC < nCr; rowC++) //For Cycling over all C's values
		{
			for (int colC = 0; colC < nCc; colC++)
			{
				rowA = rowC; // These are for defining which row and column to multiply
				colB = colC;

				for (int n = 0; n < nAc; n++) // multiplying and adding the elements. see notes for details.
				{
					C[rowC][colC] += A[rowA][n] * B[n][colB];

				}
				cout << fixed << setprecision(1); //Setting value to one decimal place
				cout << setw(10) << C[rowC][colC]; //setting a space between values
			}

			cout << "\n"; //to print the different rows on seperate lines
		}
		cout << endl;

	}else cout << "Invalid operation! \n" << endl;

	return;
}




void Division(vector<vector<float>>A, vector<vector<float>>B, int nAr, int nAc, int nBr, int nBc)
{
	if (nBr == nBc && nAc == nBr)
	{
		vector<vector<float>>Bi(nBr, vector<float>(nBc, 0));// to store the inverse matrix of B
		float determinant = 0;

		if (nBr == 2)
		{
			determinant = (B[0][0] * B[1][1]) - (B[0][1] * B[1][0]);
		}
		else if (nBr == 3)
		{
			determinant = //this part is obvious
				(B[0][0] * B[1][1] * B[2][2] + B[0][1] * B[1][2] * B[2][0] + B[0][2] * B[1][0] * B[2][1])
				- (B[0][2] * B[1][1] * B[2][0] + B[1][2] * B[2][1] * B[0][0] + B[2][2] * B[0][1] * B[1][0]);
		}
		else 
		{
			cout << "Cannot calculate inverse of matrix larger than 3x3. Sorry. \n" << endl;
			return;
		}

		if (determinant == 0)
		{
			cout << "Invalid operation! Determinant equals zero.\n" << endl; //because you can't divide by zero
			return;
		}

		if (nBr == 2)
		{
			Bi[0][0] = B[1][1]/determinant; Bi[1][1] = B[0][0]/determinant;
			Bi[0][1] = -B[0][1]/determinant; Bi[1][0] = -B[1][0]/determinant;
		}
		else
		{
			int n1 = 0, n2 = 0, m1 = 0, m2 = 0; // n & m are markers for rows and cols respectively in B, used for calc the inverse of B

			for (int rowBi = 0; rowBi < nBr; rowBi++) // only my notes can explain what happens here (it's for calculating the inverse)
			{
				m1 = (rowBi + 1) % nBr;
				m2 = (rowBi + 2) % nBr;

				for (int colBi = 0; colBi < nBc; colBi++)
				{
					n1 = (colBi + 1) % nBc;
					n2 = (colBi + 2) % nBc;

					Bi[rowBi][colBi] = (B[n1][m1] * B[n2][m2] - B[n1][m2] * B[n2][m1]) / determinant;

				}
			}
		}
		// now we multiply A by Bi (the inverse of B)

		int rowA = 0, colB = 0; // These variables are for pointing in A and B
		int nCr = nAr, nCc = nBc;
		vector<vector<float>>C(nCr, vector<float>(nCc, 0)); // The result matrix

		cout << "The division is: \n";
		for (int rowC = 0; rowC < nCr; rowC++) //For Cycling over all C's values
		{
			for (int colC = 0; colC < nCc; colC++)
			{
				rowA = rowC; // These are for defining which row and column to multiply
				colB = colC;

				for (int n = 0; n < nAc; n++) // multiplying and adding the elements. see notes for details.
				{
					C[rowC][colC] += A[rowA][n] * Bi[n][colB];

				}
				cout << fixed << setprecision(1); //Setting value to one decimal place
				cout << setw(10) << C[rowC][colC]; //setting a space between values
			}

			cout << "\n"; //to print the different rows on seperate lines
		}
		cout << endl;
	}else cout << "Invalid operation! \n" << endl;
	return;
}




//Show Matrix Value
void showMatrixValue(vector<vector<float>>C, int nCr, int nCc) {

	//Looping on Array
	
	for (int rowC = 0; rowC < nCr; rowC++) //For Cycling over all C's values
	{
		for (int colC = 0; colC < nCc; colC++)
		{

			cout << fixed << setprecision(1); //Setting value to one decimal place
			cout << setw(10) << C[rowC][colC]; //setting a space between values
		}
		cout << "\n"; //to print the different rows on seperate lines
	}
	cout << endl;
}


void Addition(vector<vector<float>>A, vector<vector<float>>B, int nAr, int nAc, int nBr, int nBc)
{
	if (nAr == nBr && nAc == nBc)
	{
		int nCr = nAr, nCc = nAc;

		vector<vector<float>>C(nCr, vector<float>(nCc, 0));

		for (int rowC = 0; rowC < nCr; rowC++)
		{
			for (int colC = 0; colC < nCc; colC++)
			{
				C[rowC][colC] = A[rowC][colC] + B[rowC][colC];
			}
		}

		cout << "The addition is: \n";

		for (int rowC = 0; rowC < nCr; rowC++)
		{
			for (int colC = 0; colC < nCc; colC++)
			{
				cout << fixed << setprecision(1);
				cout << setw(10) << C[rowC][colC];
			}
			cout << "\n";
		}
		cout << endl;
	}

	else
	{
		cout << "You can't add these matrices! \nThe matrices should be of the same dimensions. \n" << endl;
	}
	return ;
}








void Subtraction(vector<vector<float>>A, vector<vector<float>>B, int nAr, int nAc, int nBr, int nBc)
{
	if (nAr == nBr && nAc == nBc)
	{
		int nCr = nAr, nCc = nAc;
		vector<vector<float>>C(nCr, vector<float>(nCc, 0));
		for (int row = 0; row < nCr; row++)
		{
			for (int col = 0; col < nCc; col++)
			{
				{
					C[row][col] = A[row][col] - B[row][col];
				}
			}
		}
		cout << "The subtraction is: \n";
		for (int row = 0; row < nCr; row++)
		{
			for (int col = 0; col < nCc; col++)
			{
				cout << fixed << setprecision(1);
				cout << setw(10) << C[row][col];
			}
			cout << "\n";
		}
		cout << endl;
	}
	else
	{
		cout << "You can't subtract these matrices! \nThe matrices should be of the same dimensions. \n" << endl;
	}
	return;
}


void Transpose(vector<vector<float>>A, int nAr, int nAc)
{
	int nCr = nAc, nCc = nAr;
	vector<vector<float>>C(nCr, vector<float>(nCc));

	{ for (int row = 0; row < nAr; row++)

		for (int col = 0; col < nAc; col++)
		{
			C[col][row] = A[row][col];
		}
	}

	cout << "Transpose of Matrix: " << endl;
	for (int row = 0; row < nCr; row++) {
		for (int col = 0; col < nCc; col++) {
			cout << fixed << setprecision(1); 
			cout << setw(10) << C[row][col];

		}
		cout << "\n";
	}
	cout << endl;
	return;
}

	

vector <float> matvalues; // vector for storing matrix values


void extractFloat(string s) // for converting stream input to float
{
	matvalues.clear(); // clears the vector

	int pos = s.find_first_of("[;]");
	while (pos != string::npos) // While our position in the sting is in range.
	{ 
		s[pos] = ' '; // Change the character at position.
		pos = s.find_first_of("[;]", pos + 1); // Relocate again.
	}
	stringstream stream;
	stream << s; //convert the string s into stringstream
	string temp_string;
	float temp_float;
	while (!stream.eof())
	{
		stream >> temp_string; //take words into temp_string one by one
		if (stringstream(temp_string) >> temp_float) //try to convert string to float
		{
			matvalues.push_back(temp_float);
		}
		temp_string = ""; //clear temp string
	}
	return;
}




int main()
{
	int nAr, nAc, nBr, nBc, nCr, nCc; //no of rowc and cols of matrix A, B, and C respectively
	//vector<vector<float>>C(nCr, vector<float>(nCc));

	string expression;
	string valueString;
	string letter;
	int i;
	bool exit = false, firstTry = true, firstTry2 = true, firstTry3 = true;

	do
	{	start:

		cout << "Please enter number of rows of matrix A: ";
		cin >> nAr;
		cout << "Please enter number of columns of matrix A: ";
		cin >> nAc;
		vector<vector<float>>A(nAr, vector<float>(nAc));
		cin.ignore(); //so getline works after cin

	errorPoint1:
		cout << "Please enter values of matrix A: \n";

		if (firstTry == true) 
		{ 
			cout << "Example: [1.2 3.45; 56 98.523] \n";
			firstTry = false;
		}

		cout << "A = ";
		
		getline(cin, valueString);
		extractFloat(valueString);
		if (nAr * nAc != matvalues.size())
		{
			cout << "Number of values inputted not equal number of elements of the matrix! \n";
			goto errorPoint1;
		}

		i = -1;
		for (int rowA = 0; rowA < nAr; rowA++) //For Cycling over all A's values
		{
			for (int colA = 0; colA < nAc; colA++)
			{
				i++;
				A[rowA][colA] = matvalues[i];
			}
		}

		cout << "Please enter number of rows of matrix B: ";
		cin >> nBr;
		cout << "Please enter number of columns of matrix B: ";
		cin >> nBc;
		vector<vector<float>>B(nBr, vector<float>(nBc));
		cin.ignore();

	errorPoint2:
		cout << "Please enter values of matrix B: \n";
		cout << "B = ";
		
		getline(cin, valueString);
		extractFloat(valueString);
		if (nBr * nBc != matvalues.size())
		{
			cout << "Number of values inputted not equal number of elements of the matrix! \n";
			goto errorPoint2;
		}

		i = -1;
		for (int rowB = 0; rowB < nBr; rowB++) //For Cycling over all B's values
		{
			for (int colB = 0; colB < nBc; colB++)
			{
				i++;
				B[rowB][colB] = matvalues[i];
			}
		}



		do
		{
			if (firstTry2 == true)
			{
				cout << "Example expression: C=A*B (or) A*B \n";
				firstTry2 = false;
			}

			cout << "Enter  expression: "; //so getline works after cin
			getline(cin, expression);
			if (expression == "exit" || expression == "Exit" || expression == "EXIT") { exit = true; break; }

			//npos is a static member constant value with the greatest possible value for an element of type size_t.
			if (expression.size() < 2)
			{
				if (expression.find("A") != string::npos)
				{
					showMatrixValue(A, nAr, nAc);
				}
				else if (expression.find("B") != string::npos)
				{
					showMatrixValue(B, nBr, nBc);
				}
			}
			else 
			{
				if (expression.find("+") != string::npos)
				{
						Addition(A, B, nAr, nAc, nBr, nBc);
				}
				else if (expression.find("-") != string::npos)
				{
					if (expression.find("A") < expression.find("B"))
					{
						Subtraction(A, B, nAr, nAc, nBr, nBc);
					}
					else
					{
						Subtraction(B, A, nBr, nBc, nAr, nAc);
					}
				}
				else if (expression.find("*") != string::npos)
				{
					if (expression.find("A") < expression.find("B"))
					{
						Multiplication(A, B, nAr, nAc, nBr, nBc);
					}
					else
					{ 
						Multiplication(B, A, nBr, nBc, nAr, nAc); 
					}
					
				}
				else if (expression.find("/") != string::npos)
				{
					if (expression.find("A") < expression.find("B"))
					{
						Division(A, B, nAr, nAc, nBr, nBc);
					}
					else
					{
						Division(B, A, nBr, nBc, nAr, nAc);
					}
					
				}
				else if (expression.find("A'") != string::npos) 
				{
					Transpose(A, nAr, nAc);
				}
				else if (expression.find("B'") != string::npos) 
				{
					Transpose(B, nBr, nBc);
				}
			}
			cout << "Redefine matrices? (yes/no) \n";

			if (firstTry3 == true)
			{
				cout << "Enter 'yes' to go back to the beginning and re-enter the matrices. \nEnter 'no' to continue entering expressions. \n";
				firstTry3 = false;
			}

			cin >> letter;
			if (letter == "Y" || letter == "y" || letter == "Yes" || letter == "yes" || letter == "YES") { goto start; }
			if (letter == "exit" || letter == "Exit" || letter == "EXIT") { exit = true; break; }
			cin.ignore();

		} while (!exit);

	} while (!exit);
	
	return 0;
}
