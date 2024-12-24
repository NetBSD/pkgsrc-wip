$NetBSD$

--- src/FFmpegWriter.cpp.orig	2024-12-21 22:27:30.000000000 +0000
+++ src/FFmpegWriter.cpp
@@ -1424,11 +1424,11 @@ void FFmpegWriter::open_video(AVFormatCo
 	// Set number of threads equal to number of processors (not to exceed 16)
 	video_codec_ctx->thread_count = std::min(FF_NUM_PROCESSORS, 16);
 
+	char *adapter_ptr = NULL;
 #if USE_HW_ACCEL
 	if (hw_en_on && hw_en_supported) {
 		//char *dev_hw = NULL;
 		char adapter[256];
-		char *adapter_ptr = NULL;
 		int adapter_num;
 		// Use the hw device given in the environment variable HW_EN_DEVICE_SET or the default if not set
 		adapter_num = openshot::Settings::Instance()->HW_EN_DEVICE_SET;
@@ -1448,7 +1448,7 @@ void FFmpegWriter::open_video(AVFormatCo
 // Check if it is there and writable
 #if defined(__linux__)
 		if( adapter_ptr != NULL && access( adapter_ptr, W_OK ) == 0 ) {
-#elif defined(_WIN32) || defined(__APPLE__)
+#else
 		if( adapter_ptr != NULL ) {
 #endif
 			ZmqLogger::Instance()->AppendDebugMethod(
