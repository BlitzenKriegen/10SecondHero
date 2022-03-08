/*
Names:  	Enrik R
			Kiril S

Module:		Model 

Purpose: 	The model module contains the structs and functions related to the 
			model of the game, and the functions that directly impact the model. 

Details: 	The model is not responsible for handling events, whether they be
			synchronous, asychronous, or conditional. The model handles the
			behaviours or actions that result from those events occuring.
			Ex: Space bar is pressed (event) = player jumps (action)
*/


#ifndef MODEL_H
#define MODEL_H
#define base_len 20
#define score_tick 50
#define fps 35

#define TIME_ADD 3
#define SCORE_ADD 1

/* ground initilization data*/
#define GROUND 0
#define GROUND_X 0
#define GROUND_Y 350
#define GROUND_LEN 40

/* initilization data of other platforms*/
/* platform 1*/
#define P1_X 20
#define P1_Y 280
#define P1_LEN 2
/* platform 2*/
#define P2_X 40
#define P2_Y 215
#define P2_LEN 4
/* platform 3*/
#define P3_X 80
#define P3_Y 250
#define P3_LEN 8
/* platform 4*/
#define P4_X 200
#define P4_Y 150
#define P4_LEN 6
/* platform 5*/
#define P5_X 400
#define P5_Y 200
#define P5_LEN 6

/* initilization of player */
#define PLAYER_X 320
#define PLAYER_Y 340
#define PLAYER_X_VEL 3
#define PLAYER_Y_VEL 3 

/* initilization of crystal */
typedef enum {false, true} bool;
#define CRYSTAL_X 200
#define CRYSTAL_Y 300
#define CRYSTAL_CONTACT 0

/* initilization of timer */
#define TIMER_X 50
#define TIMER_Y 370
#define TIMER_SECS 10
#define TIMER_TICKS 0

/* initilization of score*/
#define SCORE_X 600
#define SCORE_Y 370
#define SCORE_AMNT 0
#define MAX_SCORE 9999

/*The following structure represents a platform 
within 10 Second Hero. The platform is defined by 
three parameters. The two parameters are the x and
y coordinates of where the platform would begin to be
drawn. Length is a whole number that represents how 
long a platform could be. For example, assuming the 
length is 3, the platform would be drawn base_len*length 
long, where baase_len is the base length of the platform.*/
struct Platform
{
	unsigned int x;			
	unsigned int y;			
	unsigned int length;
};

/*The following structure represents the player
character within 10 second hero, sans its bitmap.
x and y represent the coordinates of the player, while
xVel and yVel represent the directional movement of the
player per game tick. Negatives represent left and down
respectively, while positive values represent right and
up, again respectively.*/
struct Player
{
	unsigned int x;
	unsigned int y;
	unsigned int xVelocity;
	unsigned int yVelocity;
};

/*The following strucutre represents the collectable
crystal within the game. Once again, x and y represent
the coordinates of the crystal, while playerContact
represent if the player is "touching" the hitbox of the
crystal. This value would be 0 if the player is not in
contact with the crystal, while it would be 1 were the
player to come in contact with the crystal.*/
struct Crystal
{
	unsigned int x;
	unsigned int y;
	bool playerContact;
};

/*The following structure represents the timer within
10 second hero. Currently, this holds the x and y cordinate
of the byte wholeSeconds, which represents the remaining time.
Each game tick, the time gets subtracted by 
1/(Game ticks per second).*/
struct TimeRemaining
{
	unsigned int x;
	unsigned int y;
	unsigned int wholeSeconds;
	unsigned int ticks;
	/*unsigned char tenthSeconds;		for future development
	unsigned char hundrethSeconds;*/
};

/*The following structure holds the score of the played game.
x and y represent the coordinates of the scoreboard, while
score itself is the numeric representation of the points
attained by the player.*/

struct Score
{
	unsigned int x;
	unsigned int y;
	unsigned int scoreAmnt;
};


struct Model
{
	struct Player player;
	struct Crystal crystal;
	struct Platform platforms[6]; /* 0 is ground platform */
	struct Score score;
	struct TimeRemaining timeLeft;
	bool isTimer0;
};


/* void playerJump (struct Player *playChar)	for future development*/

/* void playerFall (struct Player *playChar)	for future development*/

void playerRun(struct Player *playChar);

void moveCrystal(struct Crystal *inPlay, int newXCord, int newYCord);

void increaseScore(struct Score *score);

void decreaseTime(struct TimeRemaining *timeLeft);

void increaseTime(struct TimeRemaining *timeLeft);

/* initiliziers*/
void initPlatform(struct Platform *platform, int initX, int initY, int initLength);	

void initPlayer(struct Player *playChar);		

void initCrystal(struct Crystal *crystal);	

void initScore(struct Score *score);	

void initTimer(struct TimeRemaining *timeLeft);	

void initModel(struct Model *model);	

#endif