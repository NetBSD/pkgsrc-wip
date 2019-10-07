$NetBSD$

probably not necessary

--- ghc-6.4.2/ghc/rts/Stable.c.orig	2005-07-08 18:08:41.000000000 +0900
+++ ../ghc-6.4.2/ghc/rts/Stable.c	2019-10-06 18:40:06.843009094 +0900
@@ -72,6 +72,7 @@
   application, etc of a stable pointer.
 
 */
+StgWord RTS_VAR(stable_ptr_table) = NULL;
 
 snEntry *stable_ptr_table = NULL;
 static snEntry *stable_ptr_free = NULL;
