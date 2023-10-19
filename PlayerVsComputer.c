/**
 *********************************************************************************************
 * @file           : PlayerVsComputer.c
 * @author         : Ahmed Faheem
 * @brief          : Functions for Single Mode
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

/* Algorithms For  Sigle Player Mode */

uint8 ticAlgorithm(uint8 board[][SIZE], uint32 *position, uint32 mode)
{
    uint8 state = 0;
    int i;

    /* If Mode == 1 -> Hard Mode else Easy Mode */
    if (mode == 1)
    {
        /* check rows */
        for (i = 0; i < SIZE; i++)
        {
            if (board[0][i] == board[2][i] && !checkEmpty(board[1][i]) && checkEmpty(board[0][i]))
            {
                board[1][i] = PLAZERTWO;
                *position = 4 + i;
                state = 1;
                break;
            }
            else if (board[0][i] == board[1][i] && !checkEmpty(board[2][i]) && checkEmpty(board[0][i]))
            {
                board[2][i] = PLAZERTWO;
                *position = 7 + i;
                state = 1;
                break;
            }
            else if (board[1][i] == board[2][i] && !checkEmpty(board[0][i]) && checkEmpty(board[1][i]))
            {
                board[0][i] = PLAZERTWO;
                *position = 1 + i;
                state = 1;
                break;
            }
        }

        /* Check col 2 with col 3 */
        if (state != 1)
        {
            for (i = 0; i < SIZE; i++)
            {
                if (board[i][1] == board[i][2] && !checkEmpty(board[i][0]) && checkEmpty(board[i][1]))
                {
                    board[i][0] = PLAZERTWO;
                    if (i == 0)
                    {
                        *position = 1;
                    }
                    else if (i == 1)
                    {
                        *position = 4;
                    }
                    else
                    {
                        *position = 7;
                    }
                    state = 1;
                    break;
                }
            }
        }

        /*col 2 with col 3*/
        if (state != 1)
        {
            for (i = 0; i < SIZE; i++)
            {
                if (board[i][0] == board[i][2] && !checkEmpty(board[i][1]) && checkEmpty(board[i][0]))
                {
                    board[i][1] = PLAZERTWO;
                    if (i == 0)
                    {
                        *position = 2;
                    }
                    else if (i == 1)
                    {
                        *position = 6;
                    }
                    else
                    {
                        *position = 8;
                    }
                    state = 1;
                    break;
                }
            }
        }

        /* col 1 and col 2 */
        if (state != 1)
        {
            for (i = SIZE - 1; i <= 0; i--)
            {
                if (board[0][i] == board[1][i] && !checkEmpty(board[i][2]) && checkEmpty(board[0][i]))
                {
                    board[i][2] = PLAZERTWO;
                    if (i == 0)
                    {
                        *position = 3;
                    }
                    else if (i == 1)
                    {
                        *position = 6;
                    }
                    else
                    {
                        *position = 9;
                    }
                    state = 1;
                    break;
                }
            }
        }
    }
    /* if Not any algoritm above work */
    if (state == 0)
    {
        if (((board[0][2] == board[1][1]) && (checkEmpty(board[0][2])) && (!checkEmpty(board[2][0]))))
        {
            board[2][0] = PLAZERTWO;
            *position = 7;
            state = 1;
        }
        else if (((board[0][0] == board[1][1]) && (checkEmpty(board[0][0])) && !checkEmpty(board[2][2])))
        {
            board[2][2] = PLAZERTWO;
            *position = 9;
            state = 1;
        }
        else if (((board[2][0] == board[1][1]) && (checkEmpty(board[2][0])) && (!checkEmpty(board[0][2]))))
        {
            board[0][2] = PLAZERTWO;
            *position = 3;
            state = 1;
        }
        else if (((board[2][2] == board[1][1]) && (checkEmpty(board[2][2])) && !checkEmpty(board[0][0])))
        {
            board[0][0] = PLAZERTWO;
            *position = 1;
            state = 1;
        }
    }
    return state;
}

/* Sigle Player Mode*/
void PlayerVsComputer(uint32 turn, uint32 mode)
{

    uint8 board[SIZE][SIZE];
    uint8 positionInput[SIZE * SIZE]; /* include each previous selected position */
    uint8 moveNum = 0, x, y;          /* move number -> number of occupied position */
    uint32 position = 0;
    initBoard(board, positionInput);

    showInstruction();
    printf("\t\t\t\t\t\033[1;34mPlayer 1 Put: X\033[1;0m\n");
    printf("\t\t\t\t\t\033[0;31mPlayer 2 Put: O \033[1;0m\n");

    printf("\t\t\t\t---------------------------------\n\n");

    while ((!WinCheck(board)) && (moveNum < (SIZE * SIZE)))
    {
        /* Player Turn */
        if (turn == PLAZERONETURN)
        {
            dispalyBoard(board);
            printf("\t\t\t\t\t\033[1;34mPlayer 1: \033[1;0m");
            inputCorrect(&position);
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
        /* Computer Turn */
        else if (turn == PLAZERTWOTURN)
        {
            if (!ticAlgorithm(board, &position, mode))
            {
                if (moveNum == 0)
                { // random location if computer start
                    position = (rand() % (9)) + 1;
                }
                else
                {
                    x = moveNum / SIZE;
                    y = moveNum % SIZE;
                    position = x + y + 1;
                }
                /* Cehck all Cells after predicted positon if is occupied*/
                while (position <= 9 && positionInput[position - 1] == 1)
                {
                    /*start check from begain if after old poisition occupied */
                    if (position - 1 == 8 && positionInput[8] == 1)
                    {
                        position = 0;
                    }
                    position++;
                }

                putOnPostion(board, position, PLAZERTWO);
            }
            positionInput[position - 1] = 1;
            turn = PLAZERONETURN;
            moveNum++;

            dispalyBoard(board);
            printf("\t\t\t\t\033[1;31m   Player 2 Put On Position:\033[1;0m %d", position);
            Sleep(2000);
            system("cls");
        }
    }

    dispalyBoard(board);

    if (WinCheck(board))
    {

        if (turn == PLAZERTWOTURN)
        {

            printf("\t\t\t\t\t\033[1;31mPlayer 1 Win\033[1;0m\n");
            lastWin = PLAZERONETURN;
        }
        else
        {
            printf("\t\t\t\t\t \033[1;34mPlayer 2 Win\033[1;0m\n");
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
 Ahmed Faheem     17Oct2023            Solve problem on PlayerVsComputer func at line (204) when all position
                                       after predicted position is occuped,so program add on last element, update for return search from start,
                                       adding additional algorithm on ticAlgorithm from line (136) to (148)
 Ahmed Faheem     19Oct2023            enable easy and hard mode on PlayerVsComputer by adding mode parameter to it, and pass this to ticAlgorithm function from line 31

*/