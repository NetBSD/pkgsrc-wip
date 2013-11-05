$NetBSD: patch-opal_util_if.h,v 1.1 2013/11/05 22:34:16 asau Exp $

--- opal/util/if.h.orig	2013-11-03 20:33:13.000000000 +0000
+++ opal/util/if.h
@@ -179,7 +179,7 @@ OPAL_DECLSPEC int opal_ifindextomac(int 
  *  @param if_index (IN)  Interface index
  *  @param if_mtu (OUT)   Interface's MTU
  */
-OPAL_DECLSPEC int opal_ifindextomtu(int if_index, int *if_mtu);
+OPAL_DECLSPEC int opal_ifindextomtu(int if_index, int *ompi_if_mtu);
 
 /**
  *  Lookup an interface by index and return its flags.
