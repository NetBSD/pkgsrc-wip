$NetBSD$

--- platforms/unix/plugins/SerialPlugin/sqUnixSerial.c.orig	2019-01-17 23:23:50.000000000 +0000
+++ platforms/unix/plugins/SerialPlugin/sqUnixSerial.c
@@ -100,10 +100,14 @@ static drDecode dataRateDecode[] = {
 #endif
 #if defined(B500000)		/* missing on GNU/Linux prior to 2.2 */
   { 500000, B500000 },
+#if defined(B576000)		/* missing on NetBSD */
   { 576000, B576000 },
+#endif
   { 921600, B921600 },
   { 1000000, B1000000 },
+#if defined(B1152000)		/* missing on NetBSD */
   { 1152000, B1152000 },
+#endif
   { 1500000, B1500000 },
   { 2000000, B2000000 },
 #endif
