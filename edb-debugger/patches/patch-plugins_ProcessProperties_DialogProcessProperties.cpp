$NetBSD$

--- plugins/ProcessProperties/DialogProcessProperties.cpp.orig	2014-01-08 04:19:31.000000000 +0000
+++ plugins/ProcessProperties/DialogProcessProperties.cpp
@@ -34,7 +34,7 @@ along with this program.  If not, see <h
 #include <QStringListModel>
 #include <QUrl>
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <link.h>
 #include <arpa/inet.h>
 #endif
