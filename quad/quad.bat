@echo off
:NOTTOP
REM #################### - UPDATE YOUR FOLDER LOCATIONS HERE - ####################
REM #### Enter the location you want results stored
REM #### set reportsfolder=C:\Reports 				!!EXAMPLE!!
set reportsfolder=
REM #### Enter the location your DayZ Server Logs
REM #### set dayzrootlog=C:\DayZ\server\0\logs\		!!EXAMPLE!!
set dayzrootlog=
IF /I EXIST testing GOTO TESTING
:QMENU
CLS
echo.
echo   _____ _____ _____ ____  
echo  ^|     ^|  ^|  ^|  _  ^|    \ 
echo  ^|  ^|  ^|  ^|  ^|     ^|  ^|  ^|
echo  ^|__  _^|_____^|__^|__^|____/ 
echo     ^|__^|           
TITLE quad
IF /I EXIST testing TITLE quad - (Test Mode)
IF /I EXIST testing set reportsfolder=Reports\
IF /I EXIST testing set dayzrootlog=testing\server\logs
echo.
echo  ### Select what logs to search through:
echo.
echo  DA. DayZ Player Damage
echo.
echo  CH. Game Chat Search
echo.
REM echo  C. 
REM echo.
REM echo  D. 
REM echo.
echo  EX. Close this window
IF NOT EXIST "%reportsfolder%" mkdir "reportsfolder%"
echo.
set /p whatarewedoingboss= Select an option: 
echo.
IF /I %whatarewedoingboss%==DA GOTO PLDMG
IF /I %whatarewedoingboss%==CH GOTO CHATSEROP
IF /I %whatarewedoingboss%==EX GOTO EXITTH
echo.
echo  Please select an option listed
echo.
PAUSE
CLS
GOTO QMENU
:PLDMG
CLS
echo.
echo  ## Player Damage
set searchedin=player-damage
REM ### Update the folder location for your server logs
echo  # Possible search strings:
echo.
echo  'DEAD' will look for results where players died
echo  'PVP' will look for results where a player attacked another
echo  Searching an IGN or GUID will find all damage to or by that player
echo  ''4. ign to if that player was involved in PvP
echo.
IF /I EXIST testing echo Example search strings:
IF /I EXIST testing echo (mountain, bubba, lunar, reese, slayer, bill)
echo.
set /p playerdamage= Search for: 
IF %playerdamage%==PVP set
echo.
echo Searching for "%playerdamage%" . . .
Powershell "Get-ChildItem -Path '%dayzrootlog%\*.ADM' -recurse | Select-String -Pattern '%playerdamage%' > reports\%searchedin%-%playerdamage%.txt"
REM Powershell "Get-ChildItem -Path '%dayzrootlog%\*.ADM' -recurse | Select-String -Pattern '%playerdamage%' > reports\%searchedin%-%playerdamage%.txt"
REM Powershell "Get-ChildItem -Path '%Temp%\QaD\%searchedin%-hitby.txt' | Select-String -Pattern '%playerdamage%' > '%reportsfolder%\%searchedin%-%playerdamage%.txt'"
GOTO ENDING
:CHATSEROP
CLS
echo.
echo  ## Game Chat Search
echo.
set searchedin=gamechat
REM ### Update the folder location for your server logs
REM set workingfolder=
echo  # Search for word, phrase, or player
echo.
set /p ignchatsearch= Paste or type string here: 
Powershell "Get-ChildItem -Path '%dayzrootlog%\logs\*.ADM' -recurse | Select-String -Pattern 'Chat' > '%Temp%\QaD\%searchedin%-chatdump.txt'"
REM Select-String -pattern "chat" | Format-Table -Autosize LineNumber,Line -GroupBy Path -HideTableHeaders
echo Filtering by "%ignchatsearch%" . . .
Powershell "Get-ChildItem -Path '%Temp%\QaD\%searchedin%-chatdump.txt' | Select-String -Pattern '%ignchatsearch%' > '%reportsfolder%\%searchedin%-%ignchatsearch%.txt'"
IF EXIST "%Temp%\QaD\%searchedin%-chatdump.txt" DEL "%Temp%\QaD\%searchedin%-chatdump.txt"
echo. 
GOTO ENDING
:COT
CLS
echo.
echo  ## Community Online Tools (COT)
echo.
set searchedin=cot
REM ### Update the folder location for your server logs
REM set workingfolder=
echo  # Paste SteamID for your desired player below
echo.
set /p cotplayersearch= SteamID: 
Powershell "Get-ChildItem -Path '%dayzrootlog%\profiles\CommunityOnlineTools\Logs\*.log' -recurse | Select-String -Pattern '%cotplayersearch%' > '%reportsfolder%\%searchedin%-%cotplayersearch%.txt'"
echo Filtering by "%cotplayersearch%" . . .
echo.
GOTO ENDING
:ENDING
GOTO QMENU
:CLOSETH
EXIT
:TESTING
set reportsfolder=reports\
set dayzrootlog=testing\server\logs
set dayzprofiles=testing\server\profiles
set modone=breachingcharge
set modtwo=codelock
set modthree=communityonlinetools
GOTO QMENU
:ENDING
GOTO QMENU
:EDITPROMPT
echo.
echo #################### - VARIABLE SETTINGS - ####################
echo.
echo  You still need to input your dayz root folder!
echo.
echo  %dayzrootlog%
echo.
echo  Please edit this file and look for the banner to update this locations
echo.
PAUSE
EXIT