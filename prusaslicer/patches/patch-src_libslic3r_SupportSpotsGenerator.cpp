$NetBSD$

Fix ambiguous lambda return type on netbsd evbarm.

--- src/libslic3r/SupportSpotsGenerator.cpp.orig	2023-11-23 14:51:47.000000000 +0000
+++ src/libslic3r/SupportSpotsGenerator.cpp
@@ -979,7 +979,7 @@ SliceMappings update_active_object_parts
                 }
             }
             const float bottom_z = layer->bottom_z();
-            auto estimate_conn_strength = [bottom_z](const SliceConnection &conn) {
+            auto estimate_conn_strength = [bottom_z](const SliceConnection &conn) -> float {
                 if (conn.area < EPSILON) { // connection is empty, does not exists. Return max strength so that it is not picked as the
                                            // weakest connection.
                     return INFINITY;
