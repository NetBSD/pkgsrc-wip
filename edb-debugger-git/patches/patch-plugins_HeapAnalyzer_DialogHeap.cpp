$NetBSD$

--- plugins/HeapAnalyzer/DialogHeap.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ plugins/HeapAnalyzer/DialogHeap.cpp
@@ -277,7 +277,7 @@ void DialogHeap::collect_blocks(edb::add
 		const int min_string_length = edb::v1::config().min_string_length;
 
 		if(start_address != 0 && end_address != 0) {
-	#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+	#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 			malloc_chunk<Addr> currentChunk;
 			malloc_chunk<Addr> nextChunk;
 			edb::address_t currentChunkAddress = start_address;
@@ -426,7 +426,7 @@ void DialogHeap::do_find() {
 		QString ldName;
 
 		get_library_names(&libcName, &ldName);
-	#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+	#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 		Symbol::pointer s = edb::v1::symbol_manager().find(libcName + "::__curbrk");
 		if(s) {
 			end_address = s->address;
