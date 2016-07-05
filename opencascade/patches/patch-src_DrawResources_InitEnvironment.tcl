$NetBSD$

--- src/DrawResources/InitEnvironment.tcl.orig	2016-04-04 14:58:02.000000000 +0000
+++ src/DrawResources/InitEnvironment.tcl
@@ -30,6 +30,8 @@ proc wokstation {} {
 	return "lin"
     } elseif { [ regexp FreeBSD $LINE_FROM_UNAME ] } {
 	return "bsd"
+    } elseif { [ regexp NetBSD $LINE_FROM_UNAME ] } {
+	return "bsd"
     } elseif { [ regexp Darwin $LINE_FROM_UNAME ] } {
 	return "mac"
     } elseif { [ regexp AIX $LINE_FROM_UNAME ] } {
