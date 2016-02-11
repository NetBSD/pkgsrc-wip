$NetBSD$

--- runtime/druntime/src/core/sys/posix/signal.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/signal.d
@@ -92,6 +92,8 @@ nothrow @nogc
     private alias void function(int, siginfo_t*, void*) sigactfn_t2;
 }
 
+version( NetBSD ) {}
+else
 enum
 {
   SIGEV_SIGNAL,
@@ -395,6 +397,62 @@ else version( FreeBSD )
     enum SIGUSR2    = 31;
     enum SIGURG     = 16;
 }
+else version( NetBSD )
+{
+    enum
+    {
+        SIGEV_NONE,
+        SIGEV_SIGNAL,
+        SIGEV_THREAD,
+        SIGEV_SA,
+    }
+/*
+    union sigval
+    {
+        int   sival_int;
+        void* sival_ptr;
+    }
+*/
+    enum        SIGHUP         = 1;      /* hangup */
+// SIGINT (defined in core.stdc.signal)
+//     enum     SIGINT         = 2;      /* interrupt */
+    enum        SIGQUIT        = 3;      /* quit */
+// SIGILL (defined in core.stdc.signal)
+//     enum     SIGILL         = 4;      /* illegal instruction (not reset when caught) */
+// SIGABRT (defined in core.stdc.signal)
+//     enum     SIGABRT        = 6;      /* abort() */
+//     enum     SIGIOT          SIGABRT /* compatibility */
+//     enum     SIGEMT         = 7;      /* EMT instruction */
+// SIGFPE (defined in core.stdc.signal)
+//     enum     SIGFPE         = 8;      /* floating point exception */
+    enum        SIGKILL        = 9;      /* kill (cannot be caught or ignored) */
+    enum        SIGBUS         = 10;     /* bus error */
+// SIGSEGV (defined in core.stdc.signal)
+//     enum     SIGSEGV        = 11;     /* segmentation violation */
+    enum        SIGPIPE        = 13;     /* write on a pipe with no one to read it */
+    enum        SIGALRM        = 14;     /* alarm clock */
+// SIGTERM (defined in core.stdc.signal)
+//     enum     SIGTERM        = 15;     /* software termination signal from kill */
+    enum        SIGURG         = 16;     /* urgent condition on IO channel */
+    enum        SIGSTOP        = 17;     /* sendable stop signal not from tty */
+    enum        SIGTSTP        = 18;     /* stop signal from tty */
+    enum        SIGCONT        = 19;     /* continue a stopped process */
+    enum        SIGCHLD        = 20;     /* to parent on child stop or exit */
+    enum        SIGTTIN        = 21;     /* to readers pgrp upon background tty read */
+    enum        SIGTTOU        = 22;     /* like TTIN for output if (tp->t_local&LTOSTOP) */
+//     enum     SIGIO          = 23;     /* input/output possible signal */
+//     enum     SIGWINCH       = 28;     /* window size changes */
+//     enum     SIGINFO        = 29;     /* information request */
+    enum        SIGUSR1        = 30;     /* user defined signal 1 */
+    enum        SIGUSR2        = 31;     /* user defined signal 2 */
+//     enum     SIGPWR         = 32;     /* power fail/restart (not reset when caught) */
+
+//    enum        SIGRTMIN       = 33;     /* Kernel only; not exposed to userland yet */
+//    enum        SIGRTMAX       = 63;     /* Kernel only; not exposed to userland */
+  
+// sigfn_t signal(int sig, sigfn_t func); (defined in core.stdc.signal)
+// int raise(int sig);                    (defined in core.stdc.signal)
+}
 else version (Solaris)
 {
     enum SIGALRM = 14;
@@ -453,6 +511,19 @@ else version( FreeBSD )
         sigset_t sa_mask;
     }
 }
+else version( NetBSD )
+{
+    struct sigaction_t
+    {
+        union
+        {
+            void function(int) sa_handler;
+            void function(int, siginfo_t*, void*) sa_siggaction;
+        }
+        sigset_t sa_mask;
+        int sa_flags;
+    }
+}
 else version (Solaris)
 {
     struct sigaction_t
@@ -855,6 +926,88 @@ else version( FreeBSD )
     int sigsuspend(in sigset_t *);
     int sigwait(in sigset_t*, int*);
 }
+else version( NetBSD )
+{
+    enum SIG_HOLD = cast(sigfn_t2) 3;
+
+    alias int sigset_t;
+
+    enum SA_NOCLDSTOP = 0x0008;	/* do not generate SIGCHLD on child stop */
+    enum
+    {
+	SIG_BLOCK = 1, /* block specified signal set */
+	SIG_UNBLOCK,   /* unblock specified signal set */
+	SIG_SETMASK,   /* set specified signal set */
+    }
+    
+    union siginfo_t {
+        char[128] si_pad;	/* Total size; for future expansion */
+        _ksiginfo _info;
+    }
+
+    struct _ksiginfo
+    {
+      int	_signo;
+      int	_code;
+      int	_errno;
+      /* In _LP64 the union starts on an 8-byte boundary. */
+      version( D_LP64 )
+      int	_pad;
+      union Reason {
+	struct Rt {
+	  pid_t	 _pid;
+	  uid_t	 _uid;
+	  sigval _value;
+	}
+	Rt _rt;
+     
+	struct Child {
+	  pid_t	_pid;
+	  uid_t	_uid;
+	  int	_status;
+	  clock_t	_utime;
+	  clock_t	_stime;
+	}
+	Child _child;
+     
+	struct Fault {
+	  void   *_addr;
+	  int	_trap;
+	  int	_trap2;
+	  int	_trap3;
+	}
+	Fault _fault;
+     
+	struct Poll {
+	  long	_band;
+	  int	_fd;
+     	}
+	Poll _poll;
+      }
+      Reason _reason;
+    }
+
+    enum
+    {
+      SI_USER,
+      SI_QUEUE,
+      SI_TIMER,
+      SI_ASYNCIO = -3,
+      SI_MESGQ = 4,
+    }
+
+    int kill(pid_t, int);
+    int sigaction(int, in sigaction_t*, sigaction_t*);
+    int sigaddset(sigset_t*, int);
+    int sigdelset(sigset_t*, int);
+    int sigemptyset(sigset_t*);
+    int sigfillset(sigset_t*);
+    int sigismember(in sigset_t*, int);
+    int sigpending(sigset_t*);
+    int sigprocmask(int, in sigset_t*, sigset_t*);
+    int sigsuspend(in sigset_t*);
+    int sigwait(in sigset_t*, int*);
+}
 else version (Solaris)
 {
     enum SIG_HOLD = cast(sigfn_t2)2;
@@ -1626,6 +1779,113 @@ else version( FreeBSD )
     int sigpause(int);
     int sigrelse(int);
 }
+else version( NetBSD )
+{
+    enum     SIGPROF        = 27;     /* profiling time alarm */
+    enum     SIGSYS         = 12;     /* bad argument to system call */
+    enum     SIGTRAP        = 5;      /* trace trap (not reset when caught) */
+    enum     SIGVTALRM      = 26;     /* virtual time alarm */
+    enum     SIGXCPU        = 24;     /* exceeded CPU time limit */
+    enum     SIGXFSZ        = 25;     /* exceeded file size limit */
+
+    enum SA_ONSTACK     = 0x0001;	/* take signal on signal stack */
+    enum SA_RESTART     = 0x0002;	/* restart system call on signal return */
+    enum SA_RESETHAND   = 0x0004;	/* reset to SIG_DFL when taking signal */
+    enum SA_NODEFER     = 0x0010;	/* don't mask the signal we're delivering */
+
+/* Only valid for SIGCHLD. */
+    // enum SA_NOCLDSTOP   = 0x0008;	/* do not generate SIGCHLD on child stop */
+    enum SA_NOCLDWAIT   = 0x0020;	/* do not generate zombies on unwaited child */
+
+    enum SA_SIGINFO     = 0x0040;	/* take sa_sigaction handler */
+
+    enum SA_NOKERNINFO  = 0x0080;	/* siginfo does not print kernel info on tty */
+
+    enum SA_ALLBITS     = 0x00ff;
+
+    enum SS_ONSTACK	= 0x0001;	/* take signals on alternate stack */
+    enum SS_DISABLE	= 0x0004;	/* disable taking signals on alternate stack */
+
+    enum SS_ALLBITS	= 0x0005;
+
+    enum MINSIGSTKSZ	= 8192;			/* minimum allowable stack */
+    enum SIGSTKSZ	= (MINSIGSTKSZ + 32768);	/* recommended stack size */
+
+    struct stack_t
+    {
+        void*   ss_sp;
+        size_t  ss_size;
+        int     ss_flags;
+    }
+
+//
+// XOpen (XSI)
+//
+/*
+SIGPOLL
+
+mcontext_t // from ucontext
+
+struct sigstack
+{
+    int   ss_onstack;
+    void* ss_sp;
+}
+
+ILL_ILLOPC
+ILL_ILLOPN
+ILL_ILLADR
+ILL_ILLTRP
+ILL_PRVOPC
+ILL_PRVREG
+ILL_COPROC
+ILL_BADSTK
+
+FPE_INTDIV
+FPE_INTOVF
+FPE_FLTDIV
+FPE_FLTOVF
+FPE_FLTUND
+FPE_FLTRES
+FPE_FLTINV
+FPE_FLTSUB
+
+SEGV_MAPERR
+SEGV_ACCERR
+
+BUS_ADRALN
+BUS_ADRERR
+BUS_OBJERR
+
+TRAP_BRKPT
+TRAP_TRACE
+
+CLD_EXITED
+CLD_KILLED
+CLD_DUMPED
+CLD_TRAPPED
+CLD_STOPPED
+CLD_CONTINUED
+
+POLL_IN
+POLL_OUT
+POLL_MSG
+POLL_ERR
+POLL_PRI
+POLL_HUP
+
+sigfn_t bsd_signal(int sig, sigfn_t func);
+sigfn_t sigset(int sig, sigfn_t func);
+
+int killpg(pid_t, int);
+int sigaltstack(in stack_t*, stack_t*);
+int sighold(int);
+int sigignore(int);
+int siginterrupt(int, int);
+int sigpause(int);
+int sigrelse(int);
+*/
+}
 else version (Solaris)
 {
     enum SIGPOLL = 22;
@@ -1929,6 +2189,14 @@ else version( FreeBSD )
         c_long  tv_nsec;
     }
 }
+else version( NetBSD )
+{
+    struct timespec
+    {
+        time_t tv_sec;
+        c_long tv_nsec;
+    }
+}
 else version (Solaris)
 {
     struct timespec
@@ -2024,6 +2292,21 @@ else version( FreeBSD )
     int sigtimedwait(in sigset_t*, siginfo_t*, in timespec*);
     int sigwaitinfo(in sigset_t*, siginfo_t*);
 }
+ else version( NetBSD )
+{     
+// MISSING
+//int sigwaitinfo(in sigset_t*, siginfo_t*);
+    struct sigevent
+    {
+        int             sigev_notify;
+        int             sigev_signo;
+        sigval          sigev_value;
+        void function(sigval) sigev_notify_function;
+        pthread_attr_t* sigev_notify_attributes;
+    }
+int sigqueue(pid_t, int, in sigval);
+int sigtimedwait(in sigset_t*, siginfo_t*, in timespec*);
+}
 else version (OSX)
 {
 }
@@ -2097,6 +2380,11 @@ else version( FreeBSD )
     int pthread_kill(pthread_t, int);
     int pthread_sigmask(int, in sigset_t*, sigset_t*);
 }
+else version( NetBSD )
+{
+    int pthread_kill(pthread_t, int);
+    int pthread_sigmask(int, in sigset_t*, sigset_t*);
+}     
 else version (Solaris)
 {
     int pthread_kill(pthread_t, int);
