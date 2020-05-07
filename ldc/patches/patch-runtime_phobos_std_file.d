$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/file.d.orig	2018-08-23 23:30:04.000000000 +0000
+++ runtime/phobos/std/file.d
@@ -1826,6 +1826,9 @@ version (OSX)
 else version (FreeBSD)
     private extern (C) int sysctl (const int* name, uint namelen, void* oldp,
         size_t* oldlenp, const void* newp, size_t newlen);
+else version (NetBSD)
+    private extern (C) int sysctl (const int* name, uint namelen, void* oldp,
+        size_t* oldlenp, const void* newp, size_t newlen);
 
 /**
  * Returns the full path of the current executable.
@@ -1899,6 +1902,10 @@ else version (FreeBSD)
     {
         return readLink("/proc/curproc/file");
     }
+    else version (NetBSD)
+    {
+        return readLink("/proc/self/exe");
+    }
     else version (Solaris)
     {
         import core.sys.posix.unistd : getpid;
