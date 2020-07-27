$NetBSD$

--- tools/gn/src/gn/args.cc.orig	2020-06-25 09:40:29.000000000 +0000
+++ tools/gn/src/gn/args.cc
@@ -316,6 +316,8 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "openbsd";
 #elif defined(OS_HAIKU)
   os = "haiku";
+#elif defined(OS_NETBSD)
+  os = "netbsd";
 #else
 #error Unknown OS type.
 #endif
