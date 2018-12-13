# Projeto MAGOS

### Aluno: Noé Fernandes

## Introdução

O `MAGOS` é um jogo não interativo que tem o objetivo de mostrar sequencialmente o processo de construção e solução de um labirinto. Nesta aplicação foram usadas um conjunto de classes com bastantes relacionamentos entre si, todas manipuladas pela classe principal MagosGame.

1. `Canvas`: Responsável pelo processo de desenho de figuras.
2. `Maze`: Responsável por guardar as células e manipular seus estados.
3. `Render`: Responsável por desenhar todo o labirinto em seu estado atual, usando o Maze e o canvas como auxílio.
4. `Builder`: Responsável por dar a cara de labirinto ao projeto. Destruindo parede por parede até ter um labirinto correto.
5. `Solver`: Responsável por encontrar a solução do labirinto.
6. `MagosGame`: Organiza todas as classes.

Problemas encontrados:

1. A classe Solver não foi criada e consequentemente o programa não encontra a solução do labirinto. 

## Compilação

- `g++ -Wall -std=c++11 src/maze.cpp src/canvas.cpp src/render.cpp src/builder.cpp src/main.cpp src/magosgame.cpp -I include/`
- `./a.out larg_maze alt_maze larg_img alt_img`


