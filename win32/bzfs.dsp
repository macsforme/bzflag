# Microsoft Developer Studio Project File - Name="bzfs" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=bzfs - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "bzfs.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "bzfs.mak" CFG="bzfs - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "bzfs - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "bzfs - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "bzfs - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /vmg /GX /O2 /I "..\include" /I "..\src\game" /D "NDEBUG" /D "_CONSOLE" /D "WIN32" /D "_MBCS" /D VERSION=10801001 /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 winmm.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "bzfs - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "bzfs___Win32_Debug"
# PROP BASE Intermediate_Dir "bzfs___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin\Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /vmg /GX /ZI /Od /I "..\include" /I "..\src\game" /D "_DEBUG" /D "_CONSOLE" /D "WIN32" /D "_MBCS" /D VERSION=10801001 /Fd"Debug/bzfs.pdb" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "bzfs - Win32 Release"
# Name "bzfs - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\bzfs\bzfs.cxx
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldFile.cxx
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldInfo.cxx
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldRegions.cxx
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldStandardRandom.cxx
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldStandardTeam.cxx
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\Address.h
# End Source File
# Begin Source File

SOURCE="C:\Program Files\Microsoft Visual Studio\VC98\Include\BASETSD.H"
# End Source File
# Begin Source File

SOURCE=..\include\bzfio.h
# End Source File
# Begin Source File

SOURCE=..\include\CallbackList.h
# End Source File
# Begin Source File

SOURCE=..\include\common.h
# End Source File
# Begin Source File

SOURCE=..\include\ConfigFileManager.h
# End Source File
# Begin Source File

SOURCE=..\include\ConfigFileReader.h
# End Source File
# Begin Source File

SOURCE=..\src\game\Flag.h
# End Source File
# Begin Source File

SOURCE=..\src\game\global.h
# End Source File
# Begin Source File

SOURCE=..\include\math3D.h
# End Source File
# Begin Source File

SOURCE=..\include\mathr.h
# End Source File
# Begin Source File

SOURCE=..\include\Pack.h
# End Source File
# Begin Source File

SOURCE=..\src\game\Ping.h
# End Source File
# Begin Source File

SOURCE=..\include\PlatformFactory.h
# End Source File
# Begin Source File

SOURCE=..\src\game\Protocol.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\RegionManagerBase.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\RegionManagerFlagSpawn.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\RegionManagerObstacle.h
# End Source File
# Begin Source File

SOURCE=..\include\RegionReader.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\RegionReaderBase.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\RegionReaderFlagSpawn.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\RegionReaderObstacle.h
# End Source File
# Begin Source File

SOURCE=..\include\Shape.h
# End Source File
# Begin Source File

SOURCE=..\include\ShapeBox.h
# End Source File
# Begin Source File

SOURCE=..\include\StateDatabase.h
# End Source File
# Begin Source File

SOURCE=..\src\game\Team.h
# End Source File
# Begin Source File

SOURCE=..\include\TimeBomb.h
# End Source File
# Begin Source File

SOURCE=..\include\TimeKeeper.h
# End Source File
# Begin Source File

SOURCE=..\include\TransformableShape.h
# End Source File
# Begin Source File

SOURCE=..\include\TransformedShape.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldFile.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldInfo.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldRegions.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldStandardRandom.h
# End Source File
# Begin Source File

SOURCE=..\src\bzfs\WorldStandardTeam.h
# End Source File
# Begin Source File

SOURCE=..\include\XMLTree.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project