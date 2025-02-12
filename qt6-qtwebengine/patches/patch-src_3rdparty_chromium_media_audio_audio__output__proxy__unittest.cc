$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/audio/audio_output_proxy_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audio_output_proxy_unittest.cc
@@ -443,7 +443,11 @@ class AudioOutputProxyTest : public test
     // |stream| is closed at this point. Start() should reopen it again.
     EXPECT_CALL(manager(), MakeAudioOutputStream(_, _, _))
         .Times(2)
+#if BUILDFLAG(IS_BSD)
+        .WillRepeatedly(Return(static_cast<AudioOutputStream*>(NULL)));
+#else
         .WillRepeatedly(Return(reinterpret_cast<AudioOutputStream*>(NULL)));
+#endif
 
     EXPECT_CALL(callback_, OnError(_)).Times(2);
 
