#pragma once
#include "../AdventOfCode2018Lib.h"

class ADVENTOFCODE2018LIB_API Day13
{
public:
	Day13();
	~Day13();
	std::vector<std::vector<char>> ReadInput();
	std::string Part1(std::vector<std::vector<char>> tracks);
	std::string Part2(std::vector<std::vector<char>> tracks);
	enum NextJunctionAction { RotateLeft, GoStraight, RotateRight };
	enum Direction { Left, Down, Right, Up };
	std::map<NextJunctionAction, NextJunctionAction> NextJunctionActions
	{
		{ NextJunctionAction::RotateLeft, NextJunctionAction::GoStraight },
		{ NextJunctionAction::GoStraight, NextJunctionAction::RotateRight },
		{ NextJunctionAction::RotateRight, NextJunctionAction::RotateLeft },
	};
	std::map<Direction, Direction> TurnLeftDirections
	{
		{ Direction::Up, Direction::Left },
		{ Direction::Left, Direction::Down },
		{ Direction::Down, Direction::Right },
		{ Direction::Right, Direction::Up },
	};
	std::map<Direction, Direction> TurnRightDirections
	{
		{ Direction::Up, Direction::Right },
		{ Direction::Right, Direction::Down },
		{ Direction::Down, Direction::Left },
		{ Direction::Left, Direction::Up },
	};
	std::map<Direction, Direction> GoStraightDirections
	{
		{ Direction::Up, Direction::Up },
		{ Direction::Right, Direction::Right },
		{ Direction::Down, Direction::Down },
		{ Direction::Left, Direction::Left },
	};
	std::map<char, Direction> DirectionChars
	{
		{ '<', Direction::Left }, 
		{ 'v', Direction::Down },
		{ '>', Direction::Right },
		{ '^', Direction::Up },
	};
	std::map<Direction, char> DirectionsToChars
	{
		{ Direction::Left, '<' },
		{ Direction::Down, 'v' },
		{ Direction::Right, '>' },
		{ Direction::Up, '^' },
	};
	std::map<std::pair<char, Direction>, Direction> NextDirections
	{
		{ { '|', Direction::Up }, Direction::Up },
		{ { '|', Direction::Down }, Direction::Down },
		{ { '-', Direction::Right }, Direction::Right },
		{ { '-', Direction::Left }, Direction::Left },
		{ { '/', Direction::Up }, Direction::Right },
		{ { '/', Direction::Left }, Direction::Down },
		{ { '/', Direction::Right }, Direction::Up },
		{ { '/', Direction::Down }, Direction::Left },
		{ { '\\', Direction::Right }, Direction::Down },
		{ { '\\', Direction::Up }, Direction::Left },
		{ { '\\', Direction::Left }, Direction::Up },
		{ { '\\', Direction::Down }, Direction::Right },
	};
	std::map<Direction, std::pair<int,int>> NumbersToAdd
	{
		{ Direction::Up, { 0, -1 } },
		{ Direction::Down, { 0, 1 } },
		{ Direction::Left, { -1, 0 } },
		{ Direction::Right, { 1, 0 } },
	};
	std::vector<std::vector<char>> ReadTracks(std::vector<std::string> tracks);
	std::map<int, std::tuple<int, int, Direction, NextJunctionAction>> ExtractCarts(std::vector<std::vector<char>> &tracks);
	std::pair<int, int> FindNextCollision(std::vector<std::vector<char>> &tracks, std::map<int, std::tuple<int, int, Day13::Direction, Day13::NextJunctionAction>> &cartsAndDirections);
};
