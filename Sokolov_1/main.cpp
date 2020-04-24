#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int read_lines(string* arr, ifstream& file)
{
	int count = 0;
	string line;
	while (std::getline(file, line))
	{
		arr[count] = line;
		count++;
	}
	return count;
}

void write_lines(string* arr, int count, ofstream& file)
{
	for (int i = 0; i < count; i++)
	{
		file << arr[i] << "\n";
	}
}

void sort_lines(string* arr, int count)
{
	bool sorted;
	do
	{
		sorted = true;
		for (int i = 1; i < count; i++)
		{
			if (arr[i].length() < arr[i - 1].length())
			{
				swap(arr[i], arr[i - 1]);
				sorted = false;
			}
		}
	}
	while (!sorted);
}

void print_menu()
{
	cout << "1. Read array" << endl;
	cout << "2. Sort array" << endl;
	cout << "3. Write array" << endl;
	cout << "0. Exit" << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");
	string lines[100];
	int count = -1;
	int k = -1;

	do
	{
		print_menu();

		cin >> k;

		switch (k)
		{
		case 1:
			{
				cout << "Use default file(1) or select file(2): ";
				int type;
				cin >> type;
				ifstream f1;
				if (type == 1)
				{
					f1.open("f1.txt");
				}
				else if (type == 2)
				{
					cout << "Enter filename: ";
					string file_name;
					cin >> file_name;
					f1.open(file_name);
				}
				else
				{
					cout << "Incorrect command" << endl;
					break;
				}

				count = read_lines(lines, f1);

				cout << "File was read" << endl;

				f1.close();
				break;
			}
		case 2:
			{
				if (count == -1)
				{
					cout << "Unable to sort lines before read" << endl;
					break;
				}
				sort_lines(lines, count);
				cout << "Lines were sorted" << endl;
				break;
			}
		case 3:
			{
				if (count == -1)
				{
					cout << "Unable to write lines before read" << endl;
					break;
				}

				cout << "Use default file(1) or select file(2): ";
				int type;
				cin >> type;

				ofstream f2;

				if (type == 1)
				{
					f2.open("f2.txt");
				}
				else if (type == 2)
				{
					cout << "Enter filename: ";
					string file_name;
					cin >> file_name;
					f2.open(file_name);
				}
				else
				{
					cout << "Incorrect command" << endl;
					break;
				}

				write_lines(lines, count, f2);

				cout << "File was written" << endl;

				f2.close();

				break;
			}
		}
	}
	while (k != 0);


	system("pause");
	return 0;
}
