$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/termios.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/termios.d
@@ -459,6 +459,115 @@ else version ( FreeBSD )
     int     tcsetattr(int, int, in termios*);
 
 }
+else version ( NetBSD )
+{
+    alias ubyte cc_t;
+    alias uint  speed_t;
+    alias uint  tcflag_t;
+
+    enum NCCS   = 20;
+
+    struct termios
+    {
+        tcflag_t   c_iflag;
+        tcflag_t   c_oflag;
+        tcflag_t   c_cflag;
+        tcflag_t   c_lflag;
+        cc_t[NCCS] c_cc;
+        speed_t    c_ispeed;
+        speed_t    c_ospeed;
+    }
+
+    enum VEOF       = 0;
+    enum VEOL       = 1;
+    enum VERASE     = 3;
+    enum VINTR      = 8;
+    enum VKILL      = 5;
+    enum VMIN       = 16;
+    enum VQUIT      = 9;
+    enum VSTART     = 12;
+    enum VSTOP      = 13;
+    enum VSUSP      = 10;
+    enum VTIME      = 17;
+
+    enum BRKINT     = 0x0000002;
+    enum ICRNL      = 0x0000100;
+    enum IGNBRK     = 0x0000001;
+    enum IGNCR      = 0x0000080;
+    enum IGNPAR     = 0x0000004;
+    enum INLCR      = 0x0000040;
+    enum INPCK      = 0x0000010;
+    enum ISTRIP     = 0x0000020;
+    enum IXOFF      = 0x0000400;
+    enum IXON       = 0x0000200;
+    enum PARMRK     = 0x0000008;
+
+    enum OPOST      = 0x0000001;
+
+    enum B0         = 0;
+    enum B50        = 50;
+    enum B75        = 75;
+    enum B110       = 110;
+    enum B134       = 134;
+    enum B150       = 150;
+    enum B200       = 200;
+    enum B300       = 300;
+    enum B600       = 600;
+    enum B1200      = 1200;
+    enum B1800      = 1800;
+    enum B2400      = 2400;
+    enum B4800      = 4800;
+    enum B9600      = 9600;
+    enum B19200     = 19200;
+    enum B38400     = 38400;
+
+    enum CSIZE      = 0x0000300;
+    enum   CS5      = 0x0000000;
+    enum   CS6      = 0x0000100;
+    enum   CS7      = 0x0000200;
+    enum   CS8      = 0x0000300;
+    enum CSTOPB     = 0x0000400;
+    enum CREAD      = 0x0000800;
+    enum PARENB     = 0x0001000;
+    enum PARODD     = 0x0002000;
+    enum HUPCL      = 0x0004000;
+    enum CLOCAL     = 0x0008000;
+
+    enum ECHO       = 0x00000008;
+    enum ECHOE      = 0x00000002;
+    enum ECHOK      = 0x00000004;
+    enum ECHONL     = 0x00000010;
+    enum ICANON     = 0x00000100;
+    enum IEXTEN     = 0x00000400;
+    enum ISIG       = 0x00000080;
+    enum NOFLSH     = 0x80000000;
+    enum TOSTOP     = 0x00400000;
+
+    enum TCSANOW    = 0;
+    enum TCSADRAIN  = 1;
+    enum TCSAFLUSH  = 2;
+
+    enum TCIFLUSH   = 1;
+    enum TCOFLUSH   = 2;
+    enum TCIOFLUSH  = 3;
+
+    enum TCIOFF     = 3;
+    enum TCION      = 4;
+    enum TCOOFF     = 1;
+    enum TCOON      = 2;
+
+    speed_t cfgetispeed(in termios*);
+    speed_t cfgetospeed(in termios*);
+    int     cfsetispeed(termios*, speed_t);
+    int     cfsetospeed(termios*, speed_t);
+    int     tcdrain(int);
+    int     tcflow(int, int);
+    int     tcflush(int, int);
+    int     tcgetattr(int, termios*);
+    int     tcsendbreak(int, int);
+    int     tcsetattr(int, int, in termios*);
+
+}
 
 //
 // XOpen (XSI)
@@ -601,4 +710,38 @@ else version( FreeBSD )
 
     pid_t   tcgetsid(int);
 }
+else version( NetBSD )
+{
+    enum IXANY      = 0x00000800;
+
+    enum ONLCR      = 0x00000002;
+    enum OCRNL      = 0x00000010;
+    enum ONOCR      = 0x00000020;
+    enum ONLRET     = 0x00000040;
+    //enum OFILL
+    //enum NLDLY
+    //enum     NL0
+    //enum     NL1
+    //enum CRDLY
+    //enum     CR0
+    //enum     CR1
+    //enum     CR2
+    //enum     CR3
+    enum TABDLY     = 0x00000004;
+    enum     TAB0   = 0x00000000;
+    //enum     TAB1
+    //enum     TAB2
+    enum     TAB3   = 0x00000004;
+    //enum BSDLY
+    //enum     BS0
+    //enum     BS1
+    //enum VTDLY
+    //enum     VT0
+    //enum     VT1
+    //enum FFDLY
+    //enum     FF0
+    //enum     FF1
+
+    pid_t   tcgetsid(int);
+}
 
