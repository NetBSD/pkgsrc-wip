$NetBSD: patch-sfx2_source_doc_objstor.cxx,v 1.1 2012/04/19 19:15:06 ftigeot Exp $

--- sfx2/source/doc/objstor.cxx.orig	2012-03-27 16:22:01.000000000 +0000
+++ sfx2/source/doc/objstor.cxx
@@ -2238,7 +2238,7 @@ sal_Bool SfxObjectShell::ImportFrom( Sfx
         }
 
         return xLoader->filter( aArgs );
-        }catch(const uno::Exception&)
+        }catch(...)
         {}
     }
 
