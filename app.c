/**
 ******************************************************************************
 * @file           : app.c
 * @author         : Ahmed Faheem
 * @brief          : Tic-Tac-Toe Game
 ******************************************************************************
 */

/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "functions.h"

/* ********************** Includes Section End   ********************** */

/* ********************** Global Variables Section Start ************** */
int lastWin = PLAZERONETURN;
/* ********************** Global Variables  Section End   ************* */

int main()
{
    printf("sds");
    uint32 option, playAgain, programState = 1, mode = 0;
    while (programState)
    {
        system("cls");
        printf(" \033[1;32m  \n");
        printf("\t\t\t\t\tTic-Tac-Toe\n\n");
        printf("\t\t\t\t       Select Option\n\n");
        printf("\t\t\t\t    1- Multiplayer Mode \n");
        printf("\t\t\t\t    2- Single Player Mode \n");
        printf("\t\t\t\t    3- Quit the game \n");
        printf("\n\n\t\t\t\t       Enter Option: ");
        inputCorrect(&option);

        playAgain = 1;

        switch (option)
        {
        case 1:

            while (playAgain == 1)
            {
                system("cls");

                if (lastWin == PLAZERONETURN)
                {
                    PlayerVsPlayer(PLAZERONETURN);
                }
                else
                {
                    PlayerVsPlayer(PLAZERTWOTURN);
                }

                printf("\n\t\t\tPlay Again? (Enter 1 To Play Again, 0 To No): ");
                inputCorrect(&playAgain);

                if (playAgain != 1)
                {
                    system("cls");
                    lastWin = PLAZERONETURN;
                }
            }

            break;

        case 2:

            system("cls");
            printf("\t\t\t\t\t Tic-Tac-Toe\n\n");
            printf("\t\t\t\t       Select Mode:-\n");
            printf("\t\t\t\t       1- Easy Mode \n");
            printf("\t\t\t\t       2- Hard Mode \n");
            printf("\n\n\t\t\t\t       Enter Option: ");
            inputCorrect(&option);

            /* check if valid option */
            while (option != 1 && option != 2)
            {
                printf("\n\n\t\t\t\t       Invalid Option -- Enter Again: ");
                inputCorrect(&option);
            }

            /* if option equal 1 enter easy mode m = 0 else m = 1 --> hard mode  */
            if (option == 1)
            {
                mode = 0;
            }
            else
            {
                mode = 1;
            }

            while (playAgain == 1)
            {
                system("cls");

                if (lastWin == PLAZERONETURN)
                {
                    PlayerVsComputer(PLAZERONETURN, mode);
                }
                else
                {
                    PlayerVsComputer(PLAZERTWOTURN, mode);
                }

                printf("\n\t\t\tPlay Again? (Enter 1 To Play Again, 0 To No): ");
                inputCorrect(&playAgain);
                if (playAgain != 1)
                {
                    lastWin = PLAZERONETURN;
                }
            }

            break;

        case 3:
            programState = 0;
            break;
        default:
            printf("\n\t\t\t  Not Valid Option( Selcet 1 or 2 or 3) Only\n");
            printf("\n\t\t\t\t   \033[1;31mEnter Again After 5 Second\033[0m\n");
            Sleep(5000);
            system("cls");

            break;
        }

        printf(" \033[1;32m  \033[1;0m \n");
    }

    return 0;
}

/**
 *************************************************************************************************************************
 User               Date                 Brief
 *************************************************************************************************************************
 Ahmed Faheem     15Oct2023            First Create
 Ahmed Faheem     19OCT2023            enable 2 mode (easy and hard) on PlayerVsComputer from line 71
*/