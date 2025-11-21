#include <stdio.h>
#include "Phisics.c"
#include "Display.c"

int main() {
    int score1 = 0, score2 = 0;

    int yFirstPlayer = FIELD_HEIGHT / 2 - 1;
    int ySecondPlayer = FIELD_HEIGHT / 2 - 1;

    int xBall = FIELD_WIDTH / 2;
    int yBall = FIELD_HEIGHT / 2;
    int speedX = 1, speedY = 0;

    int ggez = 0;
    while (ggez == 0) {
        char input[10];
        fgets(input, 10, stdin);
        char c = input[0];

        switch (c) {
            case 'E': case 'e': case 'Q': case 'q':
                ggez = 1;
            case 'A': case 'a': 
                yFirstPlayer = MoveRacket(yFirstPlayer, -1);
                break;
            case 'Z': case 'z': 
                yFirstPlayer = MoveRacket(yFirstPlayer, 1);
                break;
            case 'K': case 'k': 
                ySecondPlayer = MoveRacket(ySecondPlayer, -1);
                break;
            case 'M': case 'm': 
                ySecondPlayer = MoveRacket(ySecondPlayer, 1);
                break;
        }
        
        // Движение мяча
        xBall += speedX;
        yBall += speedY;

        // ПОДСЧЕТ ОЧКОВ ПЕРЕД физикой
        if (xBall < 0) {
            score2++;
            xBall = FIELD_WIDTH / 2;
            yBall = FIELD_HEIGHT / 2;
            speedX = 1;
            speedY = 0;
        } 
        else if (xBall >= FIELD_WIDTH) {
            score1++;
            xBall = FIELD_WIDTH / 2;
            yBall = FIELD_HEIGHT / 2;
            speedX = -1;
            speedY = 0;
        }

        // Проверка победы
        if (score1 >= 21 || score2 >= 21) {
            Drawing(xBall, yBall, yFirstPlayer, ySecondPlayer, score1, score2);
            printf("\n=== GAME OVER ===\n");
            printf("Player %s wins!\n", score1 >= 21 ? "LEFT" : "RIGHT");
            printf("Final score: %d - %d\n", score1, score2);
            return 0;
        }

        // ВАЖНО: Сначала применяем функции изменения скорости
        speedX = GeneralSpeedXBall(xBall, yBall, speedX, yFirstPlayer, ySecondPlayer);
        speedY = GeneralSpeedYBall(xBall, yBall, speedY, yFirstPlayer, ySecondPlayer);

        // Затем корректируем позицию
        xBall = GeneralXBall(xBall, yBall, yFirstPlayer, ySecondPlayer);
        yBall = GeneralYBall(xBall, yBall);

        Drawing(xBall, yBall, yFirstPlayer, ySecondPlayer, score1, score2);
    }
    
    return 0;
}

