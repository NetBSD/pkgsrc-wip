$NetBSD$

Fix incorrect case in roff macro.

--- doc/8bc.ms.orig	2024-03-07 20:00:18.657790530 +0000
+++ doc/8bc.ms
@@ -751,7 +751,7 @@ instructions, statically known skips are
 AC to 0 or 1 followed by
 .CW SZA
 or
-.Cw SNA
+.CW SNA
 are merged into one.
 .PP
 Summarised, the following optimisations are performed:
