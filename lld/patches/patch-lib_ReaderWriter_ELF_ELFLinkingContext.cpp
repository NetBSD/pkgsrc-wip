$NetBSD$

--- lib/ReaderWriter/ELF/ELFLinkingContext.cpp.orig	2016-01-11 21:40:40.000000000 +0000
+++ lib/ReaderWriter/ELF/ELFLinkingContext.cpp
@@ -15,7 +15,7 @@
 #include "lld/Core/SharedLibraryFile.h"
 #include "llvm/ADT/STLExtras.h"
 #include "llvm/ADT/Triple.h"
-#include "llvm/Config/config.h"
+#include "llvm/Config/llvm-config.h"
 #include "llvm/Support/ELF.h"
 #include "llvm/Support/Errc.h"
 #include "llvm/Support/FileSystem.h"
