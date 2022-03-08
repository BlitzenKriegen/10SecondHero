/*
Names:  	Enrik R
			Kiril S

Module:		Event

Purpose: 	The event module contains the functions related to handling events
			in the game.

Details: 	Event handlers affect the game based on the synchronous asynchronous
			or conditional events that occur, such as the pressing of keys
			requesting the player to move a specific direction, or the
			collection of a crystal.
*/

#ifndef EVENT_H
#define EVENT_H

/* Synchronous Events */
/*
void decreaseTime(struct Model *model);
*/

/* Asynchronous Events*/
/* implement these later
void moveKeyPressed ();

void jumpKeyPressed ();
*/

/* Conditional Events*/

bool isTimer0 (struct Model *model);

void crystalCollected ();


/* not sure how to code this right now, will likely need multiple functions.*/
/* void collisions();*/



#endif