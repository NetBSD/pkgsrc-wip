$NetBSD: patch-src_opl.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Add some OPL3 functionality.

--- src/opl.c.orig	2013-09-07 22:14:33.000000000 +0000
+++ src/opl.c
@@ -650,7 +650,11 @@ void adlib_write(Bitu idx, Bit8u val) {
 		int num = idx&7;
 		Bitu base = (idx-ARC_TVS_KSR_MUL)&0xff;
 		if ((num<6) && (base<22)) {
+#if defined(OPLTYPE_IS_OPL3)
 			Bitu modop = regbase2modop[second_set?(base+22):base];
+#else
+			Bitu modop = regbase2modop[base];
+#endif
 			Bitu regbase = base+second_set;
 			Bitu chanbase = second_set?(modop-18+ARC_SECONDSET):modop;
 
@@ -680,7 +684,11 @@ void adlib_write(Bitu idx, Bit8u val) {
 		int num = idx&7;
 		Bitu base = (idx-ARC_KSL_OUTLEV)&0xff;
 		if ((num<6) && (base<22)) {
+#if defined(OPLTYPE_IS_OPL3)
 			Bitu modop = regbase2modop[second_set?(base+22):base];
+#else
+			Bitu modop = regbase2modop[second_set?(base):base];
+#endif
 			Bitu chanbase = second_set?(modop-18+ARC_SECONDSET):modop;
 
 			// change frequency calculations of this operator as
