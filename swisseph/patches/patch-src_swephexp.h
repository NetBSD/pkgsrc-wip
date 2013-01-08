$NetBSD: patch-src_swephexp.h,v 1.1 2013/01/08 03:55:32 othyro Exp $

Don't hardcode SE_EPHE_PATH.

--- src/swephexp.h.orig	2012-09-04 08:44:14.000000000 +0000
+++ src/swephexp.h
@@ -322,7 +322,7 @@ extern "C" {
  * Normally, every application should make this call to define its
  * own place for the ephemeris files.
  */
-
+#ifndef SE_EPHE_PATH
 #if MSDOS
 #ifdef PAIR_SWEPH
 #  define SE_EPHE_PATH    "\\pair\\ephe\\"
@@ -340,6 +340,7 @@ extern "C" {
 			   the long file in /users/ephe2/ast*. */
 # endif
 #endif
+#endif
 
 /* defines for function swe_split_deg() (in swephlib.c) */
 # define SE_SPLIT_DEG_ROUND_SEC    1
