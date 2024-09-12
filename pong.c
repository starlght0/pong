#include <stdio.h>

void screen(int width, int height, int ballPosition, int paddle1, int paddle2);
int moveBall(int ballPosition);
int movePaddle(char action, int paddle, int height);
void clear() { printf("\033[0d\033[2J"); }

int main() {
    char action;
    int ballPosition = 11;
    int width = 80;
    int height = 25;
    int paddle1 = height / 2;
    int paddle2 = height / 2;
    while (1) {
        clear();
        screen(width, height, ballPosition, paddle1, paddle2);
        scanf(" %c", &action);
        if (action == ' ' || action == 'A' || action == 'a' || action == 'Z' || action == 'z' ||
            action == 'K' || action == 'k' || action == 'M' || action == 'm') {
            ballPosition = moveBall(ballPosition);

            if (action == ' ' || action == 'A' || action == 'a' || action == 'Z' || action == 'z') {
            paddle1 = movePaddle(action, paddle1, height);
            }
            if (action == ' ' || action == 'K' || action == 'k' || action == 'M' || action == 'm') {
            paddle2 = movePaddle(action, paddle2, height);
            }
        }
    }

    return 0;
}

void screen(int width, int height, int ballPosition, int paddle1, int paddle2) {
    int ballX = ballPosition / 10;
    int ballY = ballPosition % 10;

    for (int i = 0; i < width; i++) {
        printf("─");
    }
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                printf("│");
            } else if (j == width / 2) {
                printf("|");
            } else if (j == ballX && i == ballY) {
                printf("⦿");
            } else if (j == 1 && (i == paddle1 || i == paddle1 - 1 || i == paddle1 + 1)) {
                printf("|");
            } else if (j == width - 2 && (i == paddle2 || i == paddle2 - 1 || i == paddle2 + 1)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < width; i++) {
        printf("─");
    }
    printf("\n");
}

int moveBall(int ballPosition) {
    int x = ballPosition / 10;
    int y = ballPosition % 10;

    x += 1;
    y += 1;

    return x * 10 + y;
}

int movePaddle(char action, int paddle, int height) {
    switch(action) {
        case 'A':
        case 'a':
            if (paddle > 1) {
                paddle--;
            }
            break;
        case 'Z':
        case 'z':
            if (paddle < height - 2) {
                paddle++;
            }
            break;
        case 'K':
        case 'k':
            if (paddle > 1) {
                paddle--;
            }
            break;
        case 'M':
        case 'm':
            if (paddle < height - 2) {
                paddle++;
            }
            break;
    }
    return paddle;
}
