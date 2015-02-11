$NetBSD: patch-src_frontend_common_TemplateElementIterator.hh,v 1.1 2015/02/11 12:03:53 nros Exp $
* Fix build on gcc 4.7 and above
--- src/frontend/common/TemplateElementIterator.hh.orig	2007-08-17 10:02:34.000000000 +0000
+++ src/frontend/common/TemplateElementIterator.hh
@@ -43,7 +43,7 @@ protected:
   findValidNodeForward(const typename Model::Node& p0) const
   {
     for (typename Model::Node p = p0; p; p = Model::getNextSibling(p))
-      if (valid(p)) return Model::asElement(p);
+      if (this->valid(p)) return Model::asElement(p);
     return typename Model::Element();
   }
     
