#define WINVER 0x0500
#include <windows.h>
#include <stdio.h>
 
int main(int argc, char* argv[])
{
    // setup some variables to hold the bind key and window title
    char char_to_bind;
    char *windowTitle = "Overwatch";

    // get the current keyboard layout
    HKL currentKBL = GetKeyboardLayout(0);

    // grab the character the user wants to bind escape to
    printf("Press any key to bind escape to... ");
    char_to_bind = getchar();
    printf("\n");

    // retrieve first window on the desktop
    HWND firstwindow = FindWindowEx(NULL, NULL, NULL, NULL);
    HWND window = firstwindow;
    TCHAR windowtext[MAX_PATH];
     
    // get the console title incase we accidentally have the same window
    TCHAR consoletitle[MAX_PATH];
    GetConsoleTitle(consoletitle, MAX_PATH);

    // bring window into focus
    SetForegroundWindow(window);
 
    // declare the input here
    INPUT ip;
    
    
    while(1) {
        // check the window title for a match
        GetWindowText(window, windowtext, MAX_PATH);
        if (strstr(windowtext, windowTitle) != NULL &&
            strcmp(windowtext, consoletitle) != 0) break;
         
        // otherwise check the next window
        window = FindWindowEx(NULL, window, NULL, NULL);
        if (window == NULL || window == firstwindow) {
            fprintf(stderr, "Couldn't find Overwatch window. Do you have it open?\n");
            return 1;
        }
    }

    fprintf(stderr, "Located Overwatch window. You can go play now!");
    
    while(1) {
        if (GetAsyncKeyState(VkKeyScanEx(char_to_bind, currentKBL))) {
            printf("Escape pressed\n");
            ip.type = INPUT_KEYBOARD;
            ip.ki.wVk = VK_ESCAPE;
            ip.ki.wScan = 0;
            ip.ki.dwFlags = 0;
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;
            // finally send the input to the window
            SendInput(1, &ip, sizeof(INPUT));
        }

        // we'll go to sleep here so the key press doesn't repeat
        Sleep(100);
    }

    return 0;
}