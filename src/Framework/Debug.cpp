#include "Debug.h"

void LogError(char *where, char *error, char *FILE, int LINE)
{
    SDL_LogError(0, " %s %s line: %d : %s\n", where, FILE, LINE, error);
}