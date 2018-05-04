$NetBSD$

# Portability

--- plink2_base.h.orig	2018-05-03 22:24:28.000000000 +0000
+++ plink2_base.h
@@ -435,7 +435,12 @@ typedef uint32_t BoolErr;
 #  define FOPEN_RB "r"
 #  define FOPEN_WB "w"
 #  define FOPEN_AB "a"
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__)
+#    define fread_unlocked fread
+#    define fwrite_unlocked fwrite
+#  endif
+#  if defined(__NetBSD__)
+#    define ferror_unlocked ferror
 #    define fread_unlocked fread
 #    define fwrite_unlocked fwrite
 #  endif
