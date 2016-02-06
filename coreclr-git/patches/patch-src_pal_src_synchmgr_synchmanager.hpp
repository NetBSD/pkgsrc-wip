$NetBSD$

--- src/pal/src/synchmgr/synchmanager.hpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/synchmgr/synchmanager.hpp
@@ -452,6 +452,7 @@ namespace CorUnix
         
     public:
         CSynchWaitController() : m_pProcLocalData(NULL) {}
+        virtual ~CSynchWaitController() = default;
         
         //
         // ISynchWaitController methods
@@ -479,8 +480,9 @@ namespace CorUnix
     {
     public:
         // NB: For perforformance purposes this class is supposed
-        //     to have no constructor or destructor
-        
+        //     to have no constructor
+        virtual ~CSynchStateController() = default;
+
         //
         // ISynchStateController methods
         //
@@ -1021,4 +1023,3 @@ namespace CorUnix
 }
 
 #endif // _SINCHMANAGER_HPP_
-
