$NetBSD$

Fix portability issues

--- icon-theme/changeFillColor.sh.orig	2020-01-31 20:25:37.000000000 +0000
+++ icon-theme/changeFillColor.sh
@@ -2,7 +2,7 @@
 
 THEME=${1}
 COLOR=${2}
-if [ "z" == "${THEME}z" ] || [ "z" == "${COLOR}z" ]; then
+if [ "z" = "${THEME}z" ] || [ "z" = "${COLOR}z" ]; then
   echo "Usage: changeFillColor.sh <ThemeDir> <HexColor>"
   return 1;
 fi
