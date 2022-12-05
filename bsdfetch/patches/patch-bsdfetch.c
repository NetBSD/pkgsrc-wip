$NetBSD$

Stability and portability fixes.

--- bsdfetch.c.orig	2022-11-30 09:00:21.000000000 +0000
+++ bsdfetch.c
@@ -18,11 +18,13 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>
+#include <pwd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/utsname.h>
 #include <dlfcn.h>
-#if defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__MidnightBSD__)
 #include <time.h>
 #include <sys/vmmeter.h>
 #include <vm/vm_param.h>
@@ -32,6 +34,13 @@
 #ifdef __OpenBSD__
 #include "sysctlbyname.h"
 #include <sys/sensors.h>
+#include <machine/cpu.h>
+#else
+#include <machine/param.h>
+#endif
+
+#ifndef MAXCPUS
+#define MAXCPUS MAXCPU
 #endif
 
 #define _PRG_NAME "bsdfetch"
@@ -45,20 +54,13 @@
 
 #define _SILENT (void)
 
-#define LIBPKGSO "/lib/libpkg.so"
-
-struct pkgdb;
-struct pkgdb_it;
-typedef int (*pkg_init_fp)(const char *, const char*);
-typedef void (*pkg_shutdown_fp)(void);
-typedef int (*pkgdb_open_fp)(struct pkgdb **db, int type);
-typedef void (*pkgdb_close_fp)(struct pkgdb *db);
-typedef struct pkgdb_it *(*pkgdb_query_fp)(struct pkgdb *db,
-	const char *pattern, int type);
-typedef int (*pkgdb_it_count_fp)(struct pkgdb_it *);
-
 typedef unsigned int uint;
 
+char tmp[256] = {0};
+char buf[256] = {0};
+size_t tmp_size = 0;
+size_t buf_size = 0;
+
 int color_flag = 1;
 
 static void die(int err_num, int line);
@@ -95,57 +97,72 @@ static void show(const char *entry, cons
 }
 
 static void get_shell() {
-	show("Shell", getenv("SHELL"));
+	char *sh;
+	char *lsh;
+	uid_t uid = geteuid();
+	struct passwd *pw = getpwuid(uid);
+	const char ch = '/';
+
+	if (getenv("SHELL")) {
+		sh = getenv("SHELL");
+	} else {
+		if (!pw)
+			die(errno, __LINE__);
+		sh = pw->pw_shell;
+	}
+
+	if ((lsh = strrchr(sh, ch)))
+		sh = lsh + 1;
+
+	show("Shell", sh);
 }
 
 static void get_user() {
-	show("User", getenv("USER"));
+	char *user;
+	uid_t uid = geteuid();
+	struct passwd *pw = getpwuid(uid);
+
+	if (getenv("USER")) {
+		user = getenv("USER");
+	} else {
+		if (!pw)
+			die(errno, __LINE__);
+		user = pw->pw_name;
+		}
+
+	show("User", user);
 }
 
 static void get_cpu() {
-	size_t num_cpu_size = 0;
-	uint num_cpu = 0;
+	size_t cpu_type_size = 0;
+	uint ncpu = 0;
+	uint ncpu_max = 0;
 	char cpu_type[200] = {0};
-	char tmp[100] = {0};
-
-	num_cpu_size = sizeof(num_cpu);
-
-	if(sysctlbyname("hw.ncpu", &num_cpu, &num_cpu_size, NULL, 0) == -1)
-		die(errno, __LINE__);
 
-#if defined(__NetBSD__)
-	FILE *fc = NULL;
-
-	fc = popen("awk 'BEGIN{FS=\":\"} /model name/ { print $2; exit }' "
-                   "/proc/cpuinfo | sed -e 's/ @//' -e 's/^ *//g' -e 's/ *$//g' "
-                   "| head -1 | tr -d '\\n'",
-                   "r");
-	if (fc == NULL)
+	ncpu = sysconf(_SC_NPROCESSORS_ONLN);
+	ncpu_max = sysconf(_SC_NPROCESSORS_CONF);
+	if (ncpu_max <= 0 || ncpu <=0)
 		die(errno, __LINE__);
 
-	fgets(cpu_type, sizeof(cpu_type), fc);
-	pclose(fc);
-#else
-	size_t cpu_type_size = 0;
 	cpu_type_size = sizeof(char) * 200;
-	if(sysctlbyname("hw.model", &cpu_type, &cpu_type_size, NULL, 0) == -1)
-		die(errno, __LINE__);
-#endif
+	if(sysctlbyname("machdep.cpu_brand", &cpu_type, &cpu_type_size, NULL, 0) == -1)
+		if(sysctlbyname("hw.model", &cpu_type, &cpu_type_size, NULL, 0) == -1)
+			die(errno, __LINE__);
+
 	show("CPU", cpu_type);
 
-	_SILENT sprintf(tmp, "%d", num_cpu);
+	_SILENT snprintf(tmp, MAXCPUS, "%d of %d processors online", ncpu, ncpu_max);
 
 	show("Cores", tmp);
 
 #if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__)
 	for(uint i = 0; i < num_cpu; i++) {
 		size_t temperature_size = 0;
-		char buf[100] = {0};
 		int temperature = 0;
 
-		sprintf(buf, "dev.cpu.%d.temperature", i);
-
 		temperature_size = sizeof(buf);
+		snprintf(buf, temperature_size, "dev.cpu.%d.temperature", i);
+
 		if(sysctlbyname(buf, &temperature, &temperature_size, NULL, 0) == -1)
 			return;
 
@@ -158,6 +175,7 @@ static void get_cpu() {
 	int mib[5];
 	char temp[10] = {0};
 	size_t size = 0;
+	size_t temp_size = 0;
 	struct sensor sensors;
 
 	mib[0] = CTL_HW;
@@ -167,186 +185,104 @@ static void get_cpu() {
 	mib[4] = 0;
 
 	size = sizeof(sensors);
+	temp_size = sizeof(temp);
 
 	if(sysctl(mib, 5, &sensors, &size, NULL, 0) < 0)
 		return;
 
-	_SILENT sprintf(temp, "%d °C", (int)((float)(sensors.value - 273150000) / 1E6));
+	_SILENT snprintf(temp, temp_size, "%d °C", (int)((float)(sensors.value - 273150000) / 1E6));
 
 	show("CPU Temp", temp);
 #endif
 }
 
 static void get_loadavg() {
-	char tmp[20] = {0};
-	double *lavg = NULL;
+	double lavg[3] = { 0.0 };
 
-	lavg = malloc(sizeof(double) * 3);
+	(void)getloadavg(lavg, 3);
 
-	(void)getloadavg(lavg, -1);
-
-	_SILENT sprintf(tmp, "%.2lf %.2lf %.2lf", lavg[0], lavg[1], lavg[2]);
+	_SILENT snprintf(tmp, tmp_size, "%.2lf %.2lf %.2lf", lavg[0], lavg[1], lavg[2]);
 
 	show("Loadavg", tmp);
 }
 
 static void get_packages() {
-#if defined(__MidnightBSD__)
 	FILE *f = NULL;
-	char buf[10] = {0};
+	size_t npkg = 0;
 
-	/*
-	  It might be better to use the mport stats functionality long term, but this
-	  avoids parsing.
-	*/
-	f = popen("/usr/sbin/mport list | wc -l | tr -d \"\n \"", "r");
-	if(f == NULL)
-		die(errno, __LINE__);
-
-	fgets(buf, sizeof(buf), f);
-	pclose(f);
-
-	show("Packages", buf);
-#elif defined(__FreeBSD__)
-	int numpkg = 0;
-	void *libhdl = 0;
-	struct pkgdb *pdb = 0;
-	char buf[256];
-	size_t basesz = sizeof buf;
-
-	if (sysctlbyname("user.localbase", buf, &basesz, NULL, 0) < 0)
-	    goto done;
-	if (sizeof buf - basesz < sizeof LIBPKGSO - 1)
-	    goto done;
-	memcpy(buf + basesz - 1, LIBPKGSO, sizeof LIBPKGSO);
-
-	if (!(libhdl = dlopen(buf, RTLD_LAZY))) goto done;
-	pkg_init_fp p_init = (pkg_init_fp)dlsym(libhdl, "pkg_init");
-	if (!p_init) goto done;
-	pkg_shutdown_fp p_shutdown = (pkg_shutdown_fp)dlsym(
-		libhdl, "pkg_shutdown");
-	if (!p_shutdown) goto done;
-	pkgdb_open_fp pdb_open = (pkgdb_open_fp)dlsym(libhdl, "pkgdb_open");
-	if (!pdb_open) goto done;
-	pkgdb_close_fp pdb_close = (pkgdb_close_fp)dlsym(libhdl, "pkgdb_close");
-	if (!pdb_close) goto done;
-	pkgdb_query_fp pdb_query = (pkgdb_query_fp)dlsym(libhdl, "pkgdb_query");
-	if (!pdb_query) goto done;
-	pkgdb_it_count_fp pdb_it_count = (pkgdb_it_count_fp)dlsym(
-		libhdl, "pkgdb_it_count");
-	if (!pdb_it_count) goto done;
-
-	if (p_init("/", 0) != 0) goto done;
-	if (pdb_open(&pdb, 0) != 0) goto done;
-	struct pkgdb_it *it = pdb_query(pdb, 0, 0);
-	numpkg = pdb_it_count(it);
-
-done:
-	if (pdb) pdb_close(pdb);
-	if (libhdl)
-	{
-	    if (p_shutdown) p_shutdown();
-	    dlclose(libhdl);
-	}
-	sprintf(buf, "%d", numpkg);
-	show("Packages", buf);
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
-	FILE *f = NULL;
-	char buf[10] = {0};
-
-	/*
-		This is a little hacky for the moment. I don't
-		see another good solution to get the package
-		count on OpenBSD.
-		Still, this works fine.
-	*/
-	f = popen("/usr/sbin/pkg_info | wc -l | tr -d \"\n \"", "r");
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+	f = popen("/usr/sbin/pkg_info", "r");
+#elif defined(__FreeBSD__) || ( __DragonFly__)
+	f = popen("/usr/sbin/pkg info", "r");
+#elif defined( __MidnightBSD__)
+	f = popen("/usr/sbin/mport list", "r");
+#else
+	fprintf(stderr, "Could not determine BSD variant\n");
+	die(errno, __LINE__);
+#endif
 	if(f == NULL)
 		die(errno, __LINE__);
 
-	fgets(buf, sizeof(buf), f);
-	pclose(f);
-
-	show("Packages", buf);
-#elif defined( __DragonFly__)
-	char buf[10] ={0};
-	FILE *fp = NULL;
-
-	/**
-	 * Despite being a fork of FreeBSD 4.8, DragonFly doesn't share
-	 * same API level access. Here `pkg list` just list all the packages
-	 * from the local database.
-	*/
-	fp = popen("pkg list | wc -l | tr -d \"\n \"", "r");
-	if (fp == NULL)
+	while (fgets(buf, sizeof buf, f) != NULL)
+		if (strchr(buf, '\n') != NULL)
+			npkg++;
+	if (pclose(f) != 0)
 		die(errno, __LINE__);
 
-	fgets(buf, sizeof(buf), fp);
-	pclose(fp);
-
+	snprintf(buf, buf_size, "%zu", npkg);
 	show("Packages", buf);
-#endif
 }
 
 static void get_uptime() {
-	char buf[100] = {0};
 	int up = 0;
 	int ret = 0;
 	int days = 0;
 	int hours = 0;
 	int minutes = 0;
 	struct timespec t;
+	size_t tsz = sizeof t;
 
-#ifndef CLOCK_UPTIME
-#define CLOCK_UPTIME CLOCK_MONOTONIC
-#endif
-	ret = clock_gettime(CLOCK_UPTIME, &t);
-	if(ret == -1)
+	if ((ret = sysctlbyname("kern.boottime", &t, &tsz, NULL, 0)) == -1)
 		die(errno, __LINE__);
 
-	up = t.tv_sec;
+	up = time(NULL) - t.tv_sec + 30;
 	days = up / 86400;
 	up %= 86400;
 	hours = up / 3600;
 	up %= 3600;
 	minutes = up / 60;
 
-	_SILENT sprintf(buf, "%dd %dh %dm", days, hours, minutes);
+	_SILENT snprintf(buf, buf_size, "%dd %dh %dm", days, hours, minutes);
 
 	show("Uptime", buf);
 }
 
 static void get_memory() {
-	unsigned long long buf = 0;
+	unsigned long long buff = 0;
 	unsigned long long mem = 0;
-	char tmp[50] = {0};
-	size_t buf_size = 0;
+	const long pgsize = sysconf(_SC_PAGESIZE);
+	const long pages = sysconf(_SC_PHYS_PAGES);
 
-	buf_size = sizeof(buf);
-
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
-	if(sysctlbyname("hw.realmem", &buf, &buf_size, NULL, 0) == -1)
-		die(errno, __LINE__);
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
-	if(sysctlbyname("hw.physmem", &buf, &buf_size, NULL, 0) == -1)
+	if (pgsize == -1 || pages == -1)
 		die(errno, __LINE__);
-#elif defined(__NetBSD__)
-	if(sysctlbyname("hw.physmem64", &buf, &buf_size, NULL, 0) == -1)
-		die(errno, __LINE__);
-#endif
+	else
+		buff = (uint64_t)pgsize * (uint64_t)pages;
 
-	mem = buf / 1048576;
+	if (buff <= 0)
+		die(errno, __LINE__);
+	else
+		mem = buff / 1048576;
 
-	_SILENT sprintf(tmp, "%llu MB", mem);
+	_SILENT snprintf(tmp, tmp_size, "%llu MB", mem);
 
 	show("RAM", tmp);
 }
 
 static void get_hostname() {
 	long host_size_max = 0;
-	char hostname[15] = {0};
+	char hostname[_POSIX_HOST_NAME_MAX + 1];
 
-	host_size_max = sysconf(_SC_HOST_NAME_MAX);
+	host_size_max = sysconf(_SC_HOST_NAME_MAX) + 1;
 	if(gethostname(hostname, host_size_max) == -1)
 		die(errno, __LINE__);
 
@@ -354,20 +290,12 @@ static void get_hostname() {
 }
 
 static void get_arch() {
-	char buf[20] = {0};
-	size_t buf_size = 0;
-
-	buf_size = sizeof(buf);
+	struct utsname un;
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__)
-	if(sysctlbyname("hw.machine_arch", &buf, &buf_size, NULL, 0) == -1)
-		die(errno, __LINE__);
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
-	if(sysctlbyname("hw.machine", &buf, &buf_size, NULL, 0) == -1)
+	if(uname(&un))
 		die(errno, __LINE__);
-#endif
 
-	show("Arch", buf);
+	show("Arch", un.machine);
 }
 
 static void get_sysinfo() {
@@ -400,6 +328,10 @@ static void usage() {
 }
 
 int main(int argc, char **argv) {
+	
+	tmp_size = sizeof(tmp);    
+	buf_size = sizeof(buf);
+
 	int is_a_tty = 0;
 
 	is_a_tty = isatty(1);
