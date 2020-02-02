$NetBSD$

--- src/nuspell/utils.hxx.orig	2019-11-23 18:52:51.000000000 +0000
+++ src/nuspell/utils.hxx
@@ -111,7 +111,7 @@ class Encoding_Converter {
 };
 
 //#if _POSIX_VERSION >= 200809L
-#ifdef _POSIX_VERSION
+#if defined(_POSIX_VERSION) && !defined(__NetBSD__)
 class Setlocale_To_C_In_Scope {
 	locale_t old_loc = nullptr;
 
