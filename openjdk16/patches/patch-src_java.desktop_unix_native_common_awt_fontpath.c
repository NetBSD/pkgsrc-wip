$NetBSD: patch-src_java.desktop_unix_native_common_awt_fontpath.c,v 1.1 2019/10/01 12:36:34 tnn Exp $

Use pkgsrc fonts.

--- src/java.desktop/unix/native/common/awt/fontpath.c.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/java.desktop/unix/native/common/awt/fontpath.c	2021-06-10 13:40:58.719993986 -0400
@@ -56,8 +56,8 @@
 extern Display *awt_display;
 #endif /* !HEADLESS */
 
-#define FONTCONFIG_DLL_VERSIONED VERSIONED_JNI_LIB_NAME("fontconfig", "1")
-#define FONTCONFIG_DLL JNI_LIB_NAME("fontconfig")
+#define FONTCONFIG_DLL_VERSIONED "@BUILDLINK_PREFIX.fontconfig@/lib/" JNI_LIB_NAME("fontconfig")
+#define FONTCONFIG_DLL "@BUILDLINK_PREFIX.fontconfig@/lib/" JNI_LIB_NAME("fontconfig")
 
 #define MAXFDIRS 512    /* Max number of directories that contain fonts */
 
@@ -88,6 +88,27 @@
     NULL, /* terminates the list */
 };
 #endif
+static char *pkgsrcFontPath[] = {
+   "@PREFIX@/share/fonts/X11/100dpi",
+   "@PREFIX@/share/fonts/X11/75dpi",
+   "@PREFIX@/share/fonts/X11/Type1",
+   "@PREFIX@/share/fonts/X11/cyrillic",
+   "@PREFIX@/share/fonts/X11/misc",
+   "@PREFIX@/share/fonts/X11/TTF",
+   "/usr/X11R7/lib/X11/fonts/100dpi",
+   "/usr/X11R7/lib/X11/fonts/75dpi",
+   "/usr/X11R7/lib/X11/fonts/Type1",
+   "/usr/X11R7/lib/X11/fonts/cyrillic",
+   "/usr/X11R7/lib/X11/fonts/misc",
+   "/usr/X11R7/lib/X11/fonts/TTF",
+   "/usr/X11R6/lib/X11/fonts/100dpi",
+   "/usr/X11R6/lib/X11/fonts/75dpi",
+   "/usr/X11R6/lib/X11/fonts/Type1",
+   "/usr/X11R6/lib/X11/fonts/cyrillic",
+   "/usr/X11R6/lib/X11/fonts/misc",
+   "/usr/X11R6/lib/X11/fonts/TTF",
+   NULL
+};
 
 static char **getFontConfigLocations();
 
@@ -463,6 +484,7 @@
 #elif defined(_AIX)
     knowndirs = fullAixFontPath;
 #endif
+    knowndirs = pkgsrcFontPath;
     /* REMIND: this code requires to be executed when the GraphicsEnvironment
      * is already initialised. That is always true, but if it were not so,
      * this code could throw an exception and the fontpath would fail to
