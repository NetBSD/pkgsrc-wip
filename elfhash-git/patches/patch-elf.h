$NetBSD$

On some systems (macOS, for example), features.h is not available. This is a
quick hack to get elfhash to build on those platforms.

--- elf.h.orig	2017-10-06 18:52:37.000000000 +0000
+++ elf.h
@@ -19,7 +19,7 @@
 #ifndef _ELF_H
 #define	_ELF_H 1
 
-#include <features.h>
+//#include <features.h>
 
 __BEGIN_DECLS
 
