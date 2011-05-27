$NetBSD: patch-media_ffmpeg_file__protocol.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- media/ffmpeg/file_protocol.cc.orig	2011-05-24 08:01:03.000000000 +0000
+++ media/ffmpeg/file_protocol.cc
@@ -56,7 +56,7 @@ static int WriteContext(URLContext* h, u
   return HANDLE_EINTR(write(GetHandle(h), buf, size));
 }
 
-static int64 SeekContext(URLContext* h, int64 offset, int whence) {
+static int64_t SeekContext(URLContext* h, int64_t offset, int whence) {
 #if defined(OS_WIN)
   return _lseeki64(GetHandle(h), static_cast<__int64>(offset), whence);
 #else
