$NetBSD$

--- include/llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h
@@ -249,8 +249,7 @@ public:
           DEBUG(dbgs() << "  setting R-X permissions on code block: "
                        << format("0x%016x", ObjAllocs.RemoteCodeAddr) << "\n");
           if (auto Err = Client.setProtections(Id, ObjAllocs.RemoteCodeAddr,
-                                               sys::Memory::MF_READ |
-                                                   sys::Memory::MF_EXEC)) {
+                                                   sys::Memory::ProtectionMode::MF_EXECUTABLE)) {
             // FIXME: Replace this once finalizeMemory can return an Error.
             handleAllErrors(std::move(Err), [&](ErrorInfoBase &EIB) {
               if (ErrMsg) {
@@ -286,7 +285,7 @@ public:
                        << format("0x%016x", ObjAllocs.RemoteRODataAddr)
                        << "\n");
           if (auto Err = Client.setProtections(Id, ObjAllocs.RemoteRODataAddr,
-                                               sys::Memory::MF_READ)) {
+                                               sys::Memory::ProtectionMode::MF_READABLE)) {
             // FIXME: Replace this once finalizeMemory can return an Error.
             handleAllErrors(std::move(Err), [&](ErrorInfoBase &EIB) {
               if (ErrMsg) {
@@ -322,8 +321,7 @@ public:
                        << format("0x%016x", ObjAllocs.RemoteRWDataAddr)
                        << "\n");
           if (auto Err = Client.setProtections(Id, ObjAllocs.RemoteRWDataAddr,
-                                               sys::Memory::MF_READ |
-                                                   sys::Memory::MF_WRITE)) {
+                                                   sys::Memory::ProtectionMode::MF_WRITABLE)) {
             // FIXME: Replace this once finalizeMemory can return an Error.
             handleAllErrors(std::move(Err), [&](ErrorInfoBase &EIB) {
               if (ErrMsg) {
@@ -736,8 +734,8 @@ private:
   }
 
   Error setProtections(ResourceIdMgr::ResourceId Id,
-                       JITTargetAddress RemoteSegAddr, unsigned ProtFlags) {
-    return callB<SetProtections>(Id, RemoteSegAddr, ProtFlags);
+                       JITTargetAddress RemoteSegAddr, sys::Memory::ProtectionMode Mode) {
+    return callB<SetProtections>(Id, RemoteSegAddr, Mode);
   }
 
   Error writeMem(JITTargetAddress Addr, const char *Src, uint64_t Size) {
