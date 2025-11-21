#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define PADDLE_SIZE 3
#define LEFT_PADDLE_X 2      // Ракетка на 2 клетки от левой границы
#define RIGHT_PADDLE_X 77    // Ракетка на 2 клетки от правой границы (80-3=77)
void Drawing(int ball_x, int ball_y, int left_paddle, int right_paddle, int left_score, int right_score) {
    printf("\033[H"); // Перемещение курсора в начало
    
    // Верхняя граница
    for (int x = 0; x < FIELD_WIDTH; x++) putchar('-');
    putchar('\n');
    
    // Игровое поле
    for (int y = 0; y < FIELD_HEIGHT - 2; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            if (x == 0 || x == FIELD_WIDTH - 1) {
                putchar('|');
            } else if (x == ball_x && y == ball_y) {
                putchar('O');
            } else if (x == LEFT_PADDLE_X && y >= left_paddle && y < left_paddle + PADDLE_SIZE) {
                putchar('|');
            } else if (x == RIGHT_PADDLE_X && y >= right_paddle && y < right_paddle + PADDLE_SIZE) {
                putchar('|');
            } else if (x == FIELD_WIDTH / 2) {
                putchar(':');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    
    // Нижняя граница
    for (int x = 0; x < FIELD_WIDTH; x++) putchar('-');
    putchar('\n');
    
    // Статус
    printf("Score: %d - %d\n", left_score, right_score);
    printf("Controls: A/Z (left), K/M (right), Q (quit)\n");
}