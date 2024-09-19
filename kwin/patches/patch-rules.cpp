$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- rules.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ rules.cpp
@@ -20,7 +20,6 @@ along with this program.  If not, see <h
 
 #include "rules.h"
 
-#include <fixx11h.h>
 #include <kconfig.h>
 #include <KXMessages>
 #include <QRegExp>
