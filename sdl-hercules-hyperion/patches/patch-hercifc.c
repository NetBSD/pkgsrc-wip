$NetBSD$

NetBSD doesn't have TUNSETIFF.

--- hercifc.c.orig	2019-09-10 18:06:20.000000000 +0000
+++ hercifc.c
@@ -115,7 +115,7 @@ int main( int argc, char **argv )
 
         switch( ctlreq.iCtlOp )
         {
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
         case TUNSETIFF:
             pOp  = "TUNSETIFF";
             pArg = &ctlreq.iru.hifr.ifreq;
