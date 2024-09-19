$NetBSD$

Imported patch from qemu-2.3.0

--- qemu_mode/qemu/memory.c.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/qemu/memory.c
@@ -394,7 +394,7 @@ static void memory_region_read_accessor(
     if (mr->flush_coalesced_mmio) {
         qemu_flush_coalesced_mmio_buffer();
     }
-    tmp = mr->ops->read(mr->opaque, addr, size);
+    tmp = (*mr->ops->read)(mr->opaque, addr, size);
     trace_memory_region_ops_read(mr, addr, tmp, size);
     *value |= (tmp & mask) << shift;
 }
