$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/signal.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/signal.d
@@ -423,6 +423,31 @@ else version( DragonFlyBSD )
     enum SIGUSR2    = 31;
     enum SIGURG     = 16;
 }
+else version( NetBSD )
+{
+    //SIGABRT (defined in core.stdc.signal)
+    enum SIGALRM    = 14;
+    enum SIGBUS     = 10;
+    enum SIGCHLD    = 20;
+    enum SIGCONT    = 19;
+    //SIGFPE (defined in core.stdc.signal)
+    enum SIGHUP     = 1;
+    //SIGILL (defined in core.stdc.signal)
+    //SIGINT (defined in core.stdc.signal)
+    enum SIGKILL    = 9;
+    enum SIGPIPE    = 13;
+    enum SIGQUIT    = 3;
+    //SIGSEGV (defined in core.stdc.signal)
+    enum SIGSTOP    = 17;
+    //SIGTERM (defined in core.stdc.signal)
+    enum SIGTSTP    = 18;
+    enum SIGTTIN    = 21;
+    enum SIGTTOU    = 22;
+    enum SIGUSR1    = 30;
+    enum SIGUSR2    = 31;
+    enum SIGURG     = 16;
+}
+
 else version (Solaris)
 {
     enum SIGALRM = 14;
@@ -494,6 +519,19 @@ else version( DragonFlyBSD )
         sigset_t sa_mask;
     }
 }
+else version( NetBSD )
+{
+    struct sigaction_t
+    {
+        union
+        {
+            sigfn_t     sa_handler;
+            sigactfn_t  sa_sigaction;
+        }
+        sigset_t sa_mask;
+        int      sa_flags;
+    }
+}
 else version (Solaris)
 {
     struct sigaction_t
@@ -960,6 +998,100 @@ else version( DragonFlyBSD )
     int sigsuspend(in sigset_t *);
     int sigwait(in sigset_t*, int*);
 }
+else version( NetBSD )
+{
+    enum SIG_HOLD = cast(sigfn_t2) 3;
+
+    struct sigset_t
+    {
+        uint[4] __bits;
+    }
+
+    enum SA_NOCLDSTOP = 8;
+
+    enum SIG_BLOCK = 1;
+    enum SIG_UNBLOCK = 2;
+    enum SIG_SETMASK = 3;
+
+    union sigval_t {
+        int     sival_int;
+        void    *sival_ptr;
+    };
+    struct _rt{
+        pid_t   _pid;
+        uid_t   _uid;
+        sigval_t        _value;
+    };
+    struct _child{
+        pid_t   _pid;
+        uid_t   _uid;
+        int     _status;
+        clock_t _utime;
+        clock_t _stime;
+    };
+   struct _fault{
+        void   *_addr;
+        int     _trap;
+        int     _trap2;
+        int     _trap3;
+    };
+    struct _poll{
+        long    _band;
+        int     _fd;
+    };
+    union _reason{
+        _rt rt;
+        _child child;
+        _fault fault;
+        _poll poll;
+    };
+    struct _ksiginfo {
+        int     _signo;
+        int     _code;
+        int     _errno;
+/+#ifdef _LP64
+        /* In _LP64 the union starts on an 8-byte boundary. */
+        int     _pad;
+#endif+/
+        _reason reason;
+    };
+
+
+    union siginfo_t
+    {
+        ubyte[128] si_pad;/* Total size; for future expansion */
+        _ksiginfo _info;
+        @property ref c_long si_band() return { return _info.reason.poll._band; }
+    }
+
+    enum SI_USER    = 0;
+    enum SI_QUEUE   = -1;
+    enum SI_TIMER   = -2;
+    enum SI_ASYNCIO = -3;
+    enum SI_MESGQ   = -4;
+
+    int kill(pid_t, int);
+    int __sigaction14(int, in sigaction_t*, sigaction_t*);
+    int __sigaddset14(sigset_t*, int);
+    int __sigdelset14(sigset_t*, int);
+    int __sigemptyset14(sigset_t *);
+    int __sigfillset14(sigset_t *);
+    int __sigismember14(in sigset_t *, int);
+    int __sigpending14(sigset_t *);
+    int __sigprocmask14(int, in sigset_t*, sigset_t*);
+    int __sigsuspend14(in sigset_t *);
+    int sigwait(in sigset_t*, int*);
+
+    alias __sigaction14 sigaction;
+    alias __sigaddset14 sigaddset;
+    alias __sigdelset14 sigdelset;
+    alias __sigemptyset14 sigemptyset;
+    alias __sigfillset14 sigfillset;
+    alias __sigismember14 sigismember;
+    alias __sigpending14 sigpending;
+    alias __sigprocmask14 sigprocmask;
+    alias __sigsuspend14 sigsuspend;
+}
 else version (Solaris)
 {
     enum SIG_HOLD = cast(sigfn_t2)2;
@@ -1860,6 +1992,130 @@ else version( DragonFlyBSD )
     int sigpause(int);
     int sigrelse(int);
 }
+else version( NetBSD )
+{
+    // No SIGPOLL on *BSD
+    enum SIGPROF        = 27;
+    enum SIGSYS         = 12;
+    enum SIGTRAP        = 5;
+    enum SIGVTALRM      = 26;
+    enum SIGXCPU        = 24;
+    enum SIGXFSZ        = 25;
+
+    enum
+    {
+        SA_ONSTACK      = 0x0001,
+        SA_RESTART      = 0x0002,
+        SA_RESETHAND    = 0x0004,
+        SA_NODEFER      = 0x0010,
+        SA_NOCLDWAIT    = 0x0020,
+        SA_SIGINFO      = 0x0040,
+    }
+
+    enum
+    {
+        SS_ONSTACK = 0x0001,
+        SS_DISABLE = 0x0004,
+    }
+
+    enum MINSIGSTKSZ = 8192;
+    enum SIGSTKSZ    = (MINSIGSTKSZ + 32768);
+;
+    //ucontext_t (defined in core.sys.posix.ucontext)
+    //mcontext_t (defined in core.sys.posix.ucontext)
+
+    struct stack_t
+    {
+        void*   ss_sp;
+        size_t  ss_size;
+        int     ss_flags;
+    }
+
+    struct sigstack
+    {
+        void*   ss_sp;
+        int     ss_onstack;
+    }
+
+    enum
+    {
+        ILL_ILLOPC = 1,
+        ILL_ILLOPN,
+        ILL_ILLADR,
+        ILL_ILLTRP,
+        ILL_PRVOPC,
+        ILL_PRVREG,
+        ILL_COPROC,
+        ILL_BADSTK,
+    }
+
+    enum
+    {
+        BUS_ADRALN = 1,
+        BUS_ADRERR,
+        BUS_OBJERR,
+    }
+
+    enum
+    {
+        SEGV_MAPERR = 1,
+        SEGV_ACCERR,
+    }
+
+    enum
+    {
+        FPE_INTOVF = 1,
+        FPE_INTDIV,
+        FPE_FLTDIV,
+        FPE_FLTOVF,
+        FPE_FLTUND,
+        FPE_FLTRES,
+        FPE_FLTINV,
+        FPE_FLTSUB,
+    }
+
+    enum
+    {
+        TRAP_BRKPT = 1,
+        TRAP_TRACE,
+    }
+
+    enum
+    {
+        CLD_EXITED = 1,
+        CLD_KILLED,
+        CLD_DUMPED,
+        CLD_TRAPPED,
+        CLD_STOPPED,
+        CLD_CONTINUED,
+    }
+
+    enum
+    {
+        POLL_IN = 1,
+        POLL_OUT,
+        POLL_MSG,
+        POLL_ERR,
+        POLL_PRI,
+        POLL_HUP,
+    }
+
+    //sigfn_t bsd_signal(int sig, sigfn_t func);
+    sigfn_t sigset(int sig, sigfn_t func);
+
+  nothrow:
+  @nogc:
+    //sigfn_t2 bsd_signal(int sig, sigfn_t2 func);
+    sigfn_t2 sigset(int sig, sigfn_t2 func);
+
+    int killpg(pid_t, int);
+    int sigaltstack(in stack_t*, stack_t*);
+    int sighold(int);
+    int sigignore(int);
+    int siginterrupt(int, int);
+    int sigpause(int);
+    int sigrelse(int);
+}
 else version (Solaris)
 {
     enum SIGPOLL = 22;
@@ -2199,6 +2455,14 @@ else version( DragonFlyBSD )
         c_long  tv_nsec;
     }
 }
+else version( NetBSD )
+{
+    struct timespec
+    {
+        time_t  tv_sec;
+        c_long  tv_nsec;
+    }
+}
 else version (Solaris)
 {
     struct timespec
@@ -2321,6 +2585,21 @@ else version( DragonFlyBSD )
     int sigtimedwait(in sigset_t*, siginfo_t*, in timespec*);
     int sigwaitinfo(in sigset_t*, siginfo_t*);
 }
+else version( NetBSD )
+{
+    struct sigevent
+    {
+        int             sigev_notify;
+        int             sigev_signo;
+        sigval          sigev_value;
+        void function(sigval) sigev_notify_function;
+        void /* pthread_attr_t */*sigev_notify_attributes;
+    }
+
+    int sigqueue(pid_t, int, in sigval);
+    int sigtimedwait(in sigset_t*, siginfo_t*, in timespec*);
+    int sigwaitinfo(in sigset_t*, siginfo_t*);
+}
 else version (OSX)
 {
 }
@@ -2398,6 +2677,11 @@ else version( DragonFlyBSD )
 {
     int pthread_kill(pthread_t, int);
     int pthread_sigmask(int, in sigset_t*, sigset_t*);
+}
+else version( NetBSD )
+{
+    int pthread_kill(pthread_t, int);
+    int pthread_sigmask(int, in sigset_t*, sigset_t*);
 }
 else version (Solaris)
 {
