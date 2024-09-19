$NetBSD$

--- src/VBox/ExtPacks/VBoxDTrace/onnv/lib/libdtrace/common/dt_cc.c.orig	2016-08-05 16:45:02.000000000 +0000
+++ src/VBox/ExtPacks/VBoxDTrace/onnv/lib/libdtrace/common/dt_cc.c
@@ -103,7 +103,7 @@
 # else
 #  include <unistd.h>
 # endif
-# if defined(RT_OS_WINDOWS) || defined(RT_OS_DARWIN)
+# if defined(RT_OS_WINDOWS) || defined(RT_OS_DARWIN) || defined(RT_OS_NETBSD)
 #  ifdef _MSC_VER
 #   define ftruncate64  _chsize
 #  else
