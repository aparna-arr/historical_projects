#include<iostream>
#DEFINE LIFESPAN 20

class Mouse {
	public:
		int cycle(void); // decrememnts lifespan, returns lifespan after dec
		bool subtract(int otherMouse); // if otherMouse is <, this one wins. If otherMouse is >, this one is set to 0. If ==, return FALSE and let controller decide which one to set to 0.
		void setZero(); // set this mouse's value to 0
		bool die(bool cleanup); // Kill mouse, output value if cleanup is FALSE
		int getValue(); // get mouse value
	private:	
		bool isDead;
		int value;
		int lifespan;	
};

class Cage {
	public:
		bool addMouse(Mouse * mouse); // adds new mouse to cage
		Mouse * removeMouse(void); // removes mouse from cage
		bool fight(void); // starts fight in cage
		bool breed(void); // starts breeding in cage
		
	private:
		Mouse*[4] mice; // array of ptrs to mice in cage
};

class Hand {
	public:
		bool inc(void); // increments position
		bool dec(void); // decrements position
		bool setPos(int newpos); // sets new position
		int getPos(void); // returns current position
		bool getMouse(int mouseIndex); // gets a mouse from a cage
		bool placeMouse(int cagePos); // places a mouse in a cage
		bool killMouse(bool cleanup); // kills mouse		
		int getMouseValue(void); // gets value of mouse
	private:
		bool hasMouse;
		Mouse * mouse; // if has mouse in hand
		int curr_pos;
		int prev_pos;
};

class Control {
	public:
		void washHands(void); // NOP
		bool pop(bool store); // if store is TRUE, store cage at tmp
		bool slice(bool whichHand, int numCages); // slices numCages cages from top of stack, places whichHand at top of stack
	        bool isEmpty(bool whichHand); // check if cage is empty at whichHand. if no hand given, return TRUE if both cages are empty and FALSE if at least one is full
		void cleanUp(void); // call to cleanUp. Increments cleanup.
		bool swapCages(void); // swaps cages at hands
		bool fight(bool whichHand); // starts fight in cage at left, right, or both hands
	        bool breed(bool whichHand); // starts breeding at left, right, or both hands
		bool mutate(bool whichHand); // mutates all mice in cage at left, right, or both hands
		bool push(void); // pushes tmp cage to stack, only if nonempty	
		bool import(Mouse * newMouse); // brings in new mouse
		bool clone(void); // clones mouse in hand. Only one hand can be holding a mouse. 
		bool inc(bool whichHand);
		bool dec(bool whichHand); 
		bool toTmp(bool whichHand); // moves hand to tmp cage
	
	private:
		void cycle(void); // deals with cycle, kills mice, checks dead mice, cleans up
		void checkDeath(void); // checks all cages for mouse death. If mouse has died and cleanup != 0, calls cleanCages. 
		bool cleanCages(void); // removes dead mice from all cages: all mice of value 0 and isDead
		Hand leftHand;
		Hand rightHand;
		Cage * cages; // stack of cages
		Cage tmp; // tmp cage
		int cleanup; // keeps track of calls to cleanup. 
		Mouse * mice; // should be vector: cages too
}
