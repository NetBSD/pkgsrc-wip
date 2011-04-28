$NetBSD: patch-ppapi_proxy_serialized__var.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- ppapi/proxy/serialized_var.cc.orig	2011-04-13 08:01:10.000000000 +0000
+++ ppapi/proxy/serialized_var.cc
@@ -189,7 +189,7 @@ bool SerializedVar::Inner::ReadFromMessa
       var_.value.as_id = 0;
       break;
     case PP_VARTYPE_OBJECT:
-      success = m->ReadInt64(iter, &var_.value.as_id);
+      success = m->ReadInt64(iter, (int64 *)&var_.value.as_id);
       break;
     default:
       // Leave success as false.
