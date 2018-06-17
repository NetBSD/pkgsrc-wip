$NetBSD$

Removed "extern" so that clang (in FreeBSD 11.1) builds are fixed.

--- src/main.cc.orig	2018-06-17 16:39:50.160053000 +0000
+++ src/main.cc
@@ -73,7 +73,11 @@ extern const float TWO_PI = 2 * PI;
 extern const float PI_BY_180 = PI / 180.;
 extern const int MILLION = 1000000;
 extern const char SPC = ' ';
+#if defined (__FreeBSD__)
+const string tokenizer::DEFAULT_DELIMITER (" ");
+#else
 extern const string tokenizer::DEFAULT_DELIMITER (" ");
+#endif
 float widget::R = 0.980392, widget::G = 0.792157, widget::B = 0.509804; // default color for all widgets
 
 // for attack, decay and deltas [see keyboard-keyboard.cc, mondrian.cc, triggered_note.cc]
