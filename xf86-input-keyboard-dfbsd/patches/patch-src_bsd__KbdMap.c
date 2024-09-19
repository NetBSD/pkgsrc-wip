$NetBSD: patch-src_bsd__KbdMap.c,v 1.1 2018/01/21 10:12:39 triaxx Exp $

PR191459: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=191459
Fix a segmentation fault due to the use of Unicode codepoints in vt(4) which is
the default console driver from FreeBSD 11.

Don't query console keymap

This seems to be useless and doesn't work anymore with vt(4), due to the
use of Unicode codepoints in vt(4). So remove the related code. This fixes
a segmentation fault during X.Org server startup.

PR:             191459

Also used in DragonFly dports.

Patches from NetBSD xsrc:
Scancode translation table for wskbd on Amiga keyboards.

--- src/bsd_KbdMap.c.orig	2015-08-07 03:16:08.000000000 +0000
+++ src/bsd_KbdMap.c
@@ -28,6 +28,7 @@
 #include "bsd_kbd.h"
 
 #if (defined(SYSCONS_SUPPORT) || defined(PCVT_SUPPORT)) && defined(GIO_KEYMAP)
+#if !(defined(__FreeBSD__) && __FreeBSD__ >= 11) && !defined(__DragonFly__)
 #define KD_GET_ENTRY(i,n) \
   eascii_to_x[((keymap.key[i].spcl << (n+1)) & 0x100) + keymap.key[i].map[n]]
 
@@ -188,6 +189,7 @@ static KeySym eascii_to_x[512] = {
 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol
 };
+#endif /* !(defined(__FreeBSD__) && __FreeBSD__ >= 11) */
 
 #ifdef SYSCONS_SUPPORT
 static
@@ -841,6 +843,122 @@ TransMapRec wsAdb = {
     wsAdbMap
 };
 
+/* Map for amiga keyboards  */
+static CARD8 wsAmigaMap[] = {
+	/* 0 */ KEY_Tilde,
+	/* 1 */ KEY_1,
+	/* 2 */ KEY_2,
+	/* 3 */ KEY_3,
+	/* 4 */ KEY_4,
+	/* 5 */ KEY_5,
+	/* 6 */ KEY_6,
+	/* 7 */ KEY_7,
+	/* 8 */ KEY_8,
+	/* 9 */ KEY_9,
+	/* 10 */ KEY_0,
+	/* 11 */ KEY_Minus,
+	/* 12 */ KEY_Equal,
+	/* 13 */ KEY_BSlash,	/* key in this position only on Amiga */
+	/* 14 */ KEY_NOTUSED,
+	/* 15 */ KEY_KP_0,
+	/* 16 */ KEY_Q,
+	/* 17 */ KEY_W,
+	/* 18 */ KEY_E,
+	/* 19 */ KEY_R,
+	/* 20 */ KEY_T,
+	/* 21 */ KEY_Y,
+	/* 22 */ KEY_U,
+	/* 23 */ KEY_I,
+	/* 24 */ KEY_O,
+	/* 25 */ KEY_P,
+	/* 26 */ KEY_LBrace,
+	/* 27 */ KEY_RBrace,
+	/* 28 */ KEY_NOTUSED,
+	/* 29 */ KEY_KP_1,
+	/* 30 */ KEY_KP_2,
+	/* 31 */ KEY_KP_3,
+	/* 32 */ KEY_A,
+	/* 33 */ KEY_S,
+	/* 34 */ KEY_D,
+	/* 35 */ KEY_F,
+	/* 36 */ KEY_G,
+	/* 37 */ KEY_H,
+	/* 38 */ KEY_J,
+	/* 39 */ KEY_K,
+	/* 40 */ KEY_L,
+	/* 41 */ KEY_SemiColon,
+	/* 42 */ KEY_Quote,
+	/* 43 */ KEY_BSlash,	/* # on international keyboards */
+	/* 44 */ KEY_NOTUSED,
+	/* 45 */ KEY_KP_4,
+	/* 46 */ KEY_KP_5,
+	/* 47 */ KEY_KP_6,
+	/* 48 */ KEY_Less,
+	/* 49 */ KEY_Z,
+	/* 50 */ KEY_X,
+	/* 51 */ KEY_C,
+	/* 52 */ KEY_V,
+	/* 53 */ KEY_B,
+	/* 54 */ KEY_N,
+	/* 55 */ KEY_M,
+	/* 56 */ KEY_Comma,
+	/* 57 */ KEY_Period,
+	/* 58 */ KEY_Slash,
+	/* 59 */ KEY_NOTUSED,
+	/* 60 */ KEY_KP_Decimal,
+	/* 61 */ KEY_KP_7,
+	/* 62 */ KEY_KP_8,
+	/* 63 */ KEY_KP_9,
+	/* 64 */ KEY_Space,
+	/* 65 */ KEY_BackSpace,
+	/* 66 */ KEY_Tab,
+	/* 67 */ KEY_KP_Enter,
+	/* 68 */ KEY_Enter,
+	/* 69 */ KEY_Escape,
+	/* 70 */ KEY_Delete,
+	/* 71 */ KEY_NOTUSED,
+	/* 72 */ KEY_NOTUSED, 
+	/* 73 */ KEY_NOTUSED,
+	/* 74 */ KEY_KP_Minus,
+	/* 75 */ KEY_NOTUSED,
+	/* 76 */ KEY_Up,
+	/* 77 */ KEY_Down,
+	/* 78 */ KEY_Right,
+	/* 79 */ KEY_Left,
+	/* 80 */ KEY_F1,
+	/* 81 */ KEY_F2,
+	/* 82 */ KEY_F3,
+	/* 83 */ KEY_F4,
+	/* 84 */ KEY_F5,
+	/* 85 */ KEY_F6,
+	/* 86 */ KEY_F7,
+	/* 87 */ KEY_F8,
+	/* 88 */ KEY_F9,
+	/* 89 */ KEY_F10,
+	/* 90 */ KEY_UNKNOWN,		/* Keypad [ */
+	/* 91 */ KEY_UNKNOWN,		/* Keypad ] */
+	/* 92 */ KEY_KP_Divide,
+	/* 93 */ KEY_KP_Multiply,
+	/* 94 */ KEY_KP_Plus,
+	/* 95 */ KEY_Help,
+	/* 96 */ KEY_ShiftL,
+	/* 97 */ KEY_ShiftR,
+	/* 98 */ KEY_NOTUSED,
+	/* 99 */ KEY_LCtrl,
+	/* 100 */ KEY_Alt,
+	/* 101 */ KEY_AltLang,
+	/* 102 */ KEY_LMeta,
+	/* 103 */ KEY_RMeta
+};
+#define WS_AMIGA_MAP_SIZE (sizeof(wsAmigaMap)/sizeof(*wsAmigaMap))
+
+static
+TransMapRec wsAmiga = {
+    0,
+    WS_AMIGA_MAP_SIZE,
+    wsAmigaMap
+};
+
 /* Map for LK201 keyboards  */
 static CARD8 wsLk201Map[] = {
 	/* 0 */ KEY_F1,
@@ -1261,6 +1379,7 @@ KbdGetMapping (InputInfoPtr pInfo, KeySy
   KeySym        *k;
   int           i;
 
+#if !(defined(__FreeBSD__) && __FreeBSD__ >= 11) && !defined(__DragonFly__)
 #ifndef __bsdi__
   switch (pKbd->consType) {
 
@@ -1294,6 +1413,7 @@ KbdGetMapping (InputInfoPtr pInfo, KeySy
     
   } 
 #endif /* !bsdi */
+#endif /* !(defined(__FreeBSD__) && __FreeBSD__ >= 11) */
 
   /*
    * compute the modifier map
@@ -1386,6 +1506,11 @@ KbdGetMapping (InputInfoPtr pInfo, KeySy
                     pKbd->scancodeMap = &wsAdb; 
                     break;
 #endif
+#ifdef WSKBD_TYPE_AMIGA
+	       case WSKBD_TYPE_AMIGA:
+                    pKbd->scancodeMap = &wsAmiga; 
+                    break;
+#endif
 #ifdef WSKBD_TYPE_LK201
 	       case WSKBD_TYPE_LK201:
                     pKbd->scancodeMap = &wsLk201;
