$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/process_singleton_posix.cc.orig	2024-10-18 12:34:01.889084000 +0000
+++ chrome/browser/process_singleton_posix.cc
@@ -54,6 +54,7 @@
 #include <memory>
 #include <set>
 #include <string>
+#include <tuple>
 #include <type_traits>
 
 #include "base/base_paths.h"
@@ -81,6 +82,7 @@
 #include "base/strings/utf_string_conversions.h"
 #include "base/task/sequenced_task_runner_helpers.h"
 #include "base/task/single_thread_task_runner.h"
+#include "base/threading/thread_restrictions.h"
 #include "base/threading/platform_thread.h"
 #include "base/time/time.h"
 #include "base/timer/timer.h"
@@ -97,7 +99,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/resource/scoped_startup_resource_bundle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if 0
 #include "chrome/browser/ui/process_singleton_dialog_linux.h"
 #endif
 
@@ -343,6 +345,8 @@ bool SymlinkPath(const base::FilePath& t
 bool DisplayProfileInUseError(const base::FilePath& lock_path,
                               const std::string& hostname,
                               int pid) {
+  return true;
+#if 0
   // Ensure there is an instance of ResourceBundle that is initialized for
   // localized string resource accesses.
   ui::ScopedStartupResourceBundle ensure_startup_resource_bundle;
@@ -355,7 +359,7 @@ bool DisplayProfileInUseError(const base
   if (g_disable_prompt)
     return g_user_opted_unlock_in_use_profile;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::u16string relaunch_button_text =
       l10n_util::GetStringUTF16(IDS_PROFILE_IN_USE_LINUX_RELAUNCH);
   return ShowProcessSingletonDialog(error, relaunch_button_text);
@@ -366,6 +370,7 @@ bool DisplayProfileInUseError(const base
 
   NOTREACHED_IN_MIGRATION();
   return false;
+#endif
 }
 
 bool IsChromeProcess(pid_t pid) {
@@ -378,6 +383,21 @@ bool IsChromeProcess(pid_t pid) {
               base::FilePath(chrome::kBrowserProcessExecutableName));
 }
 
+bool IsAppSandboxed() {
+#if BUILDFLAG(IS_MAC)
+  // NB: There is no sane API for this, we have to just guess by
+  // reading tea leaves
+  base::FilePath home_dir;
+  if (!base::PathService::Get(base::DIR_HOME, &home_dir)) {
+    return false;
+  }
+
+  return home_dir.value().find("Library/Containers") != std::string::npos;
+#else
+  return false;
+#endif  // BUILDFLAG(IS_MAC)
+}
+
 // A helper class to hold onto a socket.
 class ScopedSocket {
  public:
@@ -590,6 +610,7 @@ class ProcessSingleton::LinuxWatcher
   // |reader| is for sending back ACK message.
   void HandleMessage(const std::string& current_dir,
                      const std::vector<std::string>& argv,
+                     const std::vector<uint8_t> additional_data,
                      SocketReader* reader);
 
   // Called when the ProcessSingleton that owns this class is about to be
@@ -649,13 +670,17 @@ void ProcessSingleton::LinuxWatcher::Sta
 }
 
 void ProcessSingleton::LinuxWatcher::HandleMessage(
-    const std::string& current_dir, const std::vector<std::string>& argv,
+    const std::string& current_dir,
+    const std::vector<std::string>& argv,
+    const std::vector<uint8_t> additional_data,
     SocketReader* reader) {
   DCHECK(ui_task_runner_->BelongsToCurrentThread());
   DCHECK(reader);
 
   if (parent_ && parent_->notification_callback_.Run(
-                     base::CommandLine(argv), base::FilePath(current_dir))) {
+                     base::CommandLine(argv),
+                     base::FilePath(current_dir),
+                     std::move(additional_data))) {
     // Send back "ACK" message to prevent the client process from starting up.
     reader->FinishWithACK(kACKToken, std::size(kACKToken) - 1);
   } else {
@@ -703,7 +728,8 @@ void ProcessSingleton::LinuxWatcher::Soc
     }
   }
 
-  // Validate the message.  The shortest message is kStartToken\0x\0x
+  // Validate the message.  The shortest message kStartToken\0\00
+  // The shortest message with additional data is kStartToken\0\00\00\0.
   const size_t kMinMessageLength = std::size(kStartToken) + 4;
   if (bytes_read_ < kMinMessageLength) {
     buf_[bytes_read_] = 0;
@@ -733,10 +759,28 @@ void ProcessSingleton::LinuxWatcher::Soc
   tokens.erase(tokens.begin());
   tokens.erase(tokens.begin());
 
+  size_t num_args;
+  base::StringToSizeT(tokens[0], &num_args);
+  std::vector<std::string> command_line(tokens.begin() + 1, tokens.begin() + 1 + num_args);
+
+  std::vector<uint8_t> additional_data;
+  if (tokens.size() >= 3 + num_args) {
+    size_t additional_data_size;
+    base::StringToSizeT(tokens[1 + num_args], &additional_data_size);
+    std::string remaining_args = base::JoinString(
+        base::make_span(tokens.begin() + 2 + num_args, tokens.end()),
+        std::string(1, kTokenDelimiter));
+    const uint8_t* additional_data_bits =
+        reinterpret_cast<const uint8_t*>(remaining_args.c_str());
+    additional_data = std::vector<uint8_t>(
+        additional_data_bits, additional_data_bits + additional_data_size);
+  }
+
   // Return to the UI thread to handle opening a new browser tab.
   ui_task_runner_->PostTask(
       FROM_HERE, base::BindOnce(&ProcessSingleton::LinuxWatcher::HandleMessage,
-                                parent_, current_dir, tokens, this));
+                                parent_, current_dir, command_line,
+                                std::move(additional_data), this));
   fd_watch_controller_.reset();
 
   // LinuxWatcher::HandleMessage() is in charge of destroying this SocketReader
@@ -765,8 +809,10 @@ void ProcessSingleton::LinuxWatcher::Soc
 //
 ProcessSingleton::ProcessSingleton(
     const base::FilePath& user_data_dir,
+    const base::span<const uint8_t> additional_data,
     const NotificationCallback& notification_callback)
     : notification_callback_(notification_callback),
+      additional_data_(additional_data),
       current_pid_(base::GetCurrentProcId()) {
   socket_path_ = user_data_dir.Append(chrome::kSingletonSocketFilename);
   lock_path_ = user_data_dir.Append(chrome::kSingletonLockFilename);
@@ -781,6 +827,10 @@ ProcessSingleton::~ProcessSingleton() {
   if (watcher_) {
     watcher_->OnEminentProcessSingletonDestruction();
   }
+  // Manually free resources with IO explicitly allowed.
+  base::ScopedAllowBlocking allow_blocking;
+  watcher_ = nullptr;
+  std::ignore = socket_dir_.Delete();
 }
 
 ProcessSingleton::NotifyResult ProcessSingleton::NotifyOtherProcess() {
@@ -883,7 +933,8 @@ ProcessSingleton::NotifyResult ProcessSi
              sizeof(socket_timeout));
 
   // Found another process, prepare our command line
-  // format is "START\0<current dir>\0<argv[0]>\0...\0<argv[n]>".
+  // format is "START\0<current-dir>\0<n-args>\0<argv[0]>\0...\0<argv[n]>
+  // \0<additional-data-length>\0<additional-data>".
   std::string to_send(kStartToken);
   to_send.push_back(kTokenDelimiter);
 
@@ -893,11 +944,21 @@ ProcessSingleton::NotifyResult ProcessSi
   to_send.append(current_dir.value());
 
   const std::vector<std::string>& argv = cmd_line.argv();
+  to_send.push_back(kTokenDelimiter);
+  to_send.append(base::NumberToString(argv.size()));
   for (auto it = argv.begin(); it != argv.end(); ++it) {
     to_send.push_back(kTokenDelimiter);
     to_send.append(*it);
   }
 
+  size_t data_to_send_size = additional_data_.size_bytes();
+  if (data_to_send_size) {
+    to_send.push_back(kTokenDelimiter);
+    to_send.append(base::NumberToString(data_to_send_size));
+    to_send.push_back(kTokenDelimiter);
+    to_send.append(reinterpret_cast<const char*>(additional_data_.data()), data_to_send_size);
+  }
+
   // Send the message
   if (!WriteToSocket(socket.fd(), to_send.data(), to_send.length())) {
     // Try to kill the other process, because it might have been dead.
@@ -1048,11 +1109,32 @@ bool ProcessSingleton::Create() {
   // Create the socket file somewhere in /tmp which is usually mounted as a
   // normal filesystem. Some network filesystems (notably AFS) are screwy and
   // do not support Unix domain sockets.
-  if (!socket_dir_.CreateUniqueTempDir()) {
-    LOG(ERROR) << "Failed to create socket directory.";
+  base::FilePath tmp_dir;
+  if (!base::GetTempDir(&tmp_dir)) {
+    LOG(ERROR) << "Failed to get temporary directory.";
     return false;
   }
 
+  if (IsAppSandboxed()) {
+    // For sandboxed applications, the tmp dir could be too long to fit
+    // addr->sun_path, so we need to make it as short as possible.
+    if (!socket_dir_.Set(tmp_dir.Append("S"))) {
+      LOG(ERROR) << "Failed to set socket directory.";
+      return false;
+    }
+  } else {
+    // Create the socket file somewhere in /tmp which is usually mounted as a
+    // normal filesystem. Some network filesystems (notably AFS) are screwy and
+    // do not support Unix domain sockets.
+    // Prefer CreateUniqueTempDirUnderPath rather than CreateUniqueTempDir as
+    // the latter will calculate unique paths based on bundle ids which can
+    // increase the socket path length than what is allowed.
+    if (!socket_dir_.CreateUniqueTempDirUnderPath(tmp_dir)) {
+      LOG(ERROR) << "Failed to create socket directory.";
+      return false;
+    }
+  }
+
   // Check that the directory was created with the correct permissions.
   int dir_mode = 0;
   CHECK(base::GetPosixFilePermissions(socket_dir_.GetPath(), &dir_mode) &&
