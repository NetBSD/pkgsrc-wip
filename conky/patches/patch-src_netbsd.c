$NetBSD: patch-src_netbsd.c,v 1.12 2012/05/12 18:43:11 imilh Exp $

--- src/netbsd.c.orig	2012-05-03 21:08:27.000000000 +0000
+++ src/netbsd.c
@@ -30,239 +30,226 @@
 
 #include "netbsd.h"
 #include "net_stat.h"
+#include "top.h"
+#include <sys/types.h>
+#include <sys/statvfs.h>
+#include <ifaddrs.h>
 
-static kvm_t *kd = NULL;
-int kd_init = 0, nkd_init = 0;
-u_int32_t sensvalue;
-char errbuf[_POSIX2_LINE_MAX];
+#define P_BOOL		0
+#define P_UINT8		1
+#define P_INT64		2
+#define P_STRING	3
 
-static int init_kvm(void)
-{
-	if (kd_init) {
-		return 0;
-	}
-
-	kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf);
-	if (kd == NULL) {
-		warnx("cannot kvm_openfiles: %s", errbuf);
-		return -1;
-	}
-	kd_init = 1;
-	return 0;
-}
-
-static int swapmode(int *retavail, int *retfree)
-{
-	int n;
-	struct swapent *sep;
-
-	*retavail = 0;
-	*retfree = 0;
-
-	n = swapctl(SWAP_NSWAP, 0, 0);
-
-	if (n < 1) {
-		warn("could not get swap information");
-		return 0;
-	}
+typedef struct Devquery {
+	int			type;
+	char		*dev;
+	char		*key;
+	char		*row;
+} Devquery;
 
-	sep = (struct swapent *) malloc(n * (sizeof(*sep)));
+u_int32_t		sensvalue;
+char			errbuf[_POSIX2_LINE_MAX];
+static short	cpu_setup = 0;
 
-	if (sep == NULL) {
-		warn("memory allocation failed");
-		return 0;
-	}
+int				sysmon_fd;
 
-	if (swapctl(SWAP_STATS, (void *) sep, n) < n) {
-		warn("could not get swap stats");
-		return 0;
-	}
-	for (; n > 0; n--) {
-		*retavail += (int) dbtob(sep[n - 1].se_nblks);
-		*retfree += (int) dbtob(sep[n - 1].se_nblks - sep[n - 1].se_inuse);
-	}
-	*retavail = (int) (*retavail / 1024);
-	*retfree = (int) (*retfree / 1024);
+inline void proc_find_top(struct process **cpu, struct process **mem);
 
-	return 1;
-}
+int8_t envsys_get_val(Devquery, void *);
 
-void prepare_update()
+void
+prepare_update(void)
 {
 }
 
-void update_uptime()
+int
+update_uptime(void)
 {
-	int mib[2] = { CTL_KERN, KERN_BOOTTIME };
-	struct timeval boottime;
-	time_t now;
-	int size = sizeof(boottime);
+	int 			mib[2] = { CTL_KERN, KERN_BOOTTIME };
+	struct timeval	boottime;
+	time_t			now;
+	size_t			size;
+
+	size = sizeof(boottime);
 
-	if ((sysctl(mib, 2, &boottime, &size, NULL, 0) != -1)
-			&& (boottime.tv_sec != 0)) {
+	if (sysctl(mib, 2, &boottime, &size, NULL, 0) < 0) {
+		warn("sysctl kern.boottime failed");
+		info.uptime = 0;
+	} else {
 		time(&now);
 		info.uptime = now - boottime.tv_sec;
-	} else {
-		warn("could not get uptime");
-		info.uptime = 0;
 	}
+
+	return 0;
 }
 
-int check_mount(char *s)
-{
-	/* stub */
+/* checks is mp is a mounted mountpoint */
+int
+check_mount(char *mp)
+{
+	int				nbmount, i;
+	struct statvfs	*mntbuf;
+
+	nbmount = getmntinfo(&mntbuf, MNT_NOWAIT);
+
+	for (i = 0; i < nbmount; i++) {
+		if (strcmp(mntbuf[i].f_mntonname, mp) == 0) {
+			return 1;
+		}
+	}
+
 	return 0;
 }
 
-void update_meminfo()
-{
-	int mib[] = { CTL_VM, VM_UVMEXP2 };
-	int total_pages, inactive_pages, free_pages;
-	int swap_avail, swap_free;
-	const int pagesize = getpagesize();
-	struct uvmexp_sysctl uvmexp;
-	size_t size = sizeof(uvmexp);
+/* mostly from vmstat.c */
+int
+update_meminfo(void)
+{
+	int						mib[] = { CTL_VM, VM_UVMEXP2 };
+	struct uvmexp_sysctl	uvmexp;
+	size_t					ssize;
+
+	ssize = sizeof(uvmexp);
+	memset(&uvmexp, 0, ssize);
+
+	info.mem = info.memmax = info.swap = info.swapfree = info.swapmax = 0;
+	info.buffers = info.cached = info.memfree = info.memeasyfree = 0;
+	info.bufmem = 0;
 
-	if (sysctl(mib, 2, &uvmexp, &size, NULL, 0) < 0) {
-		warn("could not get memory info");
-		return;
+	if (sysctl(mib, 2, &uvmexp, &ssize, NULL, 0) < 0) {
+		warn("sysctl vm.uvmexp2 failed");
+		return 0;
 	}
 
-	total_pages = uvmexp.npages;
-	free_pages = uvmexp.free;
-	inactive_pages = uvmexp.inactive;
+	info.memmax = uvmexp.npages * uvmexp.pagesize / 1024;
+	info.memfree = uvmexp.inactive * uvmexp.pagesize / 1024;
 
-	info.memmax = (total_pages * pagesize) >> 10;
-	info.mem = ((total_pages - free_pages - inactive_pages) * pagesize) >> 10;
-	info.memeasyfree = info.memfree = info.memmax - info.mem;
+	info.swapmax = uvmexp.swpages * uvmexp.pagesize / 1024;
+	info.swapfree = (uvmexp.swpages - uvmexp.swpginuse) * \
+		uvmexp.pagesize / 1024;
+
+	info.buffers = uvmexp.filepages * uvmexp.pagesize / 1024;
+	info.cached = uvmexp.execpages * uvmexp.pagesize / 1024;
+
+	info.mem = info.memmax - info.memfree;
+	info.memeasyfree = info.memfree;
+	info.bufmem = info.cached + info.buffers;
+	info.swap = info.swapmax - info.swapfree;
 
-	if (swapmode(&swap_avail, &swap_free) >= 0) {
-		info.swapmax = swap_avail;
-		info.swap = (swap_avail - swap_free);
-		info.swapfree = swap_free;
-	}
+	return 0;
 }
 
-void update_net_stats()
+int
+update_net_stats(void)
 {
-	int i;
+	struct net_stat *ns;
 	double delta;
-	struct ifnet ifnet;
-	struct ifnet_head ifhead;	/* interfaces are in a tail queue */
-	u_long ifnetaddr;
-	static struct nlist namelist[] = {
-		{ "_ifnet" },
-		{ NULL }
-	};
-	static kvm_t *nkd;
-
-	if (!nkd_init) {
-		nkd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, errbuf);
-		if (nkd == NULL) {
-			warnx("cannot kvm_openfiles: %s", errbuf);
-			warnx("maybe you need to setgid kmem this program?");
-			return;
-		} else if (kvm_nlist(nkd, namelist) != 0) {
-			warn("cannot kvm_nlist");
-			return;
-		} else {
-			nkd_init = 1;
-		}
-	}
-
-	if (kvm_read(nkd, (u_long) namelist[0].n_value, (void *) &ifhead,
-			sizeof(ifhead)) < 0) {
-		warn("cannot kvm_read");
-		return;
-	}
+	long long r, t, last_recv, last_trans;
+	struct ifaddrs *ifap, *ifa;
+	struct if_data *ifd;
 
 	/* get delta */
 	delta = current_update_time - last_update_time;
 	if (delta <= 0.0001) {
-		return;
+		return 0;
 	}
 
-	for (i = 0, ifnetaddr = (u_long) ifhead.tqh_first;
-			ifnet.if_list.tqe_next && i < 16;
-			ifnetaddr = (u_long) ifnet.if_list.tqe_next, i++) {
-
-		struct net_stat *ns;
-		long long last_recv, last_trans;
-
-		kvm_read(nkd, (u_long) ifnetaddr, (void *) &ifnet, sizeof(ifnet));
-		ns = get_net_stat(ifnet.if_xname, NULL, NULL);
-		ns->up = 1;
-		last_recv = ns->recv;
-		last_trans = ns->trans;
-
-		if (ifnet.if_ibytes < ns->last_read_recv) {
-			ns->recv += ((long long) 4294967295U - ns->last_read_recv) +
-				ifnet.if_ibytes;
-		} else {
-			ns->recv += (ifnet.if_ibytes - ns->last_read_recv);
-		}
+	if (getifaddrs(&ifap) < 0) {
+		return 0;
+	}
 
-		ns->last_read_recv = ifnet.if_ibytes;
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+		ns = get_net_stat((const char *) ifa->ifa_name, NULL, NULL);
 
-		if (ifnet.if_obytes < ns->last_read_trans) {
-			ns->trans += ((long long) 4294967295U - ns->last_read_trans) +
-				ifnet.if_obytes;
-		} else {
-			ns->trans += (ifnet.if_obytes - ns->last_read_trans);
-		}
+		if (ifa->ifa_flags & IFF_UP) {
+			struct ifaddrs *iftmp;
+
+			ns->up = 1;
+			last_recv = ns->recv;
+			last_trans = ns->trans;
+
+			if (ifa->ifa_addr->sa_family != AF_LINK) {
+				continue;
+			}
+
+			for (iftmp = ifa->ifa_next;
+				 iftmp != NULL && strcmp(ifa->ifa_name, iftmp->ifa_name) == 0;
+				 iftmp = iftmp->ifa_next) {
+				if (iftmp->ifa_addr->sa_family == AF_INET) {
+					memcpy(&(ns->addr), iftmp->ifa_addr,
+						iftmp->ifa_addr->sa_len);
+				}
+			}
+
+			ifd = (struct if_data *) ifa->ifa_data;
+			r = ifd->ifi_ibytes;
+			t = ifd->ifi_obytes;
+
+			if (r < ns->last_read_recv) {
+				ns->recv += ((long long) 4294967295U - ns->last_read_recv) + r;
+			} else {
+				ns->recv += (r - ns->last_read_recv);
+			}
 
-		ns->last_read_trans = ifnet.if_obytes;
+			ns->last_read_recv = r;
 
-		ns->recv += (ifnet.if_ibytes - ns->last_read_recv);
-		ns->last_read_recv = ifnet.if_ibytes;
-		ns->trans += (ifnet.if_obytes - ns->last_read_trans);
-		ns->last_read_trans = ifnet.if_obytes;
+			if (t < ns->last_read_trans) {
+				ns->trans += (long long) 4294967295U - ns->last_read_trans + t;
+			} else {
+				ns->trans += (t - ns->last_read_trans);
+			}
+
+			ns->last_read_trans = t;
 
-		ns->recv_speed = (ns->recv - last_recv) / delta;
-		ns->trans_speed = (ns->trans - last_trans) / delta;
+			/* calculate speeds */
+			ns->recv_speed = (ns->recv - last_recv) / delta;
+			ns->trans_speed = (ns->trans - last_trans) / delta;
+		} else {
+			ns->up = 0;
+		}
 	}
-}
 
-void update_total_processes()
-{
-	/* It's easier to use kvm here than sysctl */
+	freeifaddrs(ifap);
 
-	int n_processes;
+	return 0;
+}
 
-	info.procs = 0;
+int
+update_total_processes(void)
+{
+	int		mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL};
+	size_t	size;
 
-	if (init_kvm() < 0) {
-		return;
-	} else {
-		kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
-			&n_processes);
+	if (sysctl(mib, 3, NULL, &size, NULL, 0) < 0) {
+		warn("sysctl KERN_PROC_ALL failed");
+		return 0;
 	}
 
-	info.procs = n_processes;
+	info.procs = (size / sizeof (struct kinfo_proc));
+
+	return 0;
 }
 
-void update_running_processes()
+int
+update_running_processes()
 {
-	struct kinfo_proc2 *p;
-	int n_processes;
-	int i, cnt = 0;
+	int					n_processes, i, cnt = 0;
+	struct kinfo_proc2	*p;
 
 	info.run_procs = 0;
 
-	if (init_kvm() < 0) {
-		return;
-	} else {
-		p = kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
-			&n_processes);
-		for (i = 0; i < n_processes; i++) {
-			if (p[i].p_stat == LSRUN || p[i].p_stat == LSIDL
-					|| p[i].p_stat == LSONPROC) {
-				cnt++;
-			}
-		}
-	}
+	p = kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2),
+		&n_processes);
+
+	for (i = 0; i < n_processes; i++)
+		if (p[i].p_stat == LSRUN ||
+			p[i].p_stat == LSIDL || 
+			p[i].p_stat == LSONPROC)
+			cnt++;
 
 	info.run_procs = cnt;
+
+	return 0;
 }
 
 struct cpu_load_struct {
@@ -273,41 +260,79 @@ struct cpu_load_struct fresh = {
 	{0, 0, 0, 0, 0}
 };
 
-long cpu_used, oldtotal, oldused;
+long oldtotal[8], oldused[8];
 
-void update_cpu_usage()
+void
+get_cpu_count()
 {
+	static int mib[] = { CTL_HW, HW_NCPU };
+	size_t len = sizeof(int);
+	int cpu_count;
+
+	if (sysctl(mib, 2, &cpu_count, &len, NULL, 0) < 0)
+		cpu_count = 1;
+
+	info.cpu_count = cpu_count;
+
+	info.cpu_usage = malloc(info.cpu_count * sizeof(float));
+
+	if (info.cpu_usage == NULL)
+		warn("malloc");
+}
+
+int
+update_cpu_usage(void)
+{
+	typedef uint64_t cp_time_t[CPUSTATES];
+	static int mib[] = { CTL_KERN, KERN_CP_TIME };
+	static cp_time_t *cp_time = NULL;
+	int i;
 	long used, total;
-	static u_int64_t cp_time[CPUSTATES];
-	size_t len = sizeof(cp_time);
+	size_t len;
 
-	info.cpu_usage = 0;
+	if ((cpu_setup == 0) || (!info.cpu_usage)) {
+		get_cpu_count();
+		cpu_setup = 1;
+	}
+
+	cp_time = malloc(info.cpu_count * sizeof(cp_time_t));
 
-	if (sysctlbyname("kern.cp_time", &cp_time, &len, NULL, 0) < 0) {
+	info.cpu_usage[0] = 0;
+
+	len = sizeof(cp_time[0]) * info.cpu_count;
+	if (sysctl(mib, 2, cp_time, &len, NULL, 0) < 0) {
 		warn("cannot get kern.cp_time");
+		free(cp_time);
+		return 1;
 	}
 
-	fresh.load[0] = cp_time[CP_USER];
-	fresh.load[1] = cp_time[CP_NICE];
-	fresh.load[2] = cp_time[CP_SYS];
-	fresh.load[3] = cp_time[CP_IDLE];
-	fresh.load[4] = cp_time[CP_IDLE];
-
-	used = fresh.load[0] + fresh.load[1] + fresh.load[2];
-	total = fresh.load[0] + fresh.load[1] + fresh.load[2] + fresh.load[3];
-
-	if ((total - oldtotal) != 0) {
-		info.cpu_usage = ((double) (used - oldused)) /
-			(double) (total - oldtotal);
-	} else {
-		info.cpu_usage = 0;
+	for (i = 0; i < info.cpu_count; i++) {
+
+		fresh.load[0] = cp_time[i][CP_USER];
+		fresh.load[1] = cp_time[i][CP_NICE];
+		fresh.load[2] = cp_time[i][CP_SYS];
+		fresh.load[3] = cp_time[i][CP_IDLE];
+		fresh.load[4] = cp_time[i][CP_IDLE];
+
+		used = fresh.load[0] + fresh.load[1] + fresh.load[2];
+		total = fresh.load[0] + fresh.load[1] + fresh.load[2] + fresh.load[3];
+
+		if ((total - oldtotal[i]) != 0) {
+			info.cpu_usage[i] = ((double) (used - oldused[i])) /
+				(double) (total - oldtotal[i]);
+		} else {
+			info.cpu_usage[i] = 0;
+		}
+
+		oldused[i] = used;
+		oldtotal[i] = total;
 	}
 
-	oldused = used;
-	oldtotal = total;
+	free(cp_time); /* XXX: really not optimal... */
+	return 0;
 }
 
-void update_load_average()
+int update_load_average(void)
 {
 	double v[3];
 
@@ -316,51 +341,445 @@ void update_load_average()
 	info.loadavg[0] = (float) v[0];
 	info.loadavg[1] = (float) v[1];
 	info.loadavg[2] = (float) v[2];
+
+	return 0;
 }
 
-double get_acpi_temperature(int fd)
+int open_acpi_temperature(const char *name)
 {
+	(void)name; /* useless on NetBSD */
 	return -1;
 }
 
-void get_battery_stuff(char *buf, unsigned int n, const char *bat, int item)
+int get_entropy_avail(unsigned int *val)
+{
+	return 1;
+}
+
+int get_entropy_poolsize(unsigned int *val)
 {
+	return 1;
 }
 
-int open_acpi_temperature(const char *name)
+/* void */
+char
+get_freq(char *p_client_buffer, size_t client_buffer_size,
+	const char *p_format, int divisor, unsigned int cpu)
 {
-	return -1;
+        int freq = cpu;
+
+        if (!p_client_buffer || client_buffer_size <= 0 || !p_format
+                        || divisor <= 0) {
+                return 0;
+        }
+
+        size_t size = sizeof(freq);
+
+	if (sysctlbyname("machdep.est.frequency.current",
+			NULL, &size, NULL, 0) == 0) {
+		sysctlbyname("machdep.est.frequency.current", &freq, &size, NULL, 0);
+                snprintf(p_client_buffer, client_buffer_size, p_format,
+                        (float) freq / divisor);
+        } else {
+                snprintf(p_client_buffer, client_buffer_size, p_format, 0.0f);
+        }
+
+        return 1;
 }
 
-void get_acpi_ac_adapter(char *p_client_buffer, size_t client_buffer_size, const char *adapter)
+void update_diskio()
 {
-	(void) adapter; // only linux uses this
+	return; /* XXX: implement? hifi: not sure how */
+}
 
-	if (!p_client_buffer || client_buffer_size <= 0) {
+int update_top()
+{
+	proc_find_top(info.cpu, info.memu);
+
+	return 0;
+}
+
+int comparecpu(const void *a, const void *b)
+{
+	if (((struct process *) a)->amount > ((struct process *) b)->amount) {
+		return -1;
+	}
+	if (((struct process *) a)->amount < ((struct process *) b)->amount) {
+		return 1;
+	}
+
+	return 0;
+}
+
+int comparemem(const void *a, const void *b)
+{
+    if (((struct process *) a)->rss > ((struct process *) b)->rss) {
+		return -1;
+	}
+
+	if (((struct process *) a)->rss < ((struct process *) b)->rss) {
+		return 1;
+	}
+
+	return 0;
+}
+
+inline void proc_find_top(struct process **cpu, struct process **mem)
+{
+        struct kinfo_proc2 *p;
+        int n_processes;
+        int i, j = 0;
+        struct process *processes;
+        int mib[2];
+
+        u_int total_pages;
+        int64_t usermem;
+        int pagesize = getpagesize();
+
+        /* we get total pages count again to be sure it is up to date */
+        mib[0] = CTL_HW;
+        mib[1] = HW_USERMEM64;
+        size_t size = sizeof(usermem);
+
+        if (sysctl(mib, 2, &usermem, &size, NULL, 0) == -1) {
+                err(EXIT_FAILURE, "error reading usermem");
+        }
+
+        /* translate bytes into page count */
+        total_pages = usermem / pagesize;
+
+        int max_size = sizeof(struct kinfo_proc2);
+
+        p = kvm_getproc2(kd, KERN_PROC_ALL, 0, max_size, &n_processes);
+        processes = malloc(n_processes * sizeof(struct process));
+
+        for (i = 0; i < n_processes; i++) {
+			if (!((p[i].p_flag & P_SYSTEM)) && p[i].p_comm != NULL) {
+				processes[j].pid = p[i].p_pid;
+				processes[j].name = strndup(p[i].p_comm, text_buffer_size);
+				processes[j].amount = 100.0 * p[i].p_pctcpu / FSCALE;
+				processes[j].rss = p[i].p_vm_rssize * pagesize;
+				processes[j].vsize = p[i].p_vm_vsize;
+				j++;
+			}
+        }
+
+        qsort(processes, j - 1, sizeof(struct process), comparemem);
+        for (i = 0; i < 10; i++) {
+			struct process *tmp, *ttmp;
+				
+			tmp = malloc(sizeof(struct process));
+			memcpy(tmp, &processes[i], sizeof(struct process));
+			tmp->name = strndup(processes[i].name, text_buffer_size);
+
+			ttmp = mem[i];
+			mem[i] = tmp;
+			if (ttmp != NULL) {
+				free(ttmp->name);
+				free(ttmp);
+			}
+        }
+
+        qsort(processes, j - 1, sizeof(struct process), comparecpu);
+        for (i = 0; i < 10; i++) {
+			struct process *tmp, *ttmp;
+
+			tmp = malloc(sizeof(struct process));
+			memcpy(tmp, &processes[i], sizeof(struct process));
+			tmp->name = strndup(processes[i].name, text_buffer_size);
+			
+			ttmp = cpu[i];
+			cpu[i] = tmp;
+			if (ttmp != NULL) {
+				free(ttmp->name);
+				free(ttmp);
+			}
+        }
+
+        for (i = 0; i < j; i++) {
+			free(processes[i].name);
+        }
+        free(processes);
+}
+
+double
+get_acpi_temperature(int fd)
+{
+	Devquery dq_tz = { P_INT64, "acpitz0", "temperature", "cur-value" };
+	int64_t temp;
+
+	(void)fd;
+
+	if (envsys_get_val(dq_tz, (void *)&temp) < 0)
+		return 0.0;
+
+	return (temp / 1000000.0) - 273.15;
+}
+
+void
+get_bat_life(char *bat, char *buf)
+{
+	char row[32];
+	int64_t cur_charge, max_charge;
+	Devquery dq_charge = { P_INT64, bat, "charge", NULL};
+
+	strcpy(row, "max-value");
+	dq_charge.row = &row[0];
+
+	if (envsys_get_val(dq_charge, (void *)&max_charge) < 0) {
+		/* did not get any information from envsys */
+		strcpy(buf, "N/A");
 		return;
 	}
 
-	/* not implemented */
-	memset(p_client_buffer, 0, client_buffer_size);
+	strcpy(row, "cur-value");
+	dq_charge.row = &row[0];
+
+	if (envsys_get_val(dq_charge, (void *)&cur_charge) < 0) {
+		/* did not get any information from envsys */
+		strcpy(buf, "N/A");
+		return;
+	}
+
+	snprintf(buf, 8, "%d%%", (int)(((float) cur_charge / max_charge) * 100));
 }
 
-/* char *get_acpi_fan() */
-void get_acpi_fan(char *p_client_buffer, size_t client_buffer_size)
+int
+get_bat_state(char *bat, char *buf)
 {
+	bool connected = false, charging = false;
+	char curcap[8];
+	Devquery dq_ac = { P_BOOL, "acpiacad0", "connected", "cur-value" };
+	Devquery dq_charging = { P_BOOL, bat, "charging", "cur-value" };
+
+	/* get AC state */
+	if (envsys_get_val(dq_ac, (void *)&connected) < 0) {
+		/* did not get any information from envsys */
+		strcpy(buf, "N/A");
+		return 0;
+	}
+
+	/* used by get_acpi_ac_adapter */
+	if (bat == NULL)
+		return connected;
+
+	/* is the battery charging ? */
+	(void)envsys_get_val(dq_charging, (void *)&charging);
+
+	/* get its current cap */
+	get_bat_life(bat, &curcap[0]);
+
+	if (connected)
+		if (charging)
+			snprintf(buf, 256, "charging (%s)", curcap);
+		else
+			strcpy(buf, "on-line");
+	else
+		snprintf(buf, 256, "off-line (%s)", curcap);
+
+	return 0;
+}
+
+void
+get_bat_time(char *bat, char *buf, unsigned int n)
+{
+	int64_t charge, discharge;
+	int	hours, minutes;
+	Devquery dq_discharge = { P_INT64, bat, "discharge rate",
+							  "cur-value"};
+	Devquery dq_charge = { P_INT64, bat, "charge", "cur-value"};
+
+	if ((envsys_get_val(dq_discharge, (void *)&discharge) < 0) || !discharge) {
+		strcpy(buf, "N/A");
+		return;
+	}
+	if (envsys_get_val(dq_charge, (void *)&charge) < 0) {
+		strcpy(buf, "N/A");
+		return;
+	}
+
+	hours = (int)((float) charge / discharge);
+	minutes = (int)((((float) charge / discharge) - hours) * 60);
+
+	snprintf(buf, n, "%d:%02d", hours, minutes);
+}
+
+void
+get_battery_stuff(char *buf, unsigned int n, const char *bat, int item)
+{
+	int bat_num;
+	char b_name[32];
+
+	sscanf(bat, "BAT%d", &bat_num);
+	sprintf(b_name, "acpibat%d", bat_num);
+
+	switch (item) {
+	case BATTERY_TIME:
+		get_bat_time(b_name, buf, n);
+		break;
+	case BATTERY_STATUS:
+		get_bat_state(b_name, buf);
+		break;
+	default:
+		fprintf(stderr, "Unknown requested battery stat %d\n", item);
+	}
+}
+
+void
+get_battery_short_status(char *buffer, unsigned int n, const char *bat)
+{
+	get_battery_stuff(buffer, n, bat, BATTERY_STATUS);
+	if (0 == strncmp("charging", buffer, 8)) {
+		buffer[0] = 'C';
+		memmove(buffer + 1, buffer + 8, n - 8);
+	} else if (0 == strncmp("off-line", buffer, 11)) {
+		buffer[0] = 'D';
+		memmove(buffer + 1, buffer + 11, n - 11);
+	} else if (0 == strncmp("on-line", buffer, 12)) {
+		buffer[0] = 'A';
+		memmove(buffer + 1, buffer + 12, n - 12);
+	}
+}
+
+void
+get_acpi_ac_adapter(char *p_client_buffer,
+	size_t client_buffer_size, const char *adapter)
+{
+	int connected;
+
+	(void)adapter; // only linux uses this
+
 	if (!p_client_buffer || client_buffer_size <= 0) {
 		return;
 	}
 
+	connected = get_bat_state(NULL, NULL);
+
+	if (connected) {
+		strncpy(p_client_buffer, "Running on AC Power", client_buffer_size);
+	} else {
+		strncpy(p_client_buffer, "Running on battery", client_buffer_size);
+	}
+}
+
+int
+get_battery_perct(const char *bat)
+{
+	int64_t designcap, lastfulcap;
+	int bat_num, batperct;
+	char b_name[32];
+	char *lastfulcap_prop = "last full cap";
+	char *designcap_prop = "design cap";
+	Devquery dq_cap = { P_INT64, NULL, NULL, NULL};
+
+	sscanf(bat, "BAT%d", &bat_num);
+	sprintf(b_name, "acpibat%d", bat_num);
+
+	dq_cap.dev = &b_name[0];
+	dq_cap.key = designcap_prop;
+
+	if (envsys_get_val(dq_cap, (void *)&designcap) < 0)
+		designcap = 0;
+
+	dq_cap.key = lastfulcap_prop;
+
+	if (envsys_get_val(dq_cap, (void *)&lastfulcap) < 0)
+		lastfulcap = 0;
+
+	batperct = (designcap > 0 && lastfulcap > 0) ?
+		(int) (((float) lastfulcap / designcap) * 100) : 0;
+
+	return batperct > 100 ? 100 : batperct;
+}
+
+int
+get_battery_perct_bar(const char *bat)
+{
+	int batperct = get_battery_perct(bat);
+	return (int)(batperct * 2.56 - 1);
+}
+
+void get_acpi_fan(char *p_client_buffer, size_t client_buffer_size)
+{
 	/* not implemented */
-	memset(p_client_buffer, 0, client_buffer_size);
+	if (p_client_buffer && client_buffer_size > 0) {
+		memset(p_client_buffer, 0, client_buffer_size);
+	}
 }
 
-int get_entropy_avail(unsigned int *val)
+/*
+ * Here comes the mighty envsys backend
+ */
+void
+sysmon_open()
 {
-	return 1;
+    sysmon_fd = open(_DEV_SYSMON, O_RDONLY);
 }
 
-int get_entropy_poolsize(unsigned int *val)
+void
+sysmon_close()
 {
-	return 1;
+	if (sysmon_fd > -1)
+		close(sysmon_fd);
+}
+
+int8_t
+envsys_get_val(Devquery dq, void *val)
+{
+	char *descr;
+	const char *cval;
+	prop_dictionary_t dict;
+	prop_object_t device;
+	prop_object_iterator_t iter;
+	prop_object_t obj;
+	bool rc = false;
+
+	if (sysmon_fd < 0)
+		return -1;
+
+    if (prop_dictionary_recv_ioctl(sysmon_fd, ENVSYS_GETDICTIONARY, &dict)
+		!= 0)
+		return -1;
+
+	if ((device = prop_dictionary_get(dict, dq.dev)) == NULL)
+		return -1;
+      
+    iter = prop_array_iterator(device);
+
+    while((obj = prop_object_iterator_next(iter)))  {
+        descr = (char *)prop_string_cstring_nocopy(prop_dictionary_get(obj,
+				"description"));
+		if (descr != NULL && *descr) {
+			if(strcmp(descr, dq.key) == 0) {
+				switch(dq.type) {
+				case P_BOOL:
+					rc = prop_dictionary_get_bool(obj,
+						dq.row, (bool *)val);
+				case P_UINT8:
+					rc = prop_dictionary_get_uint8(obj,
+						dq.row, (uint8_t *)val);
+					break;
+				case P_INT64:
+					rc = prop_dictionary_get_int64(obj, dq.row,
+						(int64_t *)val);
+					break;
+				case P_STRING:
+					rc = prop_dictionary_get_cstring_nocopy(obj,
+						dq.row, &cval);
+					val = (void *)cval;
+					break;
+				}
+			}
+		}
+    }
+
+	prop_object_iterator_release(iter);
+	prop_object_release(dict);
+
+	if (rc == false) {
+		val = NULL;
+		return -1;
+	}
+
+	return 0;
 }
