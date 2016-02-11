$NetBSD$

--- compression.cc.orig	2015-09-16 07:28:04.000000000 +0000
+++ compression.cc
@@ -291,9 +291,11 @@ private:
     } while (true);
   }
 };
-
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
 #include <endian.h>
-
+#endif
 // like NoStreamEnDecoder, but also adds the uncompressed size before the stream
 //NOTE You should make sure that the compression function doesn't overwrite any
 //     memory, if this information is corrupted! This could be exploited by a
