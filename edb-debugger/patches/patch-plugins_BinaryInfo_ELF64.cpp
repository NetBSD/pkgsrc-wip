$NetBSD$

--- plugins/BinaryInfo/ELF64.cpp.orig	2014-01-08 02:59:13.000000000 +0000
+++ plugins/BinaryInfo/ELF64.cpp
@@ -28,7 +28,7 @@ along with this program.  If not, see <h
 #include <QFile>
 #include <cstring>
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <link.h>
 #endif
 
