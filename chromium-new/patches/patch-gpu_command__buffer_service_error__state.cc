$NetBSD$

--- gpu/command_buffer/service/error_state.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ gpu/command_buffer/service/error_state.cc
@@ -108,6 +108,7 @@ uint32_t ErrorStateImpl::GetGLError() {
 
 GLenum ErrorStateImpl::GetErrorHandleContextLoss() {
   GLenum error = glGetError();
+#if !defined(OS_NETBSD)
   if (error == GL_CONTEXT_LOST_KHR) {
     client_->OnContextLostError();
     // Do not expose GL_CONTEXT_LOST_KHR, as the version of the robustness
@@ -115,6 +116,7 @@ GLenum ErrorStateImpl::GetErrorHandleCon
     // buffer.
     error = GL_NO_ERROR;
   }
+#endif
   return error;
 }
 
@@ -205,7 +207,11 @@ void ErrorStateImpl::ClearRealGLErrors(
   // Clears and logs all current gl errors.
   GLenum error;
   while ((error = glGetError()) != GL_NO_ERROR) {
+#if defined(OS_NETBSD)
+    if (error != GL_OUT_OF_MEMORY) {
+#else
     if (error != GL_CONTEXT_LOST_KHR && error != GL_OUT_OF_MEMORY) {
+#endif
       // GL_OUT_OF_MEMORY can legally happen on lost device.
       logger_->LogMessage(
           filename, line,
