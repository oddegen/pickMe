#include <iostream>
#include "_hook.h"


int main() {
    HHOOK mouseHook = SetMouseHook();

    if ( mouseHook == NULL) {
        std::cerr << "ERROR";
        return EXIT_FAILURE;
    }

    std::cout << "A lightweight color picker in the terminal\nPress Ctrl-C to exit\n";

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnsetMouseHook(mouseHook);

    return EXIT_SUCCESS;

}