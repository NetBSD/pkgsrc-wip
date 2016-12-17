$NetBSD$

--- source/Plugins/Process/Linux/NativeRegisterContextLinux.cpp.orig	2016-10-19 22:25:12.000000000 +0000
+++ source/Plugins/Process/Linux/NativeRegisterContextLinux.cpp
@@ -163,6 +163,7 @@ Error NativeRegisterContextLinux::DoRead
   Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_REGISTERS));
 
   long data;
+#if !defined(__NetBSD__)
   Error error = NativeProcessLinux::PtraceWrapper(
       PTRACE_PEEKUSER, m_thread.GetID(), reinterpret_cast<void *>(offset),
       nullptr, 0, &data);
@@ -170,6 +171,9 @@ Error NativeRegisterContextLinux::DoRead
   if (error.Success())
     // First cast to an unsigned of the same size to avoid sign extension.
     value.SetUInt(static_cast<unsigned long>(data), size);
+#else
+  Error error;
+#endif
 
   if (log)
     log->Printf("NativeRegisterContextLinux::%s() reg %s: 0x%lx", __FUNCTION__,
@@ -188,8 +192,13 @@ Error NativeRegisterContextLinux::DoWrit
     log->Printf("NativeRegisterContextLinux::%s() reg %s: %p", __FUNCTION__,
                 reg_name, buf);
 
+#if !defined(__NetBSD__)
   return NativeProcessLinux::PtraceWrapper(
       PTRACE_POKEUSER, m_thread.GetID(), reinterpret_cast<void *>(offset), buf);
+#else
+  Error error;
+  return error;
+#endif
 }
 
 Error NativeRegisterContextLinux::DoReadGPR(void *buf, size_t buf_size) {
