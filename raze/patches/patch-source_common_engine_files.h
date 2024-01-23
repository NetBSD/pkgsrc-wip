$NetBSD$

Add a missing include for source/common/utility/writezip.cpp.

--- source/common/engine/files.h.orig	2024-01-01 06:47:40.000000000 +0000
+++ source/common/engine/files.h
@@ -1,6 +1,7 @@
 #pragma once
 #include "fs_files.h"
+#include "fs_decompress.h"
 
 using FileSys::FileReader;
 using FileSys::FileWriter;
-using FileSys::BufferWriter;
\ No newline at end of file
+using FileSys::BufferWriter;
