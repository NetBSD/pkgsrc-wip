$NetBSD: patch-mathmlps_main.cc,v 1.2 2015/02/11 12:03:53 nros Exp $
str* needs cstring
Fix build on gcc 4.7 and later
--- mathmlps/main.cc.orig	2007-08-17 10:02:46.000000000 +0000
+++ mathmlps/main.cc
@@ -21,6 +21,8 @@
 #include <cassert>
 #include <fstream>
 
+#include <cstring>
+
 #include <popt.h>
 
 // needed for old versions of GCC, must come before String.hh!
@@ -391,9 +393,9 @@ main(int argc, const char* argv[])
 #else
       SMS sms(logger, view);
       sms.process(argv[optind]);
+      optind++;
 #endif
 
-      optind++;
     }
 
   poptFreeContext(ctxt);
