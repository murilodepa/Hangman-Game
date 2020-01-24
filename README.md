# Hangman Game

## Hangman game with file.

### Descrição do Jogo  

* Trata-se de o primeiro projeto realizado na faculdade utilizado a linguagem de programação C, projeto no qual foi implementado uma leitura de arquivos, ou seja, o usuário mesmo pode montar as palavras que deseja inserir no jogo, sendo de um só tema ou variado. Entretandp, esse arquivo precisa ser padronizado, primeiramene indicando quantas palavras que contém no total, e depois uma palavra em baixo da outra, de preferência separado pelo caractere *Enter*, assim facilita na leitura do arquivo e na manipulação, pois é passado todas essas informações para uma matriz que será alocada dinamicamente conforme o numero de palavras digitada pelo usuário. Como todo jogo da forca, o usuário tem que adivinhar qual palavra o programa escolheu aleatoriamente, vendo apenas a quantidade de letras que a palavra contém, como pode ser observado na imagem abaixo. O jogador tem 6 possibilidades, podendo estar verificando as letras incorretas digitas, e se caso não acertar em 6 tentativas o programa exibe a palavra e pergunta se deseja jogar novamente, se caso sim, escolhe outro animal aleatório sem repetir um que já tenha sido sorteado.  

* Exemplo de como deve ser criado o arquivo para jogar com as palavras escolhidas pelo usuário, lembrando que o jogo vem com dois arquivos texto, um com 50 animais e o outro com 40 frutas, esses arquivos foram utilizados para testar o programa e podem ser usados para jogar.  
![image](https://user-images.githubusercontent.com/56207941/73043027-34a1bd00-3e42-11ea-9981-2ac4bda3afc2.png)  

* Primeiramente antes de jogar, pede para digitar o nome do arquivo desejado.  
![image](https://user-images.githubusercontent.com/56207941/73043816-a2031d00-3e45-11ea-9dff-d918c770b056.png)  

* Depois aguarda o jogador pressionar a tecla *Enter*, que é o *Start* do jogo.  
![image](https://user-images.githubusercontent.com/56207941/73043847-c7902680-3e45-11ea-869b-5e1ce5bdfed0.png)  

* Jogador com 6 possibilidades!  
![image](https://user-images.githubusercontent.com/56207941/73043961-4b4a1300-3e46-11ea-8724-ed1014a80d24.png)  

* Jogador com 5 possibilidades!  
![image](https://user-images.githubusercontent.com/56207941/73044022-95cb8f80-3e46-11ea-8906-c3d27ba95517.png)  

Jogador com 4 possibilidades!  
![image](https://user-images.githubusercontent.com/56207941/73044034-abd95000-3e46-11ea-9386-8560a6906b3b.png)  

Jogador com 3 possibilidades!  
![image](https://user-images.githubusercontent.com/56207941/73044063-c1e71080-3e46-11ea-9299-02114e94336f.png)  

Jogador com 2 possibilidades!  
![image](https://user-images.githubusercontent.com/56207941/73044084-da572b00-3e46-11ea-88a4-cba8d842c71d.png)  

Jogador com 1 possibilidades!  
![image](https://user-images.githubusercontent.com/56207941/73044106-f35fdc00-3e46-11ea-99b2-ea0e4c2a605e.png)  

Jogador não tem nenhuma tentativa!  
![image](https://user-images.githubusercontent.com/56207941/73044134-0c688d00-3e47-11ea-8809-48f3d29fe5bc.png)  

Jogador acertou a palavra!  
![image](https://user-images.githubusercontent.com/56207941/73044198-45a0fd00-3e47-11ea-8185-72b3264e28b4.png)  

### Pré-requisitos
 
#### Sistema Operacional
* Foi utilizado o Windows 10, mas pode ser realizado em outro sistema operacional, necessita instalar o compilador compatível com o sistema operacional.

 #### Compilador
* Foi utilizado o ambiente integrado de desenvolvimento Code::Blocks e a implementação Mingw do GCC (GNU Compiler Collection) como seu compilador.
* <a> [Code::Blocks: Necessário para desenvolvimento do projeto](http://www.codeblocks.org/downloads/26)
 
 #### Bibliotecas
#include <conio.h>       // "Used the function "Getche()"
#include <ctype.h>       // "Fuctions added to work with characters"
#include <stdio.h>       // "Standard Header (In/Out)"
#include <stdlib.h>      // "Standard Header"
#include <string.h>      // "Manipulate Strings"
#include <time.h>        // "Used the chronological time"
#include <windows.h>     // "Used to the function "Sleep"

   * **Observação:** Para desenvolver este projeto, precisa apenas de conhecimentos básicos sobre lógica de programação e linguagem de programação C.

### Guia de instalação
* Para executar o programa na linguagem C, no qual o algoritmo foi realizado, necessita apenas de um compilador e uma IDE que compile e execute essa linguagem de programação, no caso do projeto, foi utilizado o Code::Blocks e o compilador Mingw do GCC como já descrito, não precisando de nenhuma outra ferramenta adicional ou especial, esse programa pode ser obtido no link acima, mas também, pode estar sendo utilizado outros softwares para o desenvolvimento deste projeto ou similar.

### Desenvolvimento
* Git clone https://github.com/murilodepa/Hangman-Game.git
* Se realizar "Download ZIP", necessita de um descompactador de arquivos.
* Após ter instalado o Code::Blocks ou outro programa similar, execute-o e selecione "arquivo" e depois "abrir projeto".
* Selecione o diretório onde está salvo o arquivo e depois selecione a opção abrir.
* Logo em seguida, selecione a opção executar e o jogo começará.

### Contribuições
- Contribuições e possíveis melhorias, no meu ponto de vista são sempre bem-vindas.
