--- src/orthographies/MathematicalOperators.h.orig	2012-06-26 10:46:34.000000000 -0500
+++ src/orthographies/MathematicalOperators.h	2014-02-10 11:40:22.000000000 -0600
@@ -25,8 +25,19 @@
 // Unicode values 
 //
 UINT32 values[]={
+	0x002B,
+	0x003D,
+	0x00B1,
+	0x00D7,
+	0x00F7,
 	START_RANGE_PAIR,
-	0x2200,0x22F1,
+	0x2200,0x22FF,
+	START_RANGE_PAIR,
+	0x27C0,0x27EF,
+	START_RANGE_PAIR,
+	0x2980,0x29FF,
+	START_RANGE_PAIR,
+	0x2A00,0x2AFF,
 	END_OF_DATA
 };
 
