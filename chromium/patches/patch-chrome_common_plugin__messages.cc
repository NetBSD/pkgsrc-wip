$NetBSD: patch-chrome_common_plugin__messages.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/plugin_messages.cc.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/plugin_messages.cc
@@ -56,7 +56,7 @@ NPVariant_Param::~NPVariant_Param() {
 
 PluginMsg_UpdateGeometry_Param::PluginMsg_UpdateGeometry_Param()
     : transparent(false),
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       windowless_buffer(TransportDIB::DefaultHandleValue()),
       background_buffer(TransportDIB::DefaultHandleValue())
 #else
@@ -271,7 +271,7 @@ void ParamTraits<PluginMsg_UpdateGeometr
   WriteParam(m, p.windowless_buffer);
   WriteParam(m, p.background_buffer);
   WriteParam(m, p.transparent);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   WriteParam(m, p.ack_key);
 #endif
 }
@@ -285,7 +285,7 @@ bool ParamTraits<PluginMsg_UpdateGeometr
       ReadParam(m, iter, &r->windowless_buffer) &&
       ReadParam(m, iter, &r->background_buffer) &&
       ReadParam(m, iter, &r->transparent)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
       &&
       ReadParam(m, iter, &r->ack_key)
 #endif
@@ -304,7 +304,7 @@ void ParamTraits<PluginMsg_UpdateGeometr
   LogParam(p.background_buffer, l);
   l->append(", ");
   LogParam(p.transparent, l);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   l->append(", ");
   LogParam(p.ack_key, l);
 #endif
