#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int game_intro();
int choice();
int ready();
char userInput();
void hint(char user, char randomChar);
void windisplayScoreboard(int chances, int totalAttempts);
void losedisplayScoreBoard(int chances, int totalAttempts);
void bye();
int main()
{
    short int totalAttempts, chances, guess, i, replay;
    char user;
    srand(time(NULL));
    int randomIndex = rand() % 26;
    char randomChar = 'A' + randomIndex;
    printf(" %c",randomChar);
    if (game_intro())
    {
        totalAttempts = 0;
        chances = 10;
        for (i = 0; i <= chances; i++)
        {
            if (totalAttempts <= 9)
            {
                user = userInput();

                if (user == randomChar)
                {
                    printf("Congratulation You Guessed Right");
                    windisplayScoreboard(chances, totalAttempts);
                    break;
                }
                else
                {
                    totalAttempts++;
                    if (totalAttempts == 10)
                    {
                        
                        printf("You Guessed Wrong Character\n");
                        losedisplayScoreBoard(chances, totalAttempts);
                        break;
                    }
                    printf("You Guessed Wrong Character");
                    hint(user, randomChar);
                }
            }
        
        }
    }
    return 0;
}

int game_intro()
{
    int status;
    printf("\n\n\n\n\t\t\t\t");
    printf("=============================");
    printf(" Welcome to the Character Guessing Game ");
    printf("=============================\n\n\n\n");
    printf("\n\t\t\t\t\t\t*****************************************************************");
    printf("\n\t\t\t\t\t\t*                    GUESS THE CHARACTER                        *");
    printf("\n\t\t\t\t\t\t*                   ---------------------                       *");
    printf("\n\t\t\t\t\t\t*                                                               *");
    printf("\n\t\t\t\t\t\t*    The mystery character lies within A TO Z or a to z         *");
    printf("\n\t\t\t\t\t\t*        You have to find the character in each round           *");
    printf("\n\t\t\t\t\t\t*                                                               *");
    printf("\n\t\t\t\t\t\t*                        GAME RULES:                            *");
    printf("\n\t\t\t\t\t\t*                   ---------------------                       *");
    printf("\n\t\t\t\t\t\t*                                                               *");
    printf("\n\t\t\t\t\t\t*        You have 10 chances to guess the character             *");
    printf("\n\t\t\t\t\t\t*          Each correct guess earns you 10-Points               *");
    printf("\n\t\t\t\t\t\t*          You'll also get some hints to win the game           *");
    printf("\n\t\t\t\t\t\t*     You can type both small and big characters (A-Z or a-z)   *");
    printf("\n\t\t\t\t\t\t*                                                               *");
    printf("\n\t\t\t\t\t\t*****************************************************************");
    printf("\n\n");
    status = ready();
    return status;
}

int choice()
{
    char ch;
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        return 1;
    }
    return 0;
}

int ready()
{
    printf("\n\nAre You Ready to Play? [Y/N]: ");

    if (choice()) // Enter choice
    {
        printf("\nOK, Let's Begin!\n\n");
        return 1;
    }
    else
    {
        printf("\nGoodbye!");
        return 0;
    }
    return 0;
}

char userInput()
{
    char userInput;
    printf("Enter Your Guess : ");
    scanf(" %c", &userInput);
    if (userInput >= 'a' && userInput <= 'z')
    {
        // Convert Any User-input into Big-Character
        userInput = toupper(userInput);
    }
    return userInput;
}

void hint(char user, char randomChar)
{

    if (user < randomChar)
    {
        printf("\n\nHint :- Your Guessed Lesser Character from Mystery Character\n");
    }
    else
    {
        printf("\n\nHint :- Your Guessed Greater Character from Mystery Character\n");
    }
}

void windisplayScoreboard(int chances, int totalAttempts)
{
    printf("\n\n");
    printf("\n\t\t\t\t\t\t*****************************************************************");
    printf("\n\t\t\t\t\t\t***********************    GAME OVER     ************************");
    printf("\n\t\t\t\t\t\t***********************   SCORE-BOARD    ************************");
    printf("\n\t\t\t\t\t\t                         -------------                         \n");
    if (totalAttempts >= 1 || totalAttempts <= 9)
        printf("\n\t\t\t\t\t\t                     You Score Points : %d                       ", (chances - totalAttempts) * 10);
    printf("\n\t\t\t\t\t\t                         Chances Used : %d                            ", totalAttempts);
    printf("\n\t\t\t\t\t\t                         Chances Left : %d                          \n", (chances - totalAttempts));
    printf("\n\t\t\t\t\t\t                         -------------                         \n");
    if (totalAttempts == 0)
    printf("\n\t\t\t\t\t\t                       YOU'RE A CHAMPION  !!                   \n");
    printf("\n\t\t\t\t\t\t*****************************************************************");
}

void losedisplayScoreBoard(int chances, int totalAttempts)
{
    printf("\n\n");
    printf("\n\t\t\t\t\t\t*****************************************************************");
    printf("\n\t\t\t\t\t\t***********************    GAME OVER     ************************");
    printf("\n\t\t\t\t\t\t***********************   SCORE-BOARD    ************************");
    printf("\n\t\t\t\t\t\t                         -------------                         \n");
    printf("\n\t\t\t\t\t\t                      You Score Points : %d                      ", (chances - totalAttempts) * 10);
    printf("\n\t\t\t\t\t\t                      Chances You Used : %d                      ", totalAttempts);
    printf("\n\t\t\t\t\t\t                      Chances You Left : %d                    \n", (chances - totalAttempts));
    printf("\n\t\t\t\t\t\t                         -------------                         \n");
    printf("\n\t\t\t\t\t\t            Better luck next time! Keep Practicing             \n");
    printf("\n\t\t\t\t\t\t*****************************************************************");
}
