$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/constants.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/constants.js
@@ -5,12 +5,15 @@ const isWindows = process.platform === '
 module.exports = {
   // Alphabet chars.
   CHAR_UPPERCASE_A: 65, /* A */
+  CHAR_UPPERCASE_B: 66, /* B */
   CHAR_LOWERCASE_A: 97, /* a */
   CHAR_UPPERCASE_Z: 90, /* Z */
   CHAR_LOWERCASE_Z: 122, /* z */
   CHAR_UPPERCASE_C: 67, /* C */
   CHAR_LOWERCASE_B: 98, /* b */
+  CHAR_UPPERCASE_E: 69, /* E */
   CHAR_LOWERCASE_E: 101, /* e */
+
   CHAR_LOWERCASE_N: 110, /* n */
 
   // Non-alphabetic chars.
