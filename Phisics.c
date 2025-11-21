#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define PADDLE_SIZE 3
#define LEFT_PADDLE_X 2
#define RIGHT_PADDLE_X 77
int MoveRacket(int current_y, int step) {
    int new_y = current_y + step;
    if (new_y < 1) return 1;
    if (new_y > FIELD_HEIGHT - PADDLE_SIZE - 1) return FIELD_HEIGHT - PADDLE_SIZE - 1;
    return new_y;
}

int GeneralSpeedYBall(int currentX, int currentY, int speedY, int racketOneY, int racketTwoY) {
    // Отскок от верхней и нижней границ
    if (currentY >= FIELD_HEIGHT - 1) {
        speedY = -1;
    } else if (currentY <= 0) {
        speedY = 1;
    }

    // Столкновение с левой ракеткой
    if (currentX == LEFT_PADDLE_X) {
        if (currentY >= racketOneY && currentY < racketOneY + PADDLE_SIZE) {
            // Изменяем вертикальную скорость в зависимости от части ракетки
            if (currentY == racketOneY) speedY = -1;
            else if (currentY == racketOneY + 2) speedY = 1;
            else speedY = 0;
        }
    } 
    // Столкновение с правой ракеткой
    else if (currentX == RIGHT_PADDLE_X) {
        if (currentY >= racketTwoY && currentY < racketTwoY + PADDLE_SIZE) {
            if (currentY == racketTwoY) speedY = -1;
            else if (currentY == racketTwoY + 2) speedY = 1;
            else speedY = 0;
        }
    }

    return speedY;
}

int GeneralSpeedXBall(int currentX, int currentY, int speedX, int racketOneY, int racketTwoY) {
    // Столкновение с левой ракеткой
    if (currentX == LEFT_PADDLE_X) {
        if (currentY >= racketOneY && currentY < racketOneY + PADDLE_SIZE) {
            speedX = 1;  // Отскок вправо
        }
    } 
    // Столкновение с правой ракеткой
    else if (currentX == RIGHT_PADDLE_X) {
        if (currentY >= racketTwoY && currentY < racketTwoY + PADDLE_SIZE) {
            speedX = -1; // Отскок влево
        }
    }
    
    return speedX;
}

int GeneralXBall(int currentX, int currentY, int racketOneY, int racketTwoY) {
    // Если мяч ушел за левую границу - сброс в центр (уже обработано в main)
    if (currentX <= 0) {
        return FIELD_WIDTH / 2;
    }
    // Если мяч ушел за правую границу - сброс в центр (уже обработано в main)
    else if (currentX >= FIELD_WIDTH - 1) {
        return FIELD_WIDTH / 2;
    }
    
    // Корректировка позиции при столкновении с ракетками
    if (currentX == LEFT_PADDLE_X) {
        if (currentY >= racketOneY && currentY < racketOneY + PADDLE_SIZE) {
            return LEFT_PADDLE_X + 1; // Отодвигаем от левой ракетки
        }
    }
    else if (currentX == RIGHT_PADDLE_X) {
        if (currentY >= racketTwoY && currentY < racketTwoY + PADDLE_SIZE) {
            return RIGHT_PADDLE_X - 1; // Отодвигаем от правой ракетки
        }
    }
    
    return currentX;
}

int GeneralYBall(int currentX, int currentY) {
    // Отскок от верхней и нижней границ
    if (currentY >= FIELD_HEIGHT - 1) {
        return FIELD_HEIGHT - 2;
    } else if (currentY <= 0) {
        return 1;
    }
    
    return currentY;
}