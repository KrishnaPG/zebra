@ECHO OFF
@::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
@::  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  ::
@::  Read the zproject/README.md for information about making permanent changes. ::
@::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
ECHO Generating native JNI headers...
IF EXIST ..\..\..\src\native\include\org_zeromq_zebra_XrapMsg.h GOTO HAVE_XrapMsg
"%JAVA_HOME%\bin\javah.exe" -d ..\..\..\src\native\include -classpath ..\..\..\src\main\java org.zeromq.zebra.XrapMsg
:HAVE_XrapMsg
IF EXIST ..\..\..\src\native\include\org_zeromq_zebra_ZebHandler.h GOTO HAVE_ZebHandler
"%JAVA_HOME%\bin\javah.exe" -d ..\..\..\src\native\include -classpath ..\..\..\src\main\java org.zeromq.zebra.ZebHandler
:HAVE_ZebHandler
IF EXIST ..\..\..\src\native\include\org_zeromq_zebra_XrapTraffic.h GOTO HAVE_XrapTraffic
"%JAVA_HOME%\bin\javah.exe" -d ..\..\..\src\native\include -classpath ..\..\..\src\main\java org.zeromq.zebra.XrapTraffic
:HAVE_XrapTraffic
IF EXIST ..\..\..\src\native\include\org_zeromq_zebra_ZebClient.h GOTO HAVE_ZebClient
"%JAVA_HOME%\bin\javah.exe" -d ..\..\..\src\native\include -classpath ..\..\..\src\main\java org.zeromq.zebra.ZebClient
:HAVE_ZebClient
