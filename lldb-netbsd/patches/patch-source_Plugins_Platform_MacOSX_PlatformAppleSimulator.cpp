$NetBSD$

--- source/Plugins/Platform/MacOSX/PlatformAppleSimulator.cpp.orig	2017-02-04 18:35:35.000000000 +0000
+++ source/Plugins/Platform/MacOSX/PlatformAppleSimulator.cpp
@@ -242,8 +242,8 @@ FileSpec PlatformAppleSimulator::GetCore
 
 void PlatformAppleSimulator::LoadCoreSimulator() {
 #if defined(__APPLE__)
-  static std::once_flag g_load_core_sim_flag;
-  std::call_once(g_load_core_sim_flag, [this] {
+  LLVM_DEFINE_ONCE_FLAG(g_load_core_sim_flag);
+  llvm::call_once(g_load_core_sim_flag, [this] {
     const std::string core_sim_path(GetCoreSimulatorPath().GetPath());
     if (core_sim_path.size())
       dlopen(core_sim_path.c_str(), RTLD_LAZY);
