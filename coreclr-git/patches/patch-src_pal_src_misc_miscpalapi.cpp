$NetBSD$

--- src/pal/src/misc/miscpalapi.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/misc/miscpalapi.cpp
@@ -33,10 +33,10 @@ Revision History:
 #include <pthread.h>
 #include <dlfcn.h>
 
-#if HAVE_LIBUUID_H
-#include <uuid/uuid.h>
-#elif HAVE_BSD_UUID_H
+#if HAVE_BSD_UUID_H
 #include <uuid.h>
+#elif HAVE_LIBUUID_H
+#include <uuid/uuid.h>
 #endif
 
 #include <pal_endian.h>
@@ -352,15 +352,7 @@ HRESULT
 PALAPI
 CoCreateGuid(OUT GUID * pguid)
 {
-#if HAVE_LIBUUID_H
-    uuid_generate_random(*(uuid_t*)pguid);
-
-    // Change the byte order of the Data1, 2 and 3, since the uuid_generate_random
-    // generates them with big endian while GUIDS need to have them in little endian.
-    pguid->Data1 = SWAP32(pguid->Data1);
-    pguid->Data2 = SWAP16(pguid->Data2);
-    pguid->Data3 = SWAP16(pguid->Data3);
-#elif HAVE_BSD_UUID_H
+#if HAVE_BSD_UUID_H
     uuid_t uuid;
     uint32_t status;
     uuid_create(&uuid, &status);
@@ -372,6 +364,14 @@ CoCreateGuid(OUT GUID * pguid)
 
     // Encode the uuid with little endian.
     uuid_enc_le(pguid, &uuid);
+#elif HAVE_LIBUUID_H
+    uuid_generate_random(*(uuid_t*)pguid);
+
+    // Change the byte order of the Data1, 2 and 3, since the uuid_generate_random
+    // generates them with big endian while GUIDS need to have them in little endian.
+    pguid->Data1 = SWAP32(pguid->Data1);
+    pguid->Data2 = SWAP16(pguid->Data2);
+    pguid->Data3 = SWAP16(pguid->Data3);
 #else
     #error Don't know how to generate UUID on this platform
 #endif
