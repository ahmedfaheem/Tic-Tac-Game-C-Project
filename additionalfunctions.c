/**
 *********************************************************************************************
 * @file           : additionalfunctions.c
 * @author         : Ahmed Faheem
 * @brief          : Functions help to implement PlayerVsComputer and PlayerVsPlayer files
 *********************************************************************************************
 */

/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "functions.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Sub-Program Section Start ************* */

/* Check if input is integer or not and if not enter again */
void inputCorrect(uint32 *val)
{
    uint32 state = 0;
    uint32 attemps = 3;

    while (!state)
    {
        if (scanf("%d", val) == 1)
        {
            state = 1;
        }
        else
        {
            while (getchar() != '\n')
                ;

            if (attemps == 0)
            {
                exit(0);
            }

            printf("\n\n\t\tTry again. You have %d attempts remaining, after them the Game will exit", attemps--);

            printf("\n\n\t\t\t\t       Enter Again: ");
        }
    }
}

/* check cell if empty or not --if retrun 1 so not empty else is empty */
uint8 checkEmpty(uint8 val)
{
    uint8 state = 0;
    if (val == PLAZERONE || val == PLAZERTWO)
    {
        state = 1;
    }
    return state;
}

/* Describe The instruction of the Game*/
void showInstruction()
{
    printf("\n");
    printf("\t\t\t\tSelection Postion Form 1 To 9 \n\n");
    printf("\t\t\t\t---------------------------------\n\n");
}

/* Display Boarad of Game */
void dispalyBoard(uint8 board[][SIZE])
{
    printf("\033[1;32m");
    printf("\t\t\t\t---------------------------------\n\n");
    printf("\t\t\t\t\t %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t\t\t----|-----|-----\n ");

    printf("\t\t\t\t\t %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t\t\t----|-----|-----\n ");

    printf("\t\t\t\t\t %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\t\t\t\t\t----|-----|-----\n ");

    printf("\t\t\t\t---------------------------------\n\n");
    printf("\033[0m\n");
}

/* Check Rows of borad to check if each row elements is equal or not */
uint8 rowCheck(uint8 board[][SIZE])
{
    uint8 count;
    for (count = 0; count < SIZE; count++)
    {
        if (board[count][0] == board[count][1] && board[count][1] == board[count][2] && checkEmpty(board[count][0]))
        {
            return 1;
        }
    }
    return 0;
}

/* Check Columns  of borad to check if each column elements is equal or not */

uint8 colCheck(uint8 board[][SIZE])
{
    uint8 count;
    for (count = 0; count < SIZE; count++)
    {
        if (board[0][count] == board[1][count] && board[1][count] == board[2][count] && checkEmpty(board[0][count]))
        {
            return 1;
        }
    }
    return 0;
}

/* Check if Diagnal Cells on Borad is Equal or not  */

uint8 diagonalCheck(uint8 board[][SIZE])
{
    uint8 count;
    for (count = 0; count < SIZE; count++)
    {
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && checkEmpty(board[0][0])) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && checkEmpty(board[0][2])))
        {
            return 1;
        }
    }
    return 0;
}

/* check Winner */
uint8 WinCheck(uint8 board[][SIZE])
{

    if (rowCheck(board) || colCheck(board) || diagonalCheck(board))
    {
        return 1;
    }

    return 0;
}

/*
   initalize borad element to be form 1 to 9 for play instruction,
   and positonInput array which use to check if Cell is taken or not
*/

void initBoard(uint8 board[][SIZE], uint8 positionInput[])
{

    uint8 row, col, index, count = 49;

    for (row = 0; row < SIZE; row++)
    {

        for (col = 0; col < SIZE; col++, count++)
        {

            board[row][col] = count;
        }
    }

    for (index = 0; index < SIZE; index++)
    {
        positionInput[index] = 0;
    }
}

/* Assign the requied Cell with The input value */
void putOnPostion(uint8 board[][SIZE], uint32 position, uint8 playerInput)
{

    switch (position)
    {
    case 1:
        board[0][0] = playerInput;
        break;
    case 2:
        board[0][1] = playerInput;
        break;
    case 3:
        board[0][2] = playerInput;
        break;
    case 4:
        board[1][0] = playerInput;
        break;
    case 5:
        board[1][1] = playerInput;
        break;
    case 6:
        board[1][2] = playerInput;
        break;
    case 7:
        board[2][0] = playerInput;
        break;
    case 8:
        board[2][1] = playerInput;
        break;
    case 9:
        board[2][2] = playerInput;
        break;
    }
}

/* ********************** Sub-Program Section End ************* */

/**
 *************************************************************************************************************************
 User               Date                 Brief
 *************************************************************************************************************************
 Ahmed Faheem     15Oct2023            First Create
 Ahmed Faheem     19OCT2023            adding attemps counter(after 3 attemps program exit)
                                       on function inputCorrect() form line 36
*/