$NetBSD: patch-bootstrap.sh,v 1.2 2024/05/07 15:30:00 dkazankov Exp $

Fix out-of-tree bootstrap build

--- bootstrap.sh.orig	2023-10-09 21:31:11.000000000 +0300
+++ bootstrap.sh	2024-05-07 15:49:52.531377055 +0300
@@ -90,13 +90,13 @@
 UName=`uname | cut -b -5`
 PutUsage=gpr/src/gpr-util-put_resource_usage
 
-rm -f ${PutUsage}.adb
+rm -f ${srcdir}/${PutUsage}.adb
 
 if [ "$UName" = "CYGWI" ] || [ "$UName" = "MINGW" ]
 then
-	cp ${PutUsage}__null.adb ${PutUsage}.adb
+	cp ${srcdir}/${PutUsage}__null.adb ${srcdir}/${PutUsage}.adb
 else
-	ln -s $PWD/${PutUsage}__unix.adb ${PutUsage}.adb
+	ln -s ${srcdir}/${PutUsage}__unix.adb ${srcdir}/${PutUsage}.adb
 fi
 
 # Build
