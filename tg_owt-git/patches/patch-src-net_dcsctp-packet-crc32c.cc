$NetBSD$

Use librhash for CRC32C instead of bundled crc32c (empty in GitHub tarball).

--- src/net/dcsctp/packet/crc32c.cc.orig
+++ src/net/dcsctp/packet/crc32c.cc
@@ -3,19 +3,26 @@
  *
  *  Use of this source code is governed by a BSD-style license
  *  that can be found in the LICENSE file in the root of the source
- *  tree. An additional intellectual property rights grant can be found
+ *  tree.  An additional intellectual property rights grant can be found
  *  in the file PATENTS.  All contributing project authors may
  *  be found in the AUTHORS file in the root of the source tree.
  */
 #include "net/dcsctp/packet/crc32c.h"
 
 #include <cstdint>
-#include <crc32c/crc32c.h>
+#include <rhash.h>
+#include <string.h>
 
 namespace dcsctp {
 
 uint32_t GenerateCrc32C(rtc::ArrayView<const uint8_t> data) {
-  uint32_t crc32c = crc32c_value(data.data(), data.size());
+  rhash ctx = rhash_init(RHASH_CRC32C);
+  rhash_update(ctx, data.data(), data.size());
+  unsigned char result[4];
+  rhash_final(ctx, result);
+  rhash_free(ctx);
+  uint32_t crc32c;
+  memcpy(&crc32c, result, 4);
 
   // Byte swapping for little endian byte order:
   uint8_t byte0 = crc32c;
