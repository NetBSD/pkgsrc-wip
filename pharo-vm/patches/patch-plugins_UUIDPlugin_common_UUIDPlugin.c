$NetBSD$

fix compatibility between uuidgen(2) and uuid_generate

--- plugins/UUIDPlugin/common/UUIDPlugin.c.orig	2021-08-15 10:24:33.887097903 +0000
+++ plugins/UUIDPlugin/common/UUIDPlugin.c
@@ -41,6 +41,9 @@ struct VirtualMachine* interpreterProxy;
 
 	#if defined(HAVE_UUIDGEN)
 	  uuidgen(&uuid, 1);
+	  uuid.time_low = htobe32(uuid.time_low);
+	  uuid.time_mid = htobe16(uuid.time_mid);
+	  uuid.time_hi_and_version = htobe16(uuid.time_hi_and_version);
 	#else
 	  uuid_generate(uuid);
 	#endif
