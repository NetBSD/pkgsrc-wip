$NetBSD$


--- ./Source/cmake/OptionsGTK.cmake.orig	2024-05-28 19:57:38.761533500 +0900
+++ ./Source/cmake/OptionsGTK.cmake	2024-06-22 17:58:28.687546450 +0900
@@ -19,7 +19,7 @@ find_package(Libtasn1 REQUIRED)
 find_package(HarfBuzz 1.4.2 REQUIRED COMPONENTS ICU)
 find_package(ICU 61.2 REQUIRED COMPONENTS data i18n uc)
 find_package(JPEG REQUIRED)
-find_package(Epoxy 1.5.4 REQUIRED)
+#ind_package(Epoxy 1.5.4 REQUIRED)
 find_package(LibXml2 2.8.0 REQUIRED)
 find_package(PNG REQUIRED)
 find_package(SQLite3 REQUIRED)
@@ -51,7 +51,7 @@ WEBKIT_OPTION_DEFINE(ENABLE_QUARTZ_TARGE
 WEBKIT_OPTION_DEFINE(ENABLE_WAYLAND_TARGET "Whether to enable support for the Wayland windowing target." PUBLIC ON)
 WEBKIT_OPTION_DEFINE(ENABLE_X11_TARGET "Whether to enable support for the X11 windowing target." PUBLIC ON)
 WEBKIT_OPTION_DEFINE(USE_GBM "Whether to enable usage of GBM." PUBLIC ON)
-WEBKIT_OPTION_DEFINE(USE_GTK4 "Whether to enable usage of GTK4 instead of GTK3." PUBLIC ON)
+#EBKIT_OPTION_DEFINE(USE_GTK4 "Whether to enable usage of GTK4 instead of GTK3." PUBLIC ON)
 WEBKIT_OPTION_DEFINE(USE_LIBBACKTRACE "Whether to enable usage of libbacktrace." PUBLIC ON)
 WEBKIT_OPTION_DEFINE(USE_LIBDRM "Whether to enable usage of libdrm." PUBLIC ON)
 WEBKIT_OPTION_DEFINE(USE_LIBHYPHEN "Whether to enable the default automatic hyphenation implementation." PUBLIC ON)
@@ -61,7 +61,7 @@ WEBKIT_OPTION_DEFINE(USE_SOUP2 "Whether 
 WEBKIT_OPTION_DEPEND(ENABLE_DOCUMENTATION ENABLE_INTROSPECTION)
 WEBKIT_OPTION_DEPEND(USE_GBM USE_LIBDRM)
 
-WEBKIT_OPTION_CONFLICT(USE_GTK4 USE_SOUP2)
+# WEBKIT_OPTION_CONFLICT(USE_GTK4 USE_SOUP2)
 
 # Private options specific to the GTK port. Changing these options is
 # completely unsupported. They are intended for use only by WebKit developers.
