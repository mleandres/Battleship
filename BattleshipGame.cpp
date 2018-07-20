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
	std::map<Ship, int> ShipProperties{ {CARRIER, 5}, {BATTLESHIP, 4}, {CRUISER, 3}, {SUBMARINE, 3}, {DESTROYER, 2} };

	typedef std::vector<Coordinate> shipCoordinate;
	typedef std::map<Ship, shipCoordinate> ShipsOnBoard;
	ShipsOnBoard PlayersShips{};

public:
	Board() {}

	void displayBoard() {
		std::cout << "  A  B  C  D  E  F  G  H  I  J" << std::endl;

		for (int i = 0; i < 10; i++) {
			std::cout << i;

			for (int j = 0; j < 10; j++) {
				std::cout << " - ";
			}

			std::cout << std::endl;
		}
	}

	void addShip(Ship typeOfShip, Coordinate startingCoordinate, Coordinate endingCoordinate) {

		//TODO
		if (this->PlayersShips.count(*&typeOfShip) != 0) {
			std::cout << "This Ship already exists !";
			return void();
		}

		//check that coordinate makes sense and available
		//i.e make sure that not overlapping ships
		int ShipLength = this->ShipProperties.at(*&typeOfShip);
		if (*&startingCoordinate.x != *&endingCoordinate.x && *&startingCoordinate.y != *&endingCoordinate.y) {
			std::cout << "Cant Place a Ship Here !";
			return void();
		}
		else if (*&startingCoordinate.x == *&endingCoordinate.x) {
			if (*&startingCoordinate.y - *& endingCoordinate.y != ShipLength-1 && *&startingCoordinate.y - *& endingCoordinate.y != -ShipLength+1)
				std::cout << "Cant Place a Ship Here !";
				return void();
		}
		else if (*&startingCoordinate.y == *&endingCoordinate.y) {
			if (*&startingCoordinate.x - *& endingCoordinate.x != ShipLength - 1 && *&startingCoordinate.x - *& endingCoordinate.x != -ShipLength + 1)
				std::cout << "Cant Place a Ship Here !";
			return void();
		}
			else {
				//add all of the ships spots taken up into the shipCoordinate array
				shipCoordinate coordinate = { *&startingCoordinate, *&endingCoordinate };
				this->PlayersShips.insert(std::make_pair(*&typeOfShip, *&coordinate));
			}
		}
	


	void getShip() {
		shipCoordinate x = this->PlayersShips.at(CARRIER);
		Coordinate xex = x[1];
		std::cout << xex.x;
	}
};

int main()
{
	Board* player1 = new Board();
	player1->displayBoard();

	Coordinate startingCoordinate = { 5,6 };
	Coordinate endingCoordinate = { 3,6 };
	Ship typeOfShip = CRUISER;
	player1->addShip(typeOfShip, startingCoordinate, endingCoordinate);

	Coordinate poop = { 5,6 };
	Coordinate poopy = { 3,6 };
	Ship ok = CRUISER;
	player1->addShip(ok, poop, poopy);






	


	//splayer1->getShip();

	std::getchar();
}


