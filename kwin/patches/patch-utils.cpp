$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- utils.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ utils.cpp
@@ -35,8 +35,6 @@ along with this program.  If not, see <h
 #include <QApplication>
 #include <QDebug>
 
-#include <X11/Xlib.h>
-
 #include <stdio.h>
 
 #include "atoms.h"
