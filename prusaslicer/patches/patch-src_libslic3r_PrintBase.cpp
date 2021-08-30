$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/libslic3r/PrintBase.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/PrintBase.cpp
@@ -97,7 +97,7 @@ void PrintBase::status_update_warnings(O
     	printf("%s warning: %s\n", (object_id == this->id()) ? "print" : "print object", message.c_str());
 }
 
-tbb::mutex& PrintObjectBase::state_mutex(PrintBase *print)
+std::mutex& PrintObjectBase::state_mutex(PrintBase *print)
 { 
 	return print->state_mutex();
 }
