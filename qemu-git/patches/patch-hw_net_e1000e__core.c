$NetBSD$

--- hw/net/e1000e_core.c.orig	2017-08-25 15:26:30.000000000 +0000
+++ hw/net/e1000e_core.c
@@ -2855,7 +2855,7 @@ static uint32_t (*e1000e_macreg_readops[
     e1000e_getreg(RDLEN0),
     e1000e_getreg(RDH1),
     e1000e_getreg(LATECOL),
-    e1000e_getreg(SEC),
+    e1000e_getreg(SEQEC),
     e1000e_getreg(XONTXC),
     e1000e_getreg(WUS),
     e1000e_getreg(GORCL),
