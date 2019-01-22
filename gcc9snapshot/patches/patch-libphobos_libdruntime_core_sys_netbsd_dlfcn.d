$NetBSD$

--- libphobos/libdruntime/core/sys/netbsd/dlfcn.d.orig	2018-10-28 19:51:47.000000000 +0000
+++ libphobos/libdruntime/core/sys/netbsd/dlfcn.d
@@ -103,7 +103,7 @@ static if (__BSD_VISIBLE)
     //void*    fdlopen(int, int);
     int      dladdr(const(void)*, Dl_info*);
     //dlfunc_t dlfunc(void*, const(char)*);
-    //int      dlinfo(void*, int, void*);
+    int      dlinfo(void*, int, void*);
     /+void     dllockinit(void* _context,
         void* function(void* _context) _lock_create,
         void  function(void* _lock)    _rlock_acquire,
