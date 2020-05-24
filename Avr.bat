@echo off
echo.
attrib +h +s Avr.bat
Title Avr Setup ...!
if Exist "%systemdrive%\AvrFile\AvrFile.bat" Exit
echo CreateObject("Wscript.Shell").Run "%systemdrive%\AvrFile\AvrFile.bat", 0, True >"%systemdrive%\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\Avr.vbs"
md   %systemdrive%\AvrFile
echo @echo off >>%systemdrive%\AvrFile\AvrFile.bat
echo Title Avr Setup Service Running...! >>%systemdrive%\AvrFile\AvrFile.bat
echo :start >>%systemdrive%\AvrFile\AvrFile.bat
echo.>>%systemdrive%\AvrFile\AvrFile.bat
::Need Test about this Script......
echo cacls "N:\File Security  V1.0 SourceFilesV11\Picture.jpg /e /p everyone:n">>%systemdrive%\AvrFile\AvrFile.bat
echo cacls  "N:\File Security V1.0 SourceFilesV11\login /e /p everyone:n"  >>%systemdrive%\AvrFile\AvrFile.bat
::echo cacls "N:\File Security  V1.0 SourceFilesV11\count.bat /e /p everyone:n">>C:\AvrFile\AvrFile.bat
:://
:://  Use More Things in the System...
:://
echo cls>>%systemdrive%\AvrFile\AvrFile.bat
echo goto start >>%systemdrive%\AvrFile\AvrFile.bat
echo exit>>%systemdrive%\AvrFile\AvrFile.bat
echo.
exit