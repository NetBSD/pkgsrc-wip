$NetBSD$

--- lib/fuzzer/FuzzerUtilLinux.cpp.orig	2017-08-21 23:23:37.000000000 +0000
+++ lib/fuzzer/FuzzerUtilLinux.cpp
@@ -9,7 +9,7 @@
 // Misc utils for Linux.
 //===----------------------------------------------------------------------===//
 #include "FuzzerDefs.h"
-#if LIBFUZZER_LINUX
+#if LIBFUZZER_LINUX || LIBFUZZER_NETBSD
 
 #include <stdlib.h>
 
@@ -21,4 +21,4 @@ int ExecuteCommand(const std::string &Co
 
 } // namespace fuzzer
 
-#endif // LIBFUZZER_LINUX
+#endif // LIBFUZZER_LINUX || LIBFUZZER_NETBSD
