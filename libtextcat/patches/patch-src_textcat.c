$NetBSD: patch-src_textcat.c,v 1.1 2011/02/17 13:19:17 ftigeot Exp $

--- src/textcat.c.orig	2003-05-22 11:32:43 +0000
+++ src/textcat.c
@@ -4,23 +4,23 @@
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
@@ -74,6 +74,7 @@
 typedef struct {
 
 	void **fprint;
+        char *fprint_disable;
 	uint4 size;
 	uint4 maxsize;
 
@@ -112,11 +113,21 @@ extern void textcat_Done( void *handle )
 		fp_Done( h->fprint[i] );
 	}
 	wg_free( h->fprint );
+        wg_free( h->fprint_disable );
 	wg_free( h );
 
 }
 
-extern void *textcat_Init( const char *conffile )
+/** Replaces older function */
+extern void *textcat_Init( const char *conffile ){
+    return special_textcat_Init( conffile, DEFAULT_FINGERPRINTS_PATH );
+}
+
+/**
+ * Originaly this function had only one parameter (conffile) it has been modified since OOo use
+ * Basicaly prefix is the directory path where fingerprints are stored
+ */
+extern void *special_textcat_Init( const char *conffile, const char *prefix )
 {
 	textcat_t *h;
 	char line[1024];
@@ -134,11 +145,13 @@ extern void *textcat_Init( const char *c
 	h->size = 0;
 	h->maxsize = 16;
 	h->fprint = (void **)wg_malloc( sizeof(void*) * h->maxsize );
+ h->fprint_disable = (char *)wg_malloc( sizeof(char*) * h->maxsize );   /*added to store the state of languages*/
 
 	while ( wg_getline( line, 1024, fp ) ) {
 		char *p;
 		char *segment[4];
-		int res;
+                char finger_print_file_name[512];
+                int res;
 
 		/*** Skip comments ***/
 #ifdef HAVE_STRCHR
@@ -156,17 +169,23 @@ extern void *textcat_Init( const char *c
 		/*** Ensure enough space ***/
 		if ( h->size == h->maxsize ) {
 			h->maxsize *= 2;
-			h->fprint = (void *)wg_realloc( h->fprint, sizeof(void*) * h->maxsize );
+			h->fprint = (void **)wg_realloc( h->fprint, sizeof(void*) * h->maxsize );
+                        h->fprint_disable = (char *)wg_realloc( h->fprint_disable, sizeof(char*) * h->maxsize );
 		}
 
 		/*** Load data ***/
 		if ((h->fprint[ h->size ] = fp_Init( segment[1] ))==NULL) {
 			goto ERROR;
 		}
-		if ( fp_Read( h->fprint[h->size], segment[0], 400 ) == 0 ) {
+                finger_print_file_name[0] = '\0';
+                strcat(finger_print_file_name, prefix);
+                strcat(finger_print_file_name, segment[0]);
+
+                if ( fp_Read( h->fprint[h->size], finger_print_file_name, 400 ) == 0 ) {
 			textcat_Done(h);
 			goto ERROR;
-		}		
+		}
+                h->fprint_disable[h->size] = 0xF0;  /*0xF0 is the code for enabled languages, 0x0F is for disabled*/
 		h->size++;
 	}
 
@@ -203,11 +222,18 @@ extern char *textcat_Classify( void *han
 		result = _TEXTCAT_RESULT_SHORT;
 		goto READY;
 	}
-	
+
 	/*** Calculate the score for each category. ***/
 	for (i=0; i<h->size; i++) {
-		int score = fp_Compare( h->fprint[i], unknown, threshold );
-		candidates[i].score = score;
+                int score;
+                if(h->fprint_disable[i] & 0x0F){    /*if this language is disabled*/
+                    score = MAXSCORE;
+                }
+                else{
+                    score = fp_Compare( h->fprint[i], unknown, threshold );
+                    /*printf("Score for %s : %i\n", fp_Name(h->fprint[i]), score);*/
+                }
+                candidates[i].score = score;
 		candidates[i].name = fp_Name( h->fprint[i] );
 		if ( score < minscore ) {
 			minscore = score;
@@ -218,7 +244,6 @@ extern char *textcat_Classify( void *han
 	/*** Find the best performers ***/
 	for (i=0; i<h->size; i++) {
 		if ( candidates[i].score < threshold ) {
-
 			if ( ++cnt == MAXCANDIDATES+1 ) {
 				break;
 			}
@@ -235,7 +260,7 @@ extern char *textcat_Classify( void *han
 	else {
 		char *p = result;
 		char *plimit = result+MAXOUTPUTSIZE;
-		
+
 		qsort( candidates, cnt, sizeof(candidate_t), cmpcandidates );
 
 		*p = '\0';
@@ -247,7 +272,7 @@ extern char *textcat_Classify( void *han
 	}
  READY:
 	fp_Done(unknown);
-#ifdef SHOULD_FREE 
+#ifdef SHOULD_FREE
 	free(candidates);
 #undef SHOULD_FREE
 #endif
