diff --git a/deps/uv/src/unix/netbsd.c b/deps/uv/src/unix/netbsd.c
index 2fedc94..12fc8f9 100644
--- deps/uv/src/unix/netbsd.c
+++ deps/uv/src/unix/netbsd.c
@@ -19,10 +19,14 @@
  */
 
 #include "uv.h"
+#include "internal.h"
 
 #include <assert.h>
 #include <string.h>
 #include <errno.h>
+#include <kvm.h>
+#include <paths.h>
+#include <fcntl.h>
 
 #include <sys/resource.h>
 #include <sys/types.h>
@@ -106,3 +110,180 @@ uint64_t uv_get_total_memory(void) {
 
   return (uint64_t) info;
 }
+
+/* new from openbsd.c */
+static char *process_title;
+
+uv_err_t uv_set_process_title(const char* title) {
+  if (process_title) free(process_title);
+  process_title = strdup(title);
+  setproctitle(title);
+  return uv_ok_;
+}
+
+uv_err_t uv_get_process_title(char* buffer, size_t size) {
+  if (process_title) {
+    strncpy(buffer, process_title, size);
+  } else {
+    if (size > 0) {
+      buffer[0] = '\0';
+    }
+  }
+
+  return uv_ok_;
+}
+
+uv_err_t uv_uptime(double* uptime) {
+  time_t now;
+  struct timeval info;
+  size_t size = sizeof(info);
+  static int which[] = {CTL_KERN, KERN_BOOTTIME};
+
+  if (sysctl(which, 2, &info, &size, NULL, 0) < 0) {
+    return uv__new_sys_error(errno);
+  }
+
+  now = time(NULL);
+
+  *uptime = (double)(now - info.tv_sec);
+  return uv_ok_;
+}
+
+void uv_free_cpu_info(uv_cpu_info_t* cpu_infos, int count) {
+  int i;
+
+  for (i = 0; i < count; i++) {
+    free(cpu_infos[i].model);
+  }
+
+  free(cpu_infos);
+}
+
+
+uv_err_t uv_interface_addresses(uv_interface_address_t** addresses,
+  int* count) {
+  /* TODO: implement */
+  *addresses = NULL;
+  *count = 0;
+  return uv_ok_;
+}
+
+
+void uv_free_interface_addresses(uv_interface_address_t* addresses,
+  int count) {
+}
+
+uv_err_t uv_cpu_info(uv_cpu_info_t** cpu_infos, int* count) {
+  unsigned int ticks = (unsigned int)sysconf(_SC_CLK_TCK),
+               multiplier = ((uint64_t)1000L / ticks), cpuspeed, maxcpus,
+               cur = 0;
+  uv_cpu_info_t* cpu_info;
+  char model[512];
+  long* cp_times;
+  int numcpus;
+  size_t size;
+  int i;
+
+  size = sizeof(model);
+  if (sysctlbyname("hw.model", &model, &size, NULL, 0) < 0) {
+    return uv__new_sys_error(errno);
+  }
+  size = sizeof(numcpus);
+  if (sysctlbyname("hw.ncpu", &numcpus, &size, NULL, 0) < 0) {
+    return uv__new_sys_error(errno);
+  }
+
+  *cpu_infos = (uv_cpu_info_t*)malloc(numcpus * sizeof(uv_cpu_info_t));
+  if (!(*cpu_infos)) {
+    return uv__new_artificial_error(UV_ENOMEM);
+  }
+
+  *count = numcpus;
+
+  size = sizeof(cpuspeed);
+  if (sysctlbyname("hw.clockrate", &cpuspeed, &size, NULL, 0) < 0) {
+    free(*cpu_infos);
+    return uv__new_sys_error(errno);
+  }
+  /* kern.cp_times on FreeBSD i386 gives an array up to maxcpus instead of ncpu */
+  size = sizeof(maxcpus);
+#ifdef __DragonFly__
+  if (sysctlbyname("hw.ncpu", &maxcpus, &size, NULL, 0) < 0) {
+    free(*cpu_infos);
+    return uv__new_sys_error(errno);
+  }
+#else
+  if (sysctlbyname("kern.smp.maxcpus", &maxcpus, &size, NULL, 0) < 0) {
+    free(*cpu_infos);
+    return uv__new_sys_error(errno);
+  }
+#endif
+
+  size = maxcpus * CPUSTATES * sizeof(long);
+
+  cp_times = malloc(size);
+  if (cp_times == NULL) {
+    free(*cpu_infos);
+    return uv__new_sys_error(ENOMEM);
+  }
+
+  if (sysctlbyname("kern.cp_times", &cp_times, &size, NULL, 0) < 0) {
+    free(cp_times);
+    free(*cpu_infos);
+    return uv__new_sys_error(errno);
+  }
+
+  for (i = 0; i < numcpus; i++) {
+    cpu_info = &(*cpu_infos)[i];
+
+    cpu_info->cpu_times.user = (uint64_t)(cp_times[CP_USER+cur]) * multiplier;
+    cpu_info->cpu_times.nice = (uint64_t)(cp_times[CP_NICE+cur]) * multiplier;
+    cpu_info->cpu_times.sys = (uint64_t)(cp_times[CP_SYS+cur]) * multiplier;
+    cpu_info->cpu_times.idle = (uint64_t)(cp_times[CP_IDLE+cur]) * multiplier;
+    cpu_info->cpu_times.irq = (uint64_t)(cp_times[CP_INTR+cur]) * multiplier;
+
+    cpu_info->model = strdup(model);
+    cpu_info->speed = cpuspeed;
+
+    cur+=CPUSTATES;
+  }
+
+  free(cp_times);
+  return uv_ok_;
+}
+
+uv_err_t uv_resident_set_memory(size_t* rss) {
+  kvm_t *kd = NULL;
+  struct kinfo_proc2 *kinfo = NULL;
+  pid_t pid;
+  int nprocs;
+  size_t page_size = getpagesize();
+
+  pid = getpid();
+
+  kd = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, "kvm_open");
+  if (kd == NULL) goto error;
+
+  kinfo = kvm_getprocs(kd, KERN_PROC_PID, pid, &nprocs);
+  if (kinfo == NULL) goto error;
+
+#ifdef __DragonFly__
+  *rss = kinfo->kp_vm_rssize * page_size;
+#else
+  *rss = kinfo->p_vm_rssize * page_size;
+#endif
+
+  kvm_close(kd);
+
+  return uv_ok_;
+
+error:
+  if (kd) kvm_close(kd);
+  return uv__new_sys_error(errno);
+}
+
+char** uv_setup_args(int argc, char** argv) {
+  process_title = argc ? strdup(argv[0]) : NULL;
+  return argv;
+}
+
