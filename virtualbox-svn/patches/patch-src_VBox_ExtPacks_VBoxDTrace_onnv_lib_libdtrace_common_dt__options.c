$NetBSD$

--- src/VBox/ExtPacks/VBoxDTrace/onnv/lib/libdtrace/common/dt_options.c.orig	2016-08-12 18:06:11.000000000 +0000
+++ src/VBox/ExtPacks/VBoxDTrace/onnv/lib/libdtrace/common/dt_options.c
@@ -45,7 +45,7 @@
 #  include <sys/resource.h>
 #  include <unistd.h>
 #  include <signal.h>
-#  if defined(RT_OS_DARWIN)
+#  if defined(RT_OS_DARWIN) || defined(RT_OS_NETBSD)
 #   define open64 open
 #  endif
 # else
