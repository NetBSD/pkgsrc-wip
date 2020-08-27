$NetBSD$

- Fix NetBSD support.

--- src/netbsd.cc.orig	2020-07-27 12:01:52.000000000 +0000
+++ src/netbsd.cc
@@ -30,11 +30,31 @@
 #include "netbsd.h"
 #include "net_stat.h"
 
+#include <ifaddrs.h>
+
+#define P_BOOL     0
+#define P_UINT8    1
+#define P_INT64    2
+#define P_STRING   3
+
+#define _DEV_SYSMON "/dev/sysmon"
+
+typedef struct Devquery {
+  int type;
+  const char *dev;
+  const char *key;
+  const char *row;
+} Devquery;
+
+int sysmon_fd;
+
 static kvm_t *kd = nullptr;
 int kd_init = 0, nkd_init = 0;
 u_int32_t sensvalue;
 char errbuf[_POSIX2_LINE_MAX];
 
+static short conky_cpu_setup = 0;
+
 static int init_kvm(void) {
   if (kd_init) { return 0; }
 
@@ -82,13 +102,13 @@ static int swapmode(int *retavail, int *
   return 1;
 }
 
-void prepare_update() {}
+void prepare_update(void) {}
 
-void update_uptime() {
+int update_uptime(void) {
   int mib[2] = {CTL_KERN, KERN_BOOTTIME};
   struct timeval boottime;
   time_t now;
-  int size = sizeof(boottime);
+  size_t size = sizeof(boottime);
 
   if ((sysctl(mib, 2, &boottime, &size, nullptr, 0) != -1) &&
       (boottime.tv_sec != 0)) {
@@ -98,136 +118,158 @@ void update_uptime() {
     warn("could not get uptime");
     info.uptime = 0;
   }
+  return 0;
 }
 
 int check_mount(struct text_object *obj) {
-  /* stub */
-  (void)obj;
+  int nbmount, i;
+  struct statvfs *mntbuf;
+
+  nbmount = getmntinfo(&mntbuf, MNT_NOWAIT);
+
+  for (i = 0; i < nbmount; i++) {
+    if (strcmp(mntbuf[i].f_mntonname, obj->data.s) == 0) {
+      return 1;
+    }
+  }
   return 0;
 }
 
-void update_meminfo() {
-  int mib[] = {CTL_VM, VM_UVMEXP2};
-  int total_pages, inactive_pages, free_pages;
-  int swap_avail, swap_free;
-  const int pagesize = getpagesize();
+int update_meminfo(void) {
+  int mib[] = { CTL_VM, VM_UVMEXP2 };
   struct uvmexp_sysctl uvmexp;
-  size_t size = sizeof(uvmexp);
-
-  if (sysctl(mib, 2, &uvmexp, &size, nullptr, 0) < 0) {
-    warn("could not get memory info");
-    return;
-  }
+  size_t ssize;
 
-  total_pages = uvmexp.npages;
-  free_pages = uvmexp.free;
-  inactive_pages = uvmexp.inactive;
+  ssize = sizeof(uvmexp);
+  memset(&uvmexp, 0, ssize);
 
-  info.memmax = (total_pages * pagesize) >> 10;
-  info.mem = ((total_pages - free_pages - inactive_pages) * pagesize) >> 10;
-  info.memwithbuffers = info.mem;
-  info.memeasyfree = info.memfree = info.memmax - info.mem;
+  info.mem = info.memmax = info.swap = info.swapfree = info.swapmax = 0;
+  info.buffers = info.cached = info.memfree = info.memeasyfree = 0;
+  info.bufmem = 0;
 
-  if (swapmode(&swap_avail, &swap_free) >= 0) {
-    info.swapmax = swap_avail;
-    info.swap = (swap_avail - swap_free);
-    info.swapfree = swap_free;
+  if (sysctl(mib, 2, &uvmexp, &ssize, nullptr, 0) < 0) {
+    warn("could not get memory info");
+    return 0;
   }
+
+  info.memmax = uvmexp.npages * uvmexp.pagesize / 1024;
+  info.memfree = uvmexp.free * uvmexp.pagesize / 1024;
+  info.memeasyfree = uvmexp.inactive * uvmexp.pagesize / 1024;
+
+  info.swapmax = uvmexp.swpages * uvmexp.pagesize / 1024;
+  info.swapfree = (uvmexp.swpages - uvmexp.swpginuse) * \
+    uvmexp.pagesize / 1024;
+
+  info.buffers = uvmexp.filepages * uvmexp.pagesize / 1024;
+  info.cached = uvmexp.execpages * uvmexp.pagesize / 1024;
+
+  info.mem = info.memmax - info.memfree;
+  info.bufmem = info.cached + info.buffers;
+  info.swap = info.swapmax - info.swapfree;
+
+  /*
+   * Counter-adjust for the adjustment in update_stuff in common.c so
+   * that memeasyfree is the inactive memory.  Since inactive memory
+   * partially overlaps with buffer memory, but the size of the
+   * overlap is not measured, attempting to split it into non-bufmem
+   * and bufmem parts, as common.c does, can't work.  So instead we
+   * report inactive memory as memeasyfree.
+   */
+  info.memeasyfree -= info.bufmem;
+  return 0;
 }
 
-void update_net_stats() {
-  int i;
+int
+update_net_stats(void) {
+  struct net_stat *ns;
   double delta;
-  struct ifnet ifnet;
-  struct ifnet_head ifhead; /* interfaces are in a tail queue */
-  u_long ifnetaddr;
-  static struct nlist namelist[] = {{"_ifnet"}, {nullptr}};
-  static kvm_t *nkd;
-
-  if (!nkd_init) {
-    nkd = kvm_openfiles(nullptr, NULL, NULL, O_RDONLY, errbuf);
-    if (nkd == nullptr) {
-      warnx("cannot kvm_openfiles: %s", errbuf);
-      warnx("maybe you need to setgid kmem this program?");
-      return;
-    } else if (kvm_nlist(nkd, namelist) != 0) {
-      warn("cannot kvm_nlist");
-      return;
-    } else {
-      nkd_init = 1;
-    }
+  long long r, t, last_recv, last_trans;
+  struct ifaddrs *ifap, *ifa;
+  struct if_data *ifd;
+
+  /* get delta */
+  delta = current_update_time - last_update_time;
+  if (delta <= 0.0001) {
+    return 0;
   }
 
-  if (kvm_read(nkd, (u_long)namelist[0].n_value, (void *)&ifhead,
-               sizeof(ifhead)) < 0) {
-    warn("cannot kvm_read");
-    return;
+  if (getifaddrs(&ifap) < 0) {
+    return 0;
   }
 
-  /* get delta */
-  delta = current_update_time - last_update_time;
-  if (delta <= 0.0001) { return; }
+  for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+    ns = get_net_stat((const char *) ifa->ifa_name, NULL, NULL);
 
-  for (i = 0, ifnetaddr = (u_long)ifhead.tqh_first;
-       ifnet.if_list.tqe_next && i < 16;
-       ifnetaddr = (u_long)ifnet.if_list.tqe_next, i++) {
-    struct net_stat *ns;
-    long long last_recv, last_trans;
-
-    kvm_read(nkd, (u_long)ifnetaddr, (void *)&ifnet, sizeof(ifnet));
-    ns = get_net_stat(ifnet.if_xname, nullptr, NULL);
-    ns->up = 1;
-    last_recv = ns->recv;
-    last_trans = ns->trans;
-
-    if (ifnet.if_ibytes < ns->last_read_recv) {
-      ns->recv +=
-          ((long long)4294967295U - ns->last_read_recv) + ifnet.if_ibytes;
-    } else {
-      ns->recv += (ifnet.if_ibytes - ns->last_read_recv);
-    }
+    if (ifa->ifa_flags & IFF_UP) {
+      struct ifaddrs *iftmp;
 
-    ns->last_read_recv = ifnet.if_ibytes;
+      ns->up = 1;
+      last_recv = ns->recv;
+      last_trans = ns->trans;
 
-    if (ifnet.if_obytes < ns->last_read_trans) {
-      ns->trans +=
-          ((long long)4294967295U - ns->last_read_trans) + ifnet.if_obytes;
-    } else {
-      ns->trans += (ifnet.if_obytes - ns->last_read_trans);
-    }
+      if (ifa->ifa_addr->sa_family != AF_LINK) {
+        continue;
+      }
 
-    ns->last_read_trans = ifnet.if_obytes;
+      for (iftmp = ifa->ifa_next;
+         iftmp != NULL && strcmp(ifa->ifa_name, iftmp->ifa_name) == 0;
+         iftmp = iftmp->ifa_next) {
+        if (iftmp->ifa_addr->sa_family == AF_INET) {
+          memcpy(&(ns->addr), iftmp->ifa_addr,
+            iftmp->ifa_addr->sa_len);
+        }
+      }
+
+      ifd = (struct if_data *) ifa->ifa_data;
+      r = ifd->ifi_ibytes;
+      t = ifd->ifi_obytes;
+
+      if (r < ns->last_read_recv) {
+        ns->recv += ((long long) 4294967295U - ns->last_read_recv) + r;
+      } else {
+        ns->recv += (r - ns->last_read_recv);
+      }
+
+      ns->last_read_recv = r;
 
-    ns->recv += (ifnet.if_ibytes - ns->last_read_recv);
-    ns->last_read_recv = ifnet.if_ibytes;
-    ns->trans += (ifnet.if_obytes - ns->last_read_trans);
-    ns->last_read_trans = ifnet.if_obytes;
+      if (t < ns->last_read_trans) {
+        ns->trans += (long long) 4294967295U - ns->last_read_trans + t;
+      } else {
+        ns->trans += (t - ns->last_read_trans);
+      }
+
+      ns->last_read_trans = t;
 
-    ns->recv_speed = (ns->recv - last_recv) / delta;
-    ns->trans_speed = (ns->trans - last_trans) / delta;
+      /* calculate speeds */
+      ns->recv_speed = (ns->recv - last_recv) / delta;
+      ns->trans_speed = (ns->trans - last_trans) / delta;
+    } else {
+      ns->up = 0;
+    }
   }
-}
 
-int update_total_processes() {
-  /* It's easier to use kvm here than sysctl */
+  freeifaddrs(ifap);
 
-  int n_processes;
+  return 0;
+}
 
-  info.procs = 0;
 
-  if (init_kvm() < 0) {
-    return;
-  } else {
-    kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
-                 &n_processes);
+int update_total_processes(void)
+{
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL};
+  size_t size;
+
+  if (sysctl(mib, 3, NULL, &size, NULL, 0) < 0) {
+    warn("sysctl KERN_PROC_ALL failed");
+    return 0;
   }
 
-  info.procs = n_processes;
+  info.procs = (size / sizeof (struct kinfo_proc));
 
   return 0;
 }
 
-void update_running_processes() {
+int update_running_processes(void) {
   struct kinfo_proc2 *p;
   int n_processes;
   int i, cnt = 0;
@@ -235,7 +277,7 @@ void update_running_processes() {
   info.run_procs = 0;
 
   if (init_kvm() < 0) {
-    return;
+    return 0;
   } else {
     p = kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
                      &n_processes);
@@ -248,50 +290,84 @@ void update_running_processes() {
   }
 
   info.run_procs = cnt;
+  return 0;
 }
 
-struct cpu_load_struct {
-  unsigned long load[5];
-};
+void get_cpu_count(void) {
+  int cpu_count = 0;
+  size_t cpu_count_size = sizeof(cpu_count);
+
+  if (sysctlbyname("hw.ncpu", &cpu_count, &cpu_count_size, NULL, 0) != 0 || \
+      cpu_count_size != sizeof(cpu_count)) {
+    fprintf(stderr, "Cannot get hw.ncpu\n");
+    info.cpu_count = 0;
+  } else {
+    info.cpu_count = cpu_count;
+  }
+
+  info.cpu_usage = (float *)malloc((info.cpu_count + 1) * sizeof(float));
+  if (info.cpu_usage == nullptr) { CRIT_ERR(nullptr, NULL, "malloc"); }
+}
 
-struct cpu_load_struct fresh = {{0, 0, 0, 0, 0}};
+struct cpu_info {
+  long oldtotal;
+  long oldused;
+};
 
-long cpu_used, oldtotal, oldused;
+int update_cpu_usage(void) {
 
-void update_cpu_usage() {
+  int i, j = 0;
   long used, total;
-  static u_int64_t cp_time[CPUSTATES];
-  size_t len = sizeof(cp_time);
+  long *cp_time = nullptr;
+  size_t cp_len;
+  static struct cpu_info *cpu = nullptr;
+  unsigned int malloc_cpu_size = 0;
+  extern void *global_cpu;
+
+  /* add check for !info.cpu_usage since that mem is freed on a SIGUSR1 */
+  if ((conky_cpu_setup == 0) || (!info.cpu_usage)) {
+    get_cpu_count();
+    conky_cpu_setup = 1;
+  }
 
-  info.cpu_usage = 0;
+  if (!global_cpu) {
+    malloc_cpu_size = (info.cpu_count + 1) * sizeof(struct cpu_info);
+    cpu = (cpu_info *)malloc(malloc_cpu_size);
+    memset(cpu, 0, malloc_cpu_size);
+    global_cpu = cpu;
+  }
+
+  /* cpu[0] is overall stats, get it from separate sysctl */
+  cp_len = CPUSTATES * sizeof(long);
+  cp_time = (long int *)malloc(cp_len);
 
-  if (sysctlbyname("kern.cp_time", &cp_time, &len, nullptr, 0) < 0) {
-    warn("cannot get kern.cp_time");
+  if (sysctlbyname("kern.cp_time", cp_time, &cp_len, nullptr, 0) < 0) {
+    fprintf(stderr, "Cannot get kern.cp_time\n");
   }
 
-  fresh.load[0] = cp_time[CP_USER];
-  fresh.load[1] = cp_time[CP_NICE];
-  fresh.load[2] = cp_time[CP_SYS];
-  fresh.load[3] = cp_time[CP_IDLE];
-  fresh.load[4] = cp_time[CP_IDLE];
+  total = 0;
+  for (j = 0; j < CPUSTATES; j++) total += cp_time[j];
 
-  used = fresh.load[0] + fresh.load[1] + fresh.load[2];
-  total = fresh.load[0] + fresh.load[1] + fresh.load[2] + fresh.load[3];
+  used = total - cp_time[CP_IDLE];
 
-  if ((total - oldtotal) != 0) {
-    info.cpu_usage = ((double)(used - oldused)) / (double)(total - oldtotal);
+  if ((total - cpu[0].oldtotal) != 0) {
+    info.cpu_usage[0] =
+        ((double)(used - cpu[0].oldused)) / (double)(total - cpu[0].oldtotal);
   } else {
-    info.cpu_usage = 0;
+    info.cpu_usage[0] = 0;
   }
 
-  oldused = used;
-  oldtotal = total;
+  cpu[0].oldused = used;
+  cpu[0].oldtotal = total;
+
+  free(cp_time);
+  return 0;
 }
 
 void free_cpu(struct text_object *) { /* no-op */
 }
 
-void update_load_average() {
+int update_load_average(void) {
   double v[3];
 
   getloadavg(v, 3);
@@ -299,32 +375,156 @@ void update_load_average() {
   info.loadavg[0] = (float)v[0];
   info.loadavg[1] = (float)v[1];
   info.loadavg[2] = (float)v[2];
+  return 0;
+}
+
+/* char *get_acpi_fan() */
+void get_acpi_fan(char *p_client_buffer, size_t client_buffer_size) {
+  if (!p_client_buffer || client_buffer_size <= 0) { return; }
+
+  /* not implemented */
+  memset(p_client_buffer, 0, client_buffer_size);
 }
 
-double get_acpi_temperature(int fd) { return -1; }
+/* needs root on NetBSD */
+int get_entropy_avail(unsigned int *val) { return 1; }
+
+/* needs root on NetBSD */
+int get_entropy_poolsize(unsigned int *val) { return 1; }
+
+int
+sysmon_open()
+{
+  if (sysmon_fd == -1)
+    sysmon_fd = open(_DEV_SYSMON, O_RDONLY);
+
+  return sysmon_fd == -1;
+}
+ 
+int8_t
+envsys_get_val(Devquery dq, void *val)
+{
+  const char *descr;
+  const char *cval;
+  prop_dictionary_t dict;
+  prop_object_t device;
+  prop_object_iterator_t iter;
+  prop_object_t obj;
+  prop_string_t str;
+  bool rc = false;
+
+  if (!sysmon_open())
+    return -1;
+
+  if (prop_dictionary_recv_ioctl(sysmon_fd, ENVSYS_GETDICTIONARY, &dict)
+    != 0)
+    return -1;
+
+  if ((device = prop_dictionary_get(dict, dq.dev)) == NULL)
+    return -1;
+    
+  iter = prop_array_iterator((prop_array_t)device);
+
+  while((obj = prop_object_iterator_next(iter)))  {
+    if (!prop_dictionary_get_cstring_nocopy((prop_dictionary_t)obj, "description", &descr))
+      return -1;
+    if (descr != NULL && *descr) {
+      if(strcmp(descr, dq.key) == 0) {
+        switch(dq.type) {
+        case P_BOOL:
+          rc = prop_dictionary_get_bool((prop_dictionary_t)obj,
+            dq.row, (bool *)val);
+        case P_UINT8:
+          rc = prop_dictionary_get_uint8((prop_dictionary_t)obj,
+            dq.row, (uint8_t *)val);
+          break;
+        case P_INT64:
+          rc = prop_dictionary_get_int64((prop_dictionary_t)obj,
+            dq.row, (int64_t *)val);
+          break;
+        case P_STRING:
+          rc = prop_dictionary_get_cstring_nocopy((prop_dictionary_t)obj,
+            dq.row, &cval);
+          val = (void *)cval;
+          break;
+        }
+      }
+    }
+  }
+
+  prop_object_iterator_release(iter);
+  prop_object_release(dict);
 
-void get_battery_stuff(char *buf, unsigned int n, const char *bat, int item) {}
+  if (rc == false) {
+    val = NULL;
+    return -1;
+  }
+
+  return 0;
+}
 
 int open_acpi_temperature(const char *name) { return -1; }
 
+double get_acpi_temperature(int fd)
+{
+  Devquery dq_tz = { P_INT64, "acpitz0", "temperature", "cur-value" };
+  int64_t temperature;
+
+  if (envsys_get_val(dq_tz, (void *)&temperature) < 0) {
+    return 0;
+  }
+  return (temperature / 1000000.0) - 273.15;
+}
+
 void get_acpi_ac_adapter(char *p_client_buffer, size_t client_buffer_size,
                          const char *adapter) {
-  (void)adapter;  // only linux uses this
+  Devquery dq_acad = { P_BOOL, "acpiacad0", "connected", "cur-value" };
+  bool connected;
 
   if (!p_client_buffer || client_buffer_size <= 0) { return; }
 
+  if (envsys_get_val(dq_acad, (void *)&connected) < 0) {
+    strncpy(p_client_buffer, "N/A", client_buffer_size);
+    return;
+  }
+
+  if (connected) {
+    strncpy(p_client_buffer, "Running on AC Power", client_buffer_size);
+  } else {
+    strncpy(p_client_buffer, "Running on battery", client_buffer_size);
+  }
+}
+
+char get_freq(char *p_client_buffer, size_t client_buffer_size,                                                                                                               
+              const char *p_format, int divisor, unsigned int cpu) {
   /* not implemented */
-  memset(p_client_buffer, 0, client_buffer_size);
+  /* may be possible to implement, but machine dependent */
+  return 0;
 }
 
-/* char *get_acpi_fan() */
-void get_acpi_fan(char *p_client_buffer, size_t client_buffer_size) {
-  if (!p_client_buffer || client_buffer_size <= 0) { return; }
+void get_battery_stuff(char *buf, unsigned int n, const char *bat, int item) {
+  /* not implemented */
+}
 
+int get_battery_perct(const char *) {
   /* not implemented */
-  memset(p_client_buffer, 0, client_buffer_size);
+  return 0;
 }
 
-int get_entropy_avail(unsigned int *val) { return 1; }
+double get_battery_perct_bar(struct text_object *obj) {
+  /* not implemented */
+  return 0.0;
+}
 
-int get_entropy_poolsize(unsigned int *val) { return 1; }
+void get_battery_short_status(char *buffer, unsigned int n, const char *bat) {
+  /* not implemented */
+}
+
+int update_diskio(void) {
+  /* not implemented */
+  return 0;
+}
+
+void get_top_info(void) {
+  /* not implemented */
+}
