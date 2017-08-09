$NetBSD$

--- include/llvm/ExecutionEngine/Orc/OrcRemoteTargetRPCAPI.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/OrcRemoteTargetRPCAPI.h
@@ -239,7 +239,7 @@ public:
   class SetProtections
       : public rpc::Function<SetProtections,
                              void(ResourceIdMgr::ResourceId AllocID,
-                                  JITTargetAddress Dst, uint32_t ProtFlags)> {
+                                  JITTargetAddress Dst, sys::Memory::ProtectionMode Mode)> {
   public:
     static const char *getName() { return "SetProtections"; }
   };
