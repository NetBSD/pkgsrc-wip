$NetBSD: patch-src_plugins_genericprojectmanager_genericmakestep.cpp,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix toolchain debug adapter building by using gnu make.

--- src/plugins/genericprojectmanager/genericmakestep.cpp.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/plugins/genericprojectmanager/genericmakestep.cpp
@@ -179,7 +179,7 @@ QString GenericMakeStep::makeCommand() c
         if (ProjectExplorer::ToolChain *toolChain = pro->toolChain())
             command = toolChain->makeCommand();
         else
-            command = QLatin1String("make");
+            command = QLatin1String("gmake");
     }
     return command;
 }
