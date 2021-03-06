// BattleshipGame.cpp : Defines the entry point for the console application.
//in this game there will be two players who setup

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <ostream>

enum Ship {
	CARRIER,
	BATTLESHIP,
	CRUISER,
	SUBMARINE,
	DESTROYER
};

struct Coordinate {
	int x;
	int y;
};

class Board {
	typedef std::vector<Coordinate> shipCoordinate;
	typedef std::map<Ship, shipCoordinate> ShipsOnBoard;
	std::map<Ship, int> ShipProperties{ { CARRIER,    5 },
	{ BATTLESHIP, 4 },
	{ CRUISER,    3 },
	{ SUBMARINE,  3 },
	{ DESTROYER,  2 } };
	ShipsOnBoard PlayersShips{};

public:
	Board() {

	}
	void displayBoard() {
		std::cout << "  A  B  C  D  E  F  G  H  I  J" << std::endl;
		std::string placement = " - ";

		for (int i = 0; i < 10; i++) {
			std::cout << i;

			for (int j = 0; j < 10; j++) {
				std::cout << " - ";

				//foreach ship, running through the coordinates, if coordinate matches print "x"
			}
			std::cout << std::endl;
		}
	}

	void addShip(Ship& typeOfShip, Coordinate& startingCoordinate, Coordinate& endingCoordinate) {
		std::map<Ship, shipCoordinate>::iterator it;
		it = PlayersShips.find(typeOfShip);
		if (it != this->PlayersShips.end()) {
			std::cout << "Ship Already Placed on Board";
			return void();
		}

		int ShipLength = this->ShipProperties.at(typeOfShip);
		shipCoordinate shipsCoordinate = { startingCoordinate, endingCoordinate };

		if (startingCoordinate.x == endingCoordinate.x) {
			if (startingCoordinate.y - endingCoordinate.y == ShipLength - 1
				|| startingCoordinate.y - endingCoordinate.y == -ShipLength + 1) {

				
				int max = std::max(startingCoordinate.y, endingCoordinate.y);
				int min = std::min(startingCoordinate.y, endingCoordinate.y);

				for (int i = min + 1; i < max; i++) {
					shipsCoordinate.push_back({ startingCoordinate.x, i });
					
				}

				for (int j = 0; j < shipsCoordinate.size(); j++) {
					std::cout << shipsCoordinate.at(j).x << shipsCoordinate.at(j).y << std::endl;
				}

				for (it = this->PlayersShips.begin(); it != this->PlayersShips.end(); it++)
				{
					for (int j = 0; j < shipsCoordinate.size(); j++) {

						for (int i = 0; i < it->second.size(); i++) {
							if (shipsCoordinate.at(j).x == it->second.at(i).x && shipsCoordinate.at(j).x == it->second.at(i).y) {
								std::cout << "OOPS WE CANNOT PLACE A SHIP HERE AS IT IS CONFLICTING WITH ANOTHER SHIP";
								return void();
							}
							else {
								continue;
							}
						}
					}						
				}

			}
			else {
				std::cout << "Cant Place a Ship Here boi !";
				return void();
			}

		}
		else if (startingCoordinate.y == endingCoordinate.y) {
			if (startingCoordinate.x - endingCoordinate.x == ShipLength - 1 ||
				startingCoordinate.x - endingCoordinate.x == -ShipLength + 1) {

				int max = std::max(startingCoordinate.x, endingCoordinate.y);
				int min = std::min(startingCoordinate.x, endingCoordinate.y);

				for (int i = min + 1; i < max; i++) {
					shipsCoordinate.push_back({ startingCoordinate.y, i });
				}

				//check for conflicting placement
				for (it = this->PlayersShips.begin(); it != this->PlayersShips.end(); it++)
				{
					for (int j = 0; j < shipsCoordinate.size(); j++) {

						for (int i = 0; i < it->second.size(); i++) {
							if (shipsCoordinate.at(j).x == it->second.at(i).x && shipsCoordinate.at(j).x == it->second.at(i).y) {
								std::cout << "OOPS WE CANNOT PLACE A SHIP HERE AS IT IS CONFLICTING WITH ANOTHER SHIP";
								return void();
							}
							else {
								continue;
							}
						}
					}
				}
			}
			else {
				std::cout << "Cant Place a Ship Here !";
				return void();
			}
		}
		else {
			std::cout << "Bad Ship Placement";
			return void();
		}

		this->PlayersShips.insert(std::make_pair(typeOfShip, shipsCoordinate));
		
	}
};

int main()
{
	Board* player1 = new Board();
	player1->displayBoard();


	Coordinate startingCoordinate = { 4,2 };
	Coordinate endingCoordinate = { 4,5 };
	Ship typeOfShip = BATTLESHIP;
	player1->addShip(typeOfShip, startingCoordinate, endingCoordinate);


	Coordinate x = { 5,3 };
	Coordinate y = { 4,3 };
	Ship a = DESTROYER;
	player1->addShip(a, x, y);



	std::getchar();
}