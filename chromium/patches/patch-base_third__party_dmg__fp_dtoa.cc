$NetBSD: patch-base_third__party_dmg__fp_dtoa.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/third_party/dmg_fp/dtoa.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/third_party/dmg_fp/dtoa.cc
@@ -1559,7 +1559,7 @@ hexnan
 	CONST char *s;
 	int c1, havedig, udx0, xshift;
 
-	if (!hexdig['0'])
+	if (!hexdig[(int)'0'])
 		hexdig_init();
 	x[0] = x[1] = 0;
 	havedig = xshift = 0;
@@ -3283,7 +3283,7 @@ strtod
 #ifdef Avoid_Underflow
 			if (bc.scale && y <= 2*P*Exp_msk1) {
 				if (aadj <= 0x7fffffff) {
-					if ((z = aadj) <= 0)
+					if ((z = (ULong)aadj) <= 0)
 						z = 1;
 					aadj = z;
 					aadj1 = bc.dsign ? aadj : -aadj;
@@ -3837,7 +3837,7 @@ dtoa
 			 */
 			dval(&eps) = 0.5/tens[ilim-1] - dval(&eps);
 			for(i = 0;;) {
-				L = dval(&u);
+				L = (int)dval(&u);
 				dval(&u) -= L;
 				*s++ = '0' + (int)L;
 				if (dval(&u) < dval(&eps))
