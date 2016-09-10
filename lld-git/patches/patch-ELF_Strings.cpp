$NetBSD$

--- ELF/Strings.cpp.orig	2016-09-10 20:15:44.000000000 +0000
+++ ELF/Strings.cpp
@@ -12,7 +12,7 @@
 #include "llvm/ADT/ArrayRef.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/Twine.h"
-#include "llvm/Config/config.h"
+#include "llvm/Config/llvm-config.h"
 #include "llvm/Demangle/Demangle.h"
 #include <algorithm>
 
