/* DESCRIPTION: HANGMAN GAME WITH 50 ANIMALS SELECTED.

            PONTIFICAL CATHOLIC UNIVERSITY OF CAMPINAS - PUCC
            STUDENT NAME: MURILO DE PAULA ARAUJO
            RA: 17747775                       DELIVERY DATE: 20/06/2018
            TEACHER: ÂNGELA DE MENDONÇA ENGELBRECHT
            COURSE: COMPUTER ENGINEERING     PERIOD: 1º SEMESTER
            SUBJECT: COMPUTER ALGORITHM AND PROGRAMMING

                    FINAL WORK - "HANGMAN GAME"
*/

//################################# LIBRARY #################################
#include <conio.h>       //"Used the function "Getche()"
#include <ctype.h>       //"ctions added to work with characters"
#include <stdio.h>       //"Standard Header (In/Out)"
#include <stdlib.h>      //"Standard Header"
#include <string.h>      //"Manipulate Strings"
#include <time.h>        //"Used the chronological time"
#include <windows.h>     //"Used to the function "Sleep"

#define Columns 50
#define Rows  50
#define Wrong_Letters 30




int main()
{
    int Cont1, Cont2, Row_Random, Flag_Mistakes, Word_Length, Hits, Mistakes, Equal_Letter;
    int Aux1=0, Aux2=0, Win=0, Attempts=0, Quantity_of_Animals = 50;

    int Repeated_Words[Rows];

    for(Cont1=0; Cont1<Rows; Cont1++)
    {
        Repeated_Words[Cont1] = 99;
    }

    char Letter;
    char Output;

    char Animals[Rows][Columns] = {"MACACO",
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

    do
    {
        system("cls");

        printf("               ________________________________________              \n");
        printf("   ____________|WELCOME TO THE TRADITIONAL HANGMAN GAME|_____________ \n");
        printf("   |              THIS GAME CONTAINS SEVERAL ANIMALS| \n");
        printf("   _________________________________________________________________ \n");
        printf("\n\n");
        printf("\t       ________________________________________                    \n");
        printf("\t       |HIT ENTER ON YOUR KEYBOARD TO START THE GAME!|                    \n");
        printf("\t       ________________________________________                    \n");


        Letter = getche();
    }
    while(Letter != 13);

    do
    {
        Cont1=0;
        Cont2=0;
        Row_Random=0;
        Flag_Mistakes=1;
        Word_Length=0;
        Hits=0;
        Mistakes=0;
        Equal_Letter=0;
        Word_Length=0;

        do
        {
            srand( (unsigned)time(NULL) );
            Row_Random = (rand () % 50);
            Aux1=0;

            for(Cont1=0; Cont1<Rows; Cont1++)
            {
                if(Repeated_Words[Cont1] == Row_Random)
                {

                    Aux1=1;
                }
            }
        }
        while(Aux1 == 1);

        Repeated_Words[Aux2] = Row_Random;
        Aux2++;

        Word_Length = strlen(Animals[Row_Random]);
        Word_Length = Word_Length;

        char Vector_Mistakes[Wrong_Letters];
        for(Cont1=0; Cont1<Wrong_Letters; Cont1++)
        {
            Vector_Mistakes[Cont1] = '\0';
        }

        char Vector_Hits[Word_Length];

        for(Cont1=0; Cont1<Word_Length; Cont1++)
        {
            Vector_Hits[Cont1] = '_';
            if(Animals[Row_Random][Cont1] == 32)
            {
                Vector_Hits[Cont1] = 32;
                Word_Length--;
                Hits+=1;
            }
        }

        while(Mistakes < 8)
        {
            switch(Mistakes)
            {

            case 0:
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ____________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
                break;

            case 1:
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | ^   ^ |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |  ---  |      \n");
                printf("    |                          ---------      \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf("    |                                         \n");
                printf(" ___|___                                      \n");
                break;

            case 2:
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
                printf("    +------------------------------+          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                          ---------      \n");
                printf("    |                          | ^   ^ |      \n");
                printf("    |                          |   .   |      \n");
                printf("    |                          |  ---  |      \n");
                printf("    |                          ---------      \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
                printf("    |                              |          \n");
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

            case 3:
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
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
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
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
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
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
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
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
                system("cls");
                Attempts++;
                Quantity_of_Animals--;
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________   ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 7-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n");
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
                    Vector_Hits[Cont1] = Animals[Row_Random][Cont1];
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
                Win++;
                Attempts++;
                Quantity_of_Animals--;

                Sleep(1000);
                system("cls");
                printf("\n     _______________________________________________ ");
                printf("\n     | HAVE %d DISTINCT ANIMALS STILL IN THE GAME!!! |     ", Quantity_of_Animals);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | YOU GOT %d OF %d WORDS TRIED  |", Win, Attempts);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            WORD LENGTH: %d               |", Word_Length);
                printf("\n  |_______________  POSSIBILITIES: %d  _________________|", 6-Mistakes);
                printf("\n                 |___________________|");
                printf("\n\n       CONGRATULATIONS YOU HIT THE COMPLETE WORD!");
                printf("\n\n");
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

            if(Quantity_of_Animals <= 0)
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
                    if(Animals[Row_Random][Cont1] == Letter)
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
    while (Output != 'N' || Output != 'n');

    return 0;
}
