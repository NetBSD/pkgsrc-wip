$NetBSD$

Add an option to request no 128bit atomics.

-- with GCC, this unconditionally emits a call to libatomic.
On NetBSD, no libatomic is supplied, so we can't provide it even on CPUs
with 128bit atomics.

--- src/common/pony/detail/atomics.h.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/common/pony/detail/atomics.h
@@ -91,7 +91,7 @@ namespace ponyint_atomics
 #  define PONY_ABA_PROTECTED_PTR_DECLARE(T)
 #  define PONY_ABA_PROTECTED_PTR(T) ponyint_atomics::aba_protected_ptr_t<T>
 #else
-#  if defined(__LP64__) || defined(_WIN64)
+#  if !defined(AVOID_128BIT_ATOMICS) && (defined(__LP64__) || defined(_WIN64))
 #    define PONY_DOUBLEWORD __int128_t
 #  else
 #    define PONY_DOUBLEWORD int64_t
