$NetBSD: patch-clone_libs-gui_svtools_source_contnr_imivctl1.cxx,v 1.2 2011/08/03 09:58:46 thomasklausner Exp $

Note: upstream fixed this by changing the prototype in imivctl.hxx instead --
beware when updating libreoffice to a newer snapshot.

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
