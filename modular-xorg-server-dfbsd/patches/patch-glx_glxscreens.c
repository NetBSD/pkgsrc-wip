$NetBSD$

https://cgit.freedesktop.org/xorg/xserver/commit/?id=c2954b16c8730c7ed8441fd8dba25900f3aed265

glx: do not pick sRGB config for 32-bit RGBA visual
This fixes blending issues seen with kwin and gnome-shell when
32bit visual has sRGB capability set.

Bugzilla: https://bugs.freedesktop.org/show_bug.cgi?id=103699
Bugzilla: https://bugs.freedesktop.org/show_bug.cgi?id=103646
Bugzilla: https://bugs.freedesktop.org/show_bug.cgi?id=103655

--- glx/glxscreens.c.orig	2017-12-20 20:32:33.000000000 +0000
+++ glx/glxscreens.c
@@ -275,6 +275,11 @@ pickFBConfig(__GLXscreen * pGlxScreen, V
         /* If it's the 32-bit RGBA visual, demand a 32-bit fbconfig. */
         if (visual->nplanes == 32 && config->rgbBits != 32)
             continue;
+        /* If it's the 32-bit RGBA visual, do not pick sRGB capable config.
+         * This can cause issues with compositors that are not sRGB aware.
+         */
+        if (visual->nplanes == 32 && config->sRGBCapable == GL_TRUE)
+            continue;
         /* Can't use the same FBconfig for multiple X visuals.  I think. */
         if (config->visualID != 0)
             continue;
