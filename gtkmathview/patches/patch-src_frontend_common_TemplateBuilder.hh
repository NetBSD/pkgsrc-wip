$NetBSD: patch-src_frontend_common_TemplateBuilder.hh,v 1.1 2015/02/11 12:03:53 nros Exp $
* Fix build on gcc 4.7 and above
--- src/frontend/common/TemplateBuilder.hh.orig	2007-08-17 10:02:34.000000000 +0000
+++ src/frontend/common/TemplateBuilder.hh
@@ -47,12 +47,12 @@ protected:
   SmartPtr<typename ElementBuilder::type>
   getElement(const typename Model::Element& el) const
   {
-    if (SmartPtr<typename ElementBuilder::type> elem = smart_cast<typename ElementBuilder::type>(linkerAssoc(el)))
+    if (SmartPtr<typename ElementBuilder::type> elem = smart_cast<typename ElementBuilder::type>(this->linkerAssoc(el)))
       return elem;
     else
       {
-	SmartPtr<typename ElementBuilder::type> elem = ElementBuilder::type::create(ElementBuilder::getContext(*this));
-	linkerAdd(el, elem);
+	elem = ElementBuilder::type::create(ElementBuilder::getContext(*this));
+	this->linkerAdd(el, elem);
 	return elem;
       }
   }
