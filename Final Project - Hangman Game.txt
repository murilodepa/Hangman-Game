/*               PONTIFÍCIA UNIVERSIDADE CATÓLICA DE CAMPINAS
                 NOME DO ALUNO: MURILO DE PAULA ARAUJO
                 RA: 17747775                       DATA DE ENTREGA: 20/06/2018
                 PROFESSORA: ÂNGELA DE MENDONÇA ENGELBRECHT
                 CURSO: ENGENHARIA DE COMPUTAÇÃO
                 DISCIPLINA CURRICULAR: ALGORÍTMOS E PRGRAMAÇÃO DE COMPUTADORES A

                         TRABALHO FINAL - "JOGO DA FORCA"
*/

#include <conio.h>       //"Utilizada a Função "Getche()" da Biblioteca
#include <ctype.h>       //"Funções Adicionais Para Usar com Caracteres"
#include <stdio.h>       //"Cabeçalho Padrão de (Entrada/Saída)"
#include <stdlib.h>      //"Cabeçalho da Biblioteca de Propósito Geral Padrão"
#include <string.h>      //"Biblioteca com várias funções Para Manipular Strings"
#include <time.h>        //"Utilizada Para Usar o Tempo Cronológico Como Semente (SEED)"
#include <windows.h>     //"Utilizada Para Usar a Função "Sleep","Dormir" por Alguns Milissegundos.
#define colunas 50       //"Constante Usada Para Armazenar o Valor Fixo de Colunas"
#define linhas  50       //"Constante Usada Para Armazenar o Valor Fixo de Linhas"
#define LetrasErradas 30 //"Constante Usada Para Armazenar o Valor Fixo de LetrasErradas"




int main()               //Função Principal (Main), Irá Retornar Algum Valor Inteiro no Final
{
    int Cont1, Cont2, Linha_Aleatoria, Flag_Errou, Comprimento_Da_Palavra, Acertos, Erros, Letras_Iguais, Palavras_Completas;
    int Aux1=0, Aux2=0, Ganhou=0, Jogadas=0, Quantidade_De_Animais = 50;

    int Palavras_Repetidas[linhas]; //Declarando um Vetor inteiro para armazenar as palavras repetidas gerada pelo "rand"

    for(Cont1=0; Cont1<linhas; Cont1++)  //for para percorrer todo vetor de Palavras Repetidas
    {
        Palavras_Repetidas[Cont1] = 99; //Setar todas as posições como 99 em vez de lixo e não correr o risco de ter
    }                        //algum lixo como uma Linha gerada "Randomicamente"

    char letra;              //Declarando a variável letra como carácter
    char saida;              //Declarando a variável saida como carácter

    char Animais[linhas][colunas] = {"MACACO",                 //Nesta
                                     "LEAO",                   //Matriz
                                     "TIGRE DE BENGALA",       //de Caracteres
                                     "PEIXE ESPADA",           //Contém
                                     "JACARE",                 //50 Nomes
                                     "COELHO",                 //de Animais
                                     "CACHORRO",               //Aleatórios
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

    do //Loop de consistêcia
    {
        system("cls");
        // Cabelhaço Inicial do Jogo Da Forca - (Enter Inicia)
        printf("               ________________________________________              \n"); //Frase
        printf("   ____________|BEM VINDO AO TRADICIONAL JOGO DA FORCA|_____________ \n"); //Frase
        printf("   |ESSE JOGO EH COMPOSTO POR ALEATORIOS NOMES DE ANIMAIS DISTINTOS| \n"); //Frase
        printf("   _________________________________________________________________ \n"); //Frase
        printf("\n\n"); //Pula duas linhas
        printf("\t       ________________________________________                    \n"); //Frase
        printf("\t       |PRESSIONE (ENTER) PARA INICIAR O JOGO!|                    \n"); //Frase
        printf("\t       ________________________________________                    \n"); //Frase


        letra = getche(); //Entende que é um caracter e já "pega" no mesmo momento
    } while(letra != 13);  //Analisa se a pessoa digitou 13 (Tecla ENTER na Tabela ASCII)

    do //Loop de Consistência Principal, Estará funcionando enquanto o usuário digitar "S/s"
    {
        Cont1=0;                  //Inicializando a variável "Cont1" com "0"
        Cont2=0;                  //Inicializando a variável " Cont2" com "0"
        Linha_Aleatoria=0;        //Inicializando a variável "Linha_Aleatoria" com "0"
        Flag_Errou=1;                  //Inicializando a variável "Errou" com "0"
        Comprimento_Da_Palavra=0; //Inicializando a variável "CompPala" com "0"
        Acertos=0;                //Inicializando a variável "Acertos" com "0"
        Erros=0;                  //Inicializando a variável "Erros" com "0"
        Letras_Iguais=0;          //Inicializando a variável "LetraIgual" com "0"
        Palavras_Completas=0;     //Inicializando a variável "PalaCompleta" com "0"

        do              //Loop de consistência para não obter palavras repetidas no jogo
        {
            srand( (unsigned)time(NULL) ); //Função para pegar sementes aleatórias em tempos distintos
            Linha_Aleatoria = (rand () % 50);    //Gera um número aleatório, usado como linha aleatória da matriz
            Aux1=0;                         //Atribui "0" para a variável "Aux"

            for(Cont1=0; Cont1<linhas; Cont1++)  //For para percorrer o número máximo de probabilidades das
            {
                //palavras aleatórias
                if(Palavras_Repetidas[Cont1] == Linha_Aleatoria) //Se Vetor das Palavras Repetidas na posição "cont"
                {
                    //for igual a linha aleatória, irá...
                    Aux1=1;                         //Atribui 1 para a variável "Aux"
                }
            }
        }
        while(Aux1 == 1); //Enquanto a váriavél "Aux" for igual a "1", continuará nesse Loop

        Palavras_Repetidas[Aux2] = Linha_Aleatoria; //Atribui Linha Aleatória na posição "Aux2" do Vetor Palavras_Repetidas
        Aux2++;                        //Incrementa um na variável "Aux2"

        Comprimento_Da_Palavra = strlen(Animais[Linha_Aleatoria]); //Função para determinar o tamanho de uma string
        Palavras_Completas = Comprimento_Da_Palavra;           //PalaCompleta passa ter mesmo valor que a variável CompPala

        char Vetor_Erros[LetrasErradas];   //Neste vetor será armazenado as letras erradas e imprimir os erros
        for(Cont1=0; Cont1<LetrasErradas; Cont1++)     //Loop de repetição de "i" até "10"
        {
            Vetor_Erros[Cont1] = '\0';         //Inicializa todo o "Vetor_Erros com '\0'
        }

        char Vetor_Acertos[Palavras_Completas];   //Neste vetor será armazenado os acertos e imprimir os acertos

        for(Cont1=0; Cont1<Palavras_Completas; Cont1++) //Loop de repetição de "i" até o tamanho da palavra sorteada
        {
            Vetor_Acertos[Cont1] = '_'; //Inicializa todo o "Vetor_Acertos com '_'
            if(Animais[Linha_Aleatoria][Cont1] == 32) //Se a palavra tiver um espaço separando elas
            {
                Vetor_Acertos[Cont1] = 32; //Inicializa todo o "Vetor_Acertos com '_'
                Comprimento_Da_Palavra--;            //A variável "CompPala" ira descrementar "1"
            }
        }

        while(Erros < 8)    //Processo repetitivo, enquanto a variável "Erros" for menor que 8
        {
            switch(Erros)   //Interruptor que trabalha com a impressão da forca em relação aos "Erros"
            {

            case 0:             //Se caso a variável "Erros" for 0, imprime a forca a baixo
                //Forca Inicial -Estrutura - Tentativa 0
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ____________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa, se caso comutar os "Erros" continua

            case 1:             //Se caso a variável "Erros" for 1, imprime a forca a baixo
                //Forca 1 - Cabeça - Tentativa 1
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa e se caso comutar os "Erros" continua

            case 2:             //Se caso a variável "Erros" for 2, imprime a forca a baixo
                //Forca 2 - tronco - Tentativa 2
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa e se caso comutar os "Erros" continua

            case 3:             //Se caso a variável "Erros" for 3, imprime a forca a baixo
                //Forca 3 - Braço Direito - Tentativa 3
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa e se caso comutar os "Erros" continua

            case 4:             //Se caso a variável "Erros" for 4, imprime a forca a baixo
                //Forca 4 - Braço Esquerdo - Tentativa 4
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa e se caso comutar os "Erros" continua

            case 5:             //Se caso a variável "Erros" for 5, imprime a forca a baixo
                //Forca 5 - Perna Direita - Tentativa 5
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa e se caso comutar os "Erros" continua

            case 6:             //Se caso a variável "Erros" for 6, imprime a forca a baixo
                //Forca Final - Corpo Enforcado - Tentativa 6
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
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
                break; //Dá uma pausa e se caso comutar os "Erros" continua

            default :  //Se caso a variável "Erros" for diferente das anteriores, imprime a forca a baixo
                //Forca Final - Corpo Enforcado - FINAL
                system("cls");  //Limpar "saídas" anteriores
                Jogadas++;      //Incrementa "1" para a variável "Jogadas"
                Quantidade_De_Animais--;            //Desincrementa "1" para a variável "N"
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________   ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 7-Erros);
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

            printf("\n\n"); //Pula duas linhas

            if(Erros >= 7)  //Se caso a variável "Erros" for igual a "7", executa este "if"
            {
                for(Cont1=0; Cont1<Palavras_Completas; Cont1++) //Loop para igular o vetor acertos a palavra correta
                {
                    Vetor_Acertos[Cont1] = Animais[Linha_Aleatoria][Cont1];   //no Vetor Acertos
                    printf(" %c", Vetor_Acertos[Cont1]);            //Imprime caracter por caracter do
                }

                printf("\n\n");                     //Pula duas linhas
                printf("\t      QUE PENA!!!\n");                       //Frase de motivação
                printf("   TENTE UMA PROXIMA VEZ, VOCE CONSEGUE!\n\n"); //Frase de motivação
                printf("     DESEJA JOGAR NOVAMENTE < S/N > !?\n"); //Pergunta se gostaria de reiniciar

                do //Processo repetitivo para analisar se a pessoa quer reiniciar o jogo
                {
                    saida = getche(); //Entende que é um caracter e já "pega" no mesmo momento

                    if(saida == 'n' || saida == 'N') //Se caso o usuario não querer reiniciar...
                    {
                        system("cls"); //Imprime caracter por caracter do Vetor Erros
                        printf("\n\t\tVOCE REALIZOU UM BOM JOGO! ATE A PROXIMA!\n"); //Frase de despedida
                        return 0; //Sai do Programa
                    }
                    if(saida == 's' || saida == 'S') //Se caso o usuario querer iniciar de novo...
                    {
                        system("cls"); //Imprime caracter por caracter do Vetor Erros
                        Erros = 10;    //Atribui 10 para a variável "Erros"

                    }
                }
                while(saida != 'S' && saida != 's' && saida != 'N' && saida != 'n');  // Condiçao de consistência
            }

            if(Erros < 7) //Se caso a variável "Erros" for menor que "7"
            {
                for(Cont1=0; Cont1<Palavras_Completas; Cont1++) //Loop para imprimir todo o "Vetor_Acertos com "_"
                {
                    printf(" %c", Vetor_Acertos[Cont1]); //Imprime caracter por caracter do Vetor Acertos
                }

                printf("\n\n");     //Pula duas linhas

                printf("Erros: ");  //Imprime "Erros: " para que se imprima e aparece as letras erradas na "frente"
                //Não utilizei "puts" por causa de sintaxe, melhor imprimir "Espaço" e caracter por caracter!
                for(Cont1=0; Cont1<LetrasErradas; Cont1++) //Loop para imprimir todo o "Vetor_Erros com "\0"
                {
                    printf("%c ", Vetor_Erros[Cont1]); //Imprime caracter por caracter do Vetor Erros
                }

                printf("\n\n"); //Pular 2 linhas
            }
            if(Acertos == Comprimento_Da_Palavra) //Se caso a palavra estiver completada...
            {
                Ganhou++;  //Incrementa "1" para a variável "Ganhou"
                Jogadas++; //Incrementa "1" para a variável "Jogadas"
                Quantidade_De_Animais--;       //Desincrementa "1" para a variável "N"

                //Se caso a pessoa acertar a palavra completa imprime a forca a baixo
                Sleep(1000);
                system("cls");  //Limpar "saídas" anteriores
                printf("\n     _______________________________________________ ");
                printf("\n     | TEMOS %d ANIMAIS DISTINTOS AINDA NO JOGO!!! |     ", Quantidade_De_Animais);
                printf("\n     _______________________________________________     ");
                printf("\n   ____________________________________________________  ");
                printf("\n  | PONTUACAO! VOCE ACERTOU %D DE %D PALAVRAS TENTADAS  |", Ganhou, Jogadas);
                printf("\n  |___________________________________________________|");
                printf("\n   ___________________________________________________  ");
                printf("\n  |            TAMANHO DESSA PALAVRA: %d               |", Comprimento_Da_Palavra);
                printf("\n  |_______________  SUAS CHANCES: %d  _________________|", 6-Erros);
                printf("\n                 |___________________|");
                printf("\n\n       PARABENS VOCE ACERTOU A PALAVRA COMPLETA");
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
                printf("\t     PARABENS!!!\n");              //Frase de Parabenização
                printf("      VOCE ADVINHOU A PALAVRA!\n\n"); //FRASE DE PARABENIZAÇÃO!\n\n"); //Frase de Parabenização
                printf("   DESEJA JOGAR NOVAMENTE < S/N > !?\n"); //Pergunta de gostaria de reiniar

                do //Processo repetitivo para analisar se a pessoa quer reiniciar o jogo
                {
                    saida = getche(); //Entende que é um caracter e já "pega" no mesmo momento

                    if(saida == 'n' || saida == 'N') //Se caso não querer reiniciar...
                    {
                        system("cls"); //Limpar "saídas" anteriores
                        printf("\n\t VOCE REALIZOU UM BOM JOGO! ATE A PROXIMA!\n"); //Frase de despedida
                        return 0; //Sair do programa
                    }
                    if(saida == 's' || saida == 'S') //Se caso querer reiniciar...
                    {
                        Erros = 10; //Condição para sair do "While" - "Loop"
                        system("cls"); //Limpar "saídas" anteriores
                    }
                }
                while(saida != 'S' && saida != 's' && saida != 'N' && saida != 'n');  //Condição de consistência
            }

            if(Quantidade_De_Animais <= 0)
            {
                printf("\n VOCÊ REALIZOU UM BOM JOGO, NAO TEMOS MAIS NENHUMA PALAVRA DISTINTA!!!");
                printf("\n INICIALIZA O JOGO NOVAMENTE PARA OBTER UMA MELHOR PONTUACAO!!!\n\n");
                return 0;
            }

            if(Erros == 6) //Se caso a variável "Erros" for igual a "6"...
            {
                printf("VOCE PERDEU!!!\n"); //Aparece na tela "Você Perdeu!!! e pula linha"
                Erros++;                    //Acrescenta 1 para a variável "Erros"
                Sleep(1800);                //O programa "dorme" por "3" segundos
            }

            if(Erros<6) //Se caso a variável "Erros" for menor que "6"...
            {
                do //Loop de consistência para verificar se já foi digita alguma vez a letra escolhida
                {
                    Letras_Iguais = 0; //Iniicializa a variàvel "LetraIgual" com "0"
                    do //Loop para analisar se o carácter escolhido é uma letra do alfabeto
                    {
                        printf("LETRA: ");          //Imprima "Letra: " para usuario digitar algum caracter
                        letra = getche();       //Entende que é um caracter e já "pega" no mesmo momento
                        letra = toupper(letra); //converter o caractere contido na variável c em maiúscula
                        printf("\n");           //Pula uma linha

                    }
                    while(isalpha(letra) != 1);     //Condição de consistência (verifica se é uma letra)

                    for(Cont1=0; Cont1<Palavras_Completas; Cont1++)       //Loop para analisar se a letra escolhida já foi digitada
                    {
                        if(letra == Vetor_Acertos[Cont1] || letra == Vetor_Erros[Cont1]) //Se letra já foi digitada...
                        {
                            Letras_Iguais = 1;             //Atribui "1" para a variável letra "LetraIgual"
                        }
                    }
                }
                while(Letras_Iguais == 1);  //Condição de consistência (Verifica se a letra já foi digitada)

                for(Cont1=0; Cont1<Palavras_Completas; Cont1++) //Loop de repetição para analisar a letra digitada
                {
                    if(Animais[Linha_Aleatoria][Cont1] == letra) //Se a letra digitada for igual a uma das palavra
                    {
                        Vetor_Acertos[Cont1] = letra; //Subtitui '_', pela letra digitada
                        Acertos++;                //Acrescenta "1" para a variável "Acertos"
                        Flag_Errou=0;                  //Atribui "0" para a variável "Errou"
                    }
                }

                if(Flag_Errou != 0) //Se caso a variável "Errou" for diferente de "0"...
                {
                    Vetor_Erros[Cont2] = letra; //Vetor_Erros na posição "k" recebe a letra não contida
                    Cont2++;                    //Acrescenta "1" para a variável "k"
                    Erros++;                //Acrescenta "1" para a variável "Erros"
                }
                Flag_Errou=1;                    //Atribui "1" para a variável "Errou"
            }
        }
    }
    while (saida != 'N' || saida != 'n');  //Condição de consistência, verifica se a pessoa quer reiniciar o jogo

    return 0; //Sai do programa
}
