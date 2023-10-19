/**
 ******************************************************************************
 * @file           : function.h
 * @author         : Ahmed Faheem
 * @brief          : Tic-Tac-Toe Game function declarations
 ******************************************************************************
 */

#ifndef _FUNCTIONS_
#define _FUNCTIONS_

/* ********************** Includes Section Start ********************** */

#include "STD_TYPES.h"

/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

#define SIZE 3
#define PLAZERONE 'X'
#define PLAZERTWO 'O'
#define PLAZERONETURN 1
#define PLAZERTWOTURN 2

/* ********************** Macro Section End   ************************* */

/* ********************** Sub-Program Declerations Section Start ******* */

void inputCorrect(uint32 *val);
uint8 checkEmpty(uint8 val);
void showInstruction();
void dispalyBoard(uint8 board[][SIZE]);
uint8 rowCheck(uint8 board[][SIZE]);
uint8 colCheck(uint8 board[][SIZE]);
uint8 diagonalCheck(uint8 board[][SIZE]);
uint8 WinCheck(uint8 board[][SIZE]);
void initBoard(uint8 board[][SIZE], uint8 positionInput[]);
void putOnPostion(uint8 board[][SIZE], uint32 position, uint8 playerInput);
void PlayerVsPlayer(uint32 turn);
uint8 ticAlgorithm(uint8 board[][SIZE], uint32 *position, uint32 mode);
void PlayerVsComputer(uint32 turn, uint32 mode);

/* ********************** Sub-Program Declerations Section End ******* */
#endif

/**
 ******************************************************************************
 User               Date                 Brief
 ******************************************************************************
 Ahmed Faheem     15Oct2023            First Create
 Ahmed Faheem     19Oct2023            adding mode parameter on PlayerVsComputer
 */