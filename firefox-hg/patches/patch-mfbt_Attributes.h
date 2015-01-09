$NetBSD: patch-mfbt_Attributes.h,v 1.2 2015/01/09 09:08:09 thomasklausner Exp $

--- mfbt/Attributes.h.orig	2015-01-09 02:12:36.000000000 +0000
+++ mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_CXX11_DELETE
 #  define MOZ_HAVE_CXX11_FINAL         final
 #  define MOZ_HAVE_CXX11_OVERRIDE
@@ -73,6 +74,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -94,6 +98,9 @@
 #  endif
 #elif defined(__GNUC__)
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
+#    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
+#    endif
 #    if MOZ_GCC_VERSION_AT_LEAST(4, 7, 0)
 #      define MOZ_HAVE_CXX11_OVERRIDE
 #      define MOZ_HAVE_CXX11_FINAL       final
