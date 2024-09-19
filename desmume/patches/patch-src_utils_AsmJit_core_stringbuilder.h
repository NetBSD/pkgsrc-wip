$NetBSD: patch-src_utils_AsmJit_core_stringbuilder.h,v 1.2 2013/12/19 05:07:52 othyro Exp $

Needs va_list.

--- src/utils/AsmJit/core/stringbuilder.h.orig	2013-11-28 00:37:27.000000000 +0000
+++ src/utils/AsmJit/core/stringbuilder.h
@@ -4,6 +4,8 @@
 // [License]
 // Zlib - See COPYING file in this package.
 
+#include <stdarg.h>
+
 // [Guard]
 #ifndef _ASMJIT_CORE_STRINGBUILDER_H
 #define _ASMJIT_CORE_STRINGBUILDER_H
