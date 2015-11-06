$NetBSD$

osg 3.4 compatibility changes

--- simgear/scene/material/Technique.cxx.orig	2015-02-18 20:10:39.000000000 +0000
+++ simgear/scene/material/Technique.cxx
@@ -326,9 +326,9 @@ public:
             = GL2Extensions::Get(static_cast<unsigned>(contextId), true);
         if (!extensions)
             return;
-        if (!extensions->isGlslSupported())
+        if (!extensions->isGlslSupported)
             return;
-        value = extensions->getLanguageVersion();
+        value = extensions->glslLanguageVersion;
     }
 };
 
@@ -357,7 +357,7 @@ public:
            = GL2Extensions::Get(static_cast<unsigned>(contextId), true);
        if (!extensions)
            return;
-       value = extensions->isGlslSupported();
+       value = extensions->isGlslSupported;
    }
 };
 
