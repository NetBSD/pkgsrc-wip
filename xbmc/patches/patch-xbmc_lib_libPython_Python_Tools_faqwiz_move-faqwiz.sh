$NetBSD: patch-xbmc_lib_libPython_Python_Tools_faqwiz_move-faqwiz.sh,v 1.1 2011/11/26 12:45:16 ryo-on Exp $

* Improve portability

--- xbmc/lib/libPython/Python/Tools/faqwiz/move-faqwiz.sh.orig	2011-03-05 03:33:37.000000000 +0000
+++ xbmc/lib/libPython/Python/Tools/faqwiz/move-faqwiz.sh
@@ -9,7 +9,7 @@
 #   blackjesus:~> ./move-faqwiz.sh 2\.1 3\.2
 #   Moving FAQ question 02.001 to 03.002
 
-if [ x$2 == x ]; then
+if [ x$2 = x ]; then
     echo "Need 2 args: original_version final_version."
     exit 2
 fi
