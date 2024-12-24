$NetBSD$

--- src/FFmpegReader.cpp.orig	2024-12-21 22:27:30.000000000 +0000
+++ src/FFmpegReader.cpp
@@ -286,12 +286,12 @@ void FFmpegReader::Open() {
 
 				// Init options
 				av_dict_set(&opts, "strict", "experimental", 0);
+				char *adapter_ptr = NULL;
 #if USE_HW_ACCEL
 				if (hw_de_on && hw_de_supported) {
 					// Open Hardware Acceleration
 					int i_decoder_hw = 0;
 					char adapter[256];
-					char *adapter_ptr = NULL;
 					int adapter_num;
 					adapter_num = openshot::Settings::Instance()->HW_DE_DEVICE_SET;
 					fprintf(stderr, "Hardware decoding device number: %d\n", adapter_num);
@@ -365,9 +365,7 @@ void FFmpegReader::Open() {
 					// Check if it is there and writable
 #if defined(__linux__)
 					if( adapter_ptr != NULL && access( adapter_ptr, W_OK ) == 0 ) {
-#elif defined(_WIN32)
-					if( adapter_ptr != NULL ) {
-#elif defined(__APPLE__)
+#else
 					if( adapter_ptr != NULL ) {
 #endif
 						ZmqLogger::Instance()->AppendDebugMethod("Decode Device present using device");
