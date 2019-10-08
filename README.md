# Jogo-da-Forca-de-Animais

## Jogo da forca simples com 50 animais conhecidos "gerados" aleatoriamente.

### Descrição do Jogo
* Trata-se de o primeiro projeto realizado na faculdade utilizado a linguagem de programação C, projeto no qual contém uma matriz pronta com 50 animais conhecidos selecionados, e o usuário tem que adivinhar qual animal o programa escolheu aleatoriamente, vendo apenas a quantidade de letras que o animal contém, como pode ser observado na imagem abaixo. O jogador tem 6 chances, podendo estar verificando as letras incorretas digitas, e se caso não acertar em 6 tentativas o programa exibe o nome do animal e pergunta se deseja jogar novamente, como também pode estar sendo observado na segunda imagem, se caso sim, escolhe outro animal aleatório sem repetir um que já tenha sido sorteado.

![Forca1](https://user-images.githubusercontent.com/56207941/66264584-71d43780-e7de-11e9-85cf-536e81084488.PNG)

![Forca2](https://user-images.githubusercontent.com/56207941/66264594-95977d80-e7de-11e9-972e-881d4f506d6a.PNG)

### Pré-requisitos
 
#### Sistema Operacional
* Foi utilizado o Windows 10, mas pode ser realizado em outro sistema operacional, necessita instalar o compilador compatível com o sistema operacional.

 #### Compilador
* Foi utilizado o ambiente integrado de desenvolvimento Code::Blocks e a implementação Mingw do GCC (GNU Compiler Collection) como seu compilador.
* <a> [Code::Blocks: Necessário para desenvolvimento do projeto](http://www.codeblocks.org/downloads/26)
 
 #### Bibliotecas
#include <conio.h>       //"Utilizada a Função "Getche()" da Biblioteca
#include <ctype.h>       //"Funções Adicionais Para Usar com Caracteres"
#include <stdio.h>       //"Cabeçalho Padrão de (Entrada/Saída)"
#include <stdlib.h>      //"Cabeçalho da Biblioteca de Propósito Geral Padrão"
#include <string.h>      //"Biblioteca com várias funções Para Manipular Strings"
#include <time.h>        //"Utilizada Para Usar o Tempo Cronológico Como Semente (SEED)"
#include <windows.h>     //"Utilizada Para Usar a Função "Sleep","Dormir" por Alguns Milissegundos.

* **Observação:** Para desenvolver este jogo, precisa apenas de conhecimentos básicos sobre lógica de programação e linguagem de programação C.

### Guia de instalação
* Para executar o programa na linguagem C, no qual o algoritmo foi realizado, necessita apenas de um compilador e uma IDE que compile e execute essa linguagem de programação, no caso do projeto,foi utilizao o Code::Blocks e o compilador Mingw do GCC como já descrito, não precisando de nenhuma outra ferramenta adicional ou especial, esse programa pode ser obtido no link acima, mas também, pode estar sendo utilizado outros softwares para o desenvolvimento deste projeto ou similiar.

### Desenvolvimento
* Git clone https://github.com/murilodepa/Jogo-da-Forca-Simples/
* Se realizar "Download ZIP", necessita de um descompactador de arquivos.
* Após ter instalado o Code::Blocks ou outro programa similiar, execute-o e selecione "arquivo" e depois "abrir projeto".
* Selecione o diretório onde está salvo o arquivo e depois selecione a opção abrir.
* Logo em seguida, selecione a opção executar e o jogo começará.


### Contribuições
- Contribuições e possíveis melhorias no meu ponto de vista são sempre bem-vindas.
