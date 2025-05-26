$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/google/seven_zip_reader.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/google/seven_zip_reader.cc
@@ -209,7 +209,7 @@ Result SevenZipReaderImpl::Initialize(ba
   look_stream_buffer_.reset(look_stream_.buf);
 
   look_stream_.bufSize = kStreamBufferSize;
-  LookToRead2_Init(&look_stream_);
+  LookToRead2_INIT(&look_stream_);
 
   // The destructor assumes that `stream_` is valid whenever `db_` is
   // initialized.
