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

            return 'p'; //play & login

        }
        else if((input=='e' || input=='E') && y==3*ROW/4) {
            
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

void HANDLE_NEXT_MENUS(char NEXT_MENU) {

    if(NEXT_MENU=='r') {

        USER_REGISTERATION();

    }
    else if (NEXT_MENU=='p') {
    
        USER_LOGIN();

    }
}
void USER_REGISTERATION() {

    clear();

    echo();

    curs_set(1);

    FILE * USERS_AND_PASSWORDS=fopen("users_and_passwords.txt","a+");

    attron(COLOR_PAIR(1));

    mvprintw(ROW/3,COLUMN/2 -11,"Enter Your Username :");

    attron(A_ITALIC);

    mvprintw(ROW/3 +1, COLUMN/2 -46 ,"Note : Username Must Not Contain Spaces, Be Already Taken, or Be Longer Than 15 Characters");

    attroff(A_ITALIC);

    mvprintw(2*ROW/3 +1 ,COLUMN/2 - 7 ,"###############");

    move(2*ROW/3 , COLUMN/2 -7);

    refresh();

    char USERNAME[100];

    while(TRUE) {

        getstr(USERNAME);

        if(strlen(USERNAME)==0) {

            mvprintw(ROW/3+2 , COLUMN/2 -10 ,"                    ");

            mvprintw(ROW/3 +2 , COLUMN/2 -9   ,"Username Is Empty");

            move(2*ROW/3 , COLUMN/2 -7);

            refresh();

            continue;

        }

        if(strlen(USERNAME)>15) {

            mvprintw(ROW/3+2 , COLUMN/2 -10 ,"                    ");

            mvprintw(ROW/3+2 , COLUMN/2 -14 ,"Username Is Longer Than 15");

            move(2*ROW/3 , COLUMN/2 -7);

            refresh();

            continue;

        }

        if(strchr(USERNAME," ")!=NULL) {

            mvprintw(ROW/3+2 , COLUMN/2 -10 ,"                    ");

            mvprintw(ROW/3+2 , COLUMN/2 -13 ,"Username Contains Spaces");

            move(2*ROW/3 , COLUMN/2 -7);

            refresh();

            continue;

        }

        int IS_DUPLICATE=FALSE;

        while(TRUE) {

            char USER_RECORDS[16];

            if(fscanf(USERS_AND_PASSWORDS," %s",USER_RECORDS)!=EOF) {

                if(strcmp(USER_RECORDS,USERNAME)==0) {

                    IS_DUPLICATE=TRUE;

                    mvprintw(ROW/3+2 , COLUMN/2 -10 ,"                    ");

                    mvprintw(ROW/3+2, COLUMN/2 -12 , "Username Already Taken");

                    move(2*ROW/3 , COLUMN/2 -7);

                    refresh();

                    break;

                }

            }

            else {

                break;

            }
        }

        if(IS_DUPLICATE==TRUE)
            continue;
    }

    char Password[16];

    




























    //after confirming everything, add user to list and make a default 0 score for them



    fclose(USERS_AND_PASSWORDS);

}
void USER_LOGIN() {

    clear();







}