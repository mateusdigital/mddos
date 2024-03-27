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
@REM   Project   : dos-programs                                             @REM
@REM   Date      : 2024-03-27                                               @REM
@REM   License   : See project's COPYING.TXT for full info.                 @REM
@REM   Author    : mateus.digital <hello@mateus.digital>                    @REM
@REM   Copyright : mateus.digital - 2024                                    @REM
@REM                                                                        @REM
@REM   Description :                                                        @REM
@REM                                                                        @REM
@REM ---------------------------------------------------------------------- @REM


@REM ---------------------------------------------------------------------------
@REM Make the gcc avaialable.
cd ..
cd tools
cd djgpp
call setenv.bat
cd ..


@REM ---------------------------------------------------------------------------
@REM Navigate to the source folder.
cd ..
cd dos-programs

@REM Create the dos folder
md dos


@REM ---------------------------------------------------------------------------
@REM imgview
cd imgview
call build.bat
mv imgview.exe ../dos
cd ..

@REM ---------------------------------------------------------------------------
@REM palview
cd palview
call build.bat
mv palview.exe ../dos
cd ..

@REM // ------------------------------------------------------------------------
@REM Move the dos folder to the tools
mv dos ../tools