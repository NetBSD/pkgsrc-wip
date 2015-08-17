$NetBSD: patch-mfbt_Alignment.h,v 1.2 2015/08/17 07:30:48 thomasklausner Exp $

Make MOZ_ALIGNOF() use gcc's builtin __alignof__.
From https://bugzilla.mozilla.org/show_bug.cgi?id=1026499

--- mfbt/Alignment.h.orig	2015-08-16 14:08:46.000000000 +0000
+++ mfbt/Alignment.h
@@ -10,11 +10,20 @@
 #define mozilla_Alignment_h
 
 #include "mozilla/Attributes.h"
+#include "mozilla/Attributes.h"
+
 #include <stddef.h>
 #include <stdint.h>
 
 namespace mozilla {
 
+#if defined(MOZ_HAVE_CXX11_ALIGNAS)
+#define MOZ_ALIGNOF(T) alignof(T)
+#elif defined(__GNUC__)
+#define MOZ_ALIGNOF(T) __alignof__(T)
+#elif defined(_MSC_VER)
+#define MOZ_ALIGNOF(T) __alignof(T)
+#else
 /*
  * This class, and the corresponding macro MOZ_ALIGNOF, figures out how many
  * bytes of alignment a given type needs.
@@ -33,6 +42,7 @@ public:
 };
 
 #define MOZ_ALIGNOF(T) mozilla::AlignmentFinder<T>::alignment
+#endif
 
 /*
  * Declare the MOZ_ALIGNED_DECL macro for declaring aligned types.
@@ -44,7 +54,10 @@ public:
  * will declare a two-character array |arr| aligned to 8 bytes.
  */
 
-#if defined(__GNUC__)
+#if defined(MOZ_HAVE_CXX11_ALIGNAS)
+#  define MOZ_ALIGNED_DECL(_type, _align) \
+     alignas(_align) _type
+#elif defined(__GNUC__)
 #  define MOZ_ALIGNED_DECL(_type, _align) \
      _type __attribute__((aligned(_align)))
 #elif defined(_MSC_VER)
