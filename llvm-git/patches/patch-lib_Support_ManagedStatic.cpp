$NetBSD$

--- lib/Support/ManagedStatic.cpp.orig	2016-07-05 12:47:20.000000000 +0000
+++ lib/Support/ManagedStatic.cpp
@@ -21,7 +21,7 @@ using namespace llvm;
 
 static const ManagedStaticBase *StaticList = nullptr;
 static sys::Mutex *ManagedStaticMutex = nullptr;
-LLVM_DEFINE_ONCE_FLAG(mutex_init_flag);
+static llvm::once_flag mutex_init_flag;
 
 static void initializeMutex() {
   ManagedStaticMutex = new sys::Mutex();
