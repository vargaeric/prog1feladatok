#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <curses.h>
#include <unistd.h>

int main(void)
{
    struct winsize m;
    ioctl (STDOUT_FILENO,TIOCGWINSZ,&m);
    int x = 0, y = 0;
    int kx, ky;

    WINDOW *ablak;
    ablak=initscr();
    noecho();
    cbreak();
    nodelay(ablak, true);
    
    for (;;)
    {
        ioctl(STDOUT_FILENO,TIOCGWINSZ,&m);
        kx = (m.ws_col-1) * 2;
        ky = (m.ws_row-1) * 2;
        
        x = (x+1) % kx;
        y = (y+1) % ky;

        clear();

        for(int i=0;i<m.ws_col;i++) mvprintw(0,i,"-");
        for(int i=0;i<m.ws_col;i++) mvprintw(m.ws_row-1,i,"-");
        mvprintw( abs(m.ws_row - 1 - y), abs(m.ws_col - 1 - x), "O");

        refresh();
        usleep(150000);
    }

    return 0;
}
