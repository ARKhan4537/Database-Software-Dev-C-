@echo off
echo.
attrib +h +s CreatePasswordStarik.bat
Title Create Login Password..! 
:start
cls
cacls Picture.jpg /e /p everyone:f
cls
cacls login /e /p everyone:f
cls
cacls stpassword /e /p everyone:f
cls
echo =======Create Password========
echo.
echo  Please Wait ... Until Input Option is Display on Screen
echo.
echo.
echo  Password Is Not Created ... Please Create Password First
echo.
set "psCommand=powershell -Command "$pword = read-host 'Enter New Password' -AsSecureString ; ^
    $BSTR=[System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($pword); ^
    [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)""
     for /f "usebackq delims=" %%p in (`%psCommand%`) do set  num5=%%p
)
echo.
echo.


set "psCommand=powershell -Command "$pword = read-host 'Confirm New Password' -AsSecureString ; ^
    $BSTR=[System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($pword); ^
    [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)""
     for /f "usebackq delims=" %%p in (`%psCommand%`) do set  num6=%%p
)
if %num5%==%num6% goto created
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo Password Did Not Match..Please Enter Again...!
echo.
echo.
pause
cls
goto start
exit
:created
attrib -h -s crpassword
echo   %num5%>crpassword
echo.
attrib +h +s crpassword
attrib +h +s CreatePasswordStarik.bat
cls
echo.
exit