$NetBSD$

Missing ctype(3) casts.

--- lib/freebl/mpi/mpi.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/freebl/mpi/mpi.c
@@ -4571,7 +4571,7 @@ int      s_mp_tovalue(char ch, int r)
   if(r > 36)
     xch = ch;
   else
-    xch = toupper(ch);
+    xch = toupper((unsigned char)ch);
 
   if(isdigit(xch))
     val = xch - '0';
@@ -4616,7 +4616,7 @@ char     s_mp_todigit(mp_digit val, int 
   ch = s_dmap_1[val];
 
   if(r <= 36 && low)
-    ch = tolower(ch);
+    ch = tolower((unsigned char)ch);
 
   return ch;
 
