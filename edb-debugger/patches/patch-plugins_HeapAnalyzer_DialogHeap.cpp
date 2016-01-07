$NetBSD$

--- plugins/HeapAnalyzer/DialogHeap.cpp.orig	2014-01-08 04:14:36.000000000 +0000
+++ plugins/HeapAnalyzer/DialogHeap.cpp
@@ -263,7 +263,7 @@ void DialogHeap::collect_blocks(edb::add
 	const int min_string_length = edb::v1::config().min_string_length;
 
 	if(start_address != 0 && end_address != 0) {
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 		malloc_chunk currentChunk;
 		malloc_chunk nextChunk;
 		edb::address_t currentChunkAddress = start_address;
@@ -412,7 +412,7 @@ void DialogHeap::do_find() {
 	QString ldName;
 
 	get_library_names(&libcName, &ldName);
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 	s = edb::v1::symbol_manager().find(libcName + "::__curbrk");
 	if(s) {
 		end_address = s->address;
