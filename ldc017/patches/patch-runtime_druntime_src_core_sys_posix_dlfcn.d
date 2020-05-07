$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/dlfcn.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/dlfcn.d
@@ -165,6 +165,29 @@ else version( FreeBSD )
         void*        dli_saddr;
     }
 }
+else version( NetBSD )
+{
+    enum RTLD_LAZY      = 1;
+    enum RTLD_NOW       = 2;
+    enum RTLD_GLOBAL    = 0x100;
+    enum RTLD_LOCAL     = 0x200;
+    enum RTLD_NODELETE  = 0x01000;         /* Do not remove members. */
+    enum RTLD_NOLOAD    = 0x02000;
+
+    int   dlclose(void*);
+    char* dlerror();
+    void* dlopen(in char*, int);
+    void* dlsym(void*, in char*);
+    int   dladdr(const(void)* addr, Dl_info* info);
+
+    struct Dl_info
+    {
+        const(char)* dli_fname;
+        void*        dli_fbase;
+        const(char)* dli_sname;
+        void*        dli_saddr;
+    }
+}
 else version( Solaris )
 {
     enum RTLD_LAZY      = 1;
