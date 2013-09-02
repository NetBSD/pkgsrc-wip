$NetBSD: patch-gen-project.ksh,v 1.1 2013/09/02 19:08:24 thomasklausner Exp $

Adds code to a Makefile fragment that causes errors (missing "on" target)
as well as being without sense.

--- gen-project.ksh.orig	2010-10-27 12:30:16.000000000 +0000
+++ gen-project.ksh
@@ -91,7 +91,7 @@ extract_compiler_def ()
     typeset -u L_osarchi
     typeset -u L_symbName
     typeset -u L_debugMode=${DEBUG_MODE}
-    L_osname=`uname -s | tr '-' '_' | tr '.' '_' | tr '/' '_' `
+    L_osname=LINUX
     L_osarchi=`uname -m | tr '-' '_' | tr '.' '_' | tr '/' '_' `
 
     # Compiler definition
@@ -382,9 +382,9 @@ fi
 echo "# File: ${BUILD_PROJECT}" >${BUILD_PROJECT}
 if test -n "${DEBUG_MODE}"
 then
-  echo "Debug Mode: on" >>${BUILD_PROJECT}
+  echo "# Debug Mode: on" >>${BUILD_PROJECT}
 else
-  echo "Debug Mode: on" >>${BUILD_PROJECT}
+  echo "# Debug Mode: on" >>${BUILD_PROJECT}
 fi
 
 echo "" >>${BUILD_PROJECT}
@@ -395,8 +395,8 @@ determine_generation >>${BUILD_PROJECT}
 echo "" >>${BUILD_PROJECT}
 
 echo "# Compiler definitions" > ${BUILD_COMPILER_FILE}
-echo "# OS Name        : `uname -s` " >> ${BUILD_COMPILER_FILE}
-echo "# OS Architecture: `uname -s` arch: `uname -m`" >> ${BUILD_COMPILER_FILE}
+echo "# OS Name        : Linux " >> ${BUILD_COMPILER_FILE}
+echo "# OS Architecture: Linux arch: `uname -m`" >> ${BUILD_COMPILER_FILE}
 if test -n "${DEBUG_MODE}"
 then
   echo "# Debug Mode     : on" >>${BUILD_COMPILER_FILE}
