$NetBSD: patch-make_autoconf_lib-bundled.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Add rpath for zlib.

--- make/autoconf/lib-bundled.m4.orig	2021-04-23 22:52:34.000000000 -0400
+++ make/autoconf/lib-bundled.m4	2021-06-10 07:19:56.667130306 -0400
@@ -261,7 +261,8 @@
   if test "x$USE_EXTERNAL_LIBZ" = "xfalse"; then
     LIBZ_CFLAGS="$LIBZ_CFLAGS -I$TOPDIR/src/java.base/share/native/libzip/zlib"
   else
-    LIBZ_LIBS="-lz"
+    LIBZ_CFLAGS="-I@BUILDLINK_PREFIX.zlib@/include"
+    LIBZ_LIBS="@COMPILER_RPATH_FLAG@@BUILDLINK_PREFIX.zlib@/lib -L@BUILDLINK_PREFIX.zlib@/lib -lz"
   fi
 
   AC_SUBST(USE_EXTERNAL_LIBZ)
