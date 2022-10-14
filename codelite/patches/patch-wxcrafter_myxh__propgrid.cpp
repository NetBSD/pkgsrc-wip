
--- wxcrafter/myxh_propgrid.cpp.orig	2022-10-15 00:18:54.895365650 +0300
+++ wxcrafter/myxh_propgrid.cpp
@@ -47,8 +47,8 @@ wxObject* MyWxPropGridXmlHandler::DoCrea
         CreateChildren(m_pgmgr, true /*only this handler*/);
 
         // add the splitter property after the children were added
-        int splitterLeft = GetBool("splitterleft");
-        if(splitterLeft) { m_pgmgr->GetPage(0)->SetSplitterLeft(); }
+        //int splitterLeft = GetBool("splitterleft");
+        //if(splitterLeft) { m_pgmgr->GetPage(0)->SetSplitterLeft(); }
 
         int splitterPos = GetLong("splitterpos", wxNOT_FOUND);
         if(splitterPos != wxNOT_FOUND) { m_pgmgr->GetPage(0)->SetSplitterPosition(splitterPos); }
