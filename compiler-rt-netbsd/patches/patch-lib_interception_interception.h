$NetBSD$

--- lib/interception/interception.h.orig	2018-06-01 09:36:54.000000000 +0000
+++ lib/interception/interception.h
@@ -29,6 +29,7 @@ typedef __sanitizer::uptr    SIZE_T;
 typedef __sanitizer::sptr    SSIZE_T;
 typedef __sanitizer::sptr    PTRDIFF_T;
 typedef __sanitizer::s64     INTMAX_T;
+typedef __sanitizer::u64     UINTMAX_T;
 typedef __sanitizer::OFF_T   OFF_T;
 typedef __sanitizer::OFF64_T OFF64_T;
 
