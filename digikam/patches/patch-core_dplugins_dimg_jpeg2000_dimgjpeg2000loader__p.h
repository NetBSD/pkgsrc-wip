$NetBSD$

https://invent.kde.org/graphics/digikam/-/commit/82eb6e5fe3f1d2c0e4c70887877b52aab757116f

--- core/dplugins/dimg/jpeg2000/dimgjpeg2000loader_p.h.orig	2025-03-20 07:34:05.983941091 +0000
+++ core/dplugins/dimg/jpeg2000/dimgjpeg2000loader_p.h
@@ -42,6 +42,7 @@ extern "C"
 #if !defined(Q_OS_DARWIN) && defined(Q_CC_GNU)
 #   pragma GCC diagnostic push
 #   pragma GCC diagnostic ignored "-Wcpp"
+#   pragma GCC diagnostic ignored "-Wundef"
 #endif
 
 #if defined(Q_OS_DARWIN) && defined(Q_CC_CLANG)
