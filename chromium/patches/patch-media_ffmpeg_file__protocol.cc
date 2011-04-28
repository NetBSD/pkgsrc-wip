$NetBSD: patch-media_ffmpeg_file__protocol.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- media/ffmpeg/file_protocol.cc.orig	2011-04-13 08:01:06.000000000 +0000
+++ media/ffmpeg/file_protocol.cc
@@ -58,7 +58,7 @@ int WriteContext(URLContext* h, unsigned
   return HANDLE_EINTR(write(GetHandle(h), buf, size));
 }
 
-int64 SeekContext(URLContext* h, int64 offset, int whence) {
+int64_t SeekContext(URLContext* h, int64_t offset, int whence) {
 #if defined(OS_WIN)
   return _lseeki64(GetHandle(h), static_cast<__int64>(offset), whence);
 #else
