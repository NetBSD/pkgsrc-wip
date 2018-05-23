$NetBSD$

# Portability

--- plink2_base.h.orig	2018-05-18 05:07:50.000000000 +0000
+++ plink2_base.h
@@ -448,10 +448,13 @@ typedef uint32_t BoolErr;
 #  define FOPEN_RB "r"
 #  define FOPEN_WB "w"
 #  define FOPEN_AB "a"
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #    define fread_unlocked fread
 #    define fwrite_unlocked fwrite
 #  endif
+#  if defined(__NetBSD__)
+#    define ferror_unlocked ferror
+#  endif
 #endif
 
 #ifdef _WIN32
