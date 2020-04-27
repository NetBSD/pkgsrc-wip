$NetBSD$

Fix endianess for interpretation of ENDOOM lump.

The MSB of the attributes is not part of the bg color field, interpret
as blinking flag according to unofficial Doom specs (section 8-3):
<http://www.gamers.org/dhs/helpdocs/dmsp1666.html>

Convert text encoding from IBM437 codepage to Unicode.

--- src/sdl/endtxt.c.orig	2020-04-27 14:36:13.000000000 +0000
+++ src/sdl/endtxt.c
@@ -28,6 +28,20 @@
 #include "w_wad.h"
 #include "z_zone.h"
 #include "m_argv.h"
+#include "m_swap.h"
+
+// [MB] 2020-04-26: Added UTF-8 sequences for upper half of codepage IBM437
+static const char *cp437[128] =
+{
+    "\xC3\x87", "\xC3\xBC", "\xC3\xA9", "\xC3\xA2", "\xC3\xA4", "\xC3\xA0", "\xC3\xA5", "\xC3\xA7", "\xC3\xAA", "\xC3\xAB", "\xC3\xA8", "\xC3\xAF", "\xC3\xAE", "\xC3\xAC", "\xC3\x84", "\xC3\x85",
+    "\xC3\x89", "\xC3\xA6", "\xC3\x86", "\xC3\xB4", "\xC3\xB6", "\xC3\xB2", "\xC3\xBB", "\xC3\xB9", "\xC3\xBF", "\xC3\x96", "\xC3\x9C", "\xC2\xA2", "\xC2\xA3", "\xC2\xA5", "\xE2\x82\xA7", "\xC6\x92",
+    "\xC3\xA1", "\xC3\xAD", "\xC3\xB3", "\xC3\xBA", "\xC3\xB1", "\xC3\x91", "\xC2\xAA", "\xC2\xBA", "\xC2\xBF", "\xE2\x8C\x90", "\xC2\xAC", "\xC2\xBD", "\xC2\xBC", "\xC2\xA1", "\xC2\xAB", "\xC2\xBB",
+    "\xE2\x96\x91", "\xE2\x96\x92", "\xE2\x96\x93", "\xE2\x94\x82", "\xE2\x94\xA4", "\xE2\x95\xA1", "\xE2\x95\xA2", "\xE2\x95\x96", "\xE2\x95\x95", "\xE2\x95\xA3", "\xE2\x95\x91", "\xE2\x95\x97", "\xE2\x95\x9D", "\xE2\x95\x9C", "\xE2\x95\x9B", "\xE2\x94\x90",
+    "\xE2\x94\x94", "\xE2\x94\xB4", "\xE2\x94\xAC", "\xE2\x94\x9C", "\xE2\x94\x80", "\xE2\x94\xBC", "\xE2\x95\x9E", "\xE2\x95\x9F", "\xE2\x95\x9A", "\xE2\x95\x94", "\xE2\x95\xA9", "\xE2\x95\xA6", "\xE2\x95\xA0", "\xE2\x95\x90", "\xE2\x95\xAC", "\xE2\x95\xA7",
+    "\xE2\x95\xA8", "\xE2\x95\xA4", "\xE2\x95\xA5", "\xE2\x95\x99", "\xE2\x95\x98", "\xE2\x95\x92", "\xE2\x95\x93", "\xE2\x95\xAB", "\xE2\x95\xAA", "\xE2\x94\x98", "\xE2\x94\x8C", "\xE2\x96\x88", "\xE2\x96\x84", "\xE2\x96\x8C", "\xE2\x96\x90", "\xE2\x96\x80",
+    "\xCE\xB1", "\xC3\x9F", "\xCE\x93", "\xCF\x80", "\xCE\xA3", "\xCF\x83", "\xC2\xB5", "\xCF\x84", "\xCE\xA6", "\xCE\x98", "\xCE\xA9", "\xCE\xB4", "\xE2\x88\x9E", "\xCF\x86", "\xCE\xB5", "\xE2\x88\xA9",
+    "\xE2\x89\xA1", "\xC2\xB1", "\xE2\x89\xA5", "\xE2\x89\xA4", "\xE2\x8C\xA0", "\xE2\x8C\xA1", "\xC3\xB7", "\xE2\x89\x88", "\xC2\xB0", "\xE2\x88\x99", "\xC2\xB7", "\xE2\x88\x9A", "\xE2\x81\xBF", "\xC2\xB2", "\xE2\x96\xA0", "\xC2\xA0"
+};
 
 // [WDJ] Changed to public interface name.
 // Original name was ShowEndText.
@@ -59,9 +73,12 @@ void I_Show_EndText( uint16_t * text )
 
 	/* print 80x25 text and deal with the attributes too */
 	for (i=1; i<=80*25; i++) {
+		// [MB] 2020-04-26: Reset blinking
+		printf("\033[25m");
 		/* attribute first */
 		/* attribute changed? */
-		if ((j = *text >> 8) != att) {
+		// [MB] 2020-04-26: Fixed endianess
+		if ((j = ((uint16_t)LE_SWAP16(*text)) >> 8) != att) {
 			/* save current attribute */
 			att = j;
 			/* set new attribute, forground color first */
@@ -117,9 +134,16 @@ void I_Show_EndText( uint16_t * text )
 				break;
 			}
 			printf("m");
+			// [MB] 2020-04-26: Add support for blinking
+			printf("\033[");
+			if((j >> 4) & 0x08)
+				printf("5m");
+			else
+				printf("25m");
 			/* now background color */
 			printf("\033[");
-			switch((j >> 4) & 0x0f) {
+			// [MB] 2020-04-26: Mask for bg color bits fixed
+			switch((j >> 4) & 0x07) {
 			case 0:		/* black */
 				printf("40");
 				break;
@@ -144,6 +168,7 @@ void I_Show_EndText( uint16_t * text )
 			case 7:		/* bright grey */
 				printf("47");
 				break;
+#if 0  // [MB] 2020-04-26: Not available for bg color (MSB is the blink flag)
 			case 8:		/* dark grey */
 				printf("1;40");
 				break;
@@ -168,12 +193,19 @@ void I_Show_EndText( uint16_t * text )
 			case 15:	/* white */
 				printf("1;47");
 				break;
+#endif
 			}
 			printf("m");
 		}
 
 		/* now the text */
-		putchar(*text++ & 0xff);
+		// [MB] 2020-04-26: Fixed endianess
+		j = (uint16_t)LE_SWAP16(*text++) & 0xff;
+		// [MB] 2020-04-26: Convert data to Unicode before printing
+		if (128 > j)
+			putchar(j);
+		else
+			printf(cp437[j - 128]);
 
 		/* do we need a nl? */
 		if (nlflag) {
