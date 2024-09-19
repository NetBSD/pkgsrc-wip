$NetBSD: patch-Source_WebCore_editing_Editor.h,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

--- src/qt/qtwebkit/Source/WebCore/editing/Editor.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebCore/editing/Editor.h
@@ -416,7 +416,7 @@ public:
     Vector<String> dictationAlternativesForMarker(const DocumentMarker*);
     void applyDictationAlternativelternative(const String& alternativeString);
 private:
-    virtual void willDetachPage() OVERRIDE;
+    virtual void willDetachPage();
 
 #if ENABLE(DELETION_UI)
     OwnPtr<DeleteButtonController> m_deleteButtonController;
