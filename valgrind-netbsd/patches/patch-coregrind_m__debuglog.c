$NetBSD$

--- coregrind/m_debuglog.c.orig	2018-09-03 05:28:32.000000000 +0000
+++ coregrind/m_debuglog.c
@@ -566,6 +566,49 @@ static UInt local_sys_getpid ( void )
    return res;
 }
 
+#elif defined(VGP_amd64_netbsd)
+__attribute__((noinline))
+static UInt local_sys_write_stderr ( HChar* buf, Int n )
+{
+   volatile Long block[2];
+   block[0] = (Long)buf;
+   block[1] = n;
+   __asm__ volatile (
+      "subq  $256, %%rsp\n"     /* don't trash the stack redzone */
+      "pushq %%r15\n"           /* r15 is callee-save */
+      "movq  %0, %%r15\n"       /* r15 = &block */
+      "pushq %%r15\n"           /* save &block */
+      "movq  $"VG_STRINGIFY(__NR_write)", %%rax\n" /* rax = __NR_write */
+      "movq  $2, %%rdi\n"       /* rdi = stderr */
+      "movq  0(%%r15), %%rsi\n" /* rsi = buf */
+      "movq  8(%%r15), %%rdx\n" /* rdx = n */
+      "syscall\n"               /* write(stderr, buf, n) */
+      "popq  %%r15\n"           /* reestablish &block */
+      "movq  %%rax, 0(%%r15)\n" /* block[0] = result */                                                                                                      
+      "popq  %%r15\n"           /* restore r15 */
+      "addq  $256, %%rsp\n"     /* restore stack ptr */
+      : /*wr*/
+      : /*rd*/    "g" (block)
+      : /*trash*/ "rax", "rdi", "rsi", "rdx", "memory", "cc"
+   );
+   if (block[0] < 0)
+      block[0] = -1;
+   return (UInt)block[0];
+}
+
+static UInt local_sys_getpid ( void )
+{
+   UInt __res;
+   __asm__ volatile (
+      "movq $20, %%rax\n"  /* set %rax = __NR_getpid */
+      "syscall\n"          /* getpid() */
+      "movl %%eax, %0\n"   /* set __res = %eax */
+      : "=mr" (__res)
+      :
+      : "rax" );
+   return __res;
+}
+
 #else
 # error Unknown platform
 #endif
