$NetBSD$

--- libphobos/libdruntime/core/sys/netbsd/execinfo.d.orig	2018-10-28 19:51:47.000000000 +0000
+++ libphobos/libdruntime/core/sys/netbsd/execinfo.d
@@ -14,103 +14,9 @@ nothrow:
 
 import core.sys.netbsd.dlfcn;
 
-// Use extern (D) so that these functions don't collide with libexecinfo.
-
-extern (D) int backtrace(void** buffer, int size)
-{
-    import core.thread : thread_stackBottom;
-
-    void** p, pend=cast(void**)thread_stackBottom();
-    version (D_InlineAsm_X86)
-        asm nothrow @trusted { mov p[EBP], EBP; }
-    else version (D_InlineAsm_X86_64)
-        asm nothrow @trusted { mov p[RBP], RBP; }
-    else
-        static assert(false, "Architecture not supported.");
-
-    int i;
-    for (; i < size && p < pend; ++i)
-    {
-        buffer[i] = *(p + 1);
-        auto pnext = cast(void**)*p;
-        if (pnext <= p) break;
-        p = pnext;
-    }
-    return i;
-}
-
-
-extern (D) char** backtrace_symbols(const(void*)* buffer, int size)
-{
-    static void* realloc(void* p, size_t len) nothrow
-    {
-        static import cstdlib=core.stdc.stdlib;
-        auto res = cstdlib.realloc(p, len);
-        if (res is null) cstdlib.free(p);
-        return res;
-    }
-
-    if (size <= 0) return null;
-
-    size_t pos = size * (char*).sizeof;
-    char** p = cast(char**)realloc(null, pos);
-    if (p is null) return null;
-
-    Dl_info info;
-    foreach (i, addr; buffer[0 .. size])
-    {
-        if (dladdr(addr, &info) == 0)
-            (cast(ubyte*)&info)[0 .. info.sizeof] = 0;
-        fixupDLInfo(addr, info);
-
-        immutable len = formatStackFrame(null, 0, addr, info);
-        assert(len > 0);
-
-        p = cast(char**)realloc(p, pos + len);
-        if (p is null) return null;
-
-        formatStackFrame(cast(char*)p + pos, len, addr, info) == len || assert(0);
-
-        p[i] = cast(char*)pos;
-        pos += len;
-    }
-    foreach (i; 0 .. size)
-    {
-        pos = cast(size_t)p[i];
-        p[i] = cast(char*)p + pos;
-    }
-    return p;
-}
-
-
-extern (D) void backtrace_symbols_fd(const(void*)* buffer, int size, int fd)
-{
-    import core.sys.posix.unistd : write;
-    import core.stdc.stdlib : alloca;
-
-    if (size <= 0) return;
-
-    Dl_info info;
-    foreach (i, addr; buffer[0 .. size])
-    {
-        if (dladdr(addr, &info) == 0)
-            (cast(ubyte*)&info)[0 .. info.sizeof] = 0;
-        fixupDLInfo(addr, info);
-
-        enum maxAlloca = 1024;
-        enum min = (size_t a, size_t b) => a <= b ? a : b;
-        immutable len = min(formatStackFrame(null, 0, addr, info), maxAlloca);
-        assert(len > 0);
-
-        auto p = cast(char*)alloca(len);
-        if (p is null) return;
-
-        formatStackFrame(p, len, addr, info) >= len || assert(0);
-        p[len - 1] = '\n';
-        write(fd, p, len);
-    }
-}
-
+int backtrace(void** buffer, size_t size);
+char** backtrace_symbols(const(void*)* buffer, size_t size);
+int backtrace_symbols_fd(const(void*)* buffer, size_t size, int fd);
 
 private void fixupDLInfo(const(void)* addr, ref Dl_info info)
 {
