$NetBSD$

Changes for compiling with Qt5 instead of Qt4

--- libgui/graphics/Object.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/graphics/Object.cc
@@ -183,7 +183,7 @@ Object::fromQObject (QObject* obj)
   QVariant v = obj->property ("QtHandles::Object");
 
   if (v.isValid ())
-    return reinterpret_cast<Object*> (qVariantValue<void*> (v));
+    return reinterpret_cast<Object*> (qvariant_cast<void*> (v));
 
   return 0;
 }
