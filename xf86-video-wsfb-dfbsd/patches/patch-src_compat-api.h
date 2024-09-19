$NetBSD: patch-src_compat-api.h,v 1.1 2015/04/02 22:16:49 tnn Exp $

From 586b722fb17b3eb0ab776c170ee21e6a66fc7f22 Mon Sep 17 00:00:00 2001
From: Matthieu Herrb <matthieu.herrb@laas.fr>
Date: Sun, 9 Sep 2012 11:41:58 +0200
Subject: Add compat-api.h for compatibility with xserver 1.13

--- src/compat-api.h.orig	2015-04-02 17:09:03.000000000 +0000
+++ src/compat-api.h
@@ -0,0 +1,98 @@
+/*
+ * Copyright 2012 Red Hat, Inc.
+ *
+ * Permission is hereby granted, free of charge, to any person obtaining a
+ * copy of this software and associated documentation files (the "Software"),
+ * to deal in the Software without restriction, including without limitation
+ * the rights to use, copy, modify, merge, publish, distribute, sublicense,
+ * and/or sell copies of the Software, and to permit persons to whom the
+ * Software is furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice (including the next
+ * paragraph) shall be included in all copies or substantial portions of the
+ * Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+ * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+ * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
+ * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
+ * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
+ * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
+ * DEALINGS IN THE SOFTWARE.
+ *
+ * Author: Dave Airlie <airlied@redhat.com>
+ */
+
+/* this file provides API compat between server post 1.13 and pre it,
+   it should be reused inside as many drivers as possible */
+#ifndef COMPAT_API_H
+#define COMPAT_API_H
+
+#ifndef GLYPH_HAS_GLYPH_PICTURE_ACCESSOR
+#define GetGlyphPicture(g, s) GlyphPicture((g))[(s)->myNum]
+#define SetGlyphPicture(g, s, p) GlyphPicture((g))[(s)->myNum] = p
+#endif
+
+#ifndef XF86_HAS_SCRN_CONV
+#define xf86ScreenToScrn(s) xf86Screens[(s)->myNum]
+#define xf86ScrnToScreen(s) screenInfo.screens[(s)->scrnIndex]
+#endif
+
+#ifndef XF86_SCRN_INTERFACE
+
+#define SCRN_ARG_TYPE int
+#define SCRN_INFO_PTR(arg1) ScrnInfoPtr pScrn = xf86Screens[(arg1)]
+
+#define SCREEN_ARG_TYPE int
+#define SCREEN_PTR(arg1) ScreenPtr pScreen = screenInfo.screens[(arg1)]
+
+#define SCREEN_INIT_ARGS_DECL int i, ScreenPtr pScreen, int argc, char **argv
+
+#define BLOCKHANDLER_ARGS_DECL int arg, pointer blockData, pointer pTimeout, pointer pReadmask
+#define BLOCKHANDLER_ARGS arg, blockData, pTimeout, pReadmask
+
+#define CLOSE_SCREEN_ARGS_DECL int scrnIndex, ScreenPtr pScreen
+#define CLOSE_SCREEN_ARGS scrnIndex, pScreen
+
+#define ADJUST_FRAME_ARGS_DECL int arg, int x, int y, int flags
+#define ADJUST_FRAME_ARGS(arg, x, y) (arg)->scrnIndex, x, y, 0
+
+#define SWITCH_MODE_ARGS_DECL int arg, DisplayModePtr mode, int flags
+#define SWITCH_MODE_ARGS(arg, m) (arg)->scrnIndex, m, 0
+
+#define FREE_SCREEN_ARGS_DECL int arg, int flags
+
+#define VT_FUNC_ARGS_DECL int arg, int flags
+#define VT_FUNC_ARGS pScrn->scrnIndex, 0
+
+#define SCRN_OR_INDEX_ARG(x) ((x)->scrnIndex)
+#else
+#define SCRN_ARG_TYPE ScrnInfoPtr
+#define SCRN_INFO_PTR(arg1) ScrnInfoPtr pScrn = (arg1)
+
+#define SCREEN_ARG_TYPE ScreenPtr
+#define SCREEN_PTR(arg1) ScreenPtr pScreen = (arg1)
+
+#define SCREEN_INIT_ARGS_DECL ScreenPtr pScreen, int argc, char **argv
+
+#define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout, pointer pReadmask
+#define BLOCKHANDLER_ARGS arg, pTimeout, pReadmask
+
+#define CLOSE_SCREEN_ARGS_DECL ScreenPtr pScreen
+#define CLOSE_SCREEN_ARGS pScreen
+
+#define ADJUST_FRAME_ARGS_DECL ScrnInfoPtr arg, int x, int y
+#define ADJUST_FRAME_ARGS(arg, x, y) arg, x, y
+
+#define SWITCH_MODE_ARGS_DECL ScrnInfoPtr arg, DisplayModePtr mode
+#define SWITCH_MODE_ARGS(arg, m) arg, m
+#define FREE_SCREEN_ARGS_DECL ScrnInfoPtr arg
+
+#define VT_FUNC_ARGS_DECL ScrnInfoPtr arg
+#define VT_FUNC_ARGS pScrn
+
+#define SCRN_OR_INDEX_ARG(x) (x)
+
+#endif
+
+#endif
