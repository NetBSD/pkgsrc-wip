$NetBSD$

--- lib/Target/X86/X86InstrFMA3Info.cpp.orig	2017-02-05 15:43:39.582556537 +0000
+++ lib/Target/X86/X86InstrFMA3Info.cpp
@@ -23,7 +23,7 @@ using namespace llvm;
 
 /// This flag is used in the method llvm::call_once() used below to make the
 /// initialization of the map 'OpcodeToGroup' thread safe.
-LLVM_DEFINE_ONCE_FLAG(InitGroupsOnceFlag);
+static llvm::once_flag InitGroupsOnceFlag;
 
 static ManagedStatic<X86InstrFMA3Info> X86InstrFMA3InfoObj;
 X86InstrFMA3Info *X86InstrFMA3Info::getX86InstrFMA3Info() {
