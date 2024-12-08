$NetBSD$

/scratch/wip/webkit-gtk-2.46/work/webkitgtk-2.46.4/Source/WebCore/platform/graphics/gstreamer/mse/MediaSourcePrivateGStreamer.cpp:177:9: error: 'm_trackIdRegistry' was not declared in this scope
  177 |     if (m_trackIdRegistry.add(preferredId).isNewEntry) {
      |         ^~~~~~~~~~~~~~~~~

--- Source/WebCore/platform/graphics/gstreamer/mse/MediaSourcePrivateGStreamer.h.orig	2024-12-08 10:25:49.929155900 +0000
+++ Source/WebCore/platform/graphics/gstreamer/mse/MediaSourcePrivateGStreamer.h
@@ -94,12 +94,12 @@ private:
     Ref<const Logger> m_logger;
     const void* m_logIdentifier;
     uint64_t m_nextSourceBufferID { 0 };
+#endif
 
     // Stores known track IDs, so we can work around ID collisions between multiple source buffers.
     // The registry is placed here to enforce ID uniqueness specifically by player, not by process,
     // since its not an issue if multiple players use the same ID, and we want to preserve IDs as much as possible.
     HashSet<TrackID, WTF::IntHash<TrackID>, WTF::UnsignedWithZeroKeyHashTraits<TrackID>> m_trackIdRegistry;
-#endif
 };
 
 } // namespace WebCore
