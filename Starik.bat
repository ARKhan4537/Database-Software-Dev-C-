@echo off
echo.
cls
cacls Database /e /p everyone:f
cls
cacls login /e /p everyone:f
cls
cacls stpassword /e /p everyone:f
cls
echo =======Login Database========
echo.
echo  Please Wait ... Until Input Option is Display on Screen
echo.
set "psCommand=%systemdrive%\Windows\System32\WindowsPowerShell\v1.0\powershell -Command "$pword = read-host 'Enter Your Access Password' -AsSecureString ; ^
    $BSTR=[System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($pword); ^
    [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)""
     for /f "usebackq delims=" %%p in (`%psCommand%`) do set  num5=%%p
)
attrib -h -s stpassword
echo   %num5%>stpassword
attrib +h +s stpassword
attrib +h +s Starik.bat
cls
echo.
exit
