$NetBSD$

--- src/pal/src/synchmgr/synchmanager.hpp.orig	2016-02-06 04:19:55.000000000 +0000
+++ src/pal/src/synchmgr/synchmanager.hpp
@@ -452,7 +452,6 @@ namespace CorUnix
         
     public:
         CSynchWaitController() : m_pProcLocalData(NULL) {}
-        virtual ~CSynchWaitController() = default;
         
         //
         // ISynchWaitController methods
@@ -480,9 +479,8 @@ namespace CorUnix
     {
     public:
         // NB: For perforformance purposes this class is supposed
-        //     to have no constructor
-        virtual ~CSynchStateController() = default;
-
+        //     to have no constructor or destructor
+        
         //
         // ISynchStateController methods
         //
@@ -1023,3 +1021,4 @@ namespace CorUnix
 }
 
 #endif // _SINCHMANAGER_HPP_
+
