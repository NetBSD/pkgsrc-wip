$NetBSD: patch-mfbt_Attributes.h,v 1.4 2015/03/30 08:09:10 thomasklausner Exp $

--- mfbt/Attributes.h.orig	2015-03-24 09:13:57.000000000 +0000
+++ mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_NEVER_INLINE          __declspec(noinline)
 #  define MOZ_HAVE_NORETURN              __declspec(noreturn)
 #  ifdef __clang__
@@ -70,6 +71,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -83,6 +87,9 @@
 #    define MOZ_HAVE_NORETURN            __attribute__((noreturn))
 #  endif
 #elif defined(__GNUC__)
+#  if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
 #      define MOZ_HAVE_CXX11_CONSTEXPR
 #      define MOZ_HAVE_EXPLICIT_CONVERSION
