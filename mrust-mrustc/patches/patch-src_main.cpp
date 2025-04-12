$NetBSD$

--- src/main.cpp.orig	2022-08-14 04:09:16.000000000 +0000
+++ src/main.cpp
@@ -37,7 +37,7 @@
 # include <DbgHelp.h>
 #endif
 
-TargetVersion	gTargetVersion = TargetVersion::Rustc1_29;
+TargetVersion	gTargetVersion = TargetVersion::Rustc1_54;
 
 struct ProgramParams
 {
