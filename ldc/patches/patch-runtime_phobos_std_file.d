$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/file.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/file.d
@@ -1816,6 +1816,9 @@ version (OSX)
 else version (FreeBSD)
     private extern (C) int sysctl (const int* name, uint namelen, void* oldp,
         size_t* oldlenp, const void* newp, size_t newlen);
+else version (NetBSD)
+    private extern (C) int sysctl (const int* name, uint namelen, void* oldp,
+        size_t* oldlenp, const void* newp, size_t newlen);
 
 /**
  * Returns the full path of the current executable.
@@ -1885,6 +1888,10 @@ else version (FreeBSD)
 
         return buffer.assumeUnique;
     }
+    else version (NetBSD)
+    {
+        return readLink("/proc/self/exe");
+    }
     else version (Solaris)
     {
         import core.sys.posix.unistd : getpid;
