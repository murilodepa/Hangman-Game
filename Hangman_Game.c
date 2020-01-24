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

#define Columns 50        // Biggest word in the file, assuming it's 50
#define Wrong_Letters 10

#define Blue 9
#define Green 10
#define Red 12
#define White 15
//###############################################################################


//#################### PROTOTYPE OF FUNCTIONS USED IN MAIN ######################

/// CHANGES COLOR OF PRINTED CHARACTERS
void Choose_Color (int );

/// READ FILE WITH WORDS AND RETURN IN MATRIX FORMAT
char **Read_File_With_Words (int *);

/// CHECKING THE REPEAT WORD
int Check_Repeat_Word (int [], int );

/// PRINTING THE INITIAL HEADER
void Header (int );

/// STARTING THE VARIABLES
void Starting_Variables(int *, int *, int *, int *, int [], char **, char [], char **, int );

/// PRINTING GAME INFORMATION
void Game_Info (int, int, int, int, int );

/// PRITING BASIC STRUCTURE OF GALLOWS
void Basic_Structure_Gallows (int );

/// PRITING HEAD
void Head (int );

/// PRITING BODY
void Body (int );

/// PRITING RIGHT ARM
void Right_Arm (int );

/// PRITING LEFT ARM
void Left_Arm (int );

/// PRITING RIGHT LEG
void Right_Leg (int );

/// PRITING LEFT LEG
void Left_Leg (int );

/// CHECK POSSIBILITIES AND PRITING GALLOWS
void Check_Possibilities_Priting_Gallows (int, int*, int, int*, int );

/// EXIT OR RESTART OF GAME
int Restart_Or_Exit ();

/// THE PLAYER MISSED THE GAME
int Player_Lose (int, char [], char **, int, int *);

/// EMPTY HANGMAN AND HAPPY PERSON (WIN)
void Gallows_And_Happy_Person (int );

/// THE PLAYER WON THE GAME
int Player_Win (int *, int *, int *, int, int *);

/// PRITING THE WORD AND MISTAKES
void Word_And_Mistakes (int, char [], char []);

/// WHILE THE PLAYER HAVE POSSIBILITIES
void Player_Playing (int, char [], char [], char **, int, int *, int *);

/// NOTICE THAT THE PLAYER LOSE THE GAME
void Notice_Lose (int *);

/// THE PLAYER PLAYED WITH EVERY WORD
void Game_Finished ();

//#################################### MAIN #####################################
int main()
{
    int Cont = 0, Row_Random = 0, Hits = 0, Mistakes = 0, Word_Length = 0, Win = 0, Attempts = 0, Quantity_of_Words = 0;

    char Vector_Mistakes[Wrong_Letters], *Vector_Hits;

    char **Words = Read_File_With_Words(&Quantity_of_Words);

    int Repeated_Words[Quantity_of_Words];

    // Preventing from trash
    for(Cont = 0; Cont < Quantity_of_Words; Cont++)
        Repeated_Words[Cont] = 99;

    Header(Quantity_of_Words);

    while(1)
    {
        Starting_Variables(&Row_Random, &Word_Length, &Hits, &Mistakes, Repeated_Words, Words, Vector_Mistakes, &Vector_Hits, Quantity_of_Words);

        while(Mistakes < 8)
        {
            Check_Possibilities_Priting_Gallows(Mistakes, &Quantity_of_Words, Win, &Attempts, Word_Length);

            if(Mistakes >= 7)
            {
                Mistakes = Player_Lose(Word_Length, Vector_Hits, Words, Row_Random, &Mistakes);
                if(Mistakes != 10)
                    return 0;
            }

            if(Mistakes < 7)
                Word_And_Mistakes (Word_Length, Vector_Hits, Vector_Mistakes);

            if(Hits == Word_Length)
            {
                Mistakes = Player_Win(&Quantity_of_Words, &Win, &Attempts, Word_Length, &Mistakes);
                if(Mistakes != 10)
                    return 0;
            }

            if(Quantity_of_Words <= 0)
            {
                Game_Finished();
                return 0;
            }

            if(Mistakes == 6)
                Notice_Lose(&Mistakes);

            if(Mistakes<6)
                Player_Playing(Word_Length, Vector_Hits, Vector_Mistakes, Words, Row_Random, &Hits, &Mistakes);
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

/// READ FILE WITH WORDS AND RETURN IN MATRIX FORMAT
char **Read_File_With_Words (int *Quantity_of_Words)
{
    int Cont1=0, Cont2=0;
    char Character;
    char File_Name[100];

    char **Words;

    // Defining a file type variable
    FILE *Input_File;

    Choose_Color(Blue);
    printf("\n ENTER FILE NAME: ");

    Choose_Color(White);
    gets(File_Name);

    // Opening file to read data
    Input_File = fopen(File_Name, "r");

    if(Input_File == NULL)
    {
        system("cls");

        Choose_Color(Blue);
        printf("\n   \332");

        for(Cont1 = 0; Cont1 < 8; Cont1++)
            printf("\304\304\304\304\304\304");

        printf("\277 \n   \263");

        Choose_Color(Red);
        printf("\t\t  ERROR OPENING FILE!!!");

        Choose_Color(Blue);
        printf("\t\t    \263 \n   \300");

        for(Cont1 = 0; Cont1 < 8; Cont1++)
            printf("\304\304\304\304\304\304");

        printf("\331 \n\n\n\n");

        Choose_Color(White);

        exit(1);
    }

    // Reading of the quantity of Words
    fscanf(Input_File,"%d", Quantity_of_Words);

    // Allocates the rows of the matrix
    Words = (char **) calloc(*Quantity_of_Words, sizeof(char*));

    if(Words == NULL)
        exit(1);

    // Allocates the columns of the matrix
    for(Cont1 = 0; Cont1 < *Quantity_of_Words; Cont1++)
    {
        Words[Cont1] = (char *) calloc (Columns, sizeof(char));
        if(Words[Cont1] == NULL)
            exit(1);
    }
    Cont1=0;

    while(Cont1 < *Quantity_of_Words)
    {
        Cont2=0;

        while(isspace(Character) || Character == '\n' || (!(isalpha(Character))))
            Character = fgetc(Input_File);

        while(((isalpha(Character)) || (isspace(Character))) && ((Character != '\n')))
        {
            Character = toupper(Character);
            Words[Cont1][Cont2] = Character;
            Cont2+=1;
            Character = fgetc(Input_File);
        }

        Words[Cont1][Cont2] = '\0';

        Cont1+=1;
    }

    /* Priting quantity of Words and matrix */
    /*
    printf("\n Quantity_of_Words: %d ", *Quantity_of_Words);

    for(Cont1 = 0; Cont1 < *Quantity_of_Words; Cont1++)
        printf("\n %d: %s", Cont1, Words[Cont1]);
    Sleep(5000);
    */

    // Closing file
    fclose(Input_File);

    // Returns the pointer to the array
    return (Words);
}
//###############################################################################

/// CHECKING THE REPEAT WORD
int Check_Repeat_Word (int Repeated_Words[], int Quantity_of_Words)
{
    int Aux, Cont, Row_Random;

    do
    {
        srand( (unsigned)time(NULL) );
        Row_Random = (rand () % 50);
        Aux=0;

        for(Cont=0; Cont<Quantity_of_Words; Cont++)
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
void Starting_Variables(int *Row_Random, int *Word_Length, int *Hits, int *Mistakes, int Repeated_Words[], char **Words, char Vector_Mistakes[], char **Vector_Hits, int Quantity_of_Words)
{
    int Cont=0;

    *Row_Random=0;
    *Word_Length=0;
    *Hits=0;
    *Mistakes=0;
    *Word_Length=0;

    *Row_Random = Check_Repeat_Word(Repeated_Words, Quantity_of_Words);

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

/// PRITING RIGHT ARM
void Right_Arm(int Cont)
{
    Head(Cont);

    printf("\n    \263 \t\t\t\t   \263");
    printf("\n    \263 \t\t\t       \332\304\304\304\264");

    for(Cont = 0; Cont < 2; Cont++)
        printf("\n    \263 \t\t\t       \263   \263");

    printf("\n    \263 \t\t\t       \305   \263");

    for(Cont = 0; Cont < 4; Cont++)
        printf("\n    \263 \n    \263");

    printf("\n \304\304\304\301\304\304\304\n");
}
//###############################################################################

/// PRITING LEFT ARM
void Left_Arm(int Cont)
{
    Head(Cont);

    printf("\n    \263 \t\t\t\t   \263");
    printf("\n    \263 \t\t\t       \332\304\304\304\305\304\304\304\277");

    for(Cont = 0; Cont < 2; Cont++)
        printf("\n    \263 \t\t\t       \263   \263   \263");

    printf("\n    \263 \t\t\t       \305   \263   \305");
}
//###############################################################################

/// PRITING RIGHT LEG
void Right_Leg(int Cont)
{
    Left_Arm(Cont);

    printf("\n    \263 \t\t\t          / \n    \263 \t\t\t         /");
    printf("\n    \263 \t\t\t        / \n    \263 \t\t\t       /");
    printf("\n    \263  \t\t\t      / \n    \263 ");
    printf("\n    \263 \n    \263 \n \304\304\304\301\304\304\304\n");
}
//###############################################################################

/// PRITING LEFT LEG
void Left_Leg(int Cont)
{
    Basic_Structure_Gallows(Cont);

    printf("\n    \263 \t\t\t       \332\304\304\304\301\304\304\304\277");
    printf("\n    \263 \t\t\t       \263 x   x \263");
    printf("\n    \263 \t\t\t       \263   .   \263");
    printf("\n    \263 \t\t\t       \263   +   \263");
    printf("\n    \263 \t\t\t       \300\304\304\304\302\304\304\304\331");
    printf("\n    \263 \t\t\t\t\300\304\304\305\304\304\331");
    printf("\n    \263 \t\t\t       \332\304\304\304\305\304\304\304\277");

    for(Cont = 0; Cont < 2; Cont++)
        printf("\n    \263 \t\t\t       \263   \263   \263");

    printf("\n    \263 \t\t\t       \305   \263   \305");
    printf("\n    \263 \t\t\t          / \\ \n    \263 \t\t\t         /   \\");
    printf("\n    \263 \t\t\t        /     \\ \n    \263 \t\t\t       /       \\");
    printf("\n    \263  \t\t\t      /         \\ \n    \263 ");
    printf("\n    \263 \n    \263 \n \304\304\304\301\304\304\304\n");
}
//###############################################################################

/// CHECK POSSIBILITIES AND PRITING GALLOWS
void Check_Possibilities_Priting_Gallows(int Mistakes, int *Quantity_of_Words, int Win, int *Attempts, int Word_Length)
{
    int Cont;

    switch(Mistakes)
    {

    case 0:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);

        Basic_Structure_Gallows(Cont);

        for(Cont = 0; Cont < 9; Cont++)
            printf("\n    \263 \n    \263 ");

        printf("\n \304\304\304\301\304\304\304\n");
        break;

    case 1:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);

        Head(Cont);

        for(Cont = 0; Cont < 6; Cont++)
            printf("\n    \263 \n    \263 ");

        printf("\n    \263 \n \304\304\304\301\304\304\304\n");
        break;

    case 2:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);
        Body(Cont);
        break;

    case 3:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);
        Right_Arm(Cont);
        break;

    case 4:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);
        Left_Arm(Cont);

        for(Cont = 0; Cont < 4; Cont++)
            printf("\n    \263 \n    \263");

        printf("\n \304\304\304\301\304\304\304\n");
        break;

    case 5:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);
        Right_Leg(Cont);
        break;

    case 6:
        Game_Info(*Quantity_of_Words, Win, *Attempts, Word_Length, Mistakes);
        Left_Leg(Cont);
        break;

    default :
        Game_Info((*Quantity_of_Words-=1), Win, (*Attempts+=1), Word_Length, (Mistakes-1));
        Left_Leg(Cont);
    }
}
//###############################################################################

/// EXIT OR RESTART OF GAME
int Restart_Or_Exit()
{
    int Cont;
    char Output;

    do
    {
        Choose_Color(White);
        Output = getche();

        if(Output == 'n' || Output == 'N')
        {
            system("cls");

            Choose_Color(Blue);
            printf("\n\n   \332");

            for(Cont = 0; Cont < 8; Cont++)
                printf("\304\304\304\304\304\304");

            printf("\277 \n   \263");

            Choose_Color(Red);
            printf("\t\t GOOD GAME!!! SEE YOU!!!");

            Choose_Color(Blue);
            printf("\t    \263 \n   \300");

            for(Cont = 0; Cont < 8; Cont++)
                printf("\304\304\304\304\304\304");

            printf("\331 \n\n\n\n");

            Choose_Color(White);
            return 0;
        }

        if(Output == 'y' || Output == 'Y')
        {
            system("cls");
            return 10;
        }
    }
    while(Output != 'Y' && Output != 'y' && Output != 'N' && Output != 'n');
}
//###############################################################################

/// THE PLAYER MISSED THE GAME
int Player_Lose(int Word_Length, char Vector_Hits[], char **Words, int Row_Random, int *Mistakes)
{
    int Cont;
    char Output;

    Choose_Color(Blue);
    printf("\n WORD: ");

    for(Cont = 0; Cont < Word_Length; Cont++)
    {
        Choose_Color(White);
        Vector_Hits[Cont] = Words[Row_Random][Cont];
        printf(" %c", Vector_Hits[Cont]);
    }

    Choose_Color(Blue);
    printf("\n\n   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("\t  WHAT A PITY!!! TRY AGAIN, YOU CAN!!!");

    Choose_Color(Blue);
    printf("\t    \263 \n   \263");

    Choose_Color(Red);
    printf("\t      DO WANT TO PLAY AGAIN <Y/N>?");

    Choose_Color(Blue);
    printf("\t    \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n");

    return Restart_Or_Exit();
}
//###############################################################################

/// EMPTY HANGMAN AND HAPPY PERSON (WIN)
void Gallows_And_Happy_Person(int Cont)
{

    Basic_Structure_Gallows(Cont);

    printf("\n    \263 \t\t\t\t  /\301\\ \n    \263 \t\t\t\t /   \\ \n    \263 \t\t\t\t/     \\");
    printf("\n    \263 \t\t\t       \300\304\304\304\304\304\304\304\331");
    printf("\n    \263 \t\t\332\304\304\304\304\304\304\304\277");
    printf("\n    \263      \302    \263 ^   ^ \263    \302    ");
    printf("\n    \263      \263    \263   .   \263    \263    ");
    printf("\n    \263      \\    \263 [___] \263    /   ");
    printf("\n    \263       \\   \300\304\304\304\304\304\304\304\331   / ");
    printf("\n    \263 \t     \\      \263      / ");
    printf("\n    \263 \t      \\\304\304\304\304\304\263\304\304\304\304\304/ ");
    printf("\n    \263 \t\t    \263 \n    \263 \t\t    \263 \n    \263 \t\t    \263");
    printf("\n    \263 \t\t   / \\ \n    \263 \t\t  /   \\       ");
    printf("\n    \263 \t\t /     \\ \n    \263 \t\t/       \\     ");
    printf("\n \304\304\304\301\304\304\304      \304\304\331       \300\304\304\n");
}
//###############################################################################

/// THE PLAYER WON THE GAME
int Player_Win(int *Quantity_of_Words, int *Win, int *Attempts, int Word_Length, int *Mistakes)
{
    int Cont;

    Sleep(1000);
    Game_Info((*Quantity_of_Words-=1), (*Win+=1), (*Attempts+=1), Word_Length, *Mistakes);

    Choose_Color(Blue);
    printf("   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("   CONGRATULATIONS YOU HIT THE COMPLETE WORD!");

    Choose_Color(Blue);
    printf("   \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n");

    Gallows_And_Happy_Person(Cont);

    Choose_Color(Blue);
    printf("\n   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("   CONGRATULATIONS!!! YOU ADVINED THE WORD!");

    Choose_Color(Blue);
    printf("\t    \263 \n   \263");

    Choose_Color(Red);
    printf("\t      DO WANT TO PLAY AGAIN <Y/N>?");

    Choose_Color(Blue);
    printf("\t    \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n");

    return Restart_Or_Exit();
}
//###############################################################################

/// PRITING THE WORD AND MISTAKES
void Word_And_Mistakes(int Word_Length, char Vector_Hits[], char Vector_Mistakes[])
{
    int Cont;

    Choose_Color(Blue);
    printf("\n WORD: ");

    Choose_Color(White);
    for(Cont = 0; Cont < Word_Length; Cont++)
        printf("%c ", Vector_Hits[Cont]);

    printf("\n\n");

    Choose_Color(Blue);
    printf(" MISTAKES: ");

    Choose_Color(White);

    for(Cont = 0; Cont < Wrong_Letters; Cont++)
        printf("%c ", Vector_Mistakes[Cont]);

    printf("\n\n");
}
//###############################################################################

/// WHILE THE PLAYER HAVE POSSIBILITIES
void Player_Playing(int Word_Length, char Vector_Hits[], char Vector_Mistakes[], char **Words, int Row_Random, int *Hits, int *Mistakes)
{
    int Equal_Letter=0, Cont=0, Flag_Mistakes=1;
    char Letter;

    do
    {
        Equal_Letter = 0;
        do
        {
            Choose_Color(Green);
            printf(" LETTER: ");

            Choose_Color(White);
            Letter = getche();
            Letter = toupper(Letter);
            printf("\n");
        }
        while(isalpha(Letter) != 1);

        for(Cont = 0; Cont < Word_Length; Cont++)
        {
            if(Letter == Vector_Hits[Cont] || Letter == Vector_Mistakes[Cont])
                Equal_Letter = 1;
        }
    }
    while(Equal_Letter == 1);

    for(Cont = 0; Cont < Word_Length; Cont++)
    {
        if(Words[Row_Random][Cont] == Letter)
        {
            Vector_Hits[Cont] = Letter;
            *Hits+=1;
            Flag_Mistakes=0;
        }
    }

    if(Flag_Mistakes != 0)
    {
        Cont=0;
        while(Vector_Mistakes[Cont] != '\0')
            Cont++;

        Vector_Mistakes[Cont] = Letter;
        *Mistakes+=1;
    }
}
//###############################################################################

/// NOTICE THAT THE PLAYER LOSE THE GAME
void Notice_Lose(int *Mistakes)
{
    int Cont;

    Choose_Color(Blue);
    printf("   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("\t       WHAT A PITY!!! YOU LOSE!!!");

    Choose_Color(Blue);
    printf("\t    \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n\n\n\n");

    Choose_Color(White);

    *Mistakes+=1;
    Sleep(1800);
}
//###############################################################################

/// THE PLAYER PLAYED WITH EVERY WORD
void Game_Finished()
{
    int Cont;

    system("cls");

    Choose_Color(Blue);
    printf("\n\n   \332");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\277 \n   \263");

    Choose_Color(Red);
    printf("       GOOD GAME, NO MORE DISTINCT WORD!!");

    Choose_Color(Blue);
    printf("\t    \263 \n   \263");

    Choose_Color(Red);
    printf(" STARTS THE GAME AGAIN TO GET A BETTER SCORE!!!");

    Choose_Color(Blue);
    printf(" \263 \n   \300");

    for(Cont = 0; Cont < 8; Cont++)
        printf("\304\304\304\304\304\304");

    printf("\331 \n\n\n\n\n ");

    Choose_Color(White);

}
//###############################################################################
