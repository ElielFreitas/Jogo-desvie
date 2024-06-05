#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

const int larg = 20;
const int alt = 10;

int x = larg / 2;
int y = alt - 2;

struct obj {
    int x;
    int y;
    char sim;
};

const int mobj = 5;
obj obj[mobj];

int cena[alt][larg] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void mcena(int pontos) {
    for (int i = 0; i < alt; i++) {
        for (int h = 0; h < larg; h++) {
            if (i == y && h == x) {
                std::cout << "^";
            } else if (cena[i][h] == 1) {
                std::cout << "=";
            } else {
                bool objectPrinted = false;
                for (int j = 0; j < mobj; j++) {
                    if (obj[j].y == i && obj[j].x == h) {
                        std::cout << obj[j].sim;
                        objectPrinted = true;
                        break;
                    }
                }
                if (!objectPrinted) {
                    std::cout << " ";
                }
            }
        }
        std::cout << "   "; 

        if (i == alt - 2) {
            std::cout << "Pontos: " << pontos;
        }

        std::cout << "\n";
    }
}

void tc() {
    std::cout << "Carregando";
    fflush(stdout);

    for (int i = 0; i < 3; i++) {
        std::cout << "=";
        fflush(stdout);
        sleep(1);
    }
    std::cout << "\nCarregamento concluido...";
    system("pause");
    system("cls");
}

void contaregr() {
    for (int c = 3; c > 0; c--) {
        system("cls"); 
        std::cout << "O jogo vai comecar em " << c << " segundos...\n";
        sleep(1);
    }
    system("cls");
    std::cout << "Comece a jogar!\n";
    sleep(1); 
}

int menu() {
    int op;

    std::cout << "Desvie!\n\n";

    std::cout << "1-JOGAR\n";
    std::cout << "2-Regras\n";
    std::cout << "3-sair\n";
    std::cin >> op;

    switch (op) {
        case 1:
            
            contaregr();
            for (int i = 0; i < mobj; i++) {
                obj[i].x = rand() % larg;
                obj[i].y = -1 * (rand() % alt); 
                obj[i].sim = '*';
            }
            break;
        case 2:
            std::cout << "Desvie dos objetos e seja feliz =)\n";
            system("pause");
            system("cls");
            menu();
            break;
        default:
            exit(0);
    }
}

bool coli(int objtX, int objtY) {
    if (objtX == x && objtY == y) {
        return true; 
    }
    return false;
}

int main() {
    system("color a");
    
    std::srand(static_cast<unsigned int>(std::time(0)));

    tc();
    menu();

    int pontos = 0;

    while (true) {
        std::cout << "       JOGUIN\n\n";
        mcena(pontos);

        if (_kbhit()) {
            char key = _getch();
            if ((key == 'a' || key == 'A') && x > 0) {
                x--;
            } else if ((key == 'd' || key == 'D') && x < larg - 1) {
                x++;
            } else if (key == 'q') {
                break;
            }
        }

        for (int i = 0; i < mobj; i++) {
            obj[i].y++; 

            
            if (obj[i].y >= alt) {
                obj[i].x = rand() % larg;
                obj[i].y = -1; 
                pontos += 10; 
            }

            if (coli(obj[i].x, obj[i].y)) {
                std::cout << "Fim de Jogo\n";
                std::cout << "Pontuacao final: " << pontos << " pontos\n";
                system("pause");
                system("cls");
                return menu(); 
            }
        }

        usleep(100000); 

        system("cls");
    }

    std::cout << "Fim de Jogo\n";
    std::cout << "Pontuacao final: " << pontos << " pontos\n";

    return 0;
}
