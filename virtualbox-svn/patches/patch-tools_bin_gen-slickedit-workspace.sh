$NetBSD$

--- tools/bin/gen-slickedit-workspace.sh.orig	2016-07-10 19:40:35.000000000 +0000
+++ tools/bin/gen-slickedit-workspace.sh
@@ -980,6 +980,7 @@ my_generate_project "REM"           "src
 
 # src/VBox/Additions
 my_generate_project "Add-freebsd"   "src/VBox/Additions/freebsd"            --begin-incs "include" "src/VBox/Additions/freebsd"             --end-includes "src/VBox/Additions/freebsd"
+my_generate_project "Add-netbsd"    "src/VBox/Additions/netbsd"             --begin-incs "include" "src/VBox/Additions/netbsd"             --end-includes "src/VBox/Additions/netbsd"
 my_generate_project "Add-linux"     "src/VBox/Additions/linux"              --begin-incs "include" "src/VBox/Additions/linux"               --end-includes "src/VBox/Additions/linux"
 my_generate_project "Add-os2"       "src/VBox/Additions/os2"                --begin-incs "include" "src/VBox/Additions/os2"                 --end-includes "src/VBox/Additions/os2"
 my_generate_project "Add-solaris"   "src/VBox/Additions/solaris"            --begin-incs "include" "src/VBox/Additions/solaris"             --end-includes "src/VBox/Additions/solaris"
