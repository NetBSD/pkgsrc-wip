$NetBSD$

--- libswc/shm.c.orig	2019-07-11 06:33:41.000000000 +0000
+++ libswc/shm.c
@@ -47,7 +47,7 @@ static struct {
 struct pool {
 	struct wl_resource *resource;
 	void *data;
-	uint32_t size;
+	size_t size;
 	unsigned references;
 };
 
@@ -144,12 +144,15 @@ destroy(struct wl_client *client, struct
 }
 
 static void
-resize(struct wl_client *client, struct wl_resource *resource, int32_t size)
+resize(struct wl_client *client, struct wl_resource *resource, size_t size)
 {
 	struct pool *pool = wl_resource_get_user_data(resource);
 	void *data;
 
-	data = mremap(pool->data, pool->size, size, MREMAP_MAYMOVE);
+#ifndef MREMAP_MAYMOVE
+#define MREMAP_MAYMOVE 0
+#endif
+	data = mremap(pool->data, pool->size, size, MREMAP_MAYMOVE, NULL);
 
 	if (data == MAP_FAILED) {
 		wl_resource_post_error(resource, WL_SHM_ERROR_INVALID_FD, "mremap failed: %s", strerror(errno));
@@ -167,7 +170,7 @@ static struct wl_shm_pool_interface shm_
 };
 
 static void
-create_pool(struct wl_client *client, struct wl_resource *resource, uint32_t id, int32_t fd, int32_t size)
+create_pool(struct wl_client *client, struct wl_resource *resource, uint32_t id, int32_t fd, size_t size)
 {
 	struct pool *pool;
 
