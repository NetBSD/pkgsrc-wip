$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/runtime.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/runtime.d
@@ -407,6 +407,8 @@ extern (C) bool runModuleUnitTests()
         import core.sys.osx.execinfo;
     else version( FreeBSD )
         import core.sys.freebsd.execinfo;
+    else version( NetBSD )
+        import core.sys.netbsd.execinfo;
     else version( Windows )
         import core.sys.windows.stacktrace;
     else version( Solaris )
@@ -489,6 +491,8 @@ Throwable.TraceInfo defaultTraceHandler(
         import core.sys.osx.execinfo;
     else version( FreeBSD )
         import core.sys.freebsd.execinfo;
+    else version( NetBSD )
+        import core.sys.netbsd.execinfo;
     else version( Windows )
         import core.sys.windows.stacktrace;
     else version( Solaris )
@@ -650,6 +654,18 @@ Throwable.TraceInfo defaultTraceHandler(
                         symEnd = eptr - buf.ptr;
                     }
                 }
+                else version( NetBSD )
+                {
+                    // format is: 0x00000000 <_D6module4funcAFZv+0x78> at module
+                    auto bptr = cast(char*) memchr( buf.ptr, '<', buf.length );
+                    auto eptr = cast(char*) memchr( buf.ptr, '+', buf.length );
+
+                    if( bptr++ && eptr )
+                    {
+                        symBeg = bptr - buf.ptr;
+                        symEnd = eptr - buf.ptr;
+                    }
+                }
                 else version( Solaris )
                 {
                     // format is object'symbol+offset [pc]
