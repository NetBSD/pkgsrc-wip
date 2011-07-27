$NetBSD: patch-clone_libs-gui_svtools_source_contnr_imivctl1.cxx,v 1.1 2011/07/27 16:46:25 asau Exp $

--- clone/libs-gui/svtools/source/contnr/imivctl1.cxx.orig	2011-07-15 14:53:56.000000000 +0000
+++ clone/libs-gui/svtools/source/contnr/imivctl1.cxx
@@ -292,7 +292,7 @@ void SvxIconChoiceCtrl_Impl::FontModifie
     ShowCursor( sal_True );
 }
 
-void SvxIconChoiceCtrl_Impl::InsertEntry( SvxIconChoiceCtrlEntry* pEntry, size_t nPos,
+void SvxIconChoiceCtrl_Impl::InsertEntry( SvxIconChoiceCtrlEntry* pEntry, sal_uLong nPos,
     const Point* pPos )
 {
     StopEditTimer();
