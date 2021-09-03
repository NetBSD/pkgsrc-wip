$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- sm.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ sm.cpp
@@ -24,7 +24,6 @@ along with this program.  If not, see <h
 #include <unistd.h>
 #include <stdlib.h>
 #include <pwd.h>
-#include <fixx11h.h>
 #include <kconfig.h>
 
 #include "workspace.h"
