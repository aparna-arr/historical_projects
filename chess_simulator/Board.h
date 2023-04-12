#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<string>

class Piece
{
	public:
	Piece(); // default piece
	Piece(std::string square, int side); // initialize to square and side
	~Piece(); // destructor

	virtual std::vector<std::string> IdealMoves(); // returns a list of all possible squares Piece can theoretically move to
	virtual std::vector<std::string> ValidMoves(); // returns a list of all valid moves
	std::string RandomMove(); // returns a random valid move
	bool InDanger(); // queries whether piece is in danger

	// get and set functions
	std::string GetPos();
	int GetSide();
	void SetPos(std::string p); // checks if pos is a valid move
	void SetSide(int s);
	void SetDanger(bool d); // this would have to be updated every move? 

	private:
	int side; // 0 = white, 1 = black, needed?
	bool danger;
	std::string pos;
	std::vector<std::string> ideal, valid;
};

class King : public Piece
{
	public:
	King();
	King(std::string square);
	
	void SetCheck(bool c);
       	bool GetCheck();	

	private:
	bool check;
};

class Guildmaster : public Piece
{
	public:
	Guildmaster();
	Guildmaster(std::string square);
};

class HalfElf : public Piece
{
	public:
	HalfElf();
	HalfElf(std::string square);

	void Castle();
};

class Mage : public Piece
{
	public:
	Mage();
	Mage(std::string square);
};

class Dwarf : public Piece
{
	public:
	Dwarf();
	Dwarf(std::string square);
};

class Novice : public Piece
{
	public:
	Novice();
	Novice(std::string square);
	// what about promotion / graduation? En passant?
};

class Board 
{
	public:
	Board(); // default chess board
	Board(FILE * fh); // input board from file
	~Board(); // destructor

	std::string RandomMove(int side); // returns random valid move for side, 0 = white 1 = black
	std::vector<Piece> TakeSquareList(std::string square); // returns list of pieces that can take a particular square, white and black
	std::vector<Piece> DangerList(); // returns list of pieces (and their positions) that are in immediate danger, white and black
	void OutputBoard(std::string filename); // outputs pictoral (current) board to filename 
	void PrintPieces(); // prints list of pieces with positions, etc. For debug

	private:
	std::vector<Piece> black, white;
}; 

#endif
