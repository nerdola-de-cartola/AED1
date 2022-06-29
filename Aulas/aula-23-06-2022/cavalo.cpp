#include <iostream>
#include <iomanip>

typedef struct {
    int x;
    int y;
} position;

using namespace std;

void TryNextMove(int next_move, position pos, bool &s);
void Print();

const int Size = 8;
position moves[Size+1] = {
    {0, 0},
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1}
};
int tabuleiro[Size+1][Size+1];
int n;
//----------------------------------------

int main() {
    position start;
    bool possivel;

    cout << "Tamanho do tabuleiro (1-8): ";
    cin >> n;

    cout << "Posicao inicial do cavalo (x,y): ";
    cin >> start.x >> start.y;
    tabuleiro[start.x][start.y] = 1;

    TryNextMove(2, start, possivel);
    if(possivel) Print();
    else cout << "Caminho nao encontrado" << '\n';

    return 0;
}

void Print() {
    int i,j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cout << setw(5) << tabuleiro[i][j];
        }

        cout << '\n';
    }
    cout << '\n';
}

void TryNextMove(int next_move, position pos, bool &s) {
    position next;
    int i;
    bool sucesso;

    i = 0;
    sucesso = false;

    do {
        i++;
        next.x = pos.x + moves[i].x;
        next.y = pos.y + moves[i].y;

        if(1 <= next.x && next.x <= n && 1 <= next.y && next.y <= n && tabuleiro[next.x][next.y] == 0) {
            tabuleiro[next.x][next.y] = next_move;
            if(next_move < n*n) {
                TryNextMove(next_move+1, next, sucesso);
                if(!sucesso) tabuleiro[next.x][next.y] = 0;
            }
            else sucesso = true;
        }
    } while(!sucesso && i < Size);

    s = sucesso;
}