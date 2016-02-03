$NetBSD$

--- src/debug/ee/debugger.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/debugger.h
@@ -3084,6 +3084,8 @@ public:
 
 class DebuggerPendingFuncEvalTable : private CHashTableAndData<CNewZeroData>
 {
+  public: virtual ~DebuggerPendingFuncEvalTable() = default;
+
   private:
 
     BOOL Cmp(SIZE_T k1, const HASHENTRY * pc2)
@@ -3167,6 +3169,10 @@ typedef DPTR(struct DebuggerModuleEntry)
 
 class DebuggerModuleTable : private CHashTableAndData<CNewZeroData>
 {
+#ifdef DACCESS_COMPILE
+  public: virtual ~DebuggerModuleTable() = default;
+#endif
+
   private:
 
     BOOL Cmp(SIZE_T k1, const HASHENTRY * pc2)
@@ -3206,7 +3212,7 @@ public:
 #ifndef DACCESS_COMPILE
 
     DebuggerModuleTable();
-    ~DebuggerModuleTable();
+    virtual ~DebuggerModuleTable();
 
     void AddModule(DebuggerModule *module);
 
@@ -3274,6 +3280,8 @@ class DebuggerMethodInfoTable : private 
 {
     VPTR_BASE_CONCRETE_VTABLE_CLASS(DebuggerMethodInfoTable);
 
+    virtual ~DebuggerMethodInfoTable() = default;
+
   private:
     BOOL Cmp(SIZE_T k1, const HASHENTRY * pc2)
     {
@@ -3973,4 +3981,3 @@ void FixupDispatcherContext(T_DISPATCHER
 #endif
 
 #endif /* DEBUGGER_H_ */
-
