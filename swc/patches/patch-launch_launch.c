$NetBSD$

--- launch/launch.c.orig	2019-07-11 06:33:41.000000000 +0000
+++ launch/launch.c
@@ -38,21 +38,31 @@
 #include <stdnoreturn.h>
 #include <string.h>
 #include <unistd.h>
+#include <signal.h>
 
-#include <sys/socket.h>
-#include <sys/stat.h>
-#include <sys/wait.h>
-#include <sys/ioctl.h>
-#include <sys/sysmacros.h>
+#ifdef __NetBSD__
+#include <dev/wscons/wsconsio.h>
+#include <dev/wscons/wsdisplay_usl_io.h>
+extern char **environ;
+#define TTY_MAJOR	(47)
+#define WSKBD_MAJOR	(48)
+#define WSMOUSE_MAJOR	(49)
+#define	DRM_MAJOR	(180)
+#else
 #include <linux/input.h>
 #include <linux/kd.h>
 #include <linux/major.h>
 #include <linux/vt.h>
-#include <xf86drm.h>
-
 #ifndef DRM_MAJOR
 #define DRM_MAJOR 226
 #endif
+#endif
+
+#include <sys/socket.h>
+#include <sys/stat.h>
+#include <sys/wait.h>
+#include <sys/ioctl.h>
+#include <xf86drm.h>
 
 #define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array)[0])
 
@@ -116,8 +126,10 @@ stop_devices(bool fatal)
 			die("drmDropMaster:");
 	}
 	for (i = 0; i < num_input_fds; ++i) {
+#ifdef EVIOCREVOKE
 		if (ioctl(input_fds[i], EVIOCREVOKE, 0) < 0 && errno != ENODEV && fatal)
 			die("ioctl EVIOCREVOKE:");
+#endif
 		close(input_fds[i]);
 	}
 	num_input_fds = 0;
@@ -126,20 +138,16 @@ stop_devices(bool fatal)
 static void
 cleanup(void)
 {
-	struct vt_mode mode = {.mode = VT_AUTO};
-
-	if (!original_vt_state.altered)
-		return;
-
 	/* Cleanup VT */
-	ioctl(tty_fd, VT_SETMODE, &mode);
 	ioctl(tty_fd, KDSETMODE, original_vt_state.console_mode);
 	ioctl(tty_fd, KDSKBMODE, original_vt_state.kb_mode);
 
 	/* Stop devices before switching the VT to make sure we have released the DRM
 	 * device before the next session tries to claim it. */
 	stop_devices(false);
-	ioctl(tty_fd, VT_ACTIVATE, original_vt_state.vt);
+
+	int dispmode = WSDISPLAYIO_MODE_EMUL;
+	ioctl(tty_fd, WSDISPLAYIO_SMODE, &dispmode);
 
 	kill(0, SIGTERM);
 }
@@ -208,7 +216,12 @@ handle_socket_data(int socket)
 		}
 
 		switch (major(st.st_rdev)) {
+#ifdef INPUT_MAJOR
 		case INPUT_MAJOR:
+#else
+		case WSKBD_MAJOR:
+		case WSMOUSE_MAJOR:
+#endif
 			if (!active)
 				goto fail;
 			if (num_input_fds == ARRAY_LENGTH(input_fds)) {
@@ -235,7 +248,12 @@ handle_socket_data(int socket)
 		}
 
 		switch (major(st.st_rdev)) {
+#ifdef INPUT_MAJOR
 		case INPUT_MAJOR:
+#else
+		case WSKBD_MAJOR:
+		case WSMOUSE_MAJOR:
+#endif
 			input_fds[num_input_fds++] = fd;
 			break;
 		case DRM_MAJOR:
@@ -275,16 +293,16 @@ find_vt(char *vt, size_t size)
 	/* If we are running from an existing X or wayland session, always open a new
 	 * VT instead of using the current one. */
 	if (getenv("DISPLAY") || getenv("WAYLAND_DISPLAY") || !(vtnr = getenv("XDG_VTNR"))) {
-		tty0_fd = open("/dev/tty0", O_RDWR);
+		tty0_fd = open("/dev/ttyE0", O_RDWR);
 		if (tty0_fd == -1)
-			die("open /dev/tty0:");
+			die("open /dev/ttyE0:");
 		if (ioctl(tty0_fd, VT_OPENQRY, &vt_num) != 0)
 			die("VT open query failed:");
 		close(tty0_fd);
-		if (snprintf(vt, size, "/dev/tty%d", vt_num) >= size)
+		if (snprintf(vt, size, "/dev/ttyE%d", vt_num) >= size)
 			die("VT number is too large");
 	} else {
-		if (snprintf(vt, size, "/dev/tty%s", vtnr) >= size)
+		if (snprintf(vt, size, "/dev/ttyE%s", vtnr) >= size)
 			die("XDG_VTNR is too long");
 	}
 }
@@ -311,12 +329,6 @@ setup_tty(int fd)
 {
 	struct stat st;
 	int vt;
-	struct vt_stat state;
-	struct vt_mode mode = {
-		.mode = VT_PROCESS,
-		.relsig = SIGUSR1,
-		.acqsig = SIGUSR2
-	};
 
 	if (fstat(fd, &st) == -1)
 		die("failed to stat TTY fd:");
@@ -324,50 +336,10 @@ setup_tty(int fd)
 	if (major(st.st_rdev) != TTY_MAJOR || vt == 0)
 		die("not a valid VT");
 
-	if (ioctl(fd, VT_GETSTATE, &state) == -1)
-		die("failed to get the current VT state:");
-	original_vt_state.vt = state.v_active;
-	if (ioctl(fd, KDGKBMODE, &original_vt_state.kb_mode))
-		die("failed to get keyboard mode:");
-	if (ioctl(fd, KDGETMODE, &original_vt_state.console_mode))
-		die("failed to get console mode:");
-
-	if (ioctl(fd, KDSKBMODE, K_OFF) == -1)
-		die("failed to set keyboard mode to K_OFF:");
-	if (ioctl(fd, KDSETMODE, KD_GRAPHICS) == -1) {
-		perror("failed to set console mode to KD_GRAPHICS");
-		goto error0;
-	}
-	if (ioctl(fd, VT_SETMODE, &mode) == -1) {
-		perror("failed to set VT mode");
-		goto error1;
-	}
-
-	if (vt == original_vt_state.vt) {
-		activate();
-	} else if (!nflag) {
-		if (ioctl(fd, VT_ACTIVATE, vt) == -1) {
-			perror("failed to activate VT");
-			goto error2;
-		}
-
-		if (ioctl(fd, VT_WAITACTIVE, vt) == -1) {
-			perror("failed to wait for VT to become active");
-			goto error2;
-		}
-	}
-
-	original_vt_state.altered = true;
-
-	return;
+	int dispmode = WSDISPLAYIO_MODE_DUMBFB;
+	if (ioctl(fd, WSDISPLAYIO_SMODE, &dispmode) < 0)
+		die("Failed to set wsdisplay mode");
 
-error2:
-	mode = (struct vt_mode){.mode = VT_AUTO };
-	ioctl(fd, VT_SETMODE, &mode);
-error1:
-	ioctl(fd, KDSETMODE, original_vt_state.console_mode);
-error0:
-	ioctl(fd, KDSKBMODE, original_vt_state.kb_mode);
 	exit(EXIT_FAILURE);
 }
 
