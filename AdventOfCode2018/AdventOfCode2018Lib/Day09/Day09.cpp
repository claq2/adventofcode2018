#include "stdafx.h"
#include "Day09.h"
#include <fstream>
#include <sstream>
#include <list>
#include <map>

using namespace std;

Day09::Day09()
{
}

Day09::~Day09()
{
}

pair<int, int> Day09::ReadInput()
{
	vector<string> result;
	ifstream file;

	file.open("Day09.txt");
	if (!file)
	{
		exception e("file not open");
		throw e;
	}

	string line;
	getline(file, line);

	file.close();

	istringstream is(line);
	// 10 players; last marble is worth 1618 points
	string n;
	while (is >> n) {
		result.push_back(n);
	}

	pair<int, int> numbers({ stoi(result[0]), stoi(result[6]) });
	return numbers;
}

string Day09::Part1(pair<int, int> values)
{
	int players = values.first;
	int marbles = values.second;
	list<int> circle({ 0, 2, 1 });
	map<int, int> playerScores;
	/*
[-] (0)
[1]  0 (1)
[2]  0 (2) 1
[3]  0  2  1 (3)
[4]  0 (4) 2  1  3
[5]  0  4  2 (5) 1  3
[6]  0  4  2  5  1 (6) 3
[7]  0  4  2  5  1  6  3 (7)
[8]  0 (8) 4  2  5  1  6  3  7
[9]  0  8  4 (9) 2  5  1  6  3  7
[1]  0  8  4  9  2(10) 5  1  6  3  7
[2]  0  8  4  9  2 10  5(11) 1  6  3  7
[3]  0  8  4  9  2 10  5 11  1(12) 6  3  7
[4]  0  8  4  9  2 10  5 11  1 12  6(13) 3  7
[5]  0  8  4  9  2 10  5 11  1 12  6 13  3(14) 7
[6]  0  8  4  9  2 10  5 11  1 12  6 13  3 14  7(15)
	*/
	list<int>::iterator it = circle.begin();
	advance(it, 1);// start at the 2 in the middle
	for (int i = 3; i <= marbles; i++)
	{
		if (i % 23 == 0)
		{
			int player = i % players;
			playerScores[player] += i;
			// Reverse 7 
			for (int j = 0; j < 7; j++)
			{
				if (it == circle.begin())
				{
					it = circle.end();
				}
				it--;
			}

			playerScores[player] += *it;
			it = circle.erase(it);
		}
		else
		{
			// Advance twice
			for (int j = 0; j < 2; j++)
			{
				it++;
				if (it == circle.end())
				{
					it = circle.begin();
				}
			}

			// Insert next number
			if (it == circle.begin())
			{
				// Insert at end
				circle.push_back(i);
				it = circle.end();
				advance(it, -1);
			}
			else
			{
				// Insert at current location
				it = circle.insert(it, i);
			}
		}
	}

	int maxScore(0);
	for (auto const & s : playerScores)
	{
		if (s.second > maxScore)
		{
			maxScore = s.second;
		}
	}

	return to_string(maxScore);
}

string Day09::Part2(pair<int, int> values)
{
	return std::string();
}
