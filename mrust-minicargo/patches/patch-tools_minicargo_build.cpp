$NetBSD$

--- tools/minicargo/build.cpp.orig	2021-09-12 00:15:52.000000000 +0000
+++ tools/minicargo/build.cpp
@@ -48,7 +48,7 @@ extern int _putenv_s(const char*, const 
 #ifdef __APPLE__
 # include <mach-o/dyld.h>
 #endif
-#if defined(__FreeBSD__) || defined(__DragonFly__) || (defined(__NetBSD__) && defined(KERN_PROC_PATHNAME)) // NetBSD 8.0+
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 # include <sys/sysctl.h>
 #endif
 
@@ -1266,7 +1266,11 @@ const helpers::path& get_mrustc_path()
         else
             // TODO: Buffer too small
 # elif defined(__FreeBSD__) || defined(__DragonFly__) || (defined(__NetBSD__) && defined(KERN_PROC_PATHNAME)) // NetBSD 8.0+
+#  if defined(__NetBSD__)
+        int mib[4] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+#  else
         int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+#  endif
         size_t s = sizeof(buf);
         if ( sysctl(mib, 4, buf, &s, NULL, 0) == 0 )
         {
