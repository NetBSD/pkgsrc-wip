$NetBSD$

--- part.c.orig	2007-12-06 16:30:17.000000000 +0000
+++ part.c
@@ -1767,8 +1767,8 @@ static int rec01(INT ni, OP vec)
 /* to compute number of partitions */
 {
     INT erg = OK;
-    if (ni<0) return;
-    if (not EMPTYP(S_V_I(vec,ni))) return;
+    if (ni < 0) return 0;
+    if (not EMPTYP(S_V_I(vec, ni))) return 0;
     else if (ni<=1) M_I_I(1,S_V_I(vec,ni));
     else {
      
