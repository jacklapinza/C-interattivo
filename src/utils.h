#ifndef UTILS_H
#define UTILS_H
#define RESET "\033[0m"
#define HIGHLIGHT "\033[1;47;30m"
#define NORMAL "\033[0;37m"
#define UP_ARROW 65
#define DOWN_ARROW 66

int getch();
void clear_screen();
void print_menu(const char *title, const char *options[], int count, int selected);
void delay_text(char c, float seconds);
void get_terminal_width(int *cols);
#endif
