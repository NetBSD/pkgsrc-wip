$NetBSD$

--- src/image.c.orig	2024-12-03 07:29:35.236430216 +0000
+++ src/image.c
@@ -11688,7 +11688,7 @@ DEF_DLL_FN (void, rsvg_handle_get_dimens
 DEF_DLL_FN (gboolean, rsvg_handle_set_stylesheet,
 	    (RsvgHandle *, const guint8 *, gsize, GError **));
 #  endif
-#  if LIBRSVG_CHECK_VERSION (2, 58, 0)
+#  if LIBRSVG_CHECK_VERSION (2, 58, 90)
 DEF_DLL_FN (GdkPixbuf *, rsvg_handle_get_pixbuf_and_error, (RsvgHandle *, GError **));
 #  else
 DEF_DLL_FN (GdkPixbuf *, rsvg_handle_get_pixbuf, (RsvgHandle *));
@@ -11751,7 +11751,7 @@ init_svg_functions (void)
 #if LIBRSVG_CHECK_VERSION (2, 48, 0)
   LOAD_DLL_FN (library, rsvg_handle_set_stylesheet);
 #endif
-#if LIBRSVG_CHECK_VERSION (2, 58, 0)
+#if LIBRSVG_CHECK_VERSION (2, 58, 90)
   LOAD_DLL_FN (library, rsvg_handle_get_pixbuf_and_error);
 #else
   LOAD_DLL_FN (library, rsvg_handle_get_pixbuf);
@@ -11800,7 +11800,7 @@ init_svg_functions (void)
 #  if LIBRSVG_CHECK_VERSION (2, 48, 0)
 #   undef rsvg_handle_set_stylesheet
 #  endif
-#  if LIBRSVG_CHECK_VERSION (2, 58, 0)
+#  if LIBRSVG_CHECK_VERSION (2, 58, 90)
 #   undef rsvg_handle_get_pixbuf_and_error
 #  else
 #   undef rsvg_handle_get_pixbuf
@@ -11845,7 +11845,7 @@ init_svg_functions (void)
 #  if LIBRSVG_CHECK_VERSION (2, 48, 0)
 #   define rsvg_handle_set_stylesheet fn_rsvg_handle_set_stylesheet
 #  endif
-#  if LIBRSVG_CHECK_VERSION (2, 58, 0)
+#  if LIBRSVG_CHECK_VERSION (2, 58, 90)
 #   define rsvg_handle_get_pixbuf_and_error fn_rsvg_handle_get_pixbuf_and_error
 #  else
 #   define rsvg_handle_get_pixbuf fn_rsvg_handle_get_pixbuf
@@ -12354,7 +12354,7 @@ svg_load_image (struct frame *f, struct 
 
   /* We can now get a valid pixel buffer from the svg file, if all
      went ok.  */
-#if LIBRSVG_CHECK_VERSION (2, 58, 0)
+#if LIBRSVG_CHECK_VERSION (2, 58, 90)
   pixbuf = rsvg_handle_get_pixbuf_and_error (rsvg_handle, &err);
   if (err) goto rsvg_error;
 #else
