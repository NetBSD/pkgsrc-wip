$NetBSD$

--- debug.h.orig	2019-03-27 16:23:18.924489230 +0000
+++ debug.h
@@ -58,7 +58,7 @@ enum eDebugLevels {
 *   Function prototypes
 */
 extern void lineBreak (void);
-extern void debugPrintf (const enum eDebugLevels level, const char *const format, ...) __printf__ (2, 3);
+extern void debugPrintf (const enum eDebugLevels level, const char *const format, ...) CTAGS_PRINTF (2, 3);
 extern void debugPutc (const int level, const int c);
 extern void debugParseNest (const boolean increase, const unsigned int level);
 extern void debugCppNest (const boolean begin, const unsigned int level);
