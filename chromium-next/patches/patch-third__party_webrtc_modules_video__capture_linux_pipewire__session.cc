$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/video_capture/linux/pipewire_session.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ third_party/webrtc/modules/video_capture/linux/pipewire_session.cc
@@ -87,7 +87,7 @@ PipeWireNode::PipeWireNode(PipeWireSessi
       .param = OnNodeParam,
   };
 
-  pw_node_add_listener(proxy_, &node_listener_, &node_events, this);
+  pw_node_add_listener(reinterpret_cast<pw_node*>(proxy_), &node_listener_, &node_events, this);
 }
 
 // static
@@ -119,7 +119,7 @@ void PipeWireNode::OnNodeInfo(void* data
       uint32_t id = info->params[i].id;
       if (id == SPA_PARAM_EnumFormat &&
           info->params[i].flags & SPA_PARAM_INFO_READ) {
-        pw_node_enum_params(that->proxy_, 0, id, 0, UINT32_MAX, nullptr);
+        pw_node_enum_params(reinterpret_cast<pw_node*>(that->proxy_), 0, id, 0, UINT32_MAX, nullptr);
         break;
       }
     }
