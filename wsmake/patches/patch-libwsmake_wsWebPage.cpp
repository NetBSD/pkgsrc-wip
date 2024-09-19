$NetBSD: patch-libwsmake_wsWebPage.cpp,v 1.1 2012/12/29 13:14:11 othyro Exp $

Needs system.

--- libwsmake/wsWebPage.cpp.orig	2001-09-02 17:55:57.000000000 +0000
+++ libwsmake/wsWebPage.cpp
@@ -20,6 +20,7 @@
  * For questions and comments, please email the author at:             *
  * mike@wsmake.org                                                     *
  ***********************************************************************/
+#include <cstdlib>
 #include <cassert>
 #include <cerrno>
 #include <ctime>
