## Joguinho de Desviar de Objetos
Este projeto é um jogo simples de console onde o jogador controla um cursor que deve desviar de objetos caindo. O jogo é escrito em C++ e utiliza bibliotecas padrão para input/output e controle de tempo. É um projeto ideal para aprender sobre manipulação de entrada do usuário, controle de fluxo e desenho de cenas em console.

## Funcionalidades
Menu Principal

Opção para iniciar o jogo.
Opção para visualizar as regras.
Opção para sair do jogo.
Tela de Carregamento

Animação simples de carregamento antes do início do jogo.
Contagem Regressiva

Contagem regressiva de 3 segundos antes de iniciar o jogo.
Desenho da Cena

Desenho do cenário do jogo com bordas e uma área de jogo central.
Exibição da posição do jogador e dos objetos caindo.
Exibição da pontuação atual do jogador.
Movimentação do Jogador

Controle através das teclas 'A' e 'D' para mover para a esquerda e direita, respectivamente.
Saída do jogo ao pressionar a tecla 'Q'.
Gerenciamento de Objetos

Inicialização de objetos caindo de posições aleatórias.
Incremento da posição vertical dos objetos a cada iteração.
Reinicialização da posição do objeto após ultrapassar a área de jogo.
Incremento da pontuação ao desviar dos objetos.
Detecção de Colisão

Verificação de colisões entre o jogador e os objetos caindo.
Finalização do jogo em caso de colisão, exibindo a pontuação final e retornando ao menu.
Como Executar
Compilar o Código

Utilize um compilador de C++ (por exemplo, g++) para compilar o código:
bash
Copiar código
g++ -o joguinho joguinho.cpp
Executar o Programa

## Execute o arquivo compilado:
bash
Copiar código
./joguinho
Bibliotecas Utilizadas
<iostream>: Para entrada e saída padrão.
<unistd.h>: Para funções de controle de tempo (sleep).
<cstdlib>: Para funções utilitárias, como geração de números aleatórios.
<ctime>: Para inicializar a semente do gerador de números aleatórios.
<conio.h>: Para captura de entradas do teclado sem esperar por Enter (_getch e _kbhit).
Considerações Finais
Este projeto é uma excelente introdução para jogos baseados em console. Ele demonstra a criação de um loop de jogo, a manipulação de entrada do usuário e a atualização de um display baseado em texto. Além disso, oferece uma visão prática sobre como gerenciar e detectar colisões de objetos em um jogo simples.

Divirta-se jogando e explorando o código! Se tiver alguma sugestão ou encontrar algum bug, sinta-se à vontade para abrir uma issue ou enviar um pull request.





