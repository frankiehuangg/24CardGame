#include <bits/stdc++.h>

using namespace std;

char input[16];
vector<float> numbers;

float convert(char c)
{
	if (c == 'A' || c == 'a')
		return 1;
	if (c == 'J' || c == 'j')
		return 11;
	if (c == 'Q' || c == 'q')
		return 12;
	if (c == 'K' || c == 'k')
		return 13;
	if (c > 0x2f && c < 0x3a)
		return c-0x30;
	printf("Input tidak valid, silahkan ulangi!\n");
	exit(0);
}

void readInput()
{	
	fgets(input, 16, stdin);
	
	int i = 0;
	while(input[i] != 0x0)
	{
		if (input[i] == '1' && input[i+1] == '0')
		{
			numbers.push_back(10);
			i++;
		}
		else if (input[i] != ' ' && input[i] != 0xa)
		{
			numbers.push_back(convert(input[i]));
		}
		i++;
	}
}

float operate(float a, float b, int op)
{
	if (op == 0)
		return a + b;
	if (op == 1)
		return a - b;
	if (op == 2)
		return a * b;

	// Handle divide by 0
	if (b != 0)
		return a / b;

	return -3.14;
}

void printOperator(int op)
{
	if (op == 0)
		printf(" + ");
	else if (op == 1)
		printf(" - ");
	else if (op == 2)
		printf(" * ");
	else		
		printf(" / ");
}

void printResult(int j, int k, int l, int type)
{
	if (type == 1 || type == 2 || type == 3) printf("(");
	if (type == 1) printf("(");

	printf("%d", (int)numbers[0]);
	printOperator(j);

	if (type == 2 || type == 4 || type == 5) printf("(");
	if (type == 5) printf("(");

	printf("%d", (int)numbers[1]);

	if (type == 1 || type == 3) printf(")");

	printOperator(k);

	if (type == 3 || type == 4) printf("(");

	printf("%d", (int)numbers[2]);

	if (type == 1 || type == 2 || type == 5) printf(")");
	if (type == 2) printf(")");

	printOperator(l);
	printf("%d", (int)numbers[3]);

	if (type == 3 || type == 4 || type == 5) printf(")");
	if (type == 4) printf(")");

	printf("\n");
}

int main()
{
	readInput();

	int total = 0;
	
	do {
		float result = 0;

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

					// printOperator(i); printOperator(j); printOperator(k); printf(" %f %f %f %f %f %f %f\n", a, b, c, d, e, f, g);

					if (operate(operate(e, c, j), d, k) == 24)
					{
						printResult(i, j, k, 1);
						total++;
					}
					if (operate(operate(a, f, i), d, k) == 24)
					{
						printResult(i, j, k, 2);
						total++;
					}
					if (operate(e, g, j) == 24)
					{
						printResult(i, j, k, 3);
						total++;
					}
					if (operate(a, operate(b, g, j), i) == 24)
					{
						printResult(i, j, k, 4);
						total++;
					}
					if (operate(a, operate(f, d, k), i) == 24)
					{
						printResult(i, j, k, 5);
						total++;
					}
				}
			}
		}

		printf("\n");
	} while (next_permutation(numbers.begin(), numbers.end()));

	printf("%d solutions found.\n", total);
}

/* ((a b) c) d
 * (a (b c)) d
 * (a b) (c d)
 * a (b (c d))
 * a ((b c) d)
 *
 *
 * (a b) e
 * (b c) f
 * (c d) g
 *
 * (e c) d -> (e,c,j),d,k
 * (a f) d -> (a,f,i),d,k
 * e f
 * a (b g) -> a,(b,g,j),i
 * a (f d) -> a,(f,d,k),i
 */

		
