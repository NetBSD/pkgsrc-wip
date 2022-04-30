#
#	lib/vasnprintf.c
#	use c9x snprintf
#
--- gzip/lib/vasnprintf.c.old	2021-12-02 16:51:39.099686018 +0000
+++ gzip/lib/vasnprintf.c	2021-12-02 17:27:27.821686042 +0000
@@ -202,7 +202,11 @@
 #  endif
 # else
    /* Unix.  */
-#  define SNPRINTF snprintf
+#  ifdef __sysv5__
+#   define SNPRINTF _xsnprintf
+#  else
+#   define SNPRINTF snprintf
+#  endif
    /* Here we need to call the native snprintf, not rpl_snprintf.  */
 #  undef snprintf
 # endif
