$NetBSD$

hdf5 requires libaec::sz but doesn't look for it.

--- cMake/FreeCAD_Helpers/SetupSalomeSMESH.cmake.orig	2026-07-01 07:42:16.182515607 +0000
+++ cMake/FreeCAD_Helpers/SetupSalomeSMESH.cmake
@@ -25,6 +25,7 @@ macro(SetupSalomeSMESH)
         )
 
         # check which modules are available
+        find_package(libaec CONFIG REQUIRED)
         if(UNIX OR WIN32)
             # Module names changed between 8 and 9, so do a QUIET find for 9 and its module name first, and fall back
             # to v7 minimum with the old component name if it is not found.
