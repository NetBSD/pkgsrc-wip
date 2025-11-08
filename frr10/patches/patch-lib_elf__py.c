$NetBSD$

POSIX does not define the content of <elf.h>, or require that it exist.

https://github.com/FRRouting/frr/commit/2597c2769606f6c7eafe971a3384c14e6433174b.patch

--- lib/elf_py.c
+++ lib/elf_py.c
@@ -56,8 +56,6 @@
 #define _FILE_OFFSET_BITS 32
 #endif
 
-#include <elf.h>
-#include <libelf.h>
 #include <gelf.h>
 
 #include "typesafe.h"
