$NetBSD$

--- src/nvim/os/pty_process_unix.c.orig	2021-11-30 17:20:42.000000000 +0000
+++ src/nvim/os/pty_process_unix.c
@@ -15,6 +15,12 @@
 # include <libutil.h>
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 # include <util.h>
+#elif defined(__sun)
+#  include <sys/stream.h>
+#  include <sys/syscall.h>
+#  include <fcntl.h>
+#  include <unistd.h>
+#  include <signal.h>
 #else
 # include <pty.h>
 #endif
@@ -38,6 +44,123 @@
 # include "os/pty_process_unix.c.generated.h"
 #endif
 
+#if defined(__sun) && !defined(HAVE_FORKPTY)
+
+/* this header defines STR, just as nvim.h, but it is defined as ('S'<<8),
+   to avoid #undef STR, #undef STR, #define STR ('S'<<8) just delay the
+   inclusion of the header even though it gets include out of order. */
+#include <sys/stropts.h>
+
+static int openpty(int *amaster, int *aslave, char *name,
+                   struct termios *termp, struct winsize *winp)
+{
+  int slave = -1;
+  int master = open("/dev/ptmx", O_RDWR);
+  if (master == -1) {
+    goto error;
+  }
+
+  /* grantpt will invoke a setuid program to change permissions
+     and might fail if SIGCHLD handler is set, temporarily reset
+     while running */
+  void(*sig_saved)(int) = signal(SIGCHLD, SIG_DFL);
+  int res = grantpt(master);
+  signal(SIGCHLD, sig_saved);
+
+  if (res == -1 || unlockpt(master) == -1) {
+    goto error;
+  }
+
+  char *slave_name = ptsname(master);
+  if (slave_name == NULL) {
+    goto error;
+  }
+
+  slave = open(slave_name, O_RDWR|O_NOCTTY);
+  if (slave == -1) {
+    goto error;
+  }
+
+  /* ptem emulates a terminal when used on a pseudo terminal driver,
+     must be pushed before ldterm */
+  ioctl(slave, I_PUSH, "ptem");
+  /* ldterm provides most of the termio terminal interface */
+  ioctl(slave, I_PUSH, "ldterm");
+  /* ttcompat compatability with older terminal ioctls */
+  ioctl(slave, I_PUSH, "ttcompat");
+
+  if (termp) {
+    tcsetattr(slave, TCSAFLUSH, termp);
+  }
+  if (winp) {
+    ioctl(slave, TIOCSWINSZ, winp);
+  }
+
+  *amaster = master;
+  *aslave = slave;
+  if (name) {
+    strcpy(name, slave_name);
+  }
+
+  return 0;
+
+error:
+  if (slave != -1) {
+    close(slave);
+  }
+  if (master != -1) {
+    close(master);
+  }
+  return -1;
+}
+
+static int login_tty(int fd)
+{
+  setsid();
+  if (ioctl(fd, TIOCSCTTY, NULL) == -1) {
+    return -1;
+  }
+
+  dup2(fd, STDIN_FILENO);
+  dup2(fd, STDOUT_FILENO);
+  dup2(fd, STDERR_FILENO);
+  if (fd > STDERR_FILENO) {
+    close(fd);
+  }
+
+  return 0;
+}
+
+static pid_t forkpty(int *amaster, char *name,
+                     struct termios *termp, struct winsize *winp)
+{
+  int master, slave;
+  if (openpty(&master, &slave, name, termp, winp) == -1) {
+    return -1;
+  }
+
+  pid_t pid = fork();
+  switch (pid) {
+  case -1:
+    close(master);
+    close(slave);
+    if (name) {
+      name[0] = '\0';
+    }
+    return -1;
+  case 0:
+    close(master);
+    login_tty(slave);
+    return 0;
+  default:
+    close(slave);
+    *amaster = master;
+    return pid;
+  }
+}
+
+#endif
+
 /// termios saved at startup (for TUI) or initialized by pty_process_spawn().
 static struct termios termios_default;
 
@@ -198,7 +321,9 @@ static void init_termios(struct termios
   termios->c_cflag = CS8|CREAD;
   termios->c_lflag = ISIG|ICANON|IEXTEN|ECHO|ECHOE|ECHOK;
 
-  cfsetspeed(termios, 38400);
+  // not using cfsetspeed, not available on all platforms
+  cfsetispeed(termios, 38400);
+  cfsetospeed(termios, 38400);
 
 #ifdef IUTF8
   termios->c_iflag |= IUTF8;
