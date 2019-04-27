$NetBSD: patch-libs_ksysguard_processcore_processes__netbsd__p.cpp,v 1.1 2013/01/17 16:05:53 joerg Exp $

No more sys/user.h in netbsd.

--- processcore/processes_netbsd_p.cpp.orig	2018-03-27 11:18:34.000000000 +0000
+++ processcore/processes_netbsd_p.cpp
@@ -29,7 +29,7 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <sys/stat.h>
 #include <signal.h>
 #include <unistd.h>
