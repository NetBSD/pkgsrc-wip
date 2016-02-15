$NetBSD$

--- src/vm/dwreport.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/dwreport.cpp
@@ -459,8 +459,8 @@ HRESULT DwCheckCompany(                 
     }
 
     // Allocate the buffer for the version info structure
-    // _alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
-    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(_alloca(bufSize));
+    // Alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
+    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(Alloca(bufSize));
 
     // Extract the version information blob. The version information
     // contains much more than the actual item of interest.
@@ -595,8 +595,8 @@ int DwGetAppDescription(                
     }
 
     // Allocate the buffer for the version info structure
-    // _alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
-    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(_alloca(bufSize));
+    // Alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
+    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(Alloca(bufSize));
 
     // Extract the version information blob. The version information
     // contains much more than the actual item of interest.
@@ -718,8 +718,8 @@ int DwGetAssemblyVersion(               
     }
 
     // Allocate the buffer for the version info structure
-    // _alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
-    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(_alloca(bufSize));
+    // Alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
+    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(Alloca(bufSize));
 
     // Extract the version information blob. The version information
     // contains much more than the actual item of interest.
