$NetBSD$

--- chrome/browser/gpu/gl_string_manager.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/gpu/gl_string_manager.cc
@@ -33,7 +33,7 @@ GLStringManager::~GLStringManager() {
 
 void GLStringManager::Initialize() {
   // On MacOSX or Windows, preliminary GPUInfo is enough.
-#if defined(OS_LINUX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
   // We never remove this observer from GpuDataManager.
   content::GpuDataManager::GetInstance()->AddObserver(this);
 
