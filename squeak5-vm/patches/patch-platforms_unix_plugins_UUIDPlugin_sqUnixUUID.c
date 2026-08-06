$NetBSD$

fix compatibility between uuidgen(2) and uuid_generate

--- platforms/unix/plugins/UUIDPlugin/sqUnixUUID.c.orig	2026-08-05 05:02:34.197747355 +0000
+++ platforms/unix/plugins/UUIDPlugin/sqUnixUUID.c
@@ -18,7 +18,9 @@ int MakeUUID(char *location)
   uuid_t uuid;
 
 #if defined(HAVE_UUIDGEN)
-  uuidgen(&uuid, 1);
+  struct uuid store;
+  uuidgen(&store, 1);
+  uuid_enc_be(&uuid, &store);
 #elif defined(HAVE_UUID_GENERATE)
   uuid_generate(uuid);
 #else
