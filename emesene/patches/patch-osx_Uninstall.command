$NetBSD: patch-osx_Uninstall.command,v 1.1 2012/12/26 16:40:34 othyro Exp $

Fixes portability failure.

--- osx/Uninstall.command.orig	2012-09-06 09:01:16.000000000 +0000
+++ osx/Uninstall.command
@@ -35,7 +35,7 @@ rm -f "/Users/$USER/Library/Application 
 
 #Remove OS X 10.7 specific files
 os=`sw_vers -productVersion`
-if [[ "$os" == *10.7* ]]
+if [[ "$os" = *10.7* ]]
 then
     rm -rf "/Users/$USER/Library/Saved Application State/org.emesene.emesene.savedState" 
     rm -f "/Users/$USER/Library/Preferences/org.emesene.emesene.plist.lockfile"
@@ -50,11 +50,11 @@ rm -rf "/Users/$USER/.config/gtk-2.0" 
 echo "Remove user settings? Type 'yes' if you wish to remove them. If not type anything else..."
 read doremoveusersettings
 
-if [ "$doremoveusersettings" == "yes" ]
+if [ "$doremoveusersettings" = "yes" ]
 then
     rm -rf "/Users/$USER/Library/Application Support/emesene2"
 else
     continue
 fi
 
-echo "emesene has been successfully uninstalled..."
\ No newline at end of file
+echo "emesene has been successfully uninstalled..."
