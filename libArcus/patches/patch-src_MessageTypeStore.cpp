$NetBSD$

Migration to protobuf v22

--- src/MessageTypeStore.cpp.orig	2024-08-19 13:43:12.527078688 +0000
+++ src/MessageTypeStore.cpp
@@ -52,7 +52,7 @@ class ErrorCollector : public google::pr
 public:
     ErrorCollector() : _error_count(0) { }
 
-    void AddError(const std::string& filename, int line, int column, const std::string& message) override
+    void RecordError(absl::string_view filename, int line, int column, absl::string_view message) override
     {
         _stream << "[" << filename << " (" << line << "," << column << ")] " << message << std::endl;
         _error_count++;
