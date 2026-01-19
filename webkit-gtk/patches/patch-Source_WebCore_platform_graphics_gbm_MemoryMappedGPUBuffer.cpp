$NetBSD$

--- Source/WebCore/platform/graphics/gbm/MemoryMappedGPUBuffer.cpp.orig	2025-10-29 09:54:43.774761997 +0000
+++ Source/WebCore/platform/graphics/gbm/MemoryMappedGPUBuffer.cpp
@@ -35,7 +35,9 @@
 #include "PlatformDisplay.h"
 #include <epoxy/egl.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/dma-buf.h>
+#endif
 #include <sys/ioctl.h>
 #include <wtf/SafeStrerror.h>
 #include <wtf/StdLibExtras.h>
@@ -342,6 +344,7 @@ std::unique_ptr<MemoryMappedGPUBuffer::A
 
 bool MemoryMappedGPUBuffer::performDMABufSyncSystemCall(OptionSet<DMABufSyncFlag> flags)
 {
+#ifdef __linux__
     constexpr unsigned maxRetries = 10;
 
     struct dma_buf_sync sync;
@@ -371,6 +374,9 @@ bool MemoryMappedGPUBuffer::performDMABu
     }
 
     return true;
+#else
+    return false;
+#endif
 }
 
 } // namespace WebCore
