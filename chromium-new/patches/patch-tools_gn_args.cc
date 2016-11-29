$NetBSD$

--- tools/gn/args.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ tools/gn/args.cc
@@ -258,8 +258,12 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "linux";
 #elif defined(OS_ANDROID)
   os = "android";
+#elif defined(OS_FREEBSD)
+  os = "freebsd";
 #elif defined(OS_NETBSD)
   os = "netbsd";
+#elif defined(OS_OPENBSD)
+  os = "openbsd";
 #else
   #error Unknown OS type.
 #endif
