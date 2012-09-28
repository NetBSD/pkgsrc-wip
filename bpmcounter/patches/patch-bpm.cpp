$NetBSD: patch-bpm.cpp,v 1.1 2012/09/28 03:19:43 othyro Exp $

Needs several functions from stdlib and string.

--- bpm.cpp.orig	2007-01-19 01:56:44.000000000 +0000
+++ bpm.cpp
@@ -22,6 +22,8 @@ BPMCounter; if not, write to the Free So
 #include <math.h>
 #include <sys/time.h>
 #include <unistd.h>
+#include <stdlib.h>
+#include <string.h>
 
 using namespace std;
 
