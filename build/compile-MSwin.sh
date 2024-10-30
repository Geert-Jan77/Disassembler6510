# This bash script runs on MS Windows in an MSYS shell. 
cd /Projects/Disassembler6510
gcc --version | grep gcc | awk '{print $1" "$7}'
gcc --version | awk '/gcc/ && ($7+0)==11.2{print "Version is correct"}'
windres -i rsc/icon.rc -O coff -o rsc/icon.o
windres -i rsc/dis.rc -O coff -o rsc/dis.o
windres -i rsc/compile.rc -O coff -o rsc/compile.o
windres -i rsc/help.rc -O coff -o rsc/help.o
windres -i rsc/dat.rc -O coff -o rsc/dat.o
gcc src/dis.c rsc/icon.o rsc/dis.o -o "build/dis.exe" `pkg-config --cflags --libs gtk+-3.0`
echo Run: Double click 'dis.exe' - MS Windows executable 
apppath=$(pwd -W)
appname="dis"
shortcutdestinationpath=$startm
shortcutdestinationpath="${shortcutdestinationpath///\\}"
shortcutdestinationpath="${shortcutdestinationpath/c/C}"
printf "Set oWS = WScript.CreateObject(\"WScript.Shell\")\n" > CreateShortcut.vbs
echo "sLinkFile = \"${shortcutdestinationpath}/${appname}.lnk\"" >> CreateShortcut.vbs
echo "Set oLink = oWS.CreateShortcut(sLinkFile)" >> CreateShortcut.vbs
echo "oLink.TargetPath = \"${apppath}/${appname}.exe\"" >> CreateShortcut.vbs
echo "oLink.WorkingDirectory = \"${apppath}\"" >> CreateShortcut.vbs
echo "oLink.Description = \"${appname}\"" >> CreateShortcut.vbs
echo "oLink.IconLocation = \"${apppath}/rsc/${appname}.ico\"" >> CreateShortcut.vbs
echo "oLink.Save" >> CreateShortcut.vbs
cscript -nologo CreateShortcut.vbs
rm CreateShortcut.vbs
gcc src/compile.c rsc/icon.o rsc/compile.o -o "build/compile.exe" `pkg-config --cflags --libs gtk+-3.0`
echo Run: Double click 'compile.exe' - MS Windows executable 
apppath=$(pwd -W)
appname="compile"
shortcutdestinationpath=$startm
shortcutdestinationpath="${shortcutdestinationpath///\\}"
shortcutdestinationpath="${shortcutdestinationpath/c/C}"
printf "Set oWS = WScript.CreateObject(\"WScript.Shell\")\n" > CreateShortcut.vbs
echo "sLinkFile = \"${shortcutdestinationpath}/${appname}.lnk\"" >> CreateShortcut.vbs
echo "Set oLink = oWS.CreateShortcut(sLinkFile)" >> CreateShortcut.vbs
echo "oLink.TargetPath = \"${apppath}/${appname}.exe\"" >> CreateShortcut.vbs
echo "oLink.WorkingDirectory = \"${apppath}\"" >> CreateShortcut.vbs
echo "oLink.Description = \"${appname}\"" >> CreateShortcut.vbs
echo "oLink.IconLocation = \"${apppath}/rsc/${appname}.ico\"" >> CreateShortcut.vbs
echo "oLink.Save" >> CreateShortcut.vbs
cscript -nologo CreateShortcut.vbs
rm CreateShortcut.vbs
gcc src/help.c rsc/icon.o rsc/help.o -o "build/help.exe" `pkg-config --cflags --libs gtk+-3.0`
echo Run: Double click 'help.exe' - MS Windows executable 
apppath=$(pwd -W)
appname="help"
shortcutdestinationpath=$startm
shortcutdestinationpath="${shortcutdestinationpath///\\}"
shortcutdestinationpath="${shortcutdestinationpath/c/C}"
printf "Set oWS = WScript.CreateObject(\"WScript.Shell\")\n" > CreateShortcut.vbs
echo "sLinkFile = \"${shortcutdestinationpath}/${appname}.lnk\"" >> CreateShortcut.vbs
echo "Set oLink = oWS.CreateShortcut(sLinkFile)" >> CreateShortcut.vbs
echo "oLink.TargetPath = \"${apppath}/${appname}.exe\"" >> CreateShortcut.vbs
echo "oLink.WorkingDirectory = \"${apppath}\"" >> CreateShortcut.vbs
echo "oLink.Description = \"${appname}\"" >> CreateShortcut.vbs
echo "oLink.IconLocation = \"${apppath}/rsc/${appname}.ico\"" >> CreateShortcut.vbs
echo "oLink.Save" >> CreateShortcut.vbs
cscript -nologo CreateShortcut.vbs
rm CreateShortcut.vbs
gcc src/dat.c rsc/icon.o rsc/dat.o -o "build/dat.exe" `pkg-config --cflags --libs gtk+-3.0`
echo Run: Double click 'dat.exe' - MS Windows executable 
apppath=$(pwd -W)
appname="dat"
shortcutdestinationpath=$startm
shortcutdestinationpath="${shortcutdestinationpath///\\}"
shortcutdestinationpath="${shortcutdestinationpath/c/C}"
printf "Set oWS = WScript.CreateObject(\"WScript.Shell\")\n" > CreateShortcut.vbs
echo "sLinkFile = \"${shortcutdestinationpath}/${appname}.lnk\"" >> CreateShortcut.vbs
echo "Set oLink = oWS.CreateShortcut(sLinkFile)" >> CreateShortcut.vbs
echo "oLink.TargetPath = \"${apppath}/${appname}.exe\"" >> CreateShortcut.vbs
echo "oLink.WorkingDirectory = \"${apppath}\"" >> CreateShortcut.vbs
echo "oLink.Description = \"${appname}\"" >> CreateShortcut.vbs
echo "oLink.IconLocation = \"${apppath}/rsc/${appname}.ico\"" >> CreateShortcut.vbs
echo "oLink.Save" >> CreateShortcut.vbs
cscript -nologo CreateShortcut.vbs
rm CreateShortcut.vbs

echo Press return key. 
read