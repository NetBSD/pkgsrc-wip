$NetBSD: patch-memory.c,v 1.1.1.1 2011/12/11 04:11:20 ryo-on Exp $

--- memory.c.orig	2011-12-01 20:07:34.000000000 +0000
+++ memory.c
@@ -246,7 +246,7 @@ static void memory_region_read_accessor(
     MemoryRegion *mr = opaque;
     uint64_t tmp;
 
-    tmp = mr->ops->read(mr->opaque, addr, size);
+    tmp = (*mr->ops->read)(mr->opaque, addr, size);
     *value |= (tmp & mask) << shift;
 }
 
@@ -416,12 +416,12 @@ static void memory_region_iorange_read(I
 
         *data = ((uint64_t)1 << (width * 8)) - 1;
         if (mrp) {
-            *data = mrp->read(mr->opaque, offset + mr->offset);
+            *data = (*mrp->read)(mr->opaque, offset + mr->offset);
         } else if (width == 2) {
             mrp = find_portio(mr, offset, 1, false);
             assert(mrp);
-            *data = mrp->read(mr->opaque, offset + mr->offset) |
-                    (mrp->read(mr->opaque, offset + mr->offset + 1) << 8);
+            *data = (*mrp->read)(mr->opaque, offset + mr->offset) |
+                    ((*mrp->read)(mr->opaque, offset + mr->offset + 1) << 8);
         }
         return;
     }
