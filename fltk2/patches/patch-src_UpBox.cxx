$NetBSD$

Modern compilers may reject 0x55 if char is signed.

--- src/UpBox.cxx.orig	2012-03-23 05:49:17.000000000 +0000
+++ src/UpBox.cxx
@@ -47,7 +47,7 @@ void drawFocusRect(const fltk::Rectangle
   // X version uses stipple pattern because there seem to be too many
   // servers with bugs when drawing dotted lines:
   static const char pattern[]
-    = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA};
+    = {(char)(unsigned char)0xAA,0x55,(char)(unsigned char)0xAA,0x55,(char)(unsigned char)0xAA,0x55,(char)(unsigned char)0xAA,0x55,(char)(unsigned char)0xAA};
   static Pixmap evenstipple, oddstipple;
   if (!evenstipple) {
     XWindow root = RootWindow(xdisplay, xscreen);
