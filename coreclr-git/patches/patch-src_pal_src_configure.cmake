$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-01-31 00:59:14.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -23,12 +23,15 @@ check_include_files(alloca.h HAVE_ALLOCA
 check_include_files(sys/vmparam.h HAVE_SYS_VMPARAM_H)
 check_include_files(mach/vm_types.h HAVE_MACH_VM_TYPES_H)
 check_include_files(mach/vm_param.h HAVE_MACH_VM_PARAM_H)
+check_include_files(machine/npx.h HAVE_MACHINE_NPX_H)
+check_include_files(machine/reg.h HAVE_MACHINE_REG_H)
 check_include_files(machine/vmparam.h HAVE_MACHINE_VMPARAM_H)
 check_include_files(procfs.h HAVE_PROCFS_H)
 check_include_files(crt_externs.h HAVE_CRT_EXTERNS_H)
 check_include_files(sys/time.h HAVE_SYS_TIME_H)
 check_include_files(pthread_np.h HAVE_PTHREAD_NP_H)
 check_include_files(sys/lwp.h HAVE_SYS_LWP_H)
+check_include_files(lwp.h HAVE_LWP_H)
 check_include_files(libunwind.h HAVE_LIBUNWIND_H)
 check_include_files(runetype.h HAVE_RUNETYPE_H)
 check_include_files(lttng/tracepoint.h HAVE_LTTNG_TRACEPOINT_H)
@@ -76,6 +79,7 @@ check_struct_has_member ("struct stat" s
 check_struct_has_member ("struct stat" st_atimensec "sys/types.h;sys/stat.h" HAVE_STAT_NSEC)
 check_struct_has_member ("struct tm" tm_gmtoff time.h HAVE_TM_GMTOFF)
 check_struct_has_member ("ucontext_t" uc_mcontext.gregs[0] ucontext.h HAVE_GREGSET_T)
+check_struct_has_member ("ucontext_t" uc_mcontext.__gregs[0] ucontext.h HAVE___GREGSET_T)
 
 set(CMAKE_EXTRA_INCLUDE_FILES machine/reg.h)
 check_type_size("struct reg" BSD_REGS_T)
@@ -86,7 +90,7 @@ set(CMAKE_EXTRA_INCLUDE_FILES)
 set(CMAKE_EXTRA_INCLUDE_FILES signal.h)
 check_type_size(siginfo_t SIGINFO_T)
 set(CMAKE_EXTRA_INCLUDE_FILES)
-set(CMAKE_EXTRA_INCLUDE_FILES ucontext.h)
+set(CMAKE_EXTRA_INCLUDE_FILES ucontext.h sys/ucontext.h)
 check_type_size(ucontext_t UCONTEXT_T)
 set(CMAKE_EXTRA_INCLUDE_FILES)
 set(CMAKE_EXTRA_INCLUDE_FILES pthread.h)
