$NetBSD$

Adds support for chromaprint >= 1.4

--- src/musicbrainz/chromaprinter.cpp.orig	2016-04-19 15:08:35.000000000 +0000
+++ src/musicbrainz/chromaprinter.cpp
@@ -143,16 +143,24 @@ QString Chromaprinter::CreateFingerprint
   ChromaprintContext* chromaprint =
       chromaprint_new(CHROMAPRINT_ALGORITHM_DEFAULT);
   chromaprint_start(chromaprint, kDecodeRate, kDecodeChannels);
-  chromaprint_feed(chromaprint, reinterpret_cast<void*>(data.data()),
+  chromaprint_feed(chromaprint, reinterpret_cast<int16_t *>(data.data()),
                    data.size() / 2);
   chromaprint_finish(chromaprint);
 
-  void* fprint = nullptr;
   int size = 0;
+
+#if CHROMAPRINT_VERSION_MAJOR >= 1 && CHROMAPRINT_VERSION_MINOR >= 4
+  u_int32_t *fprint = nullptr;
+  char *encoded = nullptr;
+#else
+  void *fprint = nullptr;
+  void *encoded = nullptr;
+#endif
+
   int ret = chromaprint_get_raw_fingerprint(chromaprint, &fprint, &size);
+
   QByteArray fingerprint;
   if (ret == 1) {
-    void* encoded = nullptr;
     int encoded_size = 0;
     chromaprint_encode_fingerprint(fprint, size, CHROMAPRINT_ALGORITHM_DEFAULT,
                                    &encoded, &encoded_size, 1);
