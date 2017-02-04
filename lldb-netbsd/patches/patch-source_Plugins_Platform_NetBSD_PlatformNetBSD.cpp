$NetBSD$

--- source/Plugins/Platform/NetBSD/PlatformNetBSD.cpp.orig	2017-02-04 18:35:35.000000000 +0000
+++ source/Plugins/Platform/NetBSD/PlatformNetBSD.cpp
@@ -20,24 +20,107 @@
 // Other libraries and framework includes
 // Project includes
 #include "lldb/Breakpoint/BreakpointLocation.h"
-#include "lldb/Breakpoint/BreakpointSite.h"
 #include "lldb/Core/Debugger.h"
+#include "lldb/Utility/Error.h"
+#include "lldb/Core/Log.h"
 #include "lldb/Core/Module.h"
+#include "lldb/Core/ModuleList.h"
 #include "lldb/Core/ModuleSpec.h"
 #include "lldb/Core/PluginManager.h"
-#include "lldb/Host/Host.h"
+#include "lldb/Core/State.h"
+#include "lldb/Utility/StreamString.h"
+#include "lldb/Host/FileSpec.h"
 #include "lldb/Host/HostInfo.h"
+#include "lldb/Interpreter/OptionValueProperties.h"
+#include "lldb/Interpreter/Property.h"
 #include "lldb/Target/Process.h"
-#include "lldb/Utility/Error.h"
+#include "lldb/Target/Target.h"
+
+// Define these constants from NetBSD mman.h for use when targeting
+// remote linux systems even when host has different values.
+#define MAP_PRIVATE 0x0002
+#define MAP_ANON 0x1000
 
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::platform_netbsd;
 
+static uint32_t g_initialize_count = 0;
+
+//------------------------------------------------------------------
+/// Code to handle the PlatformNetBSD settings
+//------------------------------------------------------------------
+
+namespace {
+class PlatformNetBSDProperties : public Properties {
+public:
+  PlatformNetBSDProperties();
+
+  ~PlatformNetBSDProperties() override = default;
+
+  static ConstString &GetSettingName();
+
+private:
+  static const PropertyDefinition *GetStaticPropertyDefinitions();
+};
+
+typedef std::shared_ptr<PlatformNetBSDProperties> PlatformNetBSDPropertiesSP;
+
+} // anonymous namespace
+
+PlatformNetBSDProperties::PlatformNetBSDProperties() : Properties() {
+  m_collection_sp.reset(new OptionValueProperties(GetSettingName()));
+  m_collection_sp->Initialize(GetStaticPropertyDefinitions());
+}
+
+ConstString &PlatformNetBSDProperties::GetSettingName() {
+  static ConstString g_setting_name("netbsd");
+  return g_setting_name;
+}
+
+const PropertyDefinition *
+PlatformNetBSDProperties::GetStaticPropertyDefinitions() {
+  static PropertyDefinition g_properties[] = {
+      {NULL, OptionValue::eTypeInvalid, false, 0, NULL, NULL, NULL}};
+
+  return g_properties;
+}
+
+static const PlatformNetBSDPropertiesSP &GetGlobalProperties() {
+  static PlatformNetBSDPropertiesSP g_settings_sp;
+  if (!g_settings_sp)
+    g_settings_sp.reset(new PlatformNetBSDProperties());
+  return g_settings_sp;
+}
+
+void PlatformNetBSD::DebuggerInitialize(Debugger &debugger) {
+  if (!PluginManager::GetSettingForPlatformPlugin(
+          debugger, PlatformNetBSDProperties::GetSettingName())) {
+    const bool is_global_setting = true;
+    PluginManager::CreateSettingForPlatformPlugin(
+        debugger, GetGlobalProperties()->GetValueProperties(),
+        ConstString("Properties for the PlatformNetBSD plug-in."),
+        is_global_setting);
+  }
+}
+
+//------------------------------------------------------------------
+
 PlatformSP PlatformNetBSD::CreateInstance(bool force, const ArchSpec *arch) {
-  // The only time we create an instance is when we are creating a remote
-  // netbsd platform
-  const bool is_host = false;
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PLATFORM));
+  if (log) {
+    const char *arch_name;
+    if (arch && arch->GetArchitectureName())
+      arch_name = arch->GetArchitectureName();
+    else
+      arch_name = "<null>";
+
+    const char *triple_cstr =
+        arch ? arch->GetTriple().getTriple().c_str() : "<null>";
+
+    log->Printf("PlatformNetBSD::%s(force=%s, arch={%s,%s})", __FUNCTION__,
+                force ? "true" : "false", arch_name, triple_cstr);
+  }
 
   bool create = force;
   if (create == false && arch && arch->IsValid()) {
@@ -51,8 +134,19 @@ PlatformSP PlatformNetBSD::CreateInstanc
       break;
     }
   }
-  if (create)
-    return PlatformSP(new PlatformNetBSD(is_host));
+
+  if (create) {
+    if (log)
+      log->Printf("PlatformNetBSD::%s() creating remote-netbsd platform",
+                  __FUNCTION__);
+    return PlatformSP(new PlatformNetBSD(false));
+  }
+
+  if (log)
+    log->Printf(
+        "PlatformNetBSD::%s() aborting creation of remote-netbsd platform",
+        __FUNCTION__);
+
   return PlatformSP();
 }
 
@@ -66,211 +160,51 @@ ConstString PlatformNetBSD::GetPluginNam
   }
 }
 
-const char *PlatformNetBSD::GetDescriptionStatic(bool is_host) {
+const char *PlatformNetBSD::GetPluginDescriptionStatic(bool is_host) {
   if (is_host)
     return "Local NetBSD user platform plug-in.";
   else
     return "Remote NetBSD user platform plug-in.";
 }
 
-static uint32_t g_initialize_count = 0;
+ConstString PlatformNetBSD::GetPluginName() {
+  return GetPluginNameStatic(IsHost());
+}
 
 void PlatformNetBSD::Initialize() {
-  Platform::Initialize();
+  PlatformPOSIX::Initialize();
 
   if (g_initialize_count++ == 0) {
 #if defined(__NetBSD__)
-    // Force a host flag to true for the default platform object.
     PlatformSP default_platform_sp(new PlatformNetBSD(true));
     default_platform_sp->SetSystemArchitecture(HostInfo::GetArchitecture());
     Platform::SetHostPlatform(default_platform_sp);
 #endif
-    PluginManager::RegisterPlugin(PlatformNetBSD::GetPluginNameStatic(false),
-                                  PlatformNetBSD::GetDescriptionStatic(false),
-                                  PlatformNetBSD::CreateInstance);
+    PluginManager::RegisterPlugin(
+        PlatformNetBSD::GetPluginNameStatic(false),
+        PlatformNetBSD::GetPluginDescriptionStatic(false),
+        PlatformNetBSD::CreateInstance, PlatformNetBSD::DebuggerInitialize);
   }
 }
 
 void PlatformNetBSD::Terminate() {
-  if (g_initialize_count > 0 && --g_initialize_count == 0)
-    PluginManager::UnregisterPlugin(PlatformNetBSD::CreateInstance);
-
-  Platform::Terminate();
-}
-
-bool PlatformNetBSD::GetModuleSpec(const FileSpec &module_file_spec,
-                                   const ArchSpec &arch,
-                                   ModuleSpec &module_spec) {
-  if (m_remote_platform_sp)
-    return m_remote_platform_sp->GetModuleSpec(module_file_spec, arch,
-                                               module_spec);
-
-  return Platform::GetModuleSpec(module_file_spec, arch, module_spec);
-}
-
-Error PlatformNetBSD::RunShellCommand(const char *command,
-                                      const FileSpec &working_dir,
-                                      int *status_ptr, int *signo_ptr,
-                                      std::string *command_output,
-                                      uint32_t timeout_sec) {
-  if (IsHost())
-    return Host::RunShellCommand(command, working_dir, status_ptr, signo_ptr,
-                                 command_output, timeout_sec);
-  else {
-    if (m_remote_platform_sp)
-      return m_remote_platform_sp->RunShellCommand(command, working_dir,
-                                                   status_ptr, signo_ptr,
-                                                   command_output, timeout_sec);
-    else
-      return Error("unable to run a remote command without a platform");
+  if (g_initialize_count > 0) {
+    if (--g_initialize_count == 0) {
+      PluginManager::UnregisterPlugin(PlatformNetBSD::CreateInstance);
+    }
   }
+
+  PlatformPOSIX::Terminate();
 }
 
 //------------------------------------------------------------------
 /// Default Constructor
 //------------------------------------------------------------------
 PlatformNetBSD::PlatformNetBSD(bool is_host)
-    : Platform(is_host), m_remote_platform_sp() {}
-
-bool PlatformNetBSD::GetRemoteOSVersion() {
-  if (m_remote_platform_sp)
-    return m_remote_platform_sp->GetOSVersion(
-        m_major_os_version, m_minor_os_version, m_update_os_version);
-  return false;
-}
-
-bool PlatformNetBSD::GetRemoteOSBuildString(std::string &s) {
-  if (m_remote_platform_sp)
-    return m_remote_platform_sp->GetRemoteOSBuildString(s);
-  s.clear();
-  return false;
-}
-
-bool PlatformNetBSD::GetRemoteOSKernelDescription(std::string &s) {
-  if (m_remote_platform_sp)
-    return m_remote_platform_sp->GetRemoteOSKernelDescription(s);
-  s.clear();
-  return false;
-}
-
-// Remote Platform subclasses need to override this function
-ArchSpec PlatformNetBSD::GetRemoteSystemArchitecture() {
-  if (m_remote_platform_sp)
-    return m_remote_platform_sp->GetRemoteSystemArchitecture();
-  return ArchSpec();
-}
-
-const char *PlatformNetBSD::GetHostname() {
-  if (IsHost())
-    return Platform::GetHostname();
-
-  if (m_remote_platform_sp)
-    return m_remote_platform_sp->GetHostname();
-  return NULL;
-}
-
-bool PlatformNetBSD::IsConnected() const {
-  if (IsHost())
-    return true;
-  else if (m_remote_platform_sp)
-    return m_remote_platform_sp->IsConnected();
-  return false;
-}
-
-Error PlatformNetBSD::ConnectRemote(Args &args) {
-  Error error;
-  if (IsHost()) {
-    error.SetErrorStringWithFormat(
-        "can't connect to the host platform '%s', always connected",
-        GetPluginName().GetCString());
-  } else {
-    if (!m_remote_platform_sp)
-      m_remote_platform_sp =
-          Platform::Create(ConstString("remote-gdb-server"), error);
-
-    if (m_remote_platform_sp) {
-      if (error.Success()) {
-        if (m_remote_platform_sp) {
-          error = m_remote_platform_sp->ConnectRemote(args);
-        } else {
-          error.SetErrorString(
-              "\"platform connect\" takes a single argument: <connect-url>");
-        }
-      }
-    } else
-      error.SetErrorString("failed to create a 'remote-gdb-server' platform");
-
-    if (error.Fail())
-      m_remote_platform_sp.reset();
-  }
-
-  return error;
-}
+    : PlatformPOSIX(is_host) // This is the local host platform
+{}
 
-Error PlatformNetBSD::DisconnectRemote() {
-  Error error;
-
-  if (IsHost()) {
-    error.SetErrorStringWithFormat(
-        "can't disconnect from the host platform '%s', always connected",
-        GetPluginName().GetCString());
-  } else {
-    if (m_remote_platform_sp)
-      error = m_remote_platform_sp->DisconnectRemote();
-    else
-      error.SetErrorString("the platform is not currently connected");
-  }
-  return error;
-}
-
-const char *PlatformNetBSD::GetUserName(uint32_t uid) {
-  // Check the cache in Platform in case we have already looked this uid up
-  const char *user_name = Platform::GetUserName(uid);
-  if (user_name)
-    return user_name;
-
-  if (IsRemote() && m_remote_platform_sp)
-    return m_remote_platform_sp->GetUserName(uid);
-  return NULL;
-}
-
-const char *PlatformNetBSD::GetGroupName(uint32_t gid) {
-  const char *group_name = Platform::GetGroupName(gid);
-  if (group_name)
-    return group_name;
-
-  if (IsRemote() && m_remote_platform_sp)
-    return m_remote_platform_sp->GetGroupName(gid);
-  return NULL;
-}
-
-Error PlatformNetBSD::GetSharedModule(
-    const ModuleSpec &module_spec, Process *process, ModuleSP &module_sp,
-    const FileSpecList *module_search_paths_ptr, ModuleSP *old_module_sp_ptr,
-    bool *did_create_ptr) {
-  Error error;
-  module_sp.reset();
-
-  if (IsRemote()) {
-    // If we have a remote platform always, let it try and locate
-    // the shared module first.
-    if (m_remote_platform_sp) {
-      error = m_remote_platform_sp->GetSharedModule(
-          module_spec, process, module_sp, module_search_paths_ptr,
-          old_module_sp_ptr, did_create_ptr);
-    }
-  }
-
-  if (!module_sp) {
-    // Fall back to the local platform and find the file locally
-    error = Platform::GetSharedModule(module_spec, process, module_sp,
-                                      module_search_paths_ptr,
-                                      old_module_sp_ptr, did_create_ptr);
-  }
-  if (module_sp)
-    module_sp->SetPlatformFileSpec(module_spec.GetFileSpec());
-  return error;
-}
+PlatformNetBSD::~PlatformNetBSD() = default;
 
 bool PlatformNetBSD::GetSupportedArchitectureAtIndex(uint32_t idx,
                                                      ArchSpec &arch) {
@@ -323,79 +257,239 @@ bool PlatformNetBSD::GetSupportedArchite
 }
 
 void PlatformNetBSD::GetStatus(Stream &strm) {
+  Platform::GetStatus(strm);
+
 #ifndef LLDB_DISABLE_POSIX
-  struct ::utsname un;
+  // Display local kernel information only when we are running in host mode.
+  // Otherwise, we would end up printing non-NetBSD information (when running
+  // on Mac OS for example).
+  if (IsHost()) {
+    struct utsname un;
 
-  strm << "      Host: ";
+    if (uname(&un))
+      return;
 
-  ::memset(&un, 0, sizeof(utsname));
-  if (::uname(&un) == -1) {
-    strm << "NetBSD" << '\n';
-  } else {
-    strm << un.sysname << ' ' << un.release;
-    if (un.nodename[0] != '\0')
-      strm << " (" << un.nodename << ')';
-    strm << '\n';
-
-    // Dump a common information about the platform status.
-    strm << "Host: " << un.sysname << ' ' << un.release << ' ' << un.version
-         << '\n';
+    strm.Printf("    Kernel: %s\n", un.sysname);
+    strm.Printf("   Release: %s\n", un.release);
+    strm.Printf("   Version: %s\n", un.version);
   }
 #endif
-
-  Platform::GetStatus(strm);
 }
 
-void PlatformNetBSD::CalculateTrapHandlerSymbolNames() {
-  m_trap_handlers.push_back(ConstString("_sigtramp"));
+int32_t
+PlatformNetBSD::GetResumeCountForLaunchInfo(ProcessLaunchInfo &launch_info) {
+  int32_t resume_count = 0;
+
+  // Always resume past the initial stop when we use eLaunchFlagDebug
+  if (launch_info.GetFlags().Test(eLaunchFlagDebug)) {
+    // Resume past the stop for the final exec into the true inferior.
+    ++resume_count;
+  }
+
+  // If we're not launching a shell, we're done.
+  const FileSpec &shell = launch_info.GetShell();
+  if (!shell)
+    return resume_count;
+
+  std::string shell_string = shell.GetPath();
+  // We're in a shell, so for sure we have to resume past the shell exec.
+  ++resume_count;
+
+  // Figure out what shell we're planning on using.
+  const char *shell_name = strrchr(shell_string.c_str(), '/');
+  if (shell_name == NULL)
+    shell_name = shell_string.c_str();
+  else
+    shell_name++;
+
+  if (strcmp(shell_name, "csh") == 0 || strcmp(shell_name, "tcsh") == 0 ||
+      strcmp(shell_name, "zsh") == 0 || strcmp(shell_name, "sh") == 0) {
+    // These shells seem to re-exec themselves.  Add another resume.
+    ++resume_count;
+  }
+
+  return resume_count;
 }
 
-Error PlatformNetBSD::LaunchProcess(ProcessLaunchInfo &launch_info) {
-  Error error;
+bool PlatformNetBSD::CanDebugProcess() {
   if (IsHost()) {
-    error = Platform::LaunchProcess(launch_info);
+    return true;
   } else {
-    if (m_remote_platform_sp)
-      error = m_remote_platform_sp->LaunchProcess(launch_info);
-    else
-      error.SetErrorString("the platform is not currently connected");
+    // If we're connected, we can debug.
+    return IsConnected();
   }
-  return error;
 }
 
-lldb::ProcessSP PlatformNetBSD::Attach(ProcessAttachInfo &attach_info,
-                                       Debugger &debugger, Target *target,
-                                       Error &error) {
-  lldb::ProcessSP process_sp;
-  if (IsHost()) {
-    if (target == NULL) {
-      TargetSP new_target_sp;
-      ArchSpec emptyArchSpec;
-
-      error = debugger.GetTargetList().CreateTarget(debugger, "", emptyArchSpec,
-                                                    false, m_remote_platform_sp,
-                                                    new_target_sp);
-      target = new_target_sp.get();
-    } else
-      error.Clear();
-
-    if (target && error.Success()) {
-      debugger.GetTargetList().SetSelectedTarget(target);
-      // The netbsd always currently uses the GDB remote debugger plug-in
-      // so even when debugging locally we are debugging remotely!
-      // Just like the darwin plugin.
-      process_sp = target->CreateProcess(
-          attach_info.GetListenerForProcess(debugger), "gdb-remote", NULL);
+// For local debugging, NetBSD will override the debug logic to use llgs-launch
+// rather than
+// lldb-launch, llgs-attach.  This differs from current lldb-launch,
+// debugserver-attach
+// approach on MacOSX.
+lldb::ProcessSP
+PlatformNetBSD::DebugProcess(ProcessLaunchInfo &launch_info, Debugger &debugger,
+                            Target *target, // Can be NULL, if NULL create a new
+                                            // target, else use existing one
+                            Error &error) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PLATFORM));
+  if (log)
+    log->Printf("PlatformNetBSD::%s entered (target %p)", __FUNCTION__,
+                static_cast<void *>(target));
+
+  // If we're a remote host, use standard behavior from parent class.
+  if (!IsHost())
+    return PlatformPOSIX::DebugProcess(launch_info, debugger, target, error);
+
+  //
+  // For local debugging, we'll insist on having ProcessGDBRemote create the
+  // process.
+  //
+
+  ProcessSP process_sp;
+
+  // Make sure we stop at the entry point
+  launch_info.GetFlags().Set(eLaunchFlagDebug);
+
+  // We always launch the process we are going to debug in a separate process
+  // group, since then we can handle ^C interrupts ourselves w/o having to worry
+  // about the target getting them as well.
+  launch_info.SetLaunchInSeparateProcessGroup(true);
+
+  // Ensure we have a target.
+  if (target == nullptr) {
+    if (log)
+      log->Printf("PlatformNetBSD::%s creating new target", __FUNCTION__);
+
+    TargetSP new_target_sp;
+    error = debugger.GetTargetList().CreateTarget(debugger, "", "", false,
+                                                  nullptr, new_target_sp);
+    if (error.Fail()) {
+      if (log)
+        log->Printf("PlatformNetBSD::%s failed to create new target: %s",
+                    __FUNCTION__, error.AsCString());
+      return process_sp;
+    }
 
-      if (process_sp)
-        error = process_sp->Attach(attach_info);
+    target = new_target_sp.get();
+    if (!target) {
+      error.SetErrorString("CreateTarget() returned nullptr");
+      if (log)
+        log->Printf("PlatformNetBSD::%s failed: %s", __FUNCTION__,
+                    error.AsCString());
+      return process_sp;
     }
   } else {
-    if (m_remote_platform_sp)
-      process_sp =
-          m_remote_platform_sp->Attach(attach_info, debugger, target, error);
-    else
-      error.SetErrorString("the platform is not currently connected");
+    if (log)
+      log->Printf("PlatformNetBSD::%s using provided target", __FUNCTION__);
+  }
+
+  // Mark target as currently selected target.
+  debugger.GetTargetList().SetSelectedTarget(target);
+
+  // Now create the gdb-remote process.
+  if (log)
+    log->Printf(
+        "PlatformNetBSD::%s having target create process with gdb-remote plugin",
+        __FUNCTION__);
+  process_sp = target->CreateProcess(
+      launch_info.GetListenerForProcess(debugger), "gdb-remote", nullptr);
+
+  if (!process_sp) {
+    error.SetErrorString("CreateProcess() failed for gdb-remote process");
+    if (log)
+      log->Printf("PlatformNetBSD::%s failed: %s", __FUNCTION__,
+                  error.AsCString());
+    return process_sp;
+  } else {
+    if (log)
+      log->Printf("PlatformNetBSD::%s successfully created process",
+                  __FUNCTION__);
+  }
+
+  // Adjust launch for a hijacker.
+  ListenerSP listener_sp;
+  if (!launch_info.GetHijackListener()) {
+    if (log)
+      log->Printf("PlatformNetBSD::%s setting up hijacker", __FUNCTION__);
+
+    listener_sp =
+        Listener::MakeListener("lldb.PlatformNetBSD.DebugProcess.hijack");
+    launch_info.SetHijackListener(listener_sp);
+    process_sp->HijackProcessEvents(listener_sp);
+  }
+
+  // Log file actions.
+  if (log) {
+    log->Printf(
+        "PlatformNetBSD::%s launching process with the following file actions:",
+        __FUNCTION__);
+
+    StreamString stream;
+    size_t i = 0;
+    const FileAction *file_action;
+    while ((file_action = launch_info.GetFileActionAtIndex(i++)) != nullptr) {
+      file_action->Dump(stream);
+      log->PutCString(stream.GetData());
+      stream.Clear();
+    }
+  }
+
+  // Do the launch.
+  error = process_sp->Launch(launch_info);
+  if (error.Success()) {
+    // Handle the hijacking of process events.
+    if (listener_sp) {
+      const StateType state = process_sp->WaitForProcessToStop(
+          llvm::None, NULL, false, listener_sp);
+
+      if (state == eStateStopped) {
+        if (log)
+          log->Printf("PlatformNetBSD::%s pid %" PRIu64 " state %s\n",
+                      __FUNCTION__, process_sp->GetID(), StateAsCString(state));
+      } else {
+        if (log)
+          log->Printf("PlatformNetBSD::%s pid %" PRIu64
+                      " state is not stopped - %s\n",
+                      __FUNCTION__, process_sp->GetID(), StateAsCString(state));
+      }
+    }
+
+    // Hook up process PTY if we have one (which we should for local debugging
+    // with llgs).
+    int pty_fd = launch_info.GetPTY().ReleaseMasterFileDescriptor();
+    if (pty_fd != lldb_utility::PseudoTerminal::invalid_fd) {
+      process_sp->SetSTDIOFileDescriptor(pty_fd);
+      if (log)
+        log->Printf("PlatformNetBSD::%s pid %" PRIu64
+                    " hooked up STDIO pty to process",
+                    __FUNCTION__, process_sp->GetID());
+    } else {
+      if (log)
+        log->Printf("PlatformNetBSD::%s pid %" PRIu64
+                    " not using process STDIO pty",
+                    __FUNCTION__, process_sp->GetID());
+    }
+  } else {
+    if (log)
+      log->Printf("PlatformNetBSD::%s process launch failed: %s", __FUNCTION__,
+                  error.AsCString());
+    // FIXME figure out appropriate cleanup here.  Do we delete the target? Do
+    // we delete the process?  Does our caller do that?
   }
+
   return process_sp;
 }
+
+void PlatformNetBSD::CalculateTrapHandlerSymbolNames() {
+  m_trap_handlers.push_back(ConstString("_sigtramp"));
+}
+
+uint64_t PlatformNetBSD::ConvertMmapFlagsToPlatform(const ArchSpec &arch,
+                                                   unsigned flags) {
+  uint64_t flags_platform = 0;
+
+  if (flags & eMmapFlagsPrivate)
+    flags_platform |= MAP_PRIVATE;
+  if (flags & eMmapFlagsAnon)
+    flags_platform |= MAP_ANON;
+  return flags_platform;
+}
