#include <ncurses.h>    //403110585 Mohammad Amin Haghjoo
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int ROW,COLUMN;
int IS_GUEST=0;
char GAME_STARTUP_MENU();
void USER_REGISTERATION();
void HANDLE_NEXT_MENUS(char);
void USER_LOGIN();




int main() {

    initscr();

    noecho();

    curs_set(0);

    keypad(stdscr,TRUE);

    getmaxyx(stdscr,ROW,COLUMN);

    if(has_colors()==TRUE) {
        
        start_color();

        init_pair(1,COLOR_YELLOW,COLOR_BLACK);

        init_pair(2,COLOR_WHITE,COLOR_YELLOW);

        //add colors later
    }

    char NEXT_MENU=GAME_STARTUP_MENU();

    HANDLE_NEXT_MENUS(NEXT_MENU);












    
    getch();

    endwin();

    return 0;
}

char GAME_STARTUP_MENU() {

    attron(COLOR_PAIR(1));

    mvprintw(ROW-1,0,"v1.0.0 Developed By Mohammad Amin Haghjoo");

    mvprintw(ROW-1,COLUMN/2-22,"Press e or E and arrow keys to Navigate Menus");

    attron(A_ITALIC);

    mvprintw(ROW/4,COLUMN/2 -2,"Rogue");

    attroff(A_ITALIC);

    mvprintw(3*ROW/4,COLUMN/2-8,"Register New User");

    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2) | A_BLINK);

    mvprintw(ROW/2,COLUMN/2 -10 ,"Login or Play as Guest");

    attroff(COLOR_PAIR(2)); attroff(A_BLINK);

    move(ROW/2,COLUMN/2);

    int input;

    do {
        int x,y;

        getyx(stdscr,y,x);

        input=getch();

        if((input=='e' || input=='E' ) && y==ROW/2) {

            clear();

            return 'p'; //play & login

        }
        else if((input=='e' || input=='E') && y==3*ROW/4) {
            
            clear();

            return 'r'; //register new user

        }
        else if(input==KEY_DOWN && y==ROW/2) {

            attron(COLOR_PAIR(1));
            
            mvprintw(ROW/2,COLUMN/2 -10 ,"Login or Play as Guest");

            attroff(COLOR_PAIR(1));

            attron(COLOR_PAIR(2) | A_BLINK);

            mvprintw(3*ROW/4,COLUMN/2-8,"Register New User");

            attroff(COLOR_PAIR(2)); attroff(A_BLINK);

            move(3*ROW/4,COLUMN/2);

        }
        else if(input==KEY_UP && y==3*ROW/4) {

            attron(COLOR_PAIR(1));

            mvprintw(3*ROW/4,COLUMN/2-8,"Register New User");

            attroff(COLOR_PAIR(1));

            attron(COLOR_PAIR(2) | A_BLINK);

            mvprintw(ROW/2,COLUMN/2 -10 ,"Login or Play as Guest");

            attroff(COLOR_PAIR(2)); attroff(A_BLINK);

            move(ROW/2,COLUMN/2);

        }

        refresh();

    }

    while(TRUE);
}
void USER_REGISTERATION() {

}
void HANDLE_NEXT_MENUS(char NEXT_MENU) {

    if(NEXT_MENU=='r') {

        USER_REGISTERATION();

    }
    else if (NEXT_MENU=='p') {
    
        USER_LOGIN();

    }
}
void USER_LOGIN() {

}