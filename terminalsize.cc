#include <sys/ioctl.h>
#include <unistd.h>
#include <utility>

std::pair<int,int> get_terminal_size() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return { w.ws_row, w.ws_col };
}

