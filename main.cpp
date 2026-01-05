#define _USE_MATH_DEFINES

#include <iostream>
#include <windows.h> // For console settings
//#include <unistd.h> // For usleep
#include <signal.h> // To intercept kill ctrl+c
#include <cmath>
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "Light.h"
#include "Animation.h"

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void SetCursorToHomePosition()
{
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    SetCursorToHomePosition();
}

void SetCursorVisible(bool visible)
{
    if(visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

void OnKill(int signum)
{
    ClearConsole();
    SetCursorVisible(true);
    exit(signum);
}

int main(int argc, char** argv)
{
    signal(SIGINT, OnKill);
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(settings);
    Light light(settings);
    
    mesh.GenerateTorus(settings.GetTorusMajorRadius(), settings.GetTorusMinorRadius());
    if (settings.GetInitialRotationY() != 0.f) mesh.Rotate(settings.GetInitialRotationY(), Axis::Y);
    if (settings.GetInitialRotationX() != 0.f) mesh.Rotate(settings.GetInitialRotationX(), Axis::X);
    if (settings.GetInitialRotationZ() != 0.f) mesh.Rotate(settings.GetInitialRotationZ(), Axis::Z);

    Animation floatAnimation(mesh, settings);

    while(true)
    {
        SetCursorToHomePosition();
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::X);
        mesh.Rotate(settings.GetMeshRotationYPerFrame(), Axis::Y);
        mesh.Rotate(settings.GetMeshRotationZPerFrame(), Axis::Z);

        floatAnimation.Update();

        screen.Display(mesh, light, floatAnimation.GetCurrentOffset(), floatAnimation.GetOrbitOffset());

        //usleep(settings.GetFrameDuration());
		Sleep(settings.GetFrameDuration() / 1000);
    }
    return 0;
}