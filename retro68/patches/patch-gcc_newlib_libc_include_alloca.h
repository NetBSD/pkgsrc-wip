$NetBSD$ 

In file included from /tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/MakePEF.cc:9:
/tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/alloca.h:11:10: fatal error: sys/reent.h: No such file or directory
   11 | #include <sys/reent.h>
      |          ^~~~~~~~~~~~~
compilation terminated.

--- PEFTools/../gcc/newlib/libc/include/alloca.h.orig	2019-08-24 19:56:10.000000000 +0900
+++ PEFTools/../gcc/newlib/libc/include/alloca.h	2024-01-31 07:26:33.272095197 +0900
@@ -8,7 +8,7 @@
 #define _NEWLIB_ALLOCA_H
 
 #include "_ansi.h"
-#include <sys/reent.h>
+#include "sys/reent.h"
 
 #undef alloca
 
