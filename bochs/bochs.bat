@echo off

::Change this path to the location where bochs is installed
set BXSHARE=C:\...\bochs

::First test to see if we are on NT or similar OS by seeing 
::if the ampersand is interpreted as a command separator
> script echo 1234&rem
type script | find "rem" script
if not errorlevel 1 goto WIN9X

echo Running under NT, 2000, XP
del script
::Get the current batch file's short path
for %%x in (%0) do set BatchPath=%%~dpsx
for %%x in (%BatchPath%) do set BatchPath=%%~dpsx
echo BatchPath = %BatchPath%
goto TEST

:WIN9X
echo Running under Win9X, ME
::An assumption is made that the batch file is run by double-clicking.
::This means %0 is a short file name and path with no quotes
::Test for quotes by quoting %0
if not exist "%0" goto ERROR

echo e 100 "set BatchPath="> script
echo rcx>> script
echo e>> script
echo n ~temp.bat>> script
echo w>> script
echo q>>script
debug < script > nul
del script
::Change to the batch file's drive
%0\
::Change to the batch file's directory
cd %0\..
::Use the TRUENAME command to get the short path
truename | find ":" >> ~temp.bat
call ~temp.bat
del ~temp.bat
set BatchPath=%BatchPath%\
echo BatchPath = %BatchPath%
goto TEST

:TEST
if not exist %1 goto ERROR
%BXSHARE%/bochs.exe -f %BatchPath%bochsrc.txt floppya:1_44=%1,status=inserted
goto END

:ERROR
echo File %1 does not exist
echo using standard image %BatchPath%bootdisk.img
%BXSHARE%/bochs.exe -f %BatchPath%bochsrc.txt floppya:1_44=%BatchPath%bootdisk.img,status=inserted

:END
