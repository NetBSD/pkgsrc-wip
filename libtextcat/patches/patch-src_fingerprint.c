$NetBSD: patch-src_fingerprint.c,v 1.1 2011/02/17 13:19:17 ftigeot Exp $

--- src/fingerprint.c.orig	2003-05-22 11:32:43 +0000
+++ src/fingerprint.c
@@ -6,23 +6,23 @@
  * All rights reserved.
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
@@ -51,7 +51,7 @@
  * The reason why we go through the trouble of doing a partial
  * (heap)sort is that a full quicksort behaves horribly on the data:
  * most n-grams have a very low count, resulting in a data set in
- * nearly-sorted order. This causes quicksort to behave very badly. 
+ * nearly-sorted order. This causes quicksort to behave very badly.
  * Heapsort, on the other hand, behaves handsomely: worst case is
  * Mlog(N) for M n-grams filtered through a N-sized heap.
  *
@@ -63,6 +63,10 @@
  * - put table/heap datastructure in a separate file.
  */
 
+#ifndef _UTF8_
+#define _UTF8_
+#endif
+
 #include "config.h"
 #include <stdio.h>
 #ifdef HAVE_STDLIB_H
@@ -80,10 +84,12 @@
 #include "wg_mempool.h"
 #include "constants.h"
 
+#include "utf8misc.h"
 
 #define TABLESIZE  (1<<TABLEPOW)
 #define TABLEMASK  ((TABLESIZE)-1)
 
+
 typedef struct {
 
 	sint2 rank;
@@ -96,7 +102,7 @@ typedef struct fp_s {
 	const char *name;
 	ngram_t *fprint;
 	uint4 size;
-	
+
 } fp_t;
 
 typedef struct entry_s {
@@ -105,13 +111,13 @@ typedef struct entry_s {
 	struct entry_s *next;
 } entry_t;
 
-typedef struct table_s {	
+typedef struct table_s {
 	void *pool;
 	entry_t **table;
 	entry_t *heap;
 
 	struct table_s *next;
-	
+
 	uint4 heapsize;
 	uint4 size;
 } table_t;
@@ -122,7 +128,7 @@ typedef struct table_s {	
  * fast and furious little hash function
  *
  * (Note that we could use some kind of rolling checksum, and update it
- * during n-gram construction) 
+ * during n-gram construction)
  */
 static uint4 simplehash( const char *p, int len )
 {
@@ -134,29 +140,14 @@ static uint4 simplehash( const char *p, 
 }
 
 
-/* checks if n-gram lex is a prefix of key and of length len */
-inline int issame( char *lex, char *key, int len )
-{
-	int i;
-	for (i=0; i<len; i++) {
-		if ( key[i] != lex[i] ) {
-			return 0;
-		}
-	}
-	if ( lex[i] != 0 ) {
-		return 0;
-	}
-	return 1;
-}
-
 
 /* increases frequency of ngram(p,len) */
-static inline int increasefreq( table_t *t, char *p, int len ) 
-{	
-	uint4 hash = simplehash( p, len ) & TABLEMASK;				
+static int increasefreq( table_t *t, char *p, int len )
+{
+	uint4 hash = simplehash( p, len ) & TABLEMASK;
 	entry_t *entry = t->table[ hash ];
-	
-	while ( entry ) {				
+
+	while ( entry ) {
 		if ( issame( entry->str, p, len ) ) {
 			/*** Found it! ***/
 			entry->cnt++;
@@ -168,7 +159,7 @@ static inline int increasefreq( table_t 
 	}
 
 	/*** Not found, so create ***/
-	entry = wgmempool_alloc( t->pool, sizeof(entry_t) );
+        entry = (entry_t*)(wgmempool_alloc( t->pool, sizeof(entry_t) ));
 	strcpy( entry->str, p );
 	entry->cnt = 1;
 
@@ -181,12 +172,12 @@ static inline int increasefreq( table_t 
 #if 0
 
 /* looks up ngram(p,len) */
-static entry_t *findfreq( table_t *t, char *p, int len ) 
-{	
-	uint4 hash = simplehash( p, len ) & TABLEMASK;				
+static entry_t *findfreq( table_t *t, char *p, int len )
+{
+	uint4 hash = simplehash( p, len ) & TABLEMASK;
 	entry_t *entry = t->table[ hash ];
-	
-	while ( entry ) {				
+
+	while ( entry ) {
 		if ( issame( entry->str, p, len ) ) {
 			return entry;
 		}
@@ -219,7 +210,7 @@ static void dumptable(table_t *t)
 #define GREATER(x,y) ((x).cnt > (y).cnt)
 #define LESS(x,y)    ((x).cnt < (y).cnt)
 
-inline static void siftup( table_t *t, unsigned int child )
+static void siftup( table_t *t, unsigned int child )
 {
 	entry_t *heap = t->heap;
 	unsigned int parent = (child-1) >> 1;
@@ -241,7 +232,7 @@ inline static void siftup( table_t *t, u
 }
 
 
-inline static void siftdown( table_t *t, unsigned int heapsize, uint4 parent )
+static void siftdown( table_t *t, unsigned int heapsize, uint4 parent )
 {
 	entry_t *heap = t->heap;
 	unsigned int child = parent*2 + 1;
@@ -273,7 +264,7 @@ static int heapinsert( table_t *t, entry
 	if (t->size < t->heapsize) {
 		memcpy( &(heap[t->size]), item, sizeof(entry_t));
 		siftup( t, t->size );
-		t->size++;		
+		t->size++;
 		return 0;
 	}
 
@@ -316,18 +307,18 @@ static int table2heap(table_t *t)
 
 	/*** Fill result heap ***/
 	for (i=0; i<TABLESIZE; i++) {
-		entry_t *p = t->table[i];	       
+		entry_t *p = t->table[i];
 		while (p) {
 			heapinsert(t, p);
 			p = p->next;
 		}
-	}     
+	}
 	return 1;
 }
 
 
 static table_t *inittable(uint4 maxngrams)
-{	
+{
 	table_t *result = (table_t *)wg_zalloc( sizeof(table_t) );
 	result->table = (entry_t **)wg_zalloc( sizeof(entry_t*) * TABLESIZE );
 	result->pool = wgmempool_Init( 10000, 10 );
@@ -347,14 +338,14 @@ static void tabledone( table_t *t )
 	wgmempool_Done(t->pool);
 	wg_free(t->table);
 	wg_free(t->heap);
-	wg_free(t);	
+	wg_free(t);
 }
 
 
 extern void *fp_Init(const char *name)
 {
 	fp_t *h = (fp_t *)wg_zalloc( sizeof(fp_t) );
-	
+
 	if ( name ) {
 		h->name = wg_strdup(name);
 	}
@@ -458,21 +449,27 @@ static char *prepbuffer( const char *src
 	return dest;
 }
 
-
+/**
+* this function extract all n-gram from past buffer and put them into the table "t"
+* [modified] by Jocelyn Merand to accept utf-8 multi-character symbols to be used in OpenOffice
+*/
 static void createngramtable( table_t *t, const char *buf )
 {
 	char n[MAXNGRAMSIZE+1];
 	const char *p = buf;
 	int i;
+        int pointer = 0;
 
 	/*** Get all n-grams where 1<=n<=MAXNGRAMSIZE. Allow underscores only at borders. ***/
-	for (;;p++) {
+	while(1) {
 
-		const char *q = p;
+     const char *q = &p[pointer];   /*[modified] previously p++ above (for(;;p++)) now, it's pointer wich is increased so we have to get the new pointer on the buffer*/
 		char *m = n;
 
 		/*** First char may be an underscore ***/
-		*m++ = *q++;
+                int decay = charcopy(q, m); /*[modified] previously *q++ = *m++*/
+                q = &(p[pointer+decay]);    /*[modified] the old copying method do not manage multi-character symbols*/
+                m += decay; /*[modified]*/
 		*m = '\0';
 
 		increasefreq( t, n, 1 );
@@ -482,19 +479,22 @@ static void createngramtable( table_t *t
 		}
 
 		/*** Let the compiler unroll this ***/
-		for ( i=2; i<=MAXNGRAMSIZE; i++) {
+		for ( i=2; i<=MAXNGRAMSYMBOL; i++) {
 
-			*m++ = *q;
+                        decay = charcopy(q, m); /*[modified] like above*/
+                        m += decay;
 			*m = '\0';
 
 			increasefreq( t, n, i );
 
 			if ( *q == '_' ) break;
-			q++;
+                        q += decay;
 			if ( *q == '\0' ) {
 				return;
 			}
 		}
+
+  pointer = nextcharstart(p,pointer);   /*[modified] p[pointer] must point on the next start of symbol, but whith utf next start is not surely next char*/
 	}
 	return;
 }
@@ -514,7 +514,7 @@ static int ngramcmp_str(const void *a, c
 {
 	ngram_t *x = (ngram_t *)a;
 	ngram_t *y = (ngram_t *)b;
-	
+
 	return mystrcmp( x->str, y->str );
 }
 
@@ -522,12 +522,12 @@ static int ngramcmp_rank(const void *a, 
 {
 	ngram_t *x = (ngram_t *)a;
 	ngram_t *y = (ngram_t *)b;
-	
+
 	return x->rank - y->rank;
 }
 
 /**
- * Create a fingerprint: 
+ * Create a fingerprint:
  * - record the frequency of each unique n-gram in a hash table
  * - take the most frequent n-grams
  * - sort them alphabetically, recording their relative rank
@@ -544,20 +544,21 @@ extern int fp_Create( void *handle, cons
 	}
 
 	/*** Throw out all invalid chars ***/
-	tmp = prepbuffer( buffer, bufsize ); 	
+	tmp = prepbuffer( buffer, bufsize );
+    /*printf("Cleaned buffer : %s\n",tmp);*/
 	if ( tmp == NULL ) {
 		return 0;
 	}
-
 	h = (fp_t*)handle;
 	t = inittable(maxngrams);
+    /*printf("Table initialized\n");*/
 
 	/*** Create a hash table containing n-gram counts ***/
 	createngramtable(t, tmp);
-
+    /*printf("Table created\n");*/
 	/*** Take the top N n-grams and add them to the profile ***/
-	table2heap(t);	
-	maxngrams = WGMIN( maxngrams, t->size );       
+	table2heap(t);
+	maxngrams = WGMIN( maxngrams, t->size );
 
 	h->fprint = (ngram_t *)wg_malloc( sizeof(ngram_t) * maxngrams );
 	h->size = maxngrams;
@@ -568,7 +569,7 @@ extern int fp_Create( void *handle, cons
 		entry_t tmp2;
 
 		heapextract(t, &tmp2);
-		
+
 		/*** the string and its rank is all we need ***/
 		strcpy( h->fprint[i].str, tmp2.str );
 		h->fprint[i].rank = i;
@@ -578,7 +579,7 @@ extern int fp_Create( void *handle, cons
 	wg_free(tmp);
 
 	/*** Sort n-grams alphabetically, for easy comparison ***/
-	qsort( h->fprint, h->size, sizeof(ngram_t), ngramcmp_str ); 
+	qsort( h->fprint, h->size, sizeof(ngram_t), ngramcmp_str );
 	return 1;
 }
 
@@ -608,7 +609,7 @@ extern int fp_Read( void *handle, const 
 #endif
 		return 0;
 	}
-	
+
 	h->fprint = (ngram_t *)wg_malloc(maxngrams * sizeof(ngram_t));
 
 	while (cnt < maxngrams && wg_getline(line,1024,fp)) {
@@ -635,7 +636,7 @@ extern int fp_Read( void *handle, const 
 	h->size = cnt;
 
 	/*** Sort n-grams, for easy comparison later on ***/
-	qsort( h->fprint, h->size, sizeof(ngram_t), ngramcmp_str ); 
+	qsort( h->fprint, h->size, sizeof(ngram_t), ngramcmp_str );
 
 	fclose(fp);
 
@@ -648,14 +649,15 @@ extern void fp_Print( void *handle, FILE
 {
 	uint4 i;
 	fp_t *h = (fp_t *)handle;
-	ngram_t *tmp = wg_malloc( sizeof(ngram_t) * h->size );
-	
+        ngram_t *tmp = (ngram_t*)wg_malloc( sizeof(ngram_t) * h->size );
+
 	/*** Make a temporary and sort it on rank ***/
 	memcpy( tmp, h->fprint, h->size * sizeof(ngram_t) );
-	qsort( tmp, h->size, sizeof(ngram_t), ngramcmp_rank ); 
+	qsort( tmp, h->size, sizeof(ngram_t), ngramcmp_rank );
 
 	for (i=0; i<h->size; i++) {
-		fprintf( fp, "%s\n", tmp[i].str );
+        /*fprintf( fp, "%s\t%i\n", tmp[i].str, tmp[i].rank );*/
+                fprintf( fp, "%s\n", tmp[i].str);
 	}
 	wg_free( tmp );
 }
@@ -669,7 +671,7 @@ extern sint4 fp_Compare( void *cat, void
 	uint4 i = 0;
 	uint4 j = 0;
 	sint4 sum = 0;
-	
+
 	/*** Compare the profiles in mergesort fashion ***/
 	while ( i < c->size && j < u->size ) {
 
@@ -705,7 +707,7 @@ extern sint4 fp_Compare( void *cat, void
 	}
 
 	return sum;
-	       	
+
 }
 
 
