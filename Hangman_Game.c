/* DESCRIPTION: HANGMAN GAME.

            PONTIFICAL CATHOLIC UNIVERSITY OF CAMPINAS - PUCC
            STUDENT NAME: MURILO DE PAULA ARAUJO
            RA: 17747775                       DELIVERY DATE: 20/06/2018
            TEACHER: ÂNGELA DE MENDONÇA ENGELBRECHT
            COURSE: COMPUTER ENGINEERING     PERIOD: 1º SEMESTER
            SUBJECT: COMPUTER ALGORITHM AND PROGRAMMING

                    FINAL WORK - "HANGMAN GAME"
*/

//################################# LIBRARY #################################
#include <conio.h>       // "Used the function "Getche()"
#include <ctype.h>       // "Fuctions added to work with characters"
#include <stdio.h>       // "Standard Header (In/Out)"
#include <stdlib.h>      // "Standard Header"
#include <string.h>      // "Manipulate Strings"
#include <time.h>        // "Used the chronological time"
#include <windows.h>     // "Used to the function "Sleep"

#define Columns 50
#define Rows  50
#define Wrong_Letters 10

#define Blue 9
#define Green 10
#define Red 12
#define White 15
//###############################################################################


//#################### PROTOTYPE OF FUNCTIONS USED IN MAIN ######################

/// CHANGES COLOR OF PRINTED CHARACTERS
void Choose_Color (int );

/// CHECKING THE REPEAT WORD
int Check_Repeat_Word (int []);

/// PRINTING THE INITIAL HEADER
void Header (int );

/// STARTING THE VARIABLES
void Starting_Variables(int *, int *, int *, int *, int [], char [][Columns], char [], char **);

/// PRINTING GAME INFORMATION
void Game_Info (int, int, int, int, int );

/// PRITING BASIC STRUCTURE OF GALLOWS
void Basic_Structure_Gallows (int );

/// PRITING HEAD
void Head (int );

/// PRITING BODY
void Body (int );

//#################################### MAIN #####################################
int main()
{
    int Cont1, Cont2, Row_Random, Flag_Mistakes, Word_Length, Hits, Mistakes, Equal_Letter;
    int Aux1=0, Aux2=0, Win=0, Attempts=0, Quantity_of_Words = 50;

    char Vector_Mistakes[Wrong_Letters], *Vector_Hits;

    int Repeated_Words[Rows];

    // Preventing from trash
    for(Cont1 = 0; Cont1 < Rows; Cont1++)
        Repeated_Words[Cont1] = 99;

    char Letter;
    char Output;

    char Words[Rows][Columns] = {"MACACO",
                                 "LEAO",
                                 "TIGRE DE BENGALA",
                                 "PEIXE ESPADA",
                                 "JACARE",
                                 "COELHO",
                                 "CACHORRO",
                                 "CAPIVARA",
                                 "LOBO GUARA",
                                 "SURICATA",
                                 "COBRA",
                                 "TAMANDUA BANDEIRA",
                                 "TARTARUGA",
                                 "GIRAFA",
                                 "ZEBRA",
                                 "ELEFANTE",
                                 "ESTRELA DO MAR",
                                 "RINOCERONTE",
                                 "CAMELO",
                                 "LEOPARDO",
                                 "URSO PANDA",
                                 "CANGURU",
                                 "JAVALI",
                                 "BUFALO",
                                 "PANTERA",
                                 "PINGUIM",
                                 "TUCANO",
                                 "BICHO PREGUICA",
                                 "HIPOPOTAMO",
                                 "PORCO ESPINHO",
                                 "CAVALO MARINHO",
                                 "LAGARTO",
                                 "LONTRA",
                                 "ARARA AZUL",
                                 "TUBARAO MARTELO",
                                 "CAMALEAO",
                                 "GUAXINIM",
                                 "MAMUTE",
                                 "DINOSSAURO",
                                 "CORUJA",
                                 "DRAGAO DE KOMODO",
                                 "FLAMINGO",
                                 "GOLFINHO",
                                 "BALEIA JUBARTE",
                                 "OVELHA",
                                 "BEIJA FLOR",
                                 "MORCEGO",
                                 "FORMIGA",
                                 "ONCA PINTADA",
                                 "PAPAGAIO"
                                };


    Header(Quantity_of_Words);

    while(1)
    {
        Starting_Variables(&Row_Random, &Word_Length, &Hits, &Mistakes, Repeated_Words, Words, Vector_Mistakes, &Vector_Hits);

        while(Mistakes < 8)
        {
            switch(Mistakes)
            {

            case 0:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);
                Basic_Structure_Gallows(Cont1);

                for(Cont1 = 0; Cont1 < 9; Cont1++)
                    printf("\n    \263 \n    \263 ");

                printf("\n \304\304\304\301\304\304\304\n");
                break;

            case 1:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);

                Head(Cont1);

                for(Cont1 = 0; Cont1 < 6; Cont1++)
                    printf("\n    \263 \n    \263 ");

                printf("\n    \263 \n \304\304\304\301\304\304\304\n");
                break;

            case 2:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);

                Body(Cont1);
                break;

            case 3:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | ^   ^ |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |  ---  |      \n");
                printf("    |                          ---------      \n");
                printf("    |                              |          \n");
                printf("    |                             /|          \n");
                printf("    |                            / |          \n");
                printf("    |                           /  |          \n");
                printf("    |                          /   |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
                break;

            case 4:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | ^   ^ |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |  ---  |      \n");
                printf("    |                          ---------      \n");
                printf("    |                              |          \n");
                printf("    |                             /|\\        \n");
                printf("    |                            / | \\       \n");
                printf("    |                           /  |  \\      \n");
                printf("    |                          /   |   \\     \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
                break;

            case 5:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | -   - |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |  (~)  |      \n");
                printf("    |                          ---------      \n");
                printf("    |                              |          \n");
                printf("    |                             /|\\        \n");
                printf("    |                            / | \\       \n");
                printf("    |                           /  |  \\      \n");
                printf("    |                          /   |   \\     \n");
                printf("    |                             /           \n");
                printf("    |                            /            \n");
                printf("    |                           /             \n");
                printf("    |                          /              \n");
                printf("    |                         /               \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
                break;

            case 6:
                Game_Info(Quantity_of_Words, Win, Attempts, Word_Length, Mistakes);
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | x   x |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |   O   |      \n");
                printf("    |                          ---------      \n");
                printf("    |                       -------|-------   \n");
                printf("    |                             /|\\        \n");
                printf("    |                            / | \\       \n");
                printf("    |                           /  |  \\      \n");
                printf("    |                          /   |   \\     \n");
                printf("    |                             / \\        \n");
                printf("    |                            /   \\       \n");
                printf("    |                           /     \\      \n");
                printf("    |                          /       \\     \n");
                printf("    |                         /         \\    \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
                break;

            default :
                Game_Info((Quantity_of_Words-=1), Win, (Attempts+=1), Word_Length, Mistakes--);
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | x   x |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |   +   |      \n");
                printf("    |                          ---------      \n");
                printf("    |                       -------|-------   \n");
                printf("    |                             /|\\        \n");
                printf("    |                            / | \\       \n");
                printf("    |                           /  |  \\      \n");
                printf("    |                          /   |   \\     \n");
                printf("    |                             / \\        \n");
                printf("    |                            /   \\       \n");
                printf("    |                           /     \\      \n");
                printf("    |                          /       \\     \n");
                printf("    |                         /         \\    \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
            }

            printf("\n\n");

            if(Mistakes >= 7)
            {
                for(Cont1=0; Cont1<Word_Length; Cont1++)
                {
                    Vector_Hits[Cont1] = Words[Row_Random][Cont1];
                    printf(" %c", Vector_Hits[Cont1]);
                }

                printf("\n\n");
                printf("\t      WHAT A PITY!\n");
                printf("     TRY AGAIN, YOU CAN!\n\n");
                printf("   DO WANT TO PLAY AGAIN <Y / N> !?\n");

                do
                {
                    Output = getche();

                    if(Output == 'n' || Output == 'N')
                    {
                        system("cls");
                        printf("\n\t\tGOOD GAME! SEE YOU!\n");
                        return 0;
                    }
                    if(Output == 'y' || Output == 'Y')
                    {
                        system("cls");
                        Mistakes = 10;
                    }
                }
                while(Output != 'Y' && Output != 'y' && Output != 'N' && Output != 'n');
            }

            if(Mistakes < 7)
            {
                for(Cont1=0; Cont1<Word_Length; Cont1++)
                {
                    printf(" %c", Vector_Hits[Cont1]);
                }

                printf("\n\n");

                printf("Mistakes: ");

                for(Cont1=0; Cont1<Wrong_Letters; Cont1++)
                {
                    printf("%c ", Vector_Mistakes[Cont1]);
                }

                printf("\n\n");
            }
            if(Hits == Word_Length)
            {
                Sleep(1000);
                Game_Info((Quantity_of_Words-=1), (Win+=1), (Attempts+=1), Word_Length, Mistakes);
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                             /-\\        \n");
                printf("    |                            /   \\       \n");
                printf("    |                           /     \\      \n");
                printf("    |                          ---------      \n");
                printf("    |           ---------                     \n");
                printf("    |      _    | ^   ^ |    _                \n");
                printf("    |      |    |   .   |    |                \n");
                printf("    |      \\    | [___] |    /               \n");
                printf("    |       \\   ---------   /                \n");
                printf("    |        \\      |      /                 \n");
                printf("    |         \\-----|-----/                  \n");
                printf("    |               |                         \n");
                printf("    |               |                         \n");
                printf("    |               |                         \n");
                printf("    |              / \\                       \n");
                printf("    |             /   \\                      \n");
                printf("    |            /     \\                     \n");
                printf("    |           /       \\                    \n");
                printf(" ___|___     __/         \\__                 \n");

                printf("\n\n");
                printf("\t     CONGRATULATIONS!!!\n");
                printf("      YOU ADVINED THE WORD!\n\n");
                printf("    DO WANT TO PLAY AGAIN <Y / N> !?\n");

                do
                {
                    Output = getche();

                    if(Output == 'n' || Output == 'N')
                    {
                        system("cls");
                        printf("\n\t GOOD GAME! SEE YOU!\n");
                        return 0;
                    }
                    if(Output == 'y' || Output == 'Y')
                    {
                        Mistakes = 10;
                        system("cls");
                    }
                }

                while(Output != 'Y' && Output != 'y' && Output != 'N' && Output != 'n');
            }

            if(Quantity_of_Words <= 0)
            {
                printf("\n GOOD GAME, NO MORE DISTINCT WORD!!!");
                printf("\n STARTS THE GAME AGAIN TO GET A BETTER SCORE!!!\n\n");
                return 0;
            }

            if(Mistakes == 6)
            {
                printf("YOU LOSE!!!\n");
                Mistakes++;
                Sleep(1800);
            }

            if(Mistakes<6)
            {
                do
                {
                    Equal_Letter = 0;
                    do
                    {
                        printf(" LETTER: ");
                        Letter = getche();
                        Letter = toupper(Letter);
                        printf("\n");

                    }
                    while(isalpha(Letter) != 1);

                    for(Cont1=0; Cont1<Word_Length; Cont1++)
                    {
                        if(Letter == Vector_Hits[Cont1] || Letter == Vector_Mistakes[Cont1])
                        {
                            Equal_Letter = 1;
                        }
                    }
                }
                while(Equal_Letter == 1);

                for(Cont1=0; Cont1<Word_Length; Cont1++)
                {
                    if(Words[Row_Random][Cont1] == Letter)
                    {
                        Vector_Hits[Cont1] = Letter;
                        Hits++;
                        Flag_Mistakes=0;
                    }
                }

                if(Flag_Mistakes != 0)
                {
                    Vector_Mistakes[Cont2] = Letter;
                    Cont2++;
                    Mistakes++;
                }
                Flag_Mistakes=1;
            }
        }
    }

    return 0;
}
//###############################################################################

/// CHANGES COLOR OF PRINTED CHARACTERS
void Choose_Color (int Color)
{
    /*
    0 = Black		 8  = Grey
    1 = Blue		 9  = Light Blue
    2 = Green		 10 = Light Green
    3 = Green-Water	 11 = Light Green-Water
    4 = Red      	 12 = Light Red
    5 = Purple		 13 = Lilac
    6 = Yellow		 14 = Light Yellow
    7 = White		 15 = Bright White
    */
    HANDLE Output;
    Output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Output,Color);
}
//###############################################################################

/// CHECKING THE REPEAT WORD
int Check_Repeat_Word (int Repeated_Words[])
{
    int Aux, Cont, Row_Random;

    do
    {
        srand( (unsigned)time(NULL) );
        Row_Random = (rand () % 50);
        Aux=0;

        for(Cont=0; Cont<Rows; Cont++)
        {
            if(Repeated_Words[Cont] == Row_Random)
                Aux=1;
        }
    }
    while(Aux == 1);

    return Row_Random;
}
//###############################################################################

/// PRINTING THE INITIAL HEADER
void Header (int Quantity_of_Words)
{
    char Letter;
    int Cont;

    do
    {
        system("cls");

        Choose_Color(Blue);

        printf("\n   \332\304\304");

        for(Cont = 0; Cont < 6; Cont++)
            printf("\304\304\304\304\304\304\304\304\304");

        printf("\277 \n   \263\t  ");

        /// HANGMAN
        Choose_Color(Green);
        printf("*   * ***** *   * *****  **   ** ***** *   *");

        Choose_Color(Blue);
        printf("\t    \263 \n   \263\t  ");

        Choose_Color(Green);
        printf("*   * *   * **  * *      * * * * *   * **  *");

        Choose_Color(Blue);
        printf("\t    \263 \n   \263\t  ");

        Choose_Color(Green);
        printf("***** ***** * * * *  *** *  *  * ***** * * *");

        Choose_Color(Blue);
        printf("\t    \263 \n   \263\t  ");

        Choose_Color(Green);
        printf("*   * *   * *  ** *   *  *     * *   * *  **");

        Choose_Color(Blue);
        printf("\t    \263 \n   \263\t  ");

        Choose_Color(Green);
        printf("*   * *   * *   * *****  *     * *   * *   *");

        Choose_Color(Blue);
        printf("\t    \263 \n   \263\t\t\t\t\t\t\t    \263 \n   \263\t\t   ");

        /// GAME
        Choose_Color(Green);
        printf("*****  ***** **   ** *****");

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \263\t\t   ");

        Choose_Color(Green);
        printf("*      *   * * * * * *");

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \263\t\t   ");

        Choose_Color(Green);
        printf("*  *** ***** *  *  * *****");

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \263\t\t   ");

        Choose_Color(Green);
        printf("*   *  *   * *     * *");

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \263\t\t   ");

        Choose_Color(Green);
        printf("*****  *   * *     * *****");

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \300\304\304");

        for(Cont = 0; Cont<6; Cont++)
            printf("\304\304\304\304\304\304\304\304\304");

        printf("\331 \n\n\n   \332");

        for(Cont = 0; Cont < 9; Cont++)
            printf("\304\304\304\304\304\304");

        printf("\304\304\277 \n   \263");

        Choose_Color(Red);
        printf("       WELCOME TO THE TRADITIONAL HANGMAN GAME!!!");

        Choose_Color(Blue);
        printf("\t    \263 \n   \300");

        for(Cont = 0; Cont < 9; Cont++)
            printf("\304\304\304\304\304\304");

        printf("\304\304\331 \n\n\n   \332");

        for(Cont = 0; Cont < 9; Cont++)
            printf("\304\304\304\304\304\304");

        printf("\304\304\277 \n   \263");

        Choose_Color(Red);
        printf("\t\t THIS GAME CONTAINS %d WORDS!!!", Quantity_of_Words);

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \300");

        for(Cont = 0; Cont < 9; Cont++)
            printf("\304\304\304\304\304\304");

        printf("\304\304\331 \n\n\n   \332");

        for(Cont = 0; Cont < 9; Cont++)
            printf("\304\304\304\304\304\304");

        printf("\304\304\277 \n   \263");

        Choose_Color(Green);
        printf("    HIT ENTER ON YOUR KEYBOARD TO START THE GAME!!!");

        Choose_Color(Blue);
        printf("\t    \263 \n   \300");

        for(Cont = 0; Cont < 9; Cont++)
            printf("\304\304\304\304\304\304");

        printf("\304\304\331 \n\n\n");

        Choose_Color(White);

        Letter = getche();
    }
    while(Letter != 13);
}
//###############################################################################

/// STARTING THE VARIABLES
void Starting_Variables(int *Row_Random, int *Word_Length, int *Hits, int *Mistakes, int Repeated_Words[], char Words[][Columns], char Vector_Mistakes[], char **Vector_Hits)
{
    int Cont=0;

    *Row_Random=0;
    *Word_Length=0;
    *Hits=0;
    *Mistakes=0;
    *Word_Length=0;

    *Row_Random = Check_Repeat_Word(Repeated_Words);

    while(Repeated_Words[Cont] != 99)
        Cont+=1;

    Repeated_Words[Cont] = *Row_Random;

    *Word_Length = strlen(Words[*Row_Random]);

    *Vector_Hits = (char*) calloc(*Word_Length, sizeof(char));

    for(Cont = 0; Cont < Wrong_Letters; Cont++)
        Vector_Mistakes[Cont] = '\0';

    for(Cont = 0; Cont < *Word_Length; Cont++)
    {
        (*Vector_Hits)[Cont] = '_';

        if(Words[*Row_Random][Cont] == 32)
        {
            (*Vector_Hits)[Cont] = 32;
            *Hits += 1;
        }
    }
}
//###############################################################################

/// PRINTING GAME INFORMATION
void Game_Info(int Quantity_of_Words, int Win, int Attempts, int Word_Length, int Mistakes)
{
    system("cls");

    Choose_Color(Blue);
    printf("\n   \332");

    int Cont;

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("   HAVE %d DISTINCT WORDS STILL IN THE GAME!!", Quantity_of_Words);

    Choose_Color(Blue);
    printf("   \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("           YOU GOT %d OF %d WORDS TRIED", Win, Attempts);

    Choose_Color(Blue);
    printf("\t    \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("                 WORD LENGTH: %d", Word_Length);

    Choose_Color(Blue);
    printf("\t\t    \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("                POSSIBILITIES: %d", 6-Mistakes);

    Choose_Color(Blue);
    printf("\t\t    \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n\n");
}
//###############################################################################

/// PRITING BASIC STRUCTURE OF GALLOWS
void Basic_Structure_Gallows(int Cont)
{
    Choose_Color(White);
    printf("    \332");

    for(Cont = 0; Cont < 5; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n    \263 \t\t\t\t   \263 \n    \263 \t\t\t\t   \263");
}
//###############################################################################

/// PRITING HEAD
void Head(int Cont)
{
    Basic_Structure_Gallows(Cont);

    printf("\n    \263 \t\t\t       \332\304\304\304\301\304\304\304\277");
    printf("\n    \263 \t\t\t       \263 ^   ^ \263");
    printf("\n    \263 \t\t\t       \263   .   \263");
    printf("\n    \263 \t\t\t       \263  ---  \263");
    printf("\n    \263 \t\t\t       \300\304\304\304\302\304\304\304\331");
}
//###############################################################################

/// PRITING BODY
void Body(int Cont)
{
    Head(Cont);

    for(Cont = 0; Cont < 2; Cont++)
        printf("\n    \263 \t\t\t\t   \263 \n    \263 \t\t\t\t   \263");

    printf("\n    \263 \t\t\t\t   \263");

    for(Cont = 0; Cont < 4; Cont++)
        printf("\n    \263 \n    \263");

    printf("\n \304\304\304\301\304\304\304\n");
}
//###############################################################################
