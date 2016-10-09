$NetBSD$

--- lib/ReaderWriter/MachO/MachOLinkingContext.cpp.orig	2015-10-24 08:20:51.000000000 +0000
+++ lib/ReaderWriter/MachO/MachOLinkingContext.cpp
@@ -22,7 +22,7 @@
 #include "llvm/ADT/STLExtras.h"
 #include "llvm/ADT/StringExtras.h"
 #include "llvm/ADT/Triple.h"
-#include "llvm/Config/config.h"
+#include "llvm/Config/llvm-config.h"
 #include "llvm/Support/Debug.h"
 #include "llvm/Support/Errc.h"
 #include "llvm/Support/Host.h"
