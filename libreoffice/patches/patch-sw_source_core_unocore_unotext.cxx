$NetBSD: patch-sw_source_core_unocore_unotext.cxx,v 1.1 2012/04/19 19:15:06 ftigeot Exp $

--- sw/source/core/unocore/unotext.cxx.orig	2012-03-27 16:22:01.000000000 +0000
+++ sw/source/core/unocore/unotext.cxx
@@ -2231,6 +2231,10 @@ throw (lang::IllegalArgumentException, u
     std::vector<VerticallyMergedCell> aMergedCells;
 
     SwTable const*const pTable = m_pImpl->m_pDoc->TextToTable( aTableNodes );
+
+    if (!pTable)
+        return uno::Reference< text::XTextTable >();
+
     SwXTextTable *const pTextTable = new SwXTextTable( *pTable->GetFrmFmt() );
     const uno::Reference< text::XTextTable > xRet = pTextTable;
     const uno::Reference< beans::XPropertySet > xPrSet = pTextTable;
