$NetBSD: patch-libwsmake_wsSubTag.cpp,v 1.1 2012/12/29 13:14:11 othyro Exp $

Needs exit and other functions.

--- libwsmake/wsSubTag.cpp.orig	2001-05-30 13:38:56.000000000 +0000
+++ libwsmake/wsSubTag.cpp
@@ -21,6 +21,7 @@
  * mike@wsmake.org                                                     *
  ***********************************************************************/
 #include <cstdio>
+#include <cstdlib>
 #include <cstring>
 
 #include <unistd.h>
