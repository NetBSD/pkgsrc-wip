$NetBSD$

In NetBSD it's dirent.

--- Library/Implementation/HTFile.h.orig	2023-09-26 14:25:18.286011859 +0000
+++ Library/Implementation/HTFile.h
@@ -14,6 +14,9 @@
    
  */
 
+#include <dirent.h>
+#define STRUCT_DIRENT struct dirent
+
 #ifndef HTFILE_H
 #define HTFILE_H
 
