$NetBSD: patch-src_i810__reg.h,v 1.1 2013/05/29 03:38:08 makoto Exp $

git clone git://cgit.freedesktop.org/xorg/driver/xf86-video-intel/
git checkout e4cd9de2933ada3e2a4b43552729ae3a370128bf
and make diff

--- src/i810_reg.h.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i810_reg.h
@@ -114,6 +114,7 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
 #define BITBLT_STATUS          0x01
 
 #define CHDECMISC	0x10111
+#define DCC			0x10200
 #define C0DRB0			0x10200
 #define C0DRB1			0x10202
 #define C0DRB2			0x10204
