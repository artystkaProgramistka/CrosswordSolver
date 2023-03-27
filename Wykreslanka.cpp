#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void wyp(vector <string> tab);
int main()
{
	fstream plik1;
	plik1.open("WORDSEARCH.txt", ios::in);
	fstream plik2;
	plik2.open("WORDKEY.txt", ios::in);
	vector <string> wordsearch;
	vector <string> wordkey;
	vector <string> fkey;
	string temp;
	while (!plik1.eof())
	{
		getline(plik1, temp);
		wordsearch.push_back(temp);
	}
	while (!plik2.eof())
	{
		getline(plik2, temp);
		wordkey.push_back(temp);
	}
	plik1.close();
	plik2.close();
	cout << "Word search loaded..." << endl;
	wyp(wordsearch);
	cout << endl << "Words to find loaded..." << endl;
	for (int i = 0; i < wordkey.size(); i++)
	{
		cout << wordkey[i] << endl;
	}
	vector <string> solution;
	for (int i = 0; i < wordsearch.size(); i++)
	{
		temp = "";
		for (int j = 0; j < wordsearch[i].size(); j++)
		{
			temp += '*';
		}
			solution.push_back(temp);
	} 
	for (int y = 0; y < wordsearch.at(0).length(); y++)
	{
		for (int x = 0; x < wordsearch.size(); x++)
		{
			for (int i = 0; i < wordkey.size(); i++)
			{
				if (wordkey[i][0] == wordsearch[y][x])
				{
					/*
					123
					4 5
					678
					*/

					//1
					if (x > 0 && y > 0 && wordkey[i][1] == wordsearch[y - 1][x - 1])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (j > x) break;
							if (j > y) break;
							
							if (wordkey[i][j] == wordsearch[y - j][x - j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y - j][x - j] = wordsearch[y - j][x - j];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//2
					if (y > 0 && wordkey[i][1] == wordsearch[y - 1][x])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (j > y) break;
							if (wordkey[i][j] == wordsearch[y - j][x])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y - j][x] = wordsearch[y - j][x];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//3
					if (x < wordsearch[y].size() - 1 && y > 0 && wordkey[i][1] == wordsearch[y - 1][x + 1])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (x + j > wordsearch[y].size() - 1) break;
							if (j > y) break;
							if (wordkey[i][j] == wordsearch[y - j][x + j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y - j][x + j] = wordsearch[y - j][x + j];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//4
					if (x > 0 && wordkey[i][1] == wordsearch[y][x - 1])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (j > x) break;
							if (wordkey[i][j] == wordsearch[y][x - j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y][x - j] = wordsearch[y][x - j];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//5
					if (x < wordsearch[y].length() - 1 && wordkey[i][1] == wordsearch[y][x + 1])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (x + j > wordsearch[y].size() - 1) break;
							if (wordkey[i][j] == wordsearch[y][x + j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y][x + j] = wordsearch[y][x + j];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//6
					if (x > 0 && y < wordsearch.size() - 1 && wordkey[i][1] == wordsearch[y + 1][x - 1])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (y + j > wordsearch.size() - 1) break;
							if (j > x) break;
							if (wordkey[i][j] == wordsearch[y + j][x - j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y + j][x - j] = wordsearch[y + j][x - j];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//7
					if (y < wordsearch.size() - 1 && wordkey[i][1] == wordsearch[y + 1][x])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (y + j > wordsearch.size() - 1) break;
							if (wordkey[i][j] == wordsearch[y][x + j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y + j][x] = wordsearch[y + j][x];
							}
							wordkey.erase(wordkey.begin() + i);
							fkey.push_back(temp);
							break;
						}
					}
					//8
					if (x < wordsearch[y].size() - 1 && y < wordsearch.size() - 1 && wordkey[i][1] == wordsearch[y + 1][x + 1])
					{
						temp = wordkey[i][0];
						temp += wordkey[i][1];
						for (int j = 2; j < wordkey[i].length(); j++)
						{
							if (x + j > wordsearch[y].size() - 1) break;
							if (y + j > wordsearch.size() - 1) break;
							if (wordkey[i][j] == wordsearch[y + j][x + j])
							{
								temp += wordkey[i][j];
							}
							else break;
						}
						if (temp == wordkey[i])
						{
							for (int j = 0; j < wordkey[i].length(); j++)
							{
								solution[y + j][x + j] = wordsearch[y + j][x + j];
							}
							wordkey.erase(wordkey.begin()+i);
							fkey.push_back(temp);
							break;
						}
					}
				}
			}
		}
	}
	cout << endl;
	cout << "Found " << fkey.size() << " out of " << fkey.size() + wordkey.size() << " word";
	if (fkey.size() + wordkey.size() > 1) cout << "s";
	cout << ".";
	if (wordkey.size() > 0)
	{
		cout << endl << "Words not found: ";
		for (int i = 0; i < wordkey.size(); i++)
		{
			cout << wordkey[i] << ", ";
		}
	}
	cout << endl <<"Solution below: " << endl;
	wyp(solution);
}
void wyp(vector <string> tab)
{
	cout << "  |";
	for (int i = 0; i < tab.size(); i++)
	{
		cout << char(65 + i);
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < tab.size(); i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < tab.size(); i++)
	{
		if (i + 1 < 10) cout << " ";
		cout << i + 1 << "|" << tab[i] << endl;
	}
}