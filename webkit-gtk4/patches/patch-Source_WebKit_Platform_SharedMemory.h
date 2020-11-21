$NetBSD$

--- Source/WebKit/Platform/SharedMemory.h.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/Platform/SharedMemory.h
@@ -96,11 +96,10 @@ public:
         mutable IPC::Attachment m_attachment;
 #elif OS(DARWIN)
         mutable mach_port_t m_port { MACH_PORT_NULL };
-        size_t m_size;
 #elif OS(WINDOWS)
         mutable HANDLE m_handle;
-        size_t m_size;
 #endif
+	size_t m_size;
     };
 
     static RefPtr<SharedMemory> allocate(size_t);
