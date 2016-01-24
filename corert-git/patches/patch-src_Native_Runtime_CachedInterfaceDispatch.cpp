$NetBSD$

--- src/Native/Runtime/CachedInterfaceDispatch.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/CachedInterfaceDispatch.cpp
@@ -544,6 +544,6 @@ COOP_PINVOKE_HELPER(PTR_Code, RhpResolve
                                                                    PInvokeTransitionFrame * pTransitionFrame))
 {
     CID_COUNTER_INC(CacheMisses);
-    return (PTR_Code)ManagedCallout2((UIntTarget)pObject, (UIntTarget)pCell, RhpCidResolve, pTransitionFrame);
+    return (PTR_Code)ManagedCallout2((UIntTarget)pObject, (UIntTarget)pCell, reinterpret_cast<void*>(RhpCidResolve), pTransitionFrame);
 }
 #endif // FEATURE_CACHED_INTERFACE_DISPATCH
