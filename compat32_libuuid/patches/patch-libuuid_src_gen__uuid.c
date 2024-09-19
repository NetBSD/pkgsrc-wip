$NetBSD: patch-libuuid_src_gen__uuid.c,v 1.1 2017/12/08 08:03:35 adam Exp $

fcntl is portable, flock is not.
Solaris does not have ifr.ifr_hwaddr.

--- libuuid/src/gen_uuid.c.orig	2017-09-27 09:05:13.000000000 +0000
+++ libuuid/src/gen_uuid.c
@@ -172,7 +172,7 @@ static int get_node_id(unsigned char *no
 	for (i = 0; i < n; i+= ifreq_size(*ifrp) ) {
 		ifrp = (struct ifreq *)((char *) ifc.ifc_buf+i);
 		strncpy(ifr.ifr_name, ifrp->ifr_name, IFNAMSIZ);
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 		if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)
 			continue;
 		a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;
@@ -227,12 +227,17 @@ static int get_clock(uint32_t *clock_hig
 	THREAD_LOCAL int		state_fd = -2;
 	THREAD_LOCAL FILE		*state_f;
 	THREAD_LOCAL uint16_t		clock_seq;
+	struct flock			lock;
 	struct timeval			tv;
 	uint64_t			clock_reg;
 	mode_t				save_umask;
 	int				len;
 	int				ret = 0;
 
+	lock.l_whence = SEEK_SET;
+	lock.l_start = 0;
+	lock.l_len = 0;
+
 	if (state_fd == -1)
 		ret = -1;
 
@@ -253,7 +258,8 @@ static int get_clock(uint32_t *clock_hig
 	}
 	if (state_fd >= 0) {
 		rewind(state_f);
-		while (flock(state_fd, LOCK_EX) < 0) {
+		lock.l_type = F_WRLCK;
+		while (fcntl(state_fd, F_SETLKW, &lock) < 0) {
 			if ((errno == EAGAIN) || (errno == EINTR))
 				continue;
 			fclose(state_f);
@@ -325,7 +331,8 @@ try_again:
 			fflush(state_f);
 		}
 		rewind(state_f);
-		flock(state_fd, LOCK_UN);
+		lock.l_type = F_UNLCK;
+		fcntl(state_fd, F_SETLK, &lock);
 	}
 
 	*clock_high = clock_reg >> 32;
