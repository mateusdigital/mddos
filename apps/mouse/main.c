//----------------------------------------------------------------------------//
//                               *       +                                    //
//                         '                  |                               //
//                     ()    .-.,="``"=.    - o -                             //
//                           '=/_       \     |                               //
//                        *   |  '=._    |                                    //
//                             \     `=./`,        '                          //
//                          .   '=.__.=' `='      *                           //
//                 +                         +                                //
//                      O      *        '       .                             //
//                                                                            //
//  File      : main.c                                                        //
//  Project   : mouse                                                         //
//  Date      : 2024-05-03                                                    //
//  License   : See project's COPYING.TXT for full info.                      //
//  Author    : mateus.digital <hello@mateus.digital>                         //
//  Copyright : mateus.digital - 2024                                         //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//----------------------------------------------------------------------------//

// -----------------------------------------------------------------------------
#include "mddos/mddos.h"


// -----------------------------------------------------------------------------
#define PROGRAM_NAME            "mouse"
#define PROGRAM_VERSION         "1.0.0"
#define PROGRAM_AUTHOR          "mateus.digital"
#define PROGRAM_EMAIL           "hello@mateus.digital"
#define PROGRAM_COPYRIGHT_YEARS "2024"
#define PROGRAM_WEBSITE         "https://mateus.digital"


// -----------------------------------------------------------------------------
void help()
{
    printf("Usage:\n");
    printf("   %s\n", PROGRAM_NAME);
}

// -----------------------------------------------------------------------------
void version()
{
    printf("%s - %s - %s <%s>\n", PROGRAM_NAME, PROGRAM_VERSION, PROGRAM_AUTHOR, PROGRAM_EMAIL);
    printf("Copyright (c) %s - %s\n", PROGRAM_COPYRIGHT_YEARS, PROGRAM_AUTHOR);
    printf("This is a free software (GPLv3) - Share/Hack it\n");
    printf("Check %s for more :)\n", PROGRAM_WEBSITE);
}


// -----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    // Command line.
    for(int i = 0; i < argc; ++i) {
      if(strcmp(argv[1], "--help") == 0) {
          help();
          exit(0);
      }
      else if(strcmp(argv[1], "--version") == 0) {
          version();
          exit(0);
      }
    }


  uint x, y, buttonState;

  if(!InitializeMouse()) {
    printf("Error initializing mouse - Exiting...");
    exit(1);
  }

  while(true) {
    GetMousePosition(&x, &y, &buttonState);
    printf("Mouse Position: X=%d, Y=%d, Buttons=%d\n", x, y, buttonState);

    if(kbhit()) {
      if (getch() == KEYBOARD_VALUE_CONTROL_C) {
        printf("\nCtrl+C pressed. Exiting loop.\n");
        break; // Exit the loop
      }
    }
  }

  return 0;
}
