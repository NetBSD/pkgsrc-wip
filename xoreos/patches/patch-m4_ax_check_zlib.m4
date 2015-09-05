$NetBSD: patch-m4_ax_check_zlib.m4,v 1.1 2015/09/05 23:04:36 yhardy Exp $

BUILD: Use ZLIB_VERNUM to check for the correct zlib version

https://github.com/xoreos/xoreos/commit/5c3716b72126295331055cf95d53e35240447bdd

diff --git a/m4/ax_check_zlib.m4 b/m4/ax_check_zlib.m4
index aae4e77..8eba895 100644
--- m4/ax_check_zlib.m4
+++ m4/ax_check_zlib.m4
@@ -32,10 +32,7 @@ AC_DEFUN([AX_CHECK_ZLIB], [
 #include <zlib.h>
 
 int main(int argc, char **argv) {
-#if  (ZLIB_VER_MAJOR  < $1) || \
-    ((ZLIB_VER_MAJOR == $1) && (ZLIB_VER_MINOR  < $2)) || \
-    ((ZLIB_VER_MAJOR == $1) && (ZLIB_VER_MINOR == $2) && (ZLIB_VER_REVISION  < $3)) || \
-    ((ZLIB_VER_MAJOR == $1) && (ZLIB_VER_MINOR == $2) && (ZLIB_VER_REVISION == $3) && (ZLIB_VER_SUBREVISION < $4))
+#if ZLIB_VERNUM < (($1 * 4096) + ($2 * 256) + ($3 * 16) + $4)
 	#error zlib version too low
 #endif
 
