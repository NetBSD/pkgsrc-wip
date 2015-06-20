$NetBSD: patch-read.c,v 1.1 2015/06/20 19:27:52 ishit Exp $

fix "warning: 'archive_read_support_compression_none' is deprecated" from github.

--- read.c.orig	2013-01-09 04:25:03.000000000 +0000
+++ read.c
@@ -77,8 +77,8 @@ static void rbuf_consume(size_t bytes);
 static void rbuf_dispatch(void);
 
 static bool read_header(lzma_check *check);
-static bool read_block(bool force_stream, lzma_check check);
-static void read_streaming(lzma_block *block);
+static bool read_block(bool force_stream, lzma_check check, off_t uoffset);
+static void read_streaming(lzma_block *block, block_type sized, off_t uoffset);
 static void read_index(void);
 static void read_footer(void);
 
@@ -115,7 +115,7 @@ void pixz_read(bool verify, size_t nspec
         off_t lastoff = 0;
         
         struct archive *ar = archive_read_new();
-        archive_read_support_compression_none(ar);
+        prevent_compression(ar);
         archive_read_support_format_tar(ar);
         archive_read_open(ar, NULL, tar_ok, tar_read, tar_ok);
         struct archive_entry *entry;
@@ -150,7 +150,7 @@ void pixz_read(bool verify, size_t nspec
             wlast = w;
             w = w->next;
         }
-		archive_read_finish(ar);
+		finish_reading(ar);
         if (w && w->name)
             die("File %s missing in archive", w->name);
         tar_write_last(); // write whatever's left
@@ -178,11 +178,13 @@ void pixz_read(bool verify, size_t nspec
 				tar = taste_tar(ib);
 				start = false;
 			}
-			if (ib->btype != BLOCK_SIZED)
+			if (ib->btype == BLOCK_UNSIZED)
 				all_sized = false;
 			
-			if (!skipping)
-				fwrite(ib->output, ib->outsize, 1, gOutFile);
+			if (!skipping) {
+				if (fwrite(ib->output, ib->outsize, 1, gOutFile) != 1)
+					die("Can't write block");
+			}
             queue_push(gPipelineStartQ, PIPELINE_ITEM, pi);
         }
     }
@@ -361,7 +363,7 @@ static bool read_header(lzma_check *chec
 	return true;
 }
 
-static bool read_block(bool force_stream, lzma_check check) {
+static bool read_block(bool force_stream, lzma_check check, off_t uoffset) {
     lzma_filter filters[LZMA_FILTERS_MAX + 1];
     lzma_block block = { .filters = filters, .check = check, .version = 0 };
 	
@@ -379,10 +381,9 @@ static bool read_block(bool force_stream
 		die("Error decoding block header");
 		
 	size_t comp = block.compressed_size, outsize = block.uncompressed_size;
-	if (force_stream || comp == LZMA_VLI_UNKNOWN
-			|| outsize == LZMA_VLI_UNKNOWN
-			|| outsize > MAXSPLITSIZE) {
-		read_streaming(&block);
+	bool sized = (comp != LZMA_VLI_UNKNOWN && outsize != LZMA_VLI_UNKNOWN);
+    if (force_stream || !sized || outsize > MAXSPLITSIZE) {
+		read_streaming(&block, sized ? BLOCK_SIZED : BLOCK_UNSIZED, uoffset);
 	} else {
 		block_capacity(gRbuf, 0, outsize);
 		gRbuf->outsize = outsize;
@@ -396,7 +397,7 @@ static bool read_block(bool force_stream
 	return true;
 }
 
-static void read_streaming(lzma_block *block) {
+static void read_streaming(lzma_block *block, block_type sized, off_t uoffset) {
     lzma_stream stream = LZMA_STREAM_INIT;
     if (lzma_block_decoder(&stream, block) != LZMA_OK)
 		die("Error initializing streaming block decode");
@@ -415,12 +416,14 @@ static void read_streaming(lzma_block *b
 		if (stream.avail_out == 0) {
 			if (ib) {
 				ib->outsize = ib->outcap;
+                ib->uoffset = uoffset;
+                uoffset += ib->outsize;
 				pipeline_dispatch(pi, gPipelineMergeQ);
 				first = false;
 			}
 			queue_pop(gPipelineStartQ, (void**)&pi);
 			ib = (io_block_t*)pi->data;
-			ib->btype = (first ? BLOCK_UNSIZED : BLOCK_CONTINUATION);
+			ib->btype = (first ? sized : BLOCK_CONTINUATION);
 			block_capacity(ib, 0, STREAMSIZE);
 			stream.next_out = ib->output;
 			stream.avail_out = ib->outcap;
@@ -484,7 +487,7 @@ static void read_thread_noindex(void) {
 	lzma_check check = LZMA_CHECK_NONE;
 	while (read_header(&check)) {
 		empty = false;
-		while (read_block(false, check))
+		while (read_block(false, check, 0))
 			; // pass
 		read_index();
 		read_footer();
@@ -519,13 +522,6 @@ static void read_thread(void) {
         }
         debug("read: want %llu", iter.block.number_in_file);
         
-        // Get a block to work with
-        pipeline_item_t *pi;
-        queue_pop(gPipelineStartQ, (void**)&pi);
-        io_block_t *ib = (io_block_t*)(pi->data);
-		block_capacity(ib, iter.block.unpadded_size,
-			iter.block.uncompressed_size);
-        
         // Seek if needed, and get the data
         if (offset != boffset) {
             fseeko(gInFile, boffset, SEEK_SET);
@@ -535,8 +531,16 @@ static void read_thread(void) {
 		if (iter.block.uncompressed_size > MAXSPLITSIZE) { // must stream
 			if (gRbuf)
 				rbuf_consume(gRbuf->insize); // clear
-			read_block(true, iter.stream.flags->check);
+			read_block(true, iter.stream.flags->check,
+                iter.block.uncompressed_file_offset);
 		} else {
+            // Get a block to work with
+            pipeline_item_t *pi;
+            queue_pop(gPipelineStartQ, (void**)&pi);
+            io_block_t *ib = (io_block_t*)(pi->data);
+            block_capacity(ib, iter.block.unpadded_size,
+                iter.block.uncompressed_size);
+            
 	        ib->insize = fread(ib->input, 1, bsize, gInFile);
 	        if (ib->insize < bsize)
 	            die("Error reading block contents");
@@ -616,7 +620,8 @@ static bool tar_next_block(void) {
 static void tar_write_last(void) {
     if (gArItem) {
         io_block_t *ib = (io_block_t*)(gArItem->data);
-        fwrite(ib->output + gArLastOffset, gArLastSize, 1, gOutFile);
+        if (fwrite(ib->output + gArLastOffset, gArLastSize, 1, gOutFile) != 1)
+			die("Can't write previous block");
         gArLastSize = 0;
     }
 }
@@ -664,12 +669,12 @@ static ssize_t tar_read(struct archive *
 
 static bool taste_tar(io_block_t *ib) {
     struct archive *ar = archive_read_new();
-    archive_read_support_compression_none(ar);
+    prevent_compression(ar);
     archive_read_support_format_tar(ar);
     archive_read_open_memory(ar, ib->output, ib->outsize);
     struct archive_entry *entry;
     bool ok = (archive_read_next_header(ar, &entry) == ARCHIVE_OK);
-	archive_read_finish(ar);
+	finish_reading(ar);
 	return ok;
 }
 
