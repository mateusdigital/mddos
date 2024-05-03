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
cd apps

@REM Create the dos folder
set "build_dir=build";
if not exist "%build_dir%" (
    md %build_dir%
)


@REM @REM ---------------------------------------------------------------------------
@REM @REM imgview
@REM cd imgview
@REM call build.bat
@REM mv imgview.exe ../dos
@REM cd ..

@REM @REM ---------------------------------------------------------------------------
@REM @REM palview
@REM cd palview
@REM call build.bat
@REM mv palview.exe ../dos
@REM cd ..

@REM ---------------------------------------------------------------------------
@REM mouse
cd mouse
call build.bat
move /Y mouse.exe ../%build_dir%
cd ..