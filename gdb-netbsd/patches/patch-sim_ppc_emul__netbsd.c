$NetBSD$

--- sim/ppc/emul_netbsd.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ sim/ppc/emul_netbsd.c
@@ -41,6 +41,7 @@
 #include <stdio.h>
 #include <signal.h>
 #include <fcntl.h>
+#include <dirent.h>
 #include <errno.h>
 #include <sys/param.h>
 #include <sys/time.h>
@@ -783,7 +784,7 @@ do_gettimeofday(os_emul_data *emul,
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("0x%lx, 0x%lx", (long)t_addr, (long)tz_addr);
 
-  SYS(gettimeofday);
+  SYS(__gettimeofday50);
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (t_addr != 0)
@@ -813,7 +814,7 @@ do_getrusage(os_emul_data *emul,
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("%d, 0x%lx", who, (long)rusage_addr);
 
-  SYS(getrusage);
+  SYS(__getrusage50);
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (rusage_addr != 0)
@@ -1090,21 +1091,21 @@ static emul_syscall_descriptor netbsd_de
   /* 4 */ { do_write, "write" },
   /* 5 */ { do_open, "open" },
   /* 6 */ { do_close, "close" },
-  /* 7 */ { 0, "wait4" },
+  { 0, }, /* 7 is old wait4 */
   { 0, }, /* 8 is old creat */
   /* 9 */ { 0, "link" },
   /* 10 */ { 0, "unlink" },
   { 0, }, /* 11 is obsolete execv */
   /* 12 */ { 0, "chdir" },
   /* 13 */ { 0, "fchdir" },
-  /* 14 */ { 0, "mknod" },
+  { 0, }, /* 14 is old mknod */
   /* 15 */ { 0, "chmod" },
   /* 16 */ { 0, "chown" },
   /* 17 */ { do_break, "break" },
-  /* 18 */ { 0, "getfsstat" },
+  { 0, }, /* 18 is old getfsstat */
   { 0, }, /* 19 is old lseek */
   /* 20 */ { do_getpid, "getpid" },
-  /* 21 */ { 0, "mount" },
+  { 0, }, /* 21 is old mount */
   /* 22 */ { 0, "unmount" },
   /* 23 */ { 0, "setuid" },
   /* 24 */ { do_getuid, "getuid" },
@@ -1129,16 +1130,16 @@ static emul_syscall_descriptor netbsd_de
   /* 43 */ { do_getegid, "getegid" },
   /* 44 */ { 0, "profil" },
   /* 45 */ { 0, "ktrace" },
-  /* 46 */ { 0, "sigaction" },
+  { 0, }, /* 46 is old sigaction */
   /* 47 */ { do_getgid, "getgid" },
-  /* 48 */ { do_sigprocmask, "sigprocmask" },
+  { 0, }, /* 48 is old sigprocmask */
   /* 49 */ { 0, "getlogin" },
   /* 50 */ { 0, "setlogin" },
   /* 51 */ { 0, "acct" },
-  /* 52 */ { 0, "sigpending" },
-  /* 53 */ { 0, "sigaltstack" },
+  { 0, }, /* 52 is old sigpending */
+  { 0, }, /* 53 is old sigaltstack */
   /* 54 */ { do_ioctl, "ioctl" },
-  /* 55 */ { 0, "reboot" },
+  { 0, }, /* 55 is old reboot */
   /* 56 */ { 0, "revoke" },
   /* 57 */ { 0, "symlink" },
   /* 58 */ { 0, "readlink" },
@@ -1148,14 +1149,14 @@ static emul_syscall_descriptor netbsd_de
   { 0, }, /* 62 is old fstat */
   { 0, }, /* 63 is old getkerninfo */
   { 0, }, /* 64 is old getpagesize */
-  /* 65 */ { 0, "msync" },
+  { 0, }, /* 65 is old msync */
   /* 66 */ { 0, "vfork" },
   { 0, }, /* 67 is obsolete vread */
   { 0, }, /* 68 is obsolete vwrite */
   /* 69 */ { 0, "sbrk" },
-  /* 70 */ { 0, "sstk" },
+  { 0, }, /* 70 is obsolete sstk */
   { 0, }, /* 71 is old mmap */
-  /* 72 */ { 0, "vadvise" },
+  { 0, }, /* 72 is obsolete vadvise */
   /* 73 */ { 0, "munmap" },
   /* 74 */ { 0, "mprotect" },
   /* 75 */ { 0, "madvise" },
@@ -1166,27 +1167,27 @@ static emul_syscall_descriptor netbsd_de
   /* 80 */ { 0, "setgroups" },
   /* 81 */ { 0, "getpgrp" },
   /* 82 */ { 0, "setpgid" },
-  /* 83 */ { 0, "setitimer" },
+  { 0, }, /* 83 is old setitimer */
   { 0, }, /* 84 is old wait */
-  /* 85 */ { 0, "swapon" },
-  /* 86 */ { 0, "getitimer" },
+  { 0, }, /* 85 is old swapon */
+  { 0, }, /* 86 is old getitimer */
   { 0, }, /* 87 is old gethostname */
   { 0, }, /* 88 is old sethostname */
   { 0, }, /* 89 is old getdtablesize */
   { do_dup2, "dup2" },
   { 0, }, /* 91 */
   /* 92 */ { do_fcntl, "fcntl" },
-  /* 93 */ { 0, "select" },
+  { 0, }, /* 93 is old select */
   { 0, }, /* 94 */
   /* 95 */ { 0, "fsync" },
   /* 96 */ { 0, "setpriority" },
-  /* 97 */ { 0, "socket" },
-  /* 98 */ { 0, "connect" },
+  { 0, }, /* 97 is old socket */
+  { 0, }, /* 98 is old connect */
   { 0, }, /* 99 is old accept */
   /* 100 */ { 0, "getpriority" },
   { 0, }, /* 101 is old send */
   { 0, }, /* 102 is old recv */
-  /* 103 */ { 0, "sigreturn" },
+  { 0, }, /* 103 is old sigreturn */
   /* 104 */ { 0, "bind" },
   /* 105 */ { 0, "setsockopt" },
   /* 106 */ { 0, "listen" },
@@ -1194,23 +1195,25 @@ static emul_syscall_descriptor netbsd_de
   { 0, }, /* 108 is old sigvec */
   { 0, }, /* 109 is old sigblock */
   { 0, }, /* 110 is old sigsetmask */
-  /* 111 */ { 0, "sigsuspend" },
+  { 0, }, /* 111 is old sigsuspend */
   { 0, }, /* 112 is old sigstack */
   { 0, }, /* 113 is old recvmsg */
   { 0, }, /* 114 is old sendmsg */
   /* - is obsolete vtrace */ { 0, "vtrace	115" },
-  /* 116 */ { do_gettimeofday, "gettimeofday" },
-  /* 117 */ { do_getrusage, "getrusage" },
+  { 0, }, /* 116 is old gettimeofday */
+  { 0, }, /* 117 is old getrusage */
   /* 118 */ { 0, "getsockopt" },
-  /* 119 */ { 0, "resuba" },
+  /* - is obsolete resuba */ { 0, "resuba	119" },
   /* 120 */ { 0, "readv" },
   /* 121 */ { 0, "writev" },
-  /* 122 */ { 0, "settimeofday" },
+  { 0, }, /* 122 is old settimeofday */
   /* 123 */ { 0, "fchown" },
   /* 124 */ { 0, "fchmod" },
   { 0, }, /* 125 is old recvfrom */
   { 0, }, /* 126 is old setreuid */
   { 0, }, /* 127 is old setregid */
+  /* 126 */ { 0, "setreuid" },
+  /* 127 */ { 0, "setregid" },
   /* 128 */ { 0, "rename" },
   { 0, }, /* 129 is old truncate */
   { 0, }, /* 130 is old ftruncate */
@@ -1221,9 +1224,9 @@ static emul_syscall_descriptor netbsd_de
   /* 135 */ { 0, "socketpair" },
   /* 136 */ { 0, "mkdir" },
   /* 137 */ { 0, "rmdir" },
-  /* 138 */ { 0, "utimes" },
+  { 0, }, /* 138 is old utimes */
   { 0, }, /* 139 is obsolete 4.2 sigreturn */
-  /* 140 */ { 0, "adjtime" },
+  { 0, }, /* 140 is old adjtime */
   { 0, }, /* 141 is old getpeername */
   { 0, }, /* 142 is old gethostid */
   { 0, }, /* 143 is old sethostid */
@@ -1240,11 +1243,11 @@ static emul_syscall_descriptor netbsd_de
   { 0, }, /* 154 */
   /* 155 */ { 0, "nfssvc" },
   { 0, }, /* 156 is old getdirentries */
-  /* 157 */ { 0, "statfs" },
-  /* 158 */ { do_fstatfs, "fstatfs" },
+  { 0, }, /* 157 is old statfs */
+  { 0, }, /* 158 is old fstatfs */
   { 0, }, /* 159 */
   { 0, }, /* 160 */
-  /* 161 */ { 0, "getfh" },
+  { 0, }, /* 161 is old getfh */
   { 0, }, /* 162 is old getdomainname */
   { 0, }, /* 163 is old setdomainname */
   { 0, }, /* 164 is old uname */
@@ -1252,14 +1255,14 @@ static emul_syscall_descriptor netbsd_de
   { 0, }, /* 166 */
   { 0, }, /* 167 */
   { 0, }, /* 168 */
-  /* 169 */ { 0, "semsys" },
-  /* 170 */ { 0, "msgsys" },
-  /* 171 */ { 0, "shmsys" },
+  { 0, }, /* 169 is old semsys */
+  { 0, }, /* 170 is old msgsys */
+  { 0, }, /* 171 is old shmsys */
   { 0, }, /* 172 */
-  { 0, }, /* 173 */
-  { 0, }, /* 174 */
-  { 0, }, /* 175 */
-  { 0, }, /* 176 */
+  /* 173 */ { 0, "pread" },
+  /* 174 */ { 0, "pwrite" },
+  { 0, }, /* 175 is old ntp_gettime */
+  /* 176 */ { 0, "ntp_adjtime" },
   { 0, }, /* 177 */
   { 0, }, /* 178 */
   { 0, }, /* 179 */
@@ -1271,15 +1274,15 @@ static emul_syscall_descriptor netbsd_de
   /* 185 */ { 0, "lfs_markv" },
   /* 186 */ { 0, "lfs_segclean" },
   /* 187 */ { 0, "lfs_segwait" },
-  /* 188 */ { do_stat, "stat" },
-  /* 189 */ { do_fstat, "fstat" },
-  /* 190 */ { do_lstat, "lstat" },
+  { 0, }, /* 188 is old stat" */
+  { 0, }, /* 189 is old fstat */
+  { 0, }, /* 190 is old lstat */
   /* 191 */ { 0, "pathconf" },
   /* 192 */ { 0, "fpathconf" },
   { 0, }, /* 193 */
   /* 194 */ { 0, "getrlimit" },
   /* 195 */ { 0, "setrlimit" },
-  /* 196 */ { do_getdirentries, "getdirentries" },
+  { 0, }, /* 196 is old getdirentries */
   /* 197 */ { 0, "mmap" },
   /* 198 */ { do___syscall, "__syscall" },
   /* 199 */ { do_lseek, "lseek" },
@@ -1288,6 +1291,275 @@ static emul_syscall_descriptor netbsd_de
   /* 202 */ { do___sysctl, "__sysctl" },
   /* 203 */ { 0, "mlock" },
   /* 204 */ { 0, "munlock" },
+  /* 205 */ { 0, "undelete" },
+  { 0, }, /* 206 is old futimes */
+  /* 207 */ { 0, "getpgid" },
+  /* 208 */ { 0, "reboot" },
+  /* 209 */ { 0, "poll" },
+  { 0, }, /* 210 */
+  { 0, }, /* 211 */
+  { 0, }, /* 212 */
+  { 0, }, /* 213 */
+  { 0, }, /* 214 */
+  { 0, }, /* 215 */
+  { 0, }, /* 216 */
+  { 0, }, /* 217 */
+  { 0, }, /* 218 */
+  { 0, }, /* 219 */
+  { 0, }, /* 220 is old semctl */
+  /* 221 */ { 0, "semget" },
+  /* 222 */ { 0, "semop" },
+  /* 223 */ { 0, "semconfig" },
+  { 0, }, /* 224 is old msgctl */
+  /* 225 */ { 0, "msgget" },
+  /* 226 */ { 0, "msgsnd" },
+  /* 227 */ { 0, "msgrcv" },
+  /* 228 */ { 0, "shmat" },
+  { 0, }, /* 229 is old shmctl */
+  /* 230 */ { 0, "shmdt" },
+  /* 231 */ { 0, "shmget" },
+  { 0, }, /* 232 is old clock_gettime */
+  { 0, }, /* 233 is old clock_settime */
+  { 0, }, /* 234 is old clock_getres */
+  /* 235 */ { 0, "timer_create" },
+  /* 236 */ { 0, "timer_delete" },
+  { 0, }, /* 237 is old timer_settime */
+  { 0, }, /* 238 is old timer_gettime */
+  /* 239 */ { 0, "timer_getoverrun" },
+  { 0, }, /* 240 is old nanosleep */
+  /* 241 */ { 0, "fdatasync" },
+  /* 242 */ { 0, "mlockall" },
+  /* 243 */ { 0, "munlockall" },
+  { 0, }, /* 244 is old sigtimedwait */
+  { 0, }, /* 245 */
+  /* 246 */ { 0, "modctl" },
+  /* 247 */ { 0, "_ksem_init" },
+  /* 248 */ { 0, "_ksem_open" },
+  /* 249 */ { 0, "_ksem_unlink" },
+  /* 250 */ { 0, "_ksem_close" },
+  /* 251 */ { 0, "_ksem_post" },
+  /* 252 */ { 0, "_ksem_wait" },
+  /* 253 */ { 0, "_ksem_trywait" },
+  /* 254 */ { 0, "_ksem_getvalue" },
+  /* 255 */ { 0, "_ksem_destroy" },
+  /* 256 */ { 0, "_ksem_timedwait" },
+  /* 257 */ { 0, "mq_open" },
+  /* 258 */ { 0, "mq_close" },
+  /* 259 */ { 0, "mq_unlink" },
+  /* 260 */ { 0, "mq_getattr" },
+  /* 261 */ { 0, "mq_setattr" },
+  /* 262 */ { 0, "mq_notify" },
+  /* 263 */ { 0, "mq_send" },
+  /* 264 */ { 0, "mq_receive" },
+  { 0, }, /* 265 is old mq_timedsend */
+  { 0, }, /* 266 is old mq_timedrecive */
+  { 0, }, /* 267 */
+  { 0, }, /* 268 */
+  { 0, }, /* 269 */
+  /* 270 */ { 0, "__posix_rename" },
+  /* 271 */ { 0, "swapctl" },
+  { 0, }, /* 272 is old getdents */
+  /* 273 */ { 0, "minherit" },
+  /* 274 */ { 0, "lchmod" },
+  /* 275 */ { 0, "lchown" },
+  { 0, }, /* 276 is old lutimes */
+  /* 277 */ { 0, "__msync13" },
+  { 0, }, /* 278 is old stat */
+  { 0, }, /* 279 is old fstat */
+  { 0, }, /* 280 is old lstat */
+  /* 281 */ { 0, "__sigaltstack13" },
+  /* 282 */ { 0, "__vfork14" },
+  /* 283 */ { 0, "__posix_chown" },
+  /* 284 */ { 0, "__posix_fchown" },
+  /* 285 */ { 0, "__posix_lchown" },
+  /* 286 */ { 0, "getsid" },
+  /* 287 */ { 0, "__clone" },
+  /* 288 */ { 0, "fktrace" },
+  /* 289 */ { 0, "preadv" },
+  /* 290 */ { 0, "pwritev" },
+  { 0, }, /* 291 is old sigaction */
+  /* 292 */ { 0, "__sigpending14" },
+  /* 293 */ { do_sigprocmask, "__sigprocmask14" },
+  /* 294 */ { 0, "__sigsuspend14" },
+  /* 295 */ { 0, "__sigreturn14" },
+  /* 296 */ { 0, "__getcwd" },
+  /* 297 */ { 0, "fchroot" },
+  { 0, }, /* 298 is old fhopen */
+  { 0, }, /* 299 is old fhstat */
+  { 0, }, /* 300 is old fhstatfs */
+  { 0, }, /* 301 is old semctl */
+  { 0, }, /* 302 is old msgctl */
+  { 0, }, /* 303 is old shmctl */
+  /* 304 */ { 0, "lchflags" },
+  /* 305 */ { 0, "issetugid" },
+  /* 306 */ { 0, "utrace" },
+  /* 307 */ { 0, "getcontext" },
+  /* 308 */ { 0, "setcontext" },
+  /* 309 */ { 0, "_lwp_create" },
+  /* 310 */ { 0, "_lwp_exit" },
+  /* 311 */ { 0, "_lwp_self" },
+  /* 312 */ { 0, "_lwp_wait" },
+  /* 313 */ { 0, "_lwp_suspend" },
+  /* 314 */ { 0, "_lwp_continue" },
+  /* 315 */ { 0, "_lwp_wakeup" },
+  /* 316 */ { 0, "_lwp_getprivate" },
+  /* 317 */ { 0, "_lwp_setprivate" },
+  /* 318 */ { 0, "_lwp_kill" },
+  /* 319 */ { 0, "_lwp_detach" },
+  { 0, }, /* 320 is old _lwp_park */
+  /* 321 */ { 0, "_lwp_unpark" },
+  /* 322 */ { 0, "_lwp_unpark_all" },
+  /* 323 */ { 0, "_lwp_setname" },
+  /* 324 */ { 0, "_lwp_getname" },
+  /* 325 */ { 0, "_lwp_ctl" },
+  { 0, }, /* 326 */
+  { 0, }, /* 327 */
+  { 0, }, /* 328 */
+  { 0, }, /* 329 */
+  /* 330 */ { 0, "sa_register" },
+  /* 331 */ { 0, "sa_stacks" },
+  /* 332 */ { 0, "sa_enable" },
+  /* 333 */ { 0, "sa_setconcurrency" },
+  /* 334 */ { 0, "sa_yield" },
+  /* 335 */ { 0, "sa_preempt" },
+  { 0, }, /* 336 */
+  { 0, }, /* 337 */
+  { 0, }, /* 338 */
+  { 0, }, /* 339 */
+  /* 340 */ { 0, "__sigaction_sigtramp" },
+  /* 341 */ { 0, "pmc_get_info" },
+  /* 342 */ { 0, "pmc_control" },
+  /* 343 */ { 0, "rasctl" },
+  /* 344 */ { 0, "kqueue" },
+  { 0, }, /* 345 is old kevent */
+  /* 346 */ { 0, "_sched_setparam" },
+  /* 347 */ { 0, "_sched_getparam" },
+  /* 348 */ { 0, "_sched_setaffinity" },
+  /* 349 */ { 0, "_sched_getaffinity" },
+  /* 350 */ { 0, "sched_yield" },
+  { 0, }, /* 351 */
+  { 0, }, /* 352 */
+  { 0, }, /* 353 */
+  /* 354 */ { 0, "fsync_range" },
+  /* 355 */ { 0, "uuidgen" },
+  /* 356 */ { 0, "getvfsstat" },
+  /* 357 */ { 0, "statvfs1" },
+  /* 358 */ { 0, "fstatvfs1" },
+  { 0, }, /* 359 is old fhstatvfs1 */
+  /* 360 */ { 0, "extattrctl" },
+  /* 361 */ { 0, "extattr_set_file" },
+  /* 362 */ { 0, "extattr_get_file" },
+  /* 363 */ { 0, "extattr_delete_file" },
+  /* 364 */ { 0, "extattr_set_fd" },
+  /* 365 */ { 0, "extattr_get_fd" },
+  /* 366 */ { 0, "extattr_delete_fd" },
+  /* 367 */ { 0, "extattr_set_link" },
+  /* 368 */ { 0, "extattr_get_link" },
+  /* 369 */ { 0, "extattr_delete_link" },
+  /* 370 */ { 0, "extattr_list_fd" },
+  /* 371 */ { 0, "extattr_list_file" },
+  /* 372 */ { 0, "extattr_list_link" },
+  { 0, }, /* 373 is old pselect */
+  { 0, }, /* 374 is old pollts */
+  /* 375 */ { 0, "setxattr" },
+  /* 376 */ { 0, "lsetxattr" },
+  /* 377 */ { 0, "fsetxattr" },
+  /* 378 */ { 0, "getxattr" },
+  /* 379 */ { 0, "lgetxattr" },
+  /* 380 */ { 0, "fgetxattr" },
+  /* 381 */ { 0, "listxattr" },
+  /* 382 */ { 0, "llistxattr" },
+  /* 383 */ { 0, "flistxattr" },
+  /* 384 */ { 0, "removexattr" },
+  /* 385 */ { 0, "lremovexattr" },
+  /* 386 */ { 0, "fremovexattr" },
+  { 0, }, /* 387 is old stat */
+  { 0, }, /* 388 is old fstat */
+  { 0, }, /* 389 is old lstat */
+  /* 390 */ { do_getdirentries, "__getdents30" },
+  { 0, }, /* 391 is old posix_fadvise */
+  { 0, }, /* 392 is old fhstat */
+  { 0, }, /* 393 is old ntp_gettime */
+  /* 394 */ { 0, "__socket30" },
+  /* 395 */ { 0, "__getfh30" },
+  /* 396 */ { 0, "__fhopen40" },
+  /* 397 */ { 0, "__fhstatvfs140" },
+  { 0, }, /* 398 is old fhstat */
+  /* 399 */ { 0, "aio_cancel" },
+  /* 400 */ { 0, "aio_error" },
+  /* 401 */ { 0, "aio_fsync" },
+  /* 402 */ { 0, "aio_read" },
+  /* 403 */ { 0, "aio_return" },
+  { 0, }, /* 404 is old aio_suspend */
+  /* 405 */ { 0, "aio_write" },
+  /* 406 */ { 0, "lio_listio" },
+  { 0, }, /* 407 */
+  { 0, }, /* 408 */
+  { 0, }, /* 409 */
+  /* 410 */ { 0, "__mount50" },
+  /* 411 */ { 0, "mremap" },
+  /* 412 */ { 0, "pset_create" },
+  /* 413 */ { 0, "pset_destroy" },
+  /* 414 */ { 0, "pset_assign" },
+  /* 415 */ { 0, "_pset_bind" },
+  /* 416 */ { 0, "__posix_fadvise50" },
+  /* 417 */ { 0, "__select50" },
+  /* 418 */ { do_gettimeofday, "__gettimeofday50" },
+  /* 419 */ { 0, "__settimeofday50" },
+  /* 420 */ { 0, "__utimes50" },
+  /* 421 */ { 0, "__adjtime50" },
+  /* 422 */ { 0, "__lfs_segwait50" },
+  /* 423 */ { 0, "__futimes50" },
+  /* 424 */ { 0, "__lutimes50" },
+  /* 425 */ { 0, "__setitimer50" },
+  /* 426 */ { 0, "__getitimer50" },
+  /* 427 */ { 0, "__clock_gettime50" },
+  /* 428 */ { 0, "__clock_settime50" },
+  /* 429 */ { 0, "__clock_getres50" },
+  /* 430 */ { 0, "__nanosleep50" },
+  /* 431 */ { 0, "____sigtimedwait50" },
+  /* 432 */ { 0, "__mq_timedsend50" },
+  /* 433 */ { 0, "__mq_timedreceive50" },
+  /* 434 */ { 0, "____lwp_park50" },
+  /* 435 */ { 0, "__kevent50" },
+  /* 436 */ { 0, "__pselect50" },
+  /* 437 */ { 0, "__pollts50" },
+  /* 438 */ { 0, "__aio_suspend50" },
+  /* 439 */ { do_stat, "__stat50" },
+  /* 440 */ { do_fstat, "__fstat50" },
+  /* 441 */ { do_lstat, "__lstat50" },
+  /* 442 */ { 0, "____semctl50" },
+  /* 443 */ { 0, "__shmctl50" },
+  /* 444 */ { 0, "__msgctl50" },
+  /* 445 */ { do_getrusage, "__getrusage50" },
+  /* 446 */ { 0, "__timer_settime50" },
+  /* 447 */ { 0, "__timer_gettime50" },
+  /* 448 */ { 0, "__ntp_gettime50" },
+  /* 449 */ { 0, "__wait450" },
+  /* 450 */ { 0, "__mknod50" },
+  /* 451 */ { 0, "__fhstat50" },
+  { 0, }, /* 452 is obsolete 5.99 __quotactl50 */
+  /* 453 */ { 0, "pipe2" },
+  /* 454 */ { 0, "dup3" },
+  /* 455 */ { 0, "kqueue1" },
+  /* 456 */ { 0, "paccept" },
+  /* 457 */ { 0, "linkat" },
+  /* 458 */ { 0, "renameat" },
+  /* 459 */ { 0, "mkfifoat" },
+  /* 460 */ { 0, "mknodat" },
+  /* 461 */ { 0, "mkdirat" },
+  /* 462 */ { 0, "faccessat" },
+  /* 463 */ { 0, "fchmodat" },
+  /* 464 */ { 0, "fchownat" },
+  /* 465 */ { 0, "fexecve" },
+  /* 466 */ { 0, "fstatat" },
+  /* 467 */ { 0, "utimensat" },
+  /* 468 */ { 0, "openat" },
+  /* 469 */ { 0, "readlinkat" },
+  /* 470 */ { 0, "symlinkat" },
+  /* 471 */ { 0, "unlinkat" },
+  /* 472 */ { 0, "futimens" },
+  /* 473 */ { 0, "__quotactl" },
 };
 
 static char *(netbsd_error_names[]) = {
