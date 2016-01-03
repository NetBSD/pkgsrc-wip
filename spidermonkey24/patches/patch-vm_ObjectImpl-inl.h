$NetBSD: patch-vm_ObjectImpl-inl.h,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- vm/ObjectImpl-inl.h.orig	2013-10-29 20:40:17.000000000 +0000
+++ vm/ObjectImpl-inl.h
@@ -364,7 +364,7 @@ js::ObjectImpl::zone() const
 js::ObjectImpl::readBarrier(ObjectImpl *obj)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapMajorCollecting());
         JSObject *tmp = obj->asObjectPtr();
@@ -378,7 +378,7 @@ inline void
 js::ObjectImpl::privateWriteBarrierPre(void **old)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = this->zone();
+    JS::Zone *zone = this->zone();
     if (zone->needsBarrier()) {
         if (*old && getClass()->trace)
             getClass()->trace(zone->barrierTracer(), this->asObjectPtr());
@@ -405,7 +405,7 @@ js::ObjectImpl::writeBarrierPre(ObjectIm
     if (IsNullTaggedPointer(obj) || !obj->runtime()->needsBarrier())
         return;
 
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapMajorCollecting());
         JSObject *tmp = obj->asObjectPtr();
