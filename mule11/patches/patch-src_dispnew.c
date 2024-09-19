$NetBSD: patch-src_dispnew.c,v 1.2 2015/04/07 08:13:26 makoto Exp $

Squelch warining

--- src/dispnew.c.orig	2015-03-28 00:05:34.000000000 +0900
+++ src/dispnew.c	2015-04-07 10:13:29.000000000 +0900
@@ -229,6 +229,7 @@ int debug_preemption_vpos = -1;
 int debug_preemption_char_count = -1;
 
 extern int num_input_chars;
+extern int input_pending;
 
 /* 93.5.22 Y.Niibe -- Nonzero means display double cursor */
 int r2l_double_cursor;
