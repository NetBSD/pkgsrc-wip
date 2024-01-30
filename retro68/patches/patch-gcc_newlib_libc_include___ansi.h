$NetBSD$

[ 84%] Building CXX object LaunchAPPL/Client/CMakeFiles/LaunchAPPL.dir/LaunchMethod.cc.o
In file included from /tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/alloca.h:10,
                 from /tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/MakePEF.cc:9:
/tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/_ansi.h:10:10: fatal error: newlib.h: No such file or directory
   10 | #include <newlib.h>
      |          ^~~~~~~~~~

--- PEFTools/../gcc/newlib/libc/include/_ansi.h.orig	2019-08-24 19:56:10.000000000 +0900
+++ PEFTools/../gcc/newlib/libc/include/_ansi.h	2024-01-30 22:41:53.763229405 +0900
@@ -7,8 +7,8 @@
 #ifndef	_ANSIDECL_H_
 #define	_ANSIDECL_H_
 
-#include <newlib.h>
-#include <sys/config.h>
+#include "newlib.h"
+#include "sys/config.h"
 
 /*  ISO C++.  */
 
