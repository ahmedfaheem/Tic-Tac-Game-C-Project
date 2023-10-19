
/**
 *********************************************************************************************
 * @file           : PlayerVsComputer.c
 * @author         : Ahmed Faheem
 * @brief          : Functions for Multi Mode
 *********************************************************************************************
 */

/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "functions.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Global Decleration Section Start ************* */
extern int lastWin;
/* ********************** Global Decleration  Section End   ************ */

/* ********************** Sub-Program Section Start ************* */

/* Multi player Mode */
void PlayerVsPlayer(uint32 turn)
{
    uint8 board[SIZE][SIZE];
    uint8 positionInput[SIZE * SIZE]; /* include each previous selected position */
    uint8 moveNum = 1;
    uint32 position;
    initBoard(board, positionInput);
    showInstruction();

    printf("\t\t\t\t\t\033[1;34mPlayer 1 Put: X\033[1;0m\n");
    printf("\t\t\t\t\t\033[0;31mPlayer 2 Put: O \033[1;0m\n");

    printf("\t\t\t\t---------------------------------\n\n");

    while ((!WinCheck(board)) && (moveNum <= (SIZE * SIZE)))
    {
        if (turn == PLAZERONETURN)
        {
            dispalyBoard(board);
            printf("\t\t\t\t\t\033[1;34mPlayer 1: \033[1;0m");
            inputCorrect(&position);

            /* Check if Input position is Valid or not */
            while (position == 0 || position > 9 || positionInput[position - 1] == 1)
            {
                printf("\n\n\t\t\t\t\tCan't Add In This Position\n\n");
                printf("\t\t\t\t\t\033[1;34mPlayer 1 (Enter Again): \033[1;0m");
                inputCorrect(&position);
            }

            positionInput[position - 1] = 1;
            putOnPostion(board, position, PLAZERONE);
            turn = PLAZERTWOTURN;
            moveNum++;
            system("cls");
        }
        else if (turn == PLAZERTWOTURN)
        {
            dispalyBoard(board);
            printf("\t\t\t\t\t\033[1;31mPlayer 2: \033[1;0m");
            inputCorrect(&position);
            while (position == 0 || position > 9 || positionInput[position - 1] == 1)
            {
                printf("\n\n\t\t\t\tCan't Add In This Position\n\n");
                printf("\t\t\t\t\033[1;31m  Player 2 (Enter Again): \033[1;0m");
                inputCorrect(&position);
            }
            positionInput[position - 1] = 1;
            putOnPostion(board, position, PLAZERTWO);
            turn = PLAZERONETURN;
            moveNum++;
            system("cls");
        }
    }

    dispalyBoard(board);

    if (WinCheck(board))
    {

        if (turn == PLAZERTWOTURN)
        {
            printf("\t\t\t\t\t\033[1;34mPlayer 1 Win\033[1;0m\n");
            lastWin = PLAZERONETURN;
        }
        else
        {
            printf("\t\t\t\t\t\033[1;31mPlayer 2 Win\033[1;0m\n");
            lastWin = PLAZERTWOTURN;
        }
    }
    else
    {
        printf("\t\t\t\t\t Game Over\n");
    }
    printf(" \033[1;32m  \n");
}

/* ********************** Sub-Program Section End ************* */

/**
 *************************************************************************************************************************
 User               Date                 Brief
 *************************************************************************************************************************
 Ahmed Faheem     15Oct2023            First Create

*/