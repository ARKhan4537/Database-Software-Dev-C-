@echo off
echo.
Title Wrong Passwords..!
for /f "Delims=" %%a in (stpassword) do (
set qwe=%%a
)
echo.>>WrongPasswords
echo  %qwe% With Date::%date% And Time::%time% >>WrongPasswords
echo.>>WrongPasswords
attrib +h +s WrongPassword.bat
exit