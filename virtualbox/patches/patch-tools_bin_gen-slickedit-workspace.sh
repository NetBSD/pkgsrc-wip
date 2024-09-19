$NetBSD$

--- tools/bin/gen-slickedit-workspace.sh.orig	2016-03-04 19:31:11.000000000 +0000
+++ tools/bin/gen-slickedit-workspace.sh
@@ -860,6 +860,7 @@ my_generate_project "REM"           "src
 
 # src/VBox/Additions
 my_generate_project "Add-freebsd"   "src/VBox/Additions/freebsd"            --begin-incs "include" "src/VBox/Additions/freebsd"             --end-includes "src/VBox/Additions/freebsd"
+my_generate_project "Add-netbsd"    "src/VBox/Additions/netbsd"             --begin-incs "include" "src/VBox/Additions/netbsd"             --end-includes "src/VBox/Additions/netbsd"
 my_generate_project "Add-linux"     "src/VBox/Additions/linux"              --begin-incs "include" "src/VBox/Additions/linux"               --end-includes "src/VBox/Additions/linux"
 my_generate_project "Add-os2"       "src/VBox/Additions/os2"                --begin-incs "include" "src/VBox/Additions/os2"                 --end-includes "src/VBox/Additions/os2"
 my_generate_project "Add-solaris"   "src/VBox/Additions/solaris"            --begin-incs "include" "src/VBox/Additions/solaris"             --end-includes "src/VBox/Additions/solaris"
@@ -1037,4 +1038,3 @@ my_generate_usercpp_h
 
 
 echo "done"
-
