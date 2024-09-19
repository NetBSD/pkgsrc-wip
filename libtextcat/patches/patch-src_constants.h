$NetBSD: patch-src_constants.h,v 1.1 2011/02/17 13:19:17 ftigeot Exp $

--- src/constants.h.orig	2003-05-22 11:32:43 +0000
+++ src/constants.h
@@ -39,6 +39,8 @@
  */
 #include <limits.h>
 
+#define _UTF8_
+
 #define DESCRIPTION "out of place"
 
 /* Reported matches are those fingerprints with a score less than best
@@ -59,14 +61,21 @@
 /* Maximum number of n-grams in a fingerprint */
 #define MAXNGRAMS  400
 
-/* Maximum size of an n-gram? */
-#define MAXNGRAMSIZE 5
+/* Maximum number of character of an n-gram? */
+#define MAXNGRAMSYMBOL 5
+
+/* Maximum size of the string representing an n-gram (must be greater than number of symbol) */
+#ifdef _UTF8_
+#define MAXNGRAMSIZE 20
+#else
+#define MAXNGRAMSIZE MAXNGRAMSYMBOL
+#endif
 
 /* Which characters are not acceptable in n-grams? */
-#define INVALID(c) (isspace((int)c) || isdigit((int)c)) 
+#define INVALID(c) (isspace((unsigned char)c) || isdigit((unsigned char)c)) 
 
 /* Minimum size (in characters) for accepting a document */
-#define MINDOCSIZE  25
+#define MINDOCSIZE  6
 
 /* Maximum penalty for missing an n-gram in fingerprint */
 #define MAXOUTOFPLACE 400
@@ -76,4 +85,7 @@
 
 #define MAXSCORE  INT_MAX
 
+/* where the fingerprints files are stored */
+#define DEFAULT_FINGERPRINTS_PATH ""
+
 #endif
