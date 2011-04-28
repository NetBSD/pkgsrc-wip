$NetBSD: patch-webkit_plugins_ppapi_ppb__file__system__impl.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/plugins/ppapi/ppb_file_system_impl.cc.orig	2011-04-13 08:01:07.000000000 +0000
+++ webkit/plugins/ppapi/ppb_file_system_impl.cc
@@ -37,7 +37,7 @@ PP_Resource Create(PP_Instance instance,
 }
 
 int32_t Open(PP_Resource file_system_id,
-             int64 expected_size,
+             int64_t expected_size,
              PP_CompletionCallback callback) {
   scoped_refptr<PPB_FileSystem_Impl> file_system(
       Resource::GetAs<PPB_FileSystem_Impl>(file_system_id));
