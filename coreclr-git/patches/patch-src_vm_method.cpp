$NetBSD$

--- src/vm/method.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/method.cpp
@@ -5193,7 +5193,7 @@ LPVOID NDirectMethodDesc::FindEntryPoint
     if (GetEntrypointName()[0] == '#')
     {
         long ordinal = atol(GetEntrypointName()+1);
-        return GetProcAddress(hMod, (LPCSTR)(size_t)((UINT16)ordinal));
+        return reinterpret_cast<LPVOID>(GetProcAddress(hMod, (LPCSTR)(size_t)((UINT16)ordinal)));
     }
 
     // Just look for the unmangled name.  If it is unicode fcn, we are going
