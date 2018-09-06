$NetBSD$

--- src/os-netbsd.c.orig	2018-09-05 10:31:53.462583014 +0000
+++ src/os-netbsd.c
@@ -0,0 +1,119 @@
+/* libunwind - a platform-independent unwind library
+   Copyright (C) 2018 Kamil Rytarowski <n54@gmx.com>
+
+This file is part of libunwind.
+
+Permission is hereby granted, free of charge, to any person obtaining
+a copy of this software and associated documentation files (the
+"Software"), to deal in the Software without restriction, including
+without limitation the rights to use, copy, modify, merge, publish,
+distribute, sublicense, and/or sell copies of the Software, and to
+permit persons to whom the Software is furnished to do so, subject to
+the following conditions:
+
+The above copyright notice and this permission notice shall be
+included in all copies or substantial portions of the Software.
+
+THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
+EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
+MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
+NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
+LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
+OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
+WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
+
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/mman.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
+#include <errno.h>
+
+#include "libunwind_i.h"
+
+static void *
+get_mem(size_t sz)
+{
+  void *res;
+
+  res = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
+  if (res == MAP_FAILED)
+    return (NULL);
+  return (res);
+}
+
+static void
+free_mem(void *ptr, size_t sz)
+{
+  munmap(ptr, sz);
+}
+
+int
+tdep_get_elf_image (struct elf_image *ei, pid_t pid, unw_word_t ip,
+                    unsigned long *segbase, unsigned long *mapoff, char *path, size_t pathlen)
+{
+  int mib[5], error, ret;
+  size_t len, len1;
+  char *buf, *bp, *eb;
+  struct kinfo_vmentry *kv;
+
+  len = 0;
+  mib[0] = CTL_VM;
+  mib[1] = VM_PROC;
+  mib[2] = VM_PROC_MAP;
+  mib[3] = pid;
+  mib[4] = sizeof(struct kinfo_vmentry);
+
+  error = sysctl(mib, 4, NULL, &len, NULL, 0);
+  if (error == -1)
+      return (-UNW_EUNSPEC);
+  len1 = len * 4 / 3;
+  buf = get_mem(len1);
+  if (buf == NULL)
+    return (-UNW_EUNSPEC);
+  len = len1;
+  error = sysctl(mib, 4, buf, &len, NULL, 0);
+  if (error == -1) {
+    free_mem(buf, len1);
+    return (-UNW_EUNSPEC);
+  }
+  ret = -UNW_EUNSPEC;
+  for (bp = buf, eb = buf + len; bp < eb; bp += sizeof(struct kinfo_vmentry)) {
+     kv = (struct kinfo_vmentry *)(uintptr_t)bp;
+     if (ip < kv->kve_start || ip >= kv->kve_end)
+       continue;
+     if (kv->kve_type != KVME_TYPE_VNODE)
+       continue;
+     *segbase = kv->kve_start;
+     *mapoff = kv->kve_offset;
+     if (path)
+       {
+         strncpy(path, kv->kve_path, pathlen);
+       }
+     ret = elf_map_image (ei, kv->kve_path);
+     break;
+  }
+  free_mem(buf, len1);
+  return (ret);
+}
+
+#ifndef UNW_REMOTE_ONLY
+
+void
+tdep_get_exe_image_path (char *path)
+{
+  int mib[4], error;
+  size_t len;
+
+  len = 0;
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC_ARGS;
+  mib[2] = -1;
+  mib[3] = KERN_PROC_PATHNAME;
+
+  error = sysctl(mib, 4, path, &len, NULL, 0);
+  if (error == -1)
+	  path[0] = 0;
+}
+
+#endif
