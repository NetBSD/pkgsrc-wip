$NetBSD$

--- m4/dolt.m4.orig	2018-03-14 06:17:49.000000000 +0000
+++ m4/dolt.m4
@@ -20,6 +20,7 @@ AS_IF([test x$GCC != xyes], [dolt_suppor
 
 AS_CASE([$host],
     [*-*-linux*|*-*-freebsd*], [pic_options='-fPIC'],
+    [*-*-netbsd*],             [pic_options='-fPIC -DPIC'],
     [*-apple-darwin*],         [pic_options='-fno-common'],
     [*mingw*|*nacl*],          [pic_options='']
     [*],                       [dolt_supported=no]
