#include<vector>
#include<string>
#include<iostream>
#include "Board.h"
using namespace std;

Piece::Piece()
{

}

Piece::Piece(string square, int side)
{

}

Piece::~Piece() 
{

}

vector<string> Piece::IdealMoves()
{
	return ideal;
}

vector<string> Piece::ValidMoves()
{
	return valid;
}

string Piece::RandomMove()
{
	return pos; // placeholder
}

bool Piece::InDanger()
{
	return danger;
}

string Piece::GetPos()
{
	return pos;
}

int Piece::GetSide()
{
	return side;
}

void Piece::SetPos(string p)
{
	// check if position is valid
	pos = p;
}

void Piece::SetSide(int s)
{
	side = s;
}

void Piece::SetDanger(bool d)
{
	danger = d;
}

King::King() 
{

}

King::King(string square) 
{

}

void King::SetCheck(bool c) 
{
	check = c;
}

bool King::GetCheck()
{
	return check;
}

Guildmaster::Guildmaster()
{

}

Guildmaster::Guildmaster(string square)
{

}

HalfElf::HalfElf()
{

}

HalfElf::HalfElf(string square)
{

}

Mage::Mage()
{

}

Mage::Mage(string square)
{

}

Dwarf::Dwarf()
{

}

Dwarf::Dwarf(string square)
{

}

Novice::Novice()
{

}

Novice(string square) 
{

}

Board::Board()
{
	black.reserve(16);
	white.reserve(16);
	// continue
}

Board::Board(FILE * fh)
{
	
}

string Board::RandomMove(int side)
{
	// select random piece, select random valid move
	// change pos in piece
	// return new pos
	string tmp = "";
	return tmp; // placeholder
}

vector<Piece> Board::TakeSquareList(string square)
{
	vector<Piece> tmp; // placeholder
	return tmp;
}

vector<Piece> Board::DangerList()
{
	vector<Piece> tmp; // placeholder
	return tmp;
}

void Board::OutputBoard(string filename)
{

}

void Board::PrintPieces()
{

}

