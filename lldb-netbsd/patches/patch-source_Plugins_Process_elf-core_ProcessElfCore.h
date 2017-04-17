$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.h.orig	2017-02-04 18:35:34.000000000 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.h
@@ -125,6 +125,18 @@ private:
     lldb_private::ConstString path;
   };
 
+  // Parse thread(s) data structuresNetBSD(prstatus, prpsinfo) from given NOTE
+  // segment
+  lldb_private::Error ParseThreadContextsFromNoteSegmentNetBSD(
+      const elf::ELFProgramHeader *segment_header,
+      lldb_private::DataExtractor segment_data);
+
+  // Parse thread(s) data structuresGeneric(prstatus, prpsinfo) from given NOTE
+  // segment
+  lldb_private::Error ParseThreadContextsFromNoteSegmentGeneric(
+      const elf::ELFProgramHeader *segment_header,
+      lldb_private::DataExtractor segment_data);
+
   //------------------------------------------------------------------
   // For ProcessElfCore only
   //------------------------------------------------------------------
