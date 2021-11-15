$NetBSD$

Workaround for disabling PCH.

--- common/lc_instructions.h.orig	2021-06-05 23:41:42.000000000 +0000
+++ common/lc_instructions.h
@@ -1,5 +1,6 @@
 #pragma once
 
+#include "lc_global.h"
 #include "lc_math.h"
 
 struct lcInstructionsPageSetup
