$NetBSD: patch-src_base_logging.cc,v 1.1 2014/09/29 15:25:22 heidnes Exp $

Adapt to NetBSD's backtrace_symbols() behaviour, using <> instead of ().
Also increase symbol buffer -- some mangled symbols are Long.

--- src/base/logging.cc.orig	2014-09-24 09:44:41.000000000 +0000
+++ src/base/logging.cc
@@ -32,8 +32,8 @@ void DumpBacktrace() {
   } else {
     for (int i = 1; i < size; ++i) {
       OS::PrintError("%2d: ", i);
-      char mangled[201];
-      if (sscanf(symbols[i], "%*[^(]%*[(]%200[^)+]", mangled) == 1) {  // NOLINT
+      char mangled[401];
+      if (sscanf(symbols[i], "%*[^(<]%*[(<]%400[^)>+]", mangled) == 1) {  // NOLINT
         int status;
         size_t length;
         char* demangled = abi::__cxa_demangle(mangled, NULL, &length, &status);
