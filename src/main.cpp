#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

char input[16];
int integer[4];

int total = 0;

vector<float> numbers;
vector<string> answers;

set<vector<float>> permutations;

float convert(char c)
// Convert char input to number
{
	if (c == '*')
		return (rand() % 13) + 1;
	if (c == 'A' || c == 'a')
		return 1;
	if (c == 'J' || c == 'j')
		return 11;
	if (c == 'Q' || c == 'q')
		return 12;
	if (c == 'K' || c == 'k')
		return 13;
	if (c > 0x30 && c < 0x3a)
		return c-0x30;
	printf("Invalid input, please try again!\n");
	exit(0);
}

void readInput()
// Main function to read input
{	
	srand(time(0));

	printf("Please input 4 valid cards (or * to randomize one card) seperated by space.\n");

	fgets(input, 16, stdin);

	printf("\n");
	
	int i = 0;
	int count = 0;
	while(input[i] != 0x0)
	{
		if (input[i] == '1' && input[i+1] != ' ' && input[i+1] != '\n')
		{
			if (input[i+1]-0x30 > 3)
			{
				printf("Invalid input, please try again!\n");
				exit(0);
			}
			numbers.push_back(10 + input[i+1]-0x30);
			count++;
			i++;
		}
		else if (input[i] != ' ' && input[i] != 0xa)
		{
			numbers.push_back(convert(input[i]));
			count++;
		}
		i++;
	}
	
	if (count != 4)
	{
		printf("Invalid input, please try again!\n");
		exit(0);
	}
}

float operate(float a, float b, int op)
// Operate between 2 floats
{
	if (op == 0)
		return a + b;
	if (op == 1)
		return a - b;
	if (op == 2)
		return a * b;
	return a / b;
}

string insertOperator(int op)
// Change int to char
{
	if (op == 0)
		return " + ";
	else if (op == 1)
		return " - ";
	else if (op == 2)
		return " * ";
	return " / ";
}

void findResult(int i, int j, int k, int type)
// Push result to vector
{
	stringstream answer;

	if (type == 1 || type == 2 || type == 3) answer << "(";
	if (type == 1) answer << "(";

	answer << integer[0];
	answer << insertOperator(i);

	if (type == 2 || type == 4 || type == 5) answer << "(";
	if (type == 5) answer << "(";

	answer << integer[1];

	if (type == 1 || type == 3) answer << ")";

	answer << insertOperator(j);

	if (type == 3 || type == 4) answer << "(";

	answer << integer[2];
	
	if (type == 1 || type == 2 || type == 5) answer << ")";
	if (type == 2) answer << ")";

	answer << insertOperator(k);
	answer << integer[3];

	if (type == 3 || type == 4 || type == 5) answer << ")";
	if (type == 4) answer << ")";

	answer << "\n";

	answers.push_back(answer.str());
}

void swap(int a, int b)
// Swap 2 elements in vector
{
	float temp = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = temp;
}

void findNumbers(int n)
{
	if (n == 3 && permutations.count(numbers) != 1)
	{
		permutations.insert(numbers);
		
		for (int i = 0; i < 4; i++)
			integer[i] = numbers[i];

		float a = numbers[0];
		float b = numbers[1];
		float c = numbers[2];
		float d = numbers[3];

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					float e = operate(a, b, i);
					float f = operate(b, c, j);
					float g = operate(c, d, k);

					if (operate(operate(e, c, j), d, k) == 24.0)
					{
						findResult(i, j, k, 1);
						total++;
					}
					if (operate(operate(a, f, i), d, k) == 24.0)
					{
						findResult(i, j, k, 2);
						total++;
					}
					if (operate(e, g, j) == 24)
					{
						findResult(i, j, k, 3);
						total++;
					}
					if (operate(a, operate(b, g, j), i) == 24.0)
					{
						findResult(i, j, k, 4);
						total++;
					}
					if (operate(a, operate(f, d, k), i) == 24.0)
					{
						findResult(i, j, k, 5);
						total++;
					}
				}
			}
		}

	}
	else
	{
		for (int i = n; i <= 3; i++)
		{
			swap(n, i);
			findNumbers(n+1);
			swap(n, i);
		}
	}
}

int main()
// Main function
{
	readInput();
	
	auto start = high_resolution_clock::now();

	findNumbers(0);

	// Output result
	auto stop = high_resolution_clock::now();

	if (total != 0)
	{
		printf("%d solutions found for numbers %d, %d, %d, and %d.\n\n", total, integer[0], integer[1], integer[2], integer[3]);

		for (auto x : answers)
			cout << x;
	}
	else
	{
		printf("No solutions found for numbers %d, %d, %d, and %d.\n\n", integer[0], integer[1], integer[2], integer[3]);
	}

	printf("\nElapsed time: ");

	cout << duration_cast<microseconds>(stop - start).count();

	printf(" microseconds.\n\n");

	// Save to file
	char ans;
	printf("Would you like to save the output to a file? (Y/n)");
	scanf("%c", &ans);

	while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N' && ans != '\n')
	{
		printf("Please type a valid input!\n");
		printf("Would you like to save the output to a file? (Y/n)\n");
		scanf("%c", &ans);	
	}

	if (ans == 'Y' || ans == 'y' || ans == '\n')
	{
		printf("Insert file name: ");
		string name; cin >> name;

		ofstream file("test/" + name);

		file << total << " solutions found for numbers " << integer[0] << ", " << integer[1] << ", " << integer[2] << ", and " << integer[3] << ".\n\n";

		for (auto x : answers)
			file << x;

		file.close();
	}
}
