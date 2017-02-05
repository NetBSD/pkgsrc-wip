$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.cpp.orig	2017-02-01 14:45:44.000000000 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.cpp
@@ -27,6 +27,7 @@
 #include "lldb/Target/UnixSignals.h"
 
 #include "llvm/Support/ELF.h"
+#include "llvm/Support/Threading.h"
 
 #include "Plugins/DynamicLoader/POSIX-DYLD/DynamicLoaderPOSIXDYLD.h"
 #include "Plugins/ObjectFile/ELF/ObjectFileELF.h"
@@ -400,9 +401,9 @@ void ProcessElfCore::Clear() {
 }
 
 void ProcessElfCore::Initialize() {
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance);
   });
