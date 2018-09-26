$NetBSD$

--- source/fitz/load-jpx.c.orig	2018-09-25 12:39:17.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -577,19 +577,7 @@ void opj_free(void *ptr)
 
 static void * opj_aligned_malloc_n(size_t alignment, size_t size)
 {
-	uint8_t *ptr;
-	int off;
-
-	if (size == 0)
-		return NULL;
-
-	size += alignment + sizeof(uint8_t);
-	ptr = opj_malloc(size);
-	if (ptr == NULL)
-		return NULL;
-	off = alignment-(((int)(intptr_t)ptr) & (alignment - 1));
-	ptr[off-1] = off;
-	return ptr + off;
+	return opj_malloc(size);
 }
 
 void * opj_aligned_malloc(size_t size)
@@ -604,13 +592,7 @@ void * opj_aligned_32_malloc(size_t size
 
 void opj_aligned_free(void* ptr_)
 {
-	uint8_t *ptr = (uint8_t *)ptr_;
-	uint8_t off;
-	if (ptr == NULL)
-		return;
-
-	off = ptr[-1];
-	opj_free((void *)(((unsigned char *)ptr) - off));
+	opj_free(ptr_);
 }
 
 #if 0
