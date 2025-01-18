$NetBSD$

Disable name prefix detection.

--- src/netbsd/btop_collect.cpp.orig	2025-01-18 21:33:07.766242345 +0000
+++ src/netbsd/btop_collect.cpp
@@ -215,23 +215,23 @@ namespace Cpu {
 
 		auto name_vec = ssplit(name);
 
-		if ((s_contains(name, "Xeon"s) or v_contains(name_vec, "Duo"s)) and v_contains(name_vec, "CPU"s)) {
-			auto cpu_pos = v_index(name_vec, "CPU"s);
-			if (cpu_pos < name_vec.size() - 1 and not name_vec.at(cpu_pos + 1).ends_with(')'))
-				name = name_vec.at(cpu_pos + 1);
-			else
-				name.clear();
-		} else if (v_contains(name_vec, "Ryzen"s)) {
-			auto ryz_pos = v_index(name_vec, "Ryzen"s);
-			name = "Ryzen" + (ryz_pos < name_vec.size() - 1 ? ' ' + name_vec.at(ryz_pos + 1) : "") + (ryz_pos < name_vec.size() - 2 ? ' ' + name_vec.at(ryz_pos + 2) : "");
-		} else if (s_contains(name, "Intel"s) and v_contains(name_vec, "CPU"s)) {
-			auto cpu_pos = v_index(name_vec, "CPU"s);
-			if (cpu_pos < name_vec.size() - 1 and not name_vec.at(cpu_pos + 1).ends_with(')') and name_vec.at(cpu_pos + 1) != "@")
-				name = name_vec.at(cpu_pos + 1);
-			else
-				name.clear();
-		} else
-			name.clear();
+//		if ((s_contains(name, "Xeon"s) or v_contains(name_vec, "Duo"s)) and v_contains(name_vec, "CPU"s)) {
+//			auto cpu_pos = v_index(name_vec, "CPU"s);
+//			if (cpu_pos < name_vec.size() - 1 and not name_vec.at(cpu_pos + 1).ends_with(')'))
+//				name = name_vec.at(cpu_pos + 1);
+//			else
+//				name.clear();
+//		} else if (v_contains(name_vec, "Ryzen"s)) {
+//			auto ryz_pos = v_index(name_vec, "Ryzen"s);
+//			name = "Ryzen" + (ryz_pos < name_vec.size() - 1 ? ' ' + name_vec.at(ryz_pos + 1) : "") + (ryz_pos < name_vec.size() - 2 ? ' ' + name_vec.at(ryz_pos + 2) : "");
+//		} else if (s_contains(name, "Intel"s) and v_contains(name_vec, "CPU"s)) {
+//			auto cpu_pos = v_index(name_vec, "CPU"s);
+//			if (cpu_pos < name_vec.size() - 1 and not name_vec.at(cpu_pos + 1).ends_with(')') and name_vec.at(cpu_pos + 1) != "@")
+//				name = name_vec.at(cpu_pos + 1);
+//			else
+//				name.clear();
+//		} else
+//			name.clear();
 
 		if (name.empty() and not name_vec.empty()) {
 			for (const auto &n : name_vec) {
