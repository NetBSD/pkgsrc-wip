$NetBSD$

--- lib/fuzzer/FuzzerExtFunctionsWeak.cpp.orig	2017-08-21 23:23:37.000000000 +0000
+++ lib/fuzzer/FuzzerExtFunctionsWeak.cpp
@@ -13,7 +13,7 @@
 // to clients right now.
 //===----------------------------------------------------------------------===//
 #include "FuzzerDefs.h"
-#if LIBFUZZER_LINUX
+#if LIBFUZZER_LINUX || LIBFUZZER_NETBSD
 
 #include "FuzzerExtFunctions.h"
 #include "FuzzerIO.h"
@@ -51,4 +51,4 @@ ExternalFunctions::ExternalFunctions() {
 
 } // namespace fuzzer
 
-#endif // LIBFUZZER_LINUX
+#endif // LIBFUZZER_LINUX || LIBFUZZER_NETBSD
