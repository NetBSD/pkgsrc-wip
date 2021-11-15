$NetBSD$

Treat all Unices like Linux.

--- qt/qtmain.cpp.orig	2021-06-05 23:41:42.000000000 +0000
+++ qt/qtmain.cpp
@@ -184,7 +184,7 @@ int main(int argc, char *argv[])
 	LibraryPaths += qMakePair(QDir::cleanPath(QCoreApplication::applicationDirPath() + "/library.bin"), true);
 #endif
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	LibraryPaths += qMakePair(QDir::cleanPath(QCoreApplication::applicationDirPath() + "/../share/leocad/library.bin"), true);
 #endif
 
