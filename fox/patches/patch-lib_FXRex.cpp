$NetBSD$

Disable debugging code.

Patch by Jeroen van der Zijp posted on foxgui-users mailing list
at 2022-04-01 19:42:35.
--- lib/FXRex.cpp.orig	2022-03-01 04:44:00.000000000 +0000
+++ lib/FXRex.cpp
@@ -503,7 +503,7 @@
 */
 
 #define TOPIC_CONSTRUCT 1000
-#define TOPIC_REXDUMP   1014          // Debugging regex code
+//#define TOPIC_REXDUMP   1014          // Debugging regex code
 
 
 // As close to infinity as we're going to get; this seems big enough.  We can not make
