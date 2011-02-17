$NetBSD: patch-src_common.c,v 1.1 2011/02/17 13:19:17 ftigeot Exp $

--- src/common.c.orig	2003-05-22 11:32:43 +0000
+++ src/common.c
@@ -3,23 +3,23 @@
  *
  * Copyright (c) 2003, WiseGuys Internet B.V.
  * All rights reserved.
- * 
+ *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions
  * are met:
- * 
+ *
  * - Redistributions of source code must retain the above copyright
  * notice, this list of conditions and the following disclaimer.
- * 
+ *
  * - Redistributions in binary form must reproduce the above copyright
  * notice, this list of conditions and the following disclaimer in the
  * documentation and/or other materials provided with the
  * distribution.
- * 
+ *
  * - Neither the name of the WiseGuys Internet B.V. nor the names of
  * its contributors may be used to endorse or promote products derived
  * from this software without specific prior written permission.
- * 
+ *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
@@ -114,11 +114,11 @@ extern char* wg_strdup( const char *s )
 		wgmem_error( "Error while strduping %u bytes.\n", strlen(s) );
 	}
 
-	return( result ); 
+	return( result );
 }
 
-extern void* wg_realloc( void *ptr, size_t size ) 
-{ 
+extern void* wg_realloc( void *ptr, size_t size )
+{
 	void *result;
 
 	if (!size) {
@@ -131,7 +131,7 @@ extern void* wg_realloc( void *ptr, size
 		wgmem_error( "Error while reallocing %u bytes.\n", size );
 	}
 
-	return( result ); 
+	return( result );
 }
 
 extern void wg_free( void *mem )
@@ -148,12 +148,12 @@ extern char *wg_getline( char *line, int
         if ( fgets(line, size, fp) == NULL ) {
 		return NULL;
 	}
-        
+
         /** kill term null **/
         if ( (p = strpbrk( line, "\n\r" )) ) {
                 *p = '\0';
-        }           
-  
+        }
+
         return line;
 }
 
@@ -164,39 +164,39 @@ extern char *wg_getline( char *line, int
  *
  * ARGUMENTS:
  * - result:
- * 
+ *
  *  After the split, this array contains pointers to the start of each
  *  detected segment. Must be preallocated and at least as large as
  *  maxsegments. The pointers point into the dest buffer.
- * 
- * - dest: 
- * 
+ *
+ * - dest:
+ *
  *  String into which result points as an index. Must be preallocated, and
  *  at least as big as src. You can use src as dest, but in that case src
  *  is overwritten!
- * 
- * - src:  
- * 
+ *
+ * - src:
+ *
  *  The string to split. Sequences of whitespace are treated as separators, unless
  *  escaped. There are two ways to escape: by using single quotes (anything
  *  between single quotes is treated as one segment), or by using a backslash
  *  to escape the next character. The backslash escape works inside quotation
  *  as well.
- * 
+ *
  *  Example:
- *  
+ *
  *  "It\'s   very\ easy   'to  use WiseGuys\' wg_split()' function" is split into:
- *  
+ *
  *  "It's"
  *  "very easy"
  *  "to  use WiseGuys' wg_split()"
  *  "function"
- *  
- * - maxsegments: 
- * 
+ *
+ * - maxsegments:
+ *
  *  The maximum number of segments. If the splitter runs out of segments,
  *  the remainder of the string is stored in the last segment.
- *  
+ *
  * RETURN VALUE:
  * The number of segments found.
  */
@@ -218,12 +218,12 @@ unsigned int wg_split( char **result, ch
 		switch (state) {
 		case 0:
 			/*** Skip spaces ***/
-			while ( isspace((int) *p) ) {
+			while ( isspace((unsigned char) *p) ) {
 				p++;
 			}
 			state = 1;
 
-		case 1: 
+		case 1:
 			/*** Start segment ***/
 			result[cnt] = w;
 			cnt++;
@@ -232,12 +232,12 @@ unsigned int wg_split( char **result, ch
 		case 2:
 			/*** Unquoted segment ***/
 			while (*p) {
-				if ( isspace((int) *p) ) {
+				if ( isspace((unsigned char) *p) ) {
 					*w++ = '\0';
 					p++;
 					state = 0;
 					break;
-				}				
+				}
 				else if ( *p == '\'' ) {
 					/*** Start quotation ***/
 					p++;
@@ -292,17 +292,17 @@ unsigned int wg_split( char **result, ch
 }
 
 
+#ifdef HAVE_GETTIMEOFDAY    /* TL : no struct timeval under Win32 */
 extern void wg_timerstart(wgtimer_t *t)
 {
-#ifdef HAVE_GETTIMEOFDAY
         gettimeofday( &(t->start), NULL );
-#endif
 }
+#endif  /* TL : no struct timeval under Win32 */
 
 
+#ifdef HAVE_GETTIMEOFDAY    /* TL : no struct timeval under Win32 */
 extern uint4 wg_timerstop(wgtimer_t *t)
 {
-#ifdef HAVE_GETTIMEOFDAY
 	uint4 result;
         gettimeofday( &(t->stop), NULL );
         result = (t->stop.tv_sec - t->start.tv_sec) * 1000000 +
@@ -312,25 +312,23 @@ extern uint4 wg_timerstop(wgtimer_t *t)
 	t->start.tv_usec = t->stop.tv_usec;
 
 	return result;
-#else
-	return 0;
-#endif
 }
+#endif  /* TL : no struct timeval under Win32 */
 
 
 /**
  * wg_strgmov -- a guarded strcpy() variation
- * 
+ *
  * copies src to dest (including terminating zero), and returns
  * pointer to position of terminating zero in dest. The function is
  * guaranteed not to write past destlimit. If the copy couldn't be
- * finished, the function returns NULL after restoring the first 
- * character in dest for your convenience (since this is usually a zero).  
+ * finished, the function returns NULL after restoring the first
+ * character in dest for your convenience (since this is usually a zero).
  */
 char *wg_strgmov( char *dest, const char *src, const char *destlimit )
 {
 	char tmp, *w;
-	
+
 	if ( !dest || dest >= destlimit ) {
 		return NULL;
 	}
@@ -355,7 +353,7 @@ char *wg_strgmov( char *dest, const char
 }
 
 /*
- * wg_trim() -- remove whitespace surrounding a string. 
+ * wg_trim() -- remove whitespace surrounding a string.
  *
  * Example: "   bla   bla   bla   " becomes "bla   bla   bla" after trimming.
  *
@@ -373,12 +371,12 @@ char *wg_trim( char *dest, const char *s
 	char *lastnonspace = &dest[-1];
 	const char *p = src;
 	char *w = dest;
-	
-	while ( isspace((int)*p) ) {
+
+	while ( isspace((unsigned char)*p) ) {
 		p++;
 	}
 	while (*p) {
-		if ( !isspace((int)*p) ) {
+		if ( !isspace((unsigned char)*p) ) {
 			lastnonspace = w;
 		}
 		*w++ = *p++;
