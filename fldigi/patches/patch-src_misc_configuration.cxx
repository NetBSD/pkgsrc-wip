$NetBSD: patch-src_misc_configuration.cxx,v 1.1 2013/04/15 05:52:56 makoto Exp $

For DragonFly build to fix following problem:
misc/configuration.cxx: In member function 'void configuration::testCommPorts()':
misc/configuration.cxx:934:2: error: 'glob_t' was not declared in this scope
misc/configuration.cxx:934:9: error: expected ';' before 'gbuf'
gmake[3]: *** [fldigi-configuration.o] Error 1

--- src/misc/configuration.cxx.orig	2013-04-05 03:46:42.000000000 +0900
+++ src/misc/configuration.cxx	2013-04-15 03:53:20.000000000 +0900
@@ -927,7 +927,7 @@ void configuration::testCommPorts()
 #  define TTY_MAX 255
 #elif defined(__APPLE__)
 	glob_t gbuf;
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define TTY_MAX 4
 #else
 #  define TTY_MAX 8
