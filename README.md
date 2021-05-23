# Game of Life
## Propósito
Ser uma implementação de referência para o trabalho de C.

Implementar um Conway's Game of Life no terminal, capaz de receber
receber comandos para iniciar células com vida. Esses comandos podem ser
dados via uma CLI (_Command-Line-Interface_) ou um arquivo contendo os 
mesmos comandos. 

Esse não é o exercício de como programar em C, mas de como organizar um
programa. Mais importante do que a implementação das regras, o foco é em 
separar as partes do programa. Separar código que lida com a interface (entrada e saída) e a lógica do jogo. Separar o jogo em uma biblioteca que
siga boas práticas de código.  

## Como rodar
O Makefile deve criar as pastas `bin` e `obj` contendo a executável final
e os _object files_ da compilação, respectivamente. 
```bash
make
```
