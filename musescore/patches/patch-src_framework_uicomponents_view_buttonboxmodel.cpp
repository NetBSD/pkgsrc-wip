$NetBSD$

Treat NetBSD like FreeBSD.

--- src/framework/uicomponents/view/buttonboxmodel.cpp.orig	2025-07-21 11:41:44.635388783 +0000
+++ src/framework/uicomponents/view/buttonboxmodel.cpp
@@ -110,7 +110,7 @@ const std::vector <ButtonBoxModel::Butto
     } else {
 #if defined (Q_OS_MACOS)
         index = 1;
-#elif defined (Q_OS_LINUX) || defined (Q_OS_UNIX) || defined(Q_OS_FREEBSD)
+#elif defined (Q_OS_LINUX) || defined (Q_OS_UNIX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
         index = 2;
 #endif
     }
