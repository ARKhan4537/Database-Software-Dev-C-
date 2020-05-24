@echo off
echo.
attrib +h +s count.bat
for /f "tokens=* delims=" %%x in (count) do (
 set /a var=%%x+1
 
)
echo %var% > count
echo AR%var%>CounterID
exit