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
//  File      : mddos.c                                                       //
//  Project   : mddos                                                         //
//  Date      : 2024-03-27                                                    //
//  License   : See project's COPYING.TXT for full info.                      //
//  Author    : mateus.digital <hello@mateus.digital>                         //
//  Copyright : mateus.digital - 2024                                         //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef __MDDOS_C__
#define __MDDOS_C__

// -----------------------------------------------------------------------------
#include "mddos.h"

//
// IMG
//

// -----------------------------------------------------------------------------
bool LoadImg(FILE *fp, IMG *img)
{
  fread(&img->width,  sizeof(u16), 1, fp);
  fread(&img->height, sizeof(u16), 1, fp);

  //
  img->data = malloc(sizeof(u8) * img->width * img->height);
  if(!img->data) {
    return false;
  }

  fread(img->data, sizeof(u8), img->width * img->height, fp);
  return true;
}


//
// File
//

// -----------------------------------------------------------------------------
u32 GetFileSize(FILE *fp)
{
  u32 curr = ftell(fp);
  fseek(fp, 0, SEEK_END);
  u32 end = ftell(fp);
  fseek(fp, curr, SEEK_SET);

  return end;
}

//
// Graphics
//

// -----------------------------------------------------------------------------
char VIRTUAL_SCREEN[SCREEN_HEIGHT * SCREEN_WIDTH];

// -----------------------------------------------------------------------------
void SetVGA256()
{
  __dpmi_regs regs;
  regs.x.ax = 0x13;
  __dpmi_int(0x10, &regs);
  return;
}

// -----------------------------------------------------------------------------
void SetTextMode()
{
  __dpmi_regs regs;
  regs.x.ax = 0x03;
  __dpmi_int(0x10, &regs);
  return;
}


//
// Mouse
//

// -----------------------------------------------------------------------------
#define MOUSE_INT 0x33

// -----------------------------------------------------------------------------
static bool _gMouseIsInitialized = false;

// -----------------------------------------------------------------------------
bool InitializeMouse()
{
  _go32_dpmi_seginfo old_isr;

  __dpmi_regs r;
  r.x.ax = 0x00;
  __dpmi_int(MOUSE_INT, &r);

  if (r.x.ax == 0) {
    return false;
  }

  _gMouseIsInitialized = true;
}

// -----------------------------------------------------------------------------
bool MouseIsInitialized()
{
    return _gMouseIsInitialized;
}

// -----------------------------------------------------------------------------
bool GetMousePosition(uint *x, uint *y, uint *buttonState)
{
  if(!_gMouseIsInitialized) {
    return false;
  }

  __dpmi_regs r;
  r.x.ax = 0x03;
  __dpmi_int(MOUSE_INT, &r);

  *x = r.x.cx;            // X position
  *y = r.x.dx;            // Y position
  *buttonState = r.x.bx;  // Button state

  return true;
}


//
// PAL
//

// -----------------------------------------------------------------------------
bool LoadPal(FILE *fp, PAL *pal)
{
  fread(&pal->count,  sizeof(u16), 1, fp);

  //
  pal->colors = malloc(sizeof(RGB) * pal->count);
  if(!pal->colors) {
    return false;
  }

  fread(pal->colors, sizeof(RGB), pal->count, fp);
  return true;
}

// -----------------------------------------------------------------------------
void SetPaletteColor(u8 index, u8 red, u8 green, u8 blue)
{
  outportb(0x3C8, index); // Set the color index register
  outportb(0x3C9, red  );
  outportb(0x3C9, green);
  outportb(0x3C9, blue );
}

// -----------------------------------------------------------------------------
void SetPaletteWithPal(PAL *pal)
{
  for(u16 i = 0; i < pal->count; ++i) {
    RGB *rgb = &pal->colors[i];
    SetPaletteColor(i, rgb->r, rgb->g, rgb->b);
  }
}

//
// Time
//

// -----------------------------------------------------------------------------
unsigned long long get_milliseconds()
{
  struct timeb tb;
  ftime(&tb);
  return ((unsigned long long)tb.time * 1000) + tb.millitm;
}


#endif  // __MDDOS_C__