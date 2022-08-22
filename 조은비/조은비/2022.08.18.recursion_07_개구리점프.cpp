#include <iostream>
#include <queue>

using namespace std;

int map[10][10];
int H, W;
int di[3][2] = {
    {1,-1}, // ¢×
    {1,0},  // ¡é
    {1,1}   // ¢Ù
};
int score = 0;

struct frog {
    int y;
    int x;
    int score;
};

queue <frog> f;

int main() {
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }

    f.push({ 0,0,map[0][0] });

    while (!f.empty()) {
        frog frg = f.front(); f.pop();

        if (frg.y == H - 1) score = max(score, frg.score);

        for (int i = 0; i < 3; i++) {
            int ny = frg.y + di[i][0];
            int nx = frg.x + di[i][1];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (map[ny][nx] == 0) continue;

            f.push({ ny,nx,frg.score + map[ny][nx] });
        }
    }

    cout << score;
}