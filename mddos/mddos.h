//~---------------------------------------------------------------------------//
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
//  File      : mddos.h                                                       //
//  Project   : mddos                                                         //
//  Date      : 2024-03-27                                                    //
//  License   : See project's COPYING.TXT for full info.                      //
//  Author    : mateus.digital <hello@mateus.digital>                         //
//  Copyright : mateus.digital - 2024                                         //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef __MDDOS_H__
#define __MDDOS_H__

// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

#include <dos.h>
#include <conio.h>

#include <pc.h>
#include <go32.h>
#include <dpmi.h>
#include <sys/farptr.h>
#include <sys/nearptr.h>
#include <sys/timeb.h>

//
// Types
//

// -----------------------------------------------------------------------------
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef unsigned int uint;

typedef u8 bool;

#define true (!(0))
#define false (0)

//
// IMG
//

// -----------------------------------------------------------------------------
typedef struct tagIMG {
  u16 width;
  u16 height;
  u8 *data;
} IMG;

// -----------------------------------------------------------------------------
bool LoadImg(FILE *fp, IMG *img);


//
// File
//

// -----------------------------------------------------------------------------
u32 GetFileSize(FILE *fp);


//
// Graphics
//

// -----------------------------------------------------------------------------
#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 200

// -----------------------------------------------------------------------------
void SetVGA256  ();
void SetTextMode();

// -----------------------------------------------------------------------------
extern char VIRTUAL_SCREEN[SCREEN_HEIGHT * SCREEN_WIDTH];

#define VirtualScreenXY(x, y) \
  VIRTUAL_SCREEN[(y) * SCREEN_WIDTH + (x)]

#define BlitVirtualScreen() \
  dosmemput(VIRTUAL_SCREEN, sizeof(VIRTUAL_SCREEN), 0xA0000)

//
// Keyboard
//

// -----------------------------------------------------------------------------
#define KEYBOARD_VALUE_CONTROL_C 3


//
// Mouse
//

// -----------------------------------------------------------------------------
bool InitializeMouse();
bool MouseIsInitialized();
bool GetMousePosition(uint *x, uint *y, uint *buttonState);


//
// PAL
//

// -----------------------------------------------------------------------------
typedef struct tagRGB {
  u8 r, g, b;
} RGB;

typedef struct tagPAL {
  u16 count;
  RGB *colors;
} PAL;

// -----------------------------------------------------------------------------
bool LoadPal(FILE *fp, PAL *pal);

// -----------------------------------------------------------------------------
void SetPaletteColor(u8 index, u8 red, u8 green, u8 blue);

// -----------------------------------------------------------------------------
void SetPaletteWithPal(PAL *pal);


//
// Time
//

// -----------------------------------------------------------------------------
unsigned long long get_milliseconds();

#define DESIRED_FRAME_RATE 30
#define DESIRED_FRAME_TIME (1000 / DESIRED_FRAME_RATE)


#endif  // __MDDOS_H__