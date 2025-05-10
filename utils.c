#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include "utils.h"
#include <sys/ioctl.h>

int getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void clear_screen() {
    system("clear");
}

void print_menu(const char *title, const char *options[], int count, int selected) {
    int i;
    clear_screen();
    printf("%s\n\n", title);
    for (i = 0; i < count; i++) {
        if (i == selected) {
            printf("%s> %s%s\n", HIGHLIGHT, options[i], RESET);
        } else {
            printf("%s  %s%s\n", NORMAL, options[i], RESET);
        }
    }
}


void delay_text(char c, float seconds) {

    struct timespec ts;
    ts.tv_sec = (time_t)seconds;
    ts.tv_nsec = (long)((seconds - ts.tv_sec) * 1e9);

    nanosleep(&ts, NULL);

    printf("%c", c);
    fflush(stdout);
}


void get_terminal_width(int *cols) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *cols = w.ws_col;
}

