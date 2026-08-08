$NetBSD$

--- random.c.orig	2011-12-28 12:47:15.000000000 +0000
+++ random.c
@@ -276,9 +276,6 @@ fill_random_seed(ptr)
 #ifdef O_NOCTTY
             |O_NOCTTY
 #endif
-#ifdef O_NOFOLLOW
-            |O_NOFOLLOW
-#endif
             )) >= 0) {
         if (fstat(fd, &statbuf) == 0 && S_ISCHR(statbuf.st_mode)) {
             read(fd, seed, DEFAULT_SEED_LEN);
@@ -303,7 +300,7 @@ make_seed_value(char *ptr)
 
     RBIGNUM_SET_SIGN(big, 1);
 
-    digits = ALLOC_N(char, DEFAULT_SEED_LEN);
+    digits = ALLOC_N(BDIGIT, DEFAULT_SEED_LEN);
     RBIGNUM(big)->digits = digits;
     RBIGNUM(big)->len = DEFAULT_SEED_LEN / SIZEOF_BDIGITS;
 
