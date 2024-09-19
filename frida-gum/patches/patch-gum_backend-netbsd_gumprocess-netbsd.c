$NetBSD$

--- gum/backend-netbsd/gumprocess-netbsd.c.orig	2018-03-15 03:53:19.217712887 +0000
+++ gum/backend-netbsd/gumprocess-netbsd.c
@@ -0,0 +1,633 @@
+/*
+ * Copyright (C) 2010-2018 Ole André Vadla Ravnås <oleavr@nowsecure.com>
+ *
+ * Licence: wxWindows Library Licence, Version 3.1
+ */
+
+#include "gumprocess-priv.h"
+
+#include "backend-elf/gumelfmodule.h"
+#include "gumnetbsd.h"
+#include "gummodulemap.h"
+
+#include <dlfcn.h>
+#include <errno.h>
+#include <link.h>
+#include <sched.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+#include <gio/gio.h>
+#include <sys/types.h>
+#include <sys/ptrace.h>
+#include <sys/socket.h>
+#include <sys/syscall.h>
+#include <sys/types.h>
+#include <sys/uio.h>
+#include <sys/wait.h>
+#include <link.h>
+#include <lwp.h>
+
+typedef struct _GumModifyThreadContext GumModifyThreadContext;
+typedef guint8 GumModifyThreadAck;
+
+typedef struct _GumEnumerateModulesContext GumEnumerateModulesContext;
+typedef struct _GumEmitExecutableModuleContext GumEmitExecutableModuleContext;
+typedef struct _GumCopyLinkerModuleContext GumCopyLinkerModuleContext;
+typedef struct _GumEnumerateImportsContext GumEnumerateImportsContext;
+typedef struct _GumDependencyExport GumDependencyExport;
+typedef struct _GumEnumerateModuleSymbolContext GumEnumerateModuleSymbolContext;
+typedef struct _GumEnumerateModuleRangesContext GumEnumerateModuleRangesContext;
+typedef struct _GumResolveModuleNameContext GumResolveModuleNameContext;
+
+typedef gint (* GumFoundDlPhdrFunc) (struct dl_phdr_info * info,
+    gsize size, gpointer data);
+typedef void (* GumDlIteratePhdrImpl) (GumFoundDlPhdrFunc func, gpointer data);
+
+typedef struct _GumUserDesc GumUserDesc;
+
+typedef gint (* GumCloneFunc) (gpointer arg);
+
+enum _GumModifyThreadAck
+{
+  GUM_ACK_ATTACHED = 1,
+  GUM_ACK_STOPPED,
+  GUM_ACK_READ_CONTEXT,
+  GUM_ACK_MODIFIED_CONTEXT,
+  GUM_ACK_WROTE_CONTEXT,
+  GUM_ACK_FAILED_TO_ATTACH,
+  GUM_ACK_FAILED_TO_READ,
+  GUM_ACK_FAILED_TO_WRITE,
+  GUM_ACK_FAILED_TO_DETACH
+};
+
+struct _GumModifyThreadContext
+{
+  gint fd[2];
+  GumThreadId thread_id;
+  GumCpuContext cpu_context;
+};
+
+struct _GumEnumerateModulesContext
+{
+  GumFoundModuleFunc func;
+  gpointer user_data;
+
+  GHashTable * names;
+  GHashTable * sizes;
+
+  guint index;
+  gboolean carry_on;
+  GumModuleDetails * linker_module;
+};
+
+struct _GumEmitExecutableModuleContext
+{
+  const gchar * executable_path;
+  GumFoundModuleFunc func;
+  gpointer user_data;
+
+  gboolean carry_on;
+};
+
+struct _GumCopyLinkerModuleContext
+{
+  GumAddress address_in_linker;
+  GumModuleDetails * linker_module;
+};
+
+struct _GumEnumerateImportsContext
+{
+  GumFoundImportFunc func;
+  gpointer user_data;
+
+  GHashTable * dependency_exports;
+  GumElfModule * current_dependency;
+  GumModuleMap * module_map;
+};
+
+struct _GumDependencyExport
+{
+  gchar * module;
+  GumAddress address;
+};
+
+struct _GumEnumerateModuleSymbolContext
+{
+  GumFoundSymbolFunc func;
+  gpointer user_data;
+
+  GArray * sections;
+};
+
+struct _GumEnumerateModuleRangesContext
+{
+  gchar * module_name;
+  GumFoundRangeFunc func;
+  gpointer user_data;
+};
+
+struct _GumResolveModuleNameContext
+{
+  gchar * name;
+  gchar * path;
+  GumAddress base;
+};
+
+struct _GumUserDesc
+{
+  guint entry_number;
+  guint base_addr;
+  guint limit;
+  guint seg_32bit : 1;
+  guint contents : 2;
+  guint read_exec_only : 1;
+  guint limit_in_pages : 1;
+  guint seg_not_present : 1;
+  guint useable : 1;
+};
+
+typedef void *GumRegs;
+
+static gint gum_do_modify_thread (gpointer data);
+static gboolean gum_await_ack (gint fd, GumModifyThreadAck expected_ack);
+static void gum_put_ack (gint fd, GumModifyThreadAck ack);
+
+static void gum_store_cpu_context (GumThreadId thread_id,
+    GumCpuContext * cpu_context, gpointer user_data);
+
+static void gum_process_enumerate_modules_by_using_libc (
+    GumDlIteratePhdrImpl iterate_phdr, GumFoundModuleFunc func,
+    gpointer user_data);
+static gint gum_emit_module_from_phdr (struct dl_phdr_info * info, gsize size,
+    gpointer user_data);
+static GumAddress gum_resolve_base_address_from_phdr (
+    struct dl_phdr_info * info);
+static gboolean gum_emit_executable_module (const GumModuleDetails * details,
+    gpointer user_data);
+
+static void gum_process_enumerate_modules_by_parsing_proc_maps (
+    GumFoundModuleFunc func, gpointer user_data);
+
+static void gum_process_build_named_range_indexes (GHashTable ** names,
+    GHashTable ** sizes);
+
+static gboolean gum_emit_import (const GumImportDetails * details,
+    gpointer user_data);
+static gboolean gum_collect_dependency_exports (
+    const GumElfDependencyDetails * details, gpointer user_data);
+static gboolean gum_collect_dependency_export (const GumExportDetails * details,
+    gpointer user_data);
+static GumDependencyExport * gum_dependency_export_new (const gchar * module,
+    GumAddress address);
+static void gum_dependency_export_free (GumDependencyExport * export);
+static gboolean gum_emit_symbol (const GumElfSymbolDetails * details,
+    gpointer user_data);
+static gboolean gum_append_symbol_section (const GumElfSectionDetails * details,
+    gpointer user_data);
+static void gum_symbol_section_destroy (GumSymbolSection * self);
+static gboolean gum_emit_range_if_module_name_matches (
+    const GumRangeDetails * details, gpointer user_data);
+
+static gchar * gum_resolve_module_name (const gchar * name, GumAddress * base);
+static gboolean gum_store_module_path_and_base_if_name_matches (
+    const GumModuleDetails * details, gpointer user_data);
+static gboolean gum_module_path_equals (const gchar * path,
+    const gchar * name_or_path);
+
+static GumElfModule * gum_open_elf_module (const gchar * name);
+
+static gboolean gum_thread_read_state (GumThreadId tid, GumThreadState * state);
+static GumThreadState gum_thread_state_from_proc_status_character (gchar c);
+static GumPageProtection gum_page_protection_from_proc_perms_string (
+    const gchar * perms);
+
+static gssize gum_get_regs (pid_t pid, GumRegs * regs);
+static gssize gum_set_regs (pid_t pid, const GumRegs * regs);
+
+static void gum_parse_regs (const GumRegs * regs, GumCpuContext * ctx);
+static void gum_unparse_regs (const GumCpuContext * ctx, GumRegs * regs);
+
+static gssize gum_libc_clone (GumCloneFunc child_func, gpointer child_stack,
+    gint flags, gpointer arg, pid_t * parent_tidptr, GumUserDesc * tls,
+    pid_t * child_tidptr);
+static gssize gum_libc_read (gint fd, gpointer buf, gsize count);
+static gssize gum_libc_write (gint fd, gconstpointer buf, gsize count);
+static gssize gum_libc_ptrace (gsize request, pid_t pid, gpointer address,
+    gpointer data);
+
+#define gum_libc_syscall_3(n, a, b, c) gum_libc_syscall_4 (n, a, b, c, 0)
+static gssize gum_libc_syscall_4 (gsize n, gsize a, gsize b, gsize c, gsize d);
+
+static gboolean gum_is_regset_supported = TRUE;
+
+gboolean
+gum_process_is_debugger_attached (void)
+{
+  return FALSE;
+}
+
+GumThreadId
+gum_process_get_current_thread_id (void)
+{
+  return _lwp_self();
+}
+
+gboolean
+gum_process_modify_thread (GumThreadId thread_id,
+                           GumModifyThreadFunc func,
+                           gpointer user_data)
+{
+  return FALSE;
+}
+
+static gint
+gum_do_modify_thread (gpointer data)
+{
+  return 0;
+}
+
+static gboolean
+gum_await_ack (gint fd,
+               GumModifyThreadAck expected_ack)
+{
+  return FALSE;
+}
+
+static void
+gum_put_ack (gint fd,
+             GumModifyThreadAck ack)
+{
+}
+
+void
+_gum_process_enumerate_threads (GumFoundThreadFunc func,
+                                gpointer user_data)
+{
+}
+
+static void
+gum_store_cpu_context (GumThreadId thread_id,
+                       GumCpuContext * cpu_context,
+                       gpointer user_data)
+{
+}
+
+void
+gum_process_enumerate_modules (GumFoundModuleFunc func,
+                               gpointer user_data)
+{
+}
+
+static void
+gum_process_enumerate_modules_by_using_libc (GumDlIteratePhdrImpl iterate_phdr,
+                                             GumFoundModuleFunc func,
+                                             gpointer user_data)
+{
+}
+
+static gint
+gum_emit_module_from_phdr (struct dl_phdr_info * info,
+                           gsize size,
+                           gpointer user_data)
+{
+  return 0;
+}
+
+static GumAddress
+gum_resolve_base_address_from_phdr (struct dl_phdr_info * info)
+{
+  return NULL;
+}
+
+static gboolean
+gum_emit_executable_module (const GumModuleDetails * details,
+                            gpointer user_data)
+{
+  return FALSE;
+}
+
+static void
+gum_process_enumerate_modules_by_parsing_proc_maps (GumFoundModuleFunc func,
+                                                    gpointer user_data)
+{
+}
+
+static void
+gum_process_build_named_range_indexes (GHashTable ** names,
+                                       GHashTable ** sizes)
+{
+}
+
+static gboolean
+gum_copy_linker_module (const GumModuleDetails * details,
+                        gpointer user_data)
+{
+  return FALSE;
+}
+
+static GumModuleDetails *
+gum_module_details_dup (const GumModuleDetails * module)
+{
+  return NULL;
+}
+
+static void
+gum_module_details_free (GumModuleDetails * module)
+{
+}
+
+void
+_gum_process_enumerate_ranges (GumPageProtection prot,
+                               GumFoundRangeFunc func,
+                               gpointer user_data)
+{
+}
+
+void
+gum_netbsd_enumerate_ranges (pid_t pid,
+                            GumPageProtection prot,
+                            GumFoundRangeFunc func,
+                            gpointer user_data)
+{
+}
+
+void
+gum_process_enumerate_malloc_ranges (GumFoundMallocRangeFunc func,
+                                     gpointer user_data)
+{
+  /* Not implemented */
+}
+
+guint
+gum_thread_try_get_ranges (GumMemoryRange * ranges,
+                           guint max_length)
+{
+  /* Not implemented */
+  return 0;
+}
+
+gint
+gum_thread_get_system_error (void)
+{
+  return errno;
+}
+
+void
+gum_thread_set_system_error (gint value)
+{
+  errno = value;
+}
+
+gboolean
+gum_module_ensure_initialized (const gchar * module_name)
+{
+  return FALSE;
+}
+
+void
+gum_module_enumerate_imports (const gchar * module_name,
+                              GumFoundImportFunc func,
+                              gpointer user_data)
+{
+}
+
+static gboolean
+gum_emit_import (const GumImportDetails * details,
+                 gpointer user_data)
+{
+  return FALSE;
+}
+
+static gboolean
+gum_collect_dependency_exports (const GumElfDependencyDetails * details,
+                                gpointer user_data)
+{
+  return FALSE;
+}
+
+static gboolean
+gum_collect_dependency_export (const GumExportDetails * details,
+                               gpointer user_data)
+{
+  return FALSE;
+}
+
+static GumDependencyExport *
+gum_dependency_export_new (const gchar * module,
+                           GumAddress address)
+{
+  return NULL;
+}
+
+static void
+gum_dependency_export_free (GumDependencyExport * export)
+{
+}
+
+void
+gum_module_enumerate_exports (const gchar * module_name,
+                              GumFoundExportFunc func,
+                              gpointer user_data)
+{
+}
+
+void
+gum_module_enumerate_symbols (const gchar * module_name,
+                              GumFoundSymbolFunc func,
+                              gpointer user_data)
+{
+}
+
+static gboolean
+gum_emit_symbol (const GumElfSymbolDetails * details,
+                 gpointer user_data)
+{
+  return FALSE;
+}
+
+static gboolean
+gum_append_symbol_section (const GumElfSectionDetails * details,
+                           gpointer user_data)
+{
+  return FALSE;
+}
+
+static void
+gum_symbol_section_destroy (GumSymbolSection * self)
+{
+}
+
+void
+gum_module_enumerate_ranges (const gchar * module_name,
+                             GumPageProtection prot,
+                             GumFoundRangeFunc func,
+                             gpointer user_data)
+{
+}
+
+static gboolean
+gum_emit_range_if_module_name_matches (const GumRangeDetails * details,
+                                       gpointer user_data)
+{
+  return FALSE;
+}
+
+GumAddress
+gum_module_find_base_address (const gchar * module_name)
+{
+  return 0;
+}
+
+GumAddress
+gum_module_find_export_by_name (const gchar * module_name,
+                                const gchar * symbol_name)
+{
+  return 0;
+}
+
+GumCpuType
+gum_linux_cpu_type_from_file (const gchar * path,
+                              GError ** error)
+{
+  return 0;
+}
+
+GumCpuType
+gum_linux_cpu_type_from_pid (pid_t pid,
+                             GError ** error)
+{
+  return 0;
+}
+
+static gchar *
+gum_resolve_module_name (const gchar * name,
+                         GumAddress * base)
+{
+  return NULL;
+}
+
+static gboolean
+gum_store_module_path_and_base_if_name_matches (const GumModuleDetails * details,
+                                                gpointer user_data)
+{
+  return FALSE;
+}
+
+static gboolean
+gum_module_path_equals (const gchar * path,
+                        const gchar * name_or_path)
+{
+  return FALSE;
+}
+
+static GumElfModule *
+gum_open_elf_module (const gchar * name)
+{
+  return NULL;
+}
+
+void
+gum_netbsd_parse_ucontext (const ucontext_t * uc,
+                          GumCpuContext * ctx)
+{
+}
+
+void
+gum_netbsd_unparse_ucontext (const GumCpuContext * ctx,
+                            ucontext_t * uc)
+{
+}
+
+static void
+gum_parse_regs (const GumRegs * regs,
+                GumCpuContext * ctx)
+{
+}
+
+static void
+gum_unparse_regs (const GumCpuContext * ctx,
+                  GumRegs * regs)
+{
+}
+
+static gboolean
+gum_thread_read_state (GumThreadId tid,
+                       GumThreadState * state)
+{
+  return FALSE;
+}
+
+static GumThreadState
+gum_thread_state_from_proc_status_character (gchar c)
+{
+  return 0;
+}
+
+static GumPageProtection
+gum_page_protection_from_proc_perms_string (const gchar * perms)
+{
+  return 0;
+}
+
+static gssize
+gum_get_regs (pid_t pid,
+              GumRegs * regs)
+{
+  return 0;
+}
+
+static gssize
+gum_set_regs (pid_t pid,
+              const GumRegs * regs)
+{
+  return 0;
+}
+
+static gssize
+gum_libc_clone (GumCloneFunc child_func,
+                gpointer child_stack,
+                gint flags,
+                gpointer arg,
+                pid_t * parent_tidptr,
+                GumUserDesc * tls,
+                pid_t * child_tidptr)
+{
+  return 0;
+}
+
+static gssize
+gum_libc_read (gint fd,
+               gpointer buf,
+               gsize count)
+{
+  return 0;
+}
+
+static gssize
+gum_libc_write (gint fd,
+                gconstpointer buf,
+                gsize count)
+{
+  return 0;
+}
+
+static gssize
+gum_libc_ptrace (gsize request,
+                 pid_t pid,
+                 gpointer address,
+                 gpointer data)
+{
+  return 0;
+}
+
+static gssize
+gum_libc_syscall_4 (gsize n,
+                    gsize a,
+                    gsize b,
+                    gsize c,
+                    gsize d)
+{
+  return 0;
+}
