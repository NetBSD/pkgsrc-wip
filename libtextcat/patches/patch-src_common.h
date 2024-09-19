$NetBSD: patch-src_common.h,v 1.1 2011/02/17 13:19:17 ftigeot Exp $

--- src/common.h.orig	2003-05-22 13:02:29 +0000
+++ src/common.h
@@ -1,28 +1,28 @@
 #ifndef _COMMON_H_
 #define _COMMON_H_
 /**
- * common.h -- a mixed bag of helper functions 
+ * common.h -- a mixed bag of helper functions
  *
  * Copyright (C) 2003 WiseGuys Internet B.V.
  *
  * THE BSD LICENSE
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
@@ -86,10 +86,12 @@ typedef char		schar;
 typedef char		boole;
 #endif
 
+#ifdef HAVE_GETTIMEOFDAY    /* TL : no struct timeval under Win32 */
 typedef struct wgtimer_s {
         struct timeval start;
         struct timeval stop;
 } wgtimer_t;
+#endif  /* TL : no struct timeval under Win32 */
 
 
 extern void *wg_malloc( size_t size );
@@ -101,13 +103,15 @@ extern void wg_free( void *mem );
 
 extern char *wg_getline( char *line, int size, FILE *fp );
 
+#ifdef HAVE_GETTIMEOFDAY    /* TL : no struct timeval under Win32 */
 extern void wg_timerstart(wgtimer_t *t);
 extern uint4 wg_timerstop(wgtimer_t *t);
+#endif  /* TL : no struct timeval under Win32 */
 
 extern unsigned int wg_split( char **result, char *dest, char *src, int maxsegments );
 extern char *wg_strgmov( char *dest, const char *src, const char *destlimit );
 extern char *wg_trim( char *dest, const char *src );
 
-      
+
 #endif
 
