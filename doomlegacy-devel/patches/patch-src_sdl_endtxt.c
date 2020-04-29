$NetBSD$

Fix printing of exit text from ENDOOM lump.
This works only if the terminal uses an Unicode locale and can handle
ANSI control sequences.

--- src/sdl/endtxt.c.orig	2020-04-29 12:06:57.000000000 +0000
+++ src/sdl/endtxt.c
@@ -28,13 +28,35 @@
 #include "w_wad.h"
 #include "z_zone.h"
 #include "m_argv.h"
+#include "m_swap.h"
+
+// [MB] 2020-04-28: Added UTF-8 sequences for IBM437 codepage
+static const char *cp437[256] =
+{
+    " ", "\xE2\x98\xBA", "\xE2\x98\xBB", "\xE2\x99\xA5", "\xE2\x99\xA6", "\xE2\x99\xA3", "\xE2\x99\xA0", "\xE2\x80\xA2", "\xE2\x97\x98", "\xE2\x97\x8B", "\xE2\x97\x99", "\xE2\x99\x82", "\xE2\x99\x80", "\xE2\x99\xAA", "\xE2\x99\xAB", "\xE2\x98\xBC",
+    "\xE2\x96\xBA", "\xE2\x97\x84", "\xE2\x86\x95", "\xE2\x80\xBC", "\xC2\xB6", "\xC2\xA7", "\xE2\x96\xAC", "\xE2\x86\xA8", "\xE2\x86\x91", "\xE2\x86\x93", "\xE2\x86\x92", "\xE2\x86\x90", "\xE2\x88\x9F", "\xE2\x86\x94", "\xE2\x96\xB2", "\xE2\x96\xBC",
+    " ", "!", "\x22", "#", "$", "%", "&", "\x27", "(", ")", "*", "+", ",", "-", ".", "/",
+    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?",
+    "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
+    "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\x5C", "]", "^", "_",
+    "\x60", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
+    "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "\xC2\xA6", "}", "~", "\xE2\x8C\x82",
+    "\xC3\x87", "\xC3\xBC", "\xC3\xA9", "\xC3\xA2", "\xC3\xA4", "\xC3\xA0", "\xC3\xA5", "\xC3\xA7", "\xC3\xAA", "\xC3\xAB", "\xC3\xA8", "\xC3\xAF", "\xC3\xAE", "\xC3\xAC", "\xC3\x84", "\xC3\x85",
+    "\xC3\x89", "\xC3\xA6", "\xC3\x86", "\xC3\xB4", "\xC3\xB6", "\xC3\xB2", "\xC3\xBB", "\xC3\xB9", "\xC3\xBF", "\xC3\x96", "\xC3\x9C", "\xC2\xA2", "\xC2\xA3", "\xC2\xA5", "\xE2\x82\xA7", "\xC6\x92",
+    "\xC3\xA1", "\xC3\xAD", "\xC3\xB3", "\xC3\xBA", "\xC3\xB1", "\xC3\x91", "\xC2\xAA", "\xC2\xBA", "\xC2\xBF", "\xE2\x8C\x90", "\xC2\xAC", "\xC2\xBD", "\xC2\xBC", "\xC2\xA1", "\xC2\xAB", "\xC2\xBB",
+    "\xE2\x96\x91", "\xE2\x96\x92", "\xE2\x96\x93", "\xE2\x94\x82", "\xE2\x94\xA4", "\xE2\x95\xA1", "\xE2\x95\xA2", "\xE2\x95\x96", "\xE2\x95\x95", "\xE2\x95\xA3", "\xE2\x95\x91", "\xE2\x95\x97", "\xE2\x95\x9D", "\xE2\x95\x9C", "\xE2\x95\x9B", "\xE2\x94\x90",
+    "\xE2\x94\x94", "\xE2\x94\xB4", "\xE2\x94\xAC", "\xE2\x94\x9C", "\xE2\x94\x80", "\xE2\x94\xBC", "\xE2\x95\x9E", "\xE2\x95\x9F", "\xE2\x95\x9A", "\xE2\x95\x94", "\xE2\x95\xA9", "\xE2\x95\xA6", "\xE2\x95\xA0", "\xE2\x95\x90", "\xE2\x95\xAC", "\xE2\x95\xA7",
+    "\xE2\x95\xA8", "\xE2\x95\xA4", "\xE2\x95\xA5", "\xE2\x95\x99", "\xE2\x95\x98", "\xE2\x95\x92", "\xE2\x95\x93", "\xE2\x95\xAB", "\xE2\x95\xAA", "\xE2\x94\x98", "\xE2\x94\x8C", "\xE2\x96\x88", "\xE2\x96\x84", "\xE2\x96\x8C", "\xE2\x96\x90", "\xE2\x96\x80",
+    "\xCE\xB1", "\xC3\x9F", "\xCE\x93", "\xCF\x80", "\xCE\xA3", "\xCF\x83", "\xC2\xB5", "\xCF\x84", "\xCE\xA6", "\xCE\x98", "\xCE\xA9", "\xCE\xB4", "\xE2\x88\x9E", "\xCF\x86", "\xCE\xB5", "\xE2\x88\xA9",
+    "\xE2\x89\xA1", "\xC2\xB1", "\xE2\x89\xA5", "\xE2\x89\xA4", "\xE2\x8C\xA0", "\xE2\x8C\xA1", "\xC3\xB7", "\xE2\x89\x88", "\xC2\xB0", "\xE2\x88\x99", "\xC2\xB7", "\xE2\x88\x9A", "\xE2\x81\xBF", "\xC2\xB2", "\xE2\x96\xA0", " "
+};
 
 // [WDJ] Changed to public interface name.
 // Original name was ShowEndText.
 void I_Show_EndText( uint16_t * text )
 {
-	int i, j;
-	int att = 0;
+	int i;
+	int c, att, bg, fg;
 	int nlflag = 1;
 #if 0
 	unsigned short *text;
@@ -59,127 +81,137 @@ void I_Show_EndText( uint16_t * text )
 
 	/* print 80x25 text and deal with the attributes too */
 	for (i=1; i<=80*25; i++) {
+		// [MB] 2020-04-26: Reset color configuration
+		printf("\033[0m");
 		/* attribute first */
-		/* attribute changed? */
-		if ((j = *text >> 8) != att) {
-			/* save current attribute */
-			att = j;
-			/* set new attribute, forground color first */
-			printf("\033[");
-			switch (j & 0x0f) {
-			case 0:		/* black */
-				printf("30");
-				break;
-			case 1:		/* blue */
-				printf("34");
-				break;
-			case 2:		/* green */
-				printf("32");
-				break;
-			case 3:		/* cyan */
-				printf("36");
-				break;
-			case 4:		/* red */
-				printf("31");
-				break;
-			case 5:		/* magenta */
-				printf("35");
-				break;
-			case 6:		/* brown */
-				printf("33");
-				break;
-			case 7:		/* bright grey */
-				printf("37");
-				break;
-			case 8:		/* dark grey */
-				printf("1;30");
-				break;
-			case 9:		/* bright blue */
-				printf("1;34");
-				break;
-			case 10:	/* bright green */
-				printf("1;32");
-				break;
-			case 11:	/* bright cyan */
-				printf("1;36");
-				break;
-			case 12:	/* bright red */
-				printf("1;31");
-				break;
-			case 13:	/* bright magenta */
-				printf("1;35");
-				break;
-			case 14:	/* yellow */
-				printf("1;33");
-				break;
-			case 15:	/* white */
-				printf("1;37");
-				break;
-			}
-			printf("m");
-			/* now background color */
-			printf("\033[");
-			switch((j >> 4) & 0x0f) {
-			case 0:		/* black */
-				printf("40");
-				break;
-			case 1:		/* blue */
-				printf("44");
-				break;
-			case 2:		/* green */
-				printf("42");
-				break;
-			case 3:		/* cyan */
-				printf("46");
-				break;
-			case 4:		/* red */
-				printf("41");
-				break;
-			case 5:		/* magenta */
-				printf("45");
-				break;
-			case 6:		/* brown */
-				printf("43");
-				break;
-			case 7:		/* bright grey */
-				printf("47");
-				break;
-			case 8:		/* dark grey */
-				printf("1;40");
-				break;
-			case 9:		/* bright blue */
-				printf("1;44");
-				break;
-			case 10:	/* bright green */
-				printf("1;42");
-				break;
-			case 11:	/* bright cyan */
-				printf("1;46");
-				break;
-			case 12:	/* bright red */
-				printf("1;41");
-				break;
-			case 13:	/* bright magenta */
-				printf("1;45");
-				break;
-			case 14:	/* yellow */
-				printf("1;43");
-				break;
-			case 15:	/* white */
-				printf("1;47");
-				break;
-			}
-			printf("m");
+		// [MB] 2020-04-26: Fixed endianess
+		att = ((uint16_t)LE_SWAP16(*text)) >> 8;
+#if 0  // [MB] 2020-04-26: Blink support does not work correctly
+		if(att & 0x80)
+			printf("\033[5m");
+#endif
+		/* set new attribute, forground color first */
+		fg = att & 0x0f;
+		printf("\033[");
+		switch (fg) {
+		case 0:		/* black */
+			printf("30");
+			break;
+		case 1:		/* blue */
+			printf("34");
+			break;
+		case 2:		/* green */
+			printf("32");
+			break;
+		case 3:		/* cyan */
+			printf("36");
+			break;
+		case 4:		/* red */
+			printf("31");
+			break;
+		case 5:		/* magenta */
+			printf("35");
+			break;
+		case 6:		/* brown */
+			printf("33");
+			break;
+		case 7:		/* bright grey */
+			printf("37");
+			break;
+		case 8:		/* dark grey */
+			printf("1;30");
+			break;
+		case 9:		/* bright blue */
+			printf("1;34");
+			break;
+		case 10:	/* bright green */
+			printf("1;32");
+			break;
+		case 11:	/* bright cyan */
+			printf("1;36");
+			break;
+		case 12:	/* bright red */
+			printf("1;31");
+			break;
+		case 13:	/* bright magenta */
+			printf("1;35");
+			break;
+		case 14:	/* yellow */
+			printf("1;33");
+			break;
+		case 15:	/* white */
+			printf("1;37");
+			break;
+		}
+		printf("m");
+		/* now background color */
+		bg = (att >> 4) & 0x0f;
+		printf("\033[");
+		// [MB] 2020-04-26: Mask only bg color bits here
+		switch(bg & 0x07) {
+		case 0:		/* black */
+			printf("40");
+			break;
+		case 1:		/* blue */
+			printf("44");
+			break;
+		case 2:		/* green */
+			printf("42");
+			break;
+		case 3:		/* cyan */
+			printf("46");
+			break;
+		case 4:		/* red */
+			printf("41");
+			break;
+		case 5:		/* magenta */
+			printf("45");
+			break;
+		case 6:		/* brown */
+			printf("43");
+			break;
+		case 7:		/* bright grey */
+			printf("47");
+			break;
+#if 0  // [MB] 2020-04-26: Not available for bg color (MSB is the blink flag)
+		case 8:		/* dark grey */
+			printf("1;40");
+			break;
+		case 9:		/* bright blue */
+			printf("1;44");
+			break;
+		case 10:	/* bright green */
+			printf("1;42");
+			break;
+		case 11:	/* bright cyan */
+			printf("1;46");
+			break;
+		case 12:	/* bright red */
+			printf("1;41");
+			break;
+		case 13:	/* bright magenta */
+			printf("1;45");
+			break;
+		case 14:	/* yellow */
+			printf("1;43");
+			break;
+		case 15:	/* white */
+			printf("1;47");
+			break;
+#endif
 		}
+		printf("m");
 
 		/* now the text */
-		putchar(*text++ & 0xff);
+		// [MB] 2020-04-26: Fixed endianess
+		c = (uint16_t)LE_SWAP16(*text++) & 0xff;
+		// [MB] 2020-04-26: Convert data to Unicode and print as UTF-8
+		printf(cp437[c]);
 
 		/* do we need a nl? */
 		if (nlflag) {
 			if (!(i % 80)) {
 				printf("\033[0m");
-				att = 0;
 				printf("\n");
 			}
 		}
