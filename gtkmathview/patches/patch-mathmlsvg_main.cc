$NetBSD: patch-mathmlsvg_main.cc,v 1.2 2015/02/11 12:03:53 nros Exp $
* str* functions need cstring
* fix build on gcc 4.7 and later
--- mathmlsvg/main.cc.orig	2007-08-17 10:02:46.000000000 +0000
+++ mathmlsvg/main.cc
@@ -21,6 +21,8 @@
 #include <cassert>
 #include <fstream>
 
+#include <cstring>
+
 #include <popt.h>
 
 // needed for old versions of GCC, must come before String.hh!
@@ -360,9 +362,8 @@ main(int argc, const char* argv[])
 #else
       SMS sms(logger, view);
       sms.process(argv[optind]);
-#endif
-
       optind++;
+#endif
     }
 
   poptFreeContext(ctxt);
