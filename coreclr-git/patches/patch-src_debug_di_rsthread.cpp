$NetBSD$

--- src/debug/di/rsthread.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/rsthread.cpp
@@ -9368,7 +9368,7 @@ HRESULT CordbEval::GatherArgInfo(ICorDeb
 
             _ASSERTE(fullArgTypeNodeCount > 0);
             unsigned int bufferSize = sizeof(DebuggerIPCE_TypeArgData) * fullArgTypeNodeCount;
-            DebuggerIPCE_TypeArgData *bufferFrom = (DebuggerIPCE_TypeArgData *) _alloca(bufferSize);
+            DebuggerIPCE_TypeArgData *bufferFrom = (DebuggerIPCE_TypeArgData *) Alloca(bufferSize);
 
             DebuggerIPCE_TypeArgData *curr = bufferFrom;
             CordbType::GatherTypeData(cv->m_type, &curr);
@@ -10332,7 +10332,7 @@ HRESULT CordbEval::NewParameterizedArray
     }
 
     // Just in case sizeof(SIZE_T) != sizeof(ULONG32)
-    SIZE_T * rgDimensionsSizeT = reinterpret_cast<SIZE_T *>(_alloca(allocSize.Value()));
+    SIZE_T * rgDimensionsSizeT = reinterpret_cast<SIZE_T *>(Alloca(allocSize.Value()));
 
     for (unsigned int i = 0; i < rank; i++)
     {
