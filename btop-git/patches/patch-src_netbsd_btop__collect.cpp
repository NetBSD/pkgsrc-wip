$NetBSD$

Cache UID->username mappings to reduce getpwuid() calls.

getpwuid() uses an internal libc mutex and is NOT a POSIX cancellation point.
When the Runner thread stalls and pthread_cancel is called, the thread may
be blocked inside getpwuid() waiting for the mutex. Since it's not a
cancellation point, the thread cannot be cancelled cleanly.

By caching the UID->username mappings, we minimize the number of getpwuid()
calls, reducing the window where the thread can get stuck in a non-cancellable
state.

--- src/netbsd/btop_collect.cpp.orig	2026-07-06 07:53:49.000000000 +0000
+++ src/netbsd/btop_collect.cpp
@@ -1091,7 +1091,7 @@ namespace Net {
 namespace Proc {
 
 	vector<proc_info> current_procs;
-	std::unordered_map<string, string> uid_user;
+	std::unordered_map<uid_t, string> uid_user;
 	string current_sort;
 	string current_filter;
 	bool current_rev = false;
@@ -1248,9 +1248,22 @@ namespace Proc {
 					}
 					new_proc.ppid = kproc->p_ppid;
 					new_proc.cpu_s = round(kproc->p_ustart_sec);
-					struct passwd *pwd = getpwuid(kproc->p_uid);
-					if (pwd)
-						new_proc.user = pwd->pw_name;
+					//? Cache UID->username to avoid repeated getpwuid() calls
+					//? getpwuid() holds an internal libc mutex and is NOT a cancellation point,
+					//? so pthread_cancel during getpwuid() causes the Runner thread to stall
+					auto uid = kproc->p_uid;
+					if (auto it = uid_user.find(uid); it != uid_user.end()) {
+						new_proc.user = it->second;
+					} else {
+						struct passwd *pwd = getpwuid(uid);
+						if (pwd) {
+							uid_user[uid] = pwd->pw_name;
+							new_proc.user = pwd->pw_name;
+						} else {
+							uid_user[uid] = std::to_string(uid);
+							new_proc.user = uid_user[uid];
+						}
+					}
 				}
 				new_proc.p_nice = kproc->p_nice;
 				new_proc.state = kproc->p_stat;
