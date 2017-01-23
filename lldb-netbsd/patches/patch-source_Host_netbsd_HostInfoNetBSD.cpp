$NetBSD$

--- source/Host/netbsd/HostInfoNetBSD.cpp.orig	2016-12-17 10:30:35.000000000 +0000
+++ source/Host/netbsd/HostInfoNetBSD.cpp
@@ -85,15 +85,15 @@ FileSpec HostInfoNetBSD::GetProgramFileS
   static FileSpec g_program_filespec;
 
   if (!g_program_filespec) {
-    ssize_t len;
-    static char buf[PATH_MAX];
-    char name[PATH_MAX];
+    static const int name[] = {
+        CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME,
+    };
+    char path[MAXPATHLEN];
+    size_t len;
 
-    ::snprintf(name, PATH_MAX, "/proc/%d/exe", ::getpid());
-    len = ::readlink(name, buf, PATH_MAX - 1);
-    if (len != -1) {
-      buf[len] = '\0';
-      g_program_filespec.SetFile(buf, false);
+    len = sizeof(path);
+    if (sysctl(name, __arraycount(name), path, &len, NULL, 0) != -1) {
+        g_program_filespec.SetFile(path, false);
     }
   }
   return g_program_filespec;
