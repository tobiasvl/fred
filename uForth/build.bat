@echo off
\mingw\bin\asw -L uforth.asm
if errorlevel 1 goto end
\mingw\bin\p2bin -r 0-1023 -l 0 uforth.p
python makedist.py

copy /Y uforth.core ..\games\jackpot
copy /Y uforth.core ..\games\deduce
copy /Y uforth.core ..\games\life
copy /Y uforth.core ..\games\spacewar
copy /Y uforth.core ..\games\match
copy /Y uforth.core ..\games\acey
copy /Y uforth.core ..\games\speedway

:end