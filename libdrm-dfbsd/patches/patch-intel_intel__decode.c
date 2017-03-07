$NetBSD$

intel: avoid null pointer dereference
https://cgit.freedesktop.org/mesa/drm/commit/?id=5ee9cb4b4b6964bcd463b0490f3027e6ccfbf45a

--- intel/intel_decode.c.orig	2016-12-13 02:45:20.000000000 +0000
+++ intel/intel_decode.c
@@ -3899,7 +3899,7 @@ drm_intel_decode(struct drm_intel_decode
 	int ret;
 	unsigned int index = 0;
 	uint32_t devid;
-	int size = ctx->base_count * 4;
+	int size;
 	void *temp;
 
 	if (!ctx)
@@ -3909,6 +3909,7 @@ drm_intel_decode(struct drm_intel_decode
 	 * the batchbuffer.  This lets us avoid a bunch of length
 	 * checking in statically sized packets.
 	 */
+	size = ctx->base_count * 4;
 	temp = malloc(size + 4096);
 	memcpy(temp, ctx->base_data, size);
 	memset((char *)temp + size, 0xd0, 4096);
