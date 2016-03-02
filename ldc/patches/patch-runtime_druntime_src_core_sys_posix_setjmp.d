$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/setjmp.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/setjmp.d
@@ -170,6 +170,26 @@ else version( FreeBSD )
     int  setjmp(ref jmp_buf);
     void longjmp(ref jmp_buf, int);
 }
+else version( NetBSD )
+{
+    // <machine/setjmp.h>
+    version( X86 )
+    {
+        enum _JBLEN = 13;
+        struct _jmp_buf { int[_JBLEN + 1] _jb; }
+    }
+    else version( X86_64)
+    {
+        enum _JBLEN = 11;
+        struct _jmp_buf { c_long[_JBLEN] _jb; }
+    }
+    else
+        static assert(0);
+    alias _jmp_buf[_JBLEN] jmp_buf;
+
+    int  setjmp(ref jmp_buf);
+    void longjmp(ref jmp_buf, int);
+}
 else version( CRuntime_Bionic )
 {
     // <machine/setjmp.h>
@@ -238,6 +258,24 @@ else version( FreeBSD )
     int  sigsetjmp(ref sigjmp_buf);
     void siglongjmp(ref sigjmp_buf, int);
 }
+else version( NetBSD )
+{
+    // <machine/setjmp.h>
+    version( X86 )
+    {
+        struct _sigjmp_buf { int[_JBLEN + 1] _ssjb; }
+    }
+    else version( X86_64)
+    {
+        struct _sigjmp_buf { c_long[_JBLEN] _sjb; }
+    }
+    else
+        static assert(0);
+    alias _sigjmp_buf[_JBLEN + 1] sigjmp_buf;
+
+    int  sigsetjmp(ref sigjmp_buf);
+    void siglongjmp(ref sigjmp_buf, int);
+}
 else version( CRuntime_Bionic )
 {
     alias c_long[_JBLEN + 1] sigjmp_buf;
@@ -264,6 +302,12 @@ else version( FreeBSD )
     int  _setjmp(ref jmp_buf);
     void _longjmp(ref jmp_buf, int);
 }
+else version( NetBSD )
+{
+    int  _setjmp(ref jmp_buf);
+    void _longjmp(ref jmp_buf, int);
+}
+
 else version( CRuntime_Bionic )
 {
     int  _setjmp(ref jmp_buf);
