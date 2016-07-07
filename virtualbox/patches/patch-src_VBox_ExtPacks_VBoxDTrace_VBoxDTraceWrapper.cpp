$NetBSD$

--- src/VBox/ExtPacks/VBoxDTrace/VBoxDTraceWrapper.cpp.orig	2016-03-04 19:28:27.000000000 +0000
+++ src/VBox/ExtPacks/VBoxDTrace/VBoxDTraceWrapper.cpp
@@ -68,7 +68,7 @@ int main(int argc, char **argv)
     char szDTraceCmd[RTPATH_MAX];
     szDTraceCmd[0] = '\0';
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD)
     /*
      * 1. Try native first on platforms where it's applicable.
      */
@@ -199,4 +199,3 @@ int main(int argc, char **argv)
     }
     return rcExit;
 }
-
