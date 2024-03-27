@REM ~--------------------------------------------------------------------- @REM
@REM                                *       +                               @REM
@REM                          '                  |                          @REM
@REM                      ()    .-.,="``"=.    - o -                        @REM
@REM                            '=/_       \     |                          @REM
@REM                         *   |  '=._    |                               @REM
@REM                              \     `=./`,        '                     @REM
@REM                           .   '=.__.=' `='      *                      @REM
@REM                  +                         +                           @REM
@REM                       O      *        '       .                        @REM
@REM                                                                        @REM
@REM   File      : build.bat                                                @REM
@REM   Project   : imgview                                                  @REM
@REM   Date      : 2024-03-27                                               @REM
@REM   License   : See project's COPYING.TXT for full info.                 @REM
@REM   Author    : mateus.digital <hello@mateus.digital>                    @REM
@REM   Copyright : mateus.digital - 2024                                    @REM
@REM                                                                        @REM
@REM   Description :                                                        @REM
@REM                                                                        @REM
@REM ---------------------------------------------------------------------- @REM

gcc -I../../ ../../mddos/mddos.c main.c -o imgview.exe
