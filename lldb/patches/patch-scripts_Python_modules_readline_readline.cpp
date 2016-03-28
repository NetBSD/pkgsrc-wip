$NetBSD$

--- scripts/Python/modules/readline/readline.cpp.orig	2015-10-19 01:16:17.000000000 +0000
+++ scripts/Python/modules/readline/readline.cpp
@@ -6,7 +6,7 @@
 #include <stdio.h>
 
 #ifndef LLDB_DISABLE_LIBEDIT
-#include <editline/readline.h>
+#include <readline/readline.h>
 #endif
 
 // Simple implementation of the Python readline module using libedit.
