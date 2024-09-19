$NetBSD$

--- runtime/druntime/src/core/runtime.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/runtime.d
@@ -666,6 +666,18 @@ Throwable.TraceInfo defaultTraceHandler(
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
