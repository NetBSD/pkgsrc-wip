$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- cc/tiles/gpu_image_decode_cache.cc.orig	2024-10-18 12:33:59.978154700 +0000
+++ cc/tiles/gpu_image_decode_cache.cc
@@ -2398,6 +2398,9 @@ void GpuImageDecodeCache::DecodeImageIfN
 
   image_data->decode.ResetData();
 
+  // Prevent image_data from being deleted while lock is not held.
+  scoped_refptr<ImageData> image_data_holder(image_data);
+
   // Decode the image into `aux_image_data` while the lock is not held.
   DecodedAuxImageData aux_image_data[kAuxImageCount];
   {
@@ -2725,6 +2728,9 @@ void GpuImageDecodeCache::UploadImageIfN
   sk_sp<SkImage> uploaded_v_image =
       image_data->decode.image(2, AuxImage::kDefault);
 
+  // Prevent image_data from being deleted while lock is not held.
+  scoped_refptr<ImageData> image_data_holder(image_data);
+
   // For kGpu, we upload and color convert (if necessary).
   if (image_data->mode == DecodedDataMode::kGpu) {
     DCHECK(!use_transfer_cache_);
@@ -2812,6 +2818,9 @@ void GpuImageDecodeCache::UploadImageIfN
   DCHECK(!use_transfer_cache_);
   DCHECK(!image_data->info.yuva.has_value());
 
+  // Prevent image_data from being deleted while lock is not held.
+  scoped_refptr<ImageData> image_data_holder(image_data);
+
   // RGBX decoding is below.
   // For kGpu, we upload and color convert (if necessary).
   if (image_data->mode == DecodedDataMode::kGpu) {
