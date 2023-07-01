$NetBSD$

Deal with the fact that, on NetBSD, the s_addr field of a struct sockaddr_in
is packed. 

--- Core/HLE/proAdhoc.cpp.orig	2023-06-29 00:33:37.275915356 -0700
+++ Core/HLE/proAdhoc.cpp	2023-06-29 00:33:30.317029940 -0700
@@ -1894,15 +1894,15 @@
 	ip_ranges.reserve(5);
 
 	if (1 == inet_pton(AF_INET, "192.168.0.0", &(saNet.sin_addr)) && 1 == inet_pton(AF_INET, "255.255.0.0", &(saMask.sin_addr)))
-		ip_ranges.push_back({saNet.sin_addr.s_addr, saMask.sin_addr.s_addr});
+		ip_ranges.push_back({(uint32_t)saNet.sin_addr.s_addr, (uint32_t)saMask.sin_addr.s_addr});
 	if (1 == inet_pton(AF_INET, "172.16.0.0", &(saNet.sin_addr)) && 1 == inet_pton(AF_INET, "255.240.0.0", &(saMask.sin_addr)))
-		ip_ranges.push_back({ saNet.sin_addr.s_addr, saMask.sin_addr.s_addr });
+		ip_ranges.push_back({ (uint32_t)saNet.sin_addr.s_addr, (uint32_t)saMask.sin_addr.s_addr });
 	if (1 == inet_pton(AF_INET, "10.0.0.0", &(saNet.sin_addr)) && 1 == inet_pton(AF_INET, "255.0.0.0", &(saMask.sin_addr)))
-		ip_ranges.push_back({ saNet.sin_addr.s_addr, saMask.sin_addr.s_addr });
+		ip_ranges.push_back({ (uint32_t)saNet.sin_addr.s_addr, (uint32_t)saMask.sin_addr.s_addr });
 	if (1 == inet_pton(AF_INET, "127.0.0.0", &(saNet.sin_addr)) && 1 == inet_pton(AF_INET, "255.0.0.0", &(saMask.sin_addr)))
-		ip_ranges.push_back({ saNet.sin_addr.s_addr, saMask.sin_addr.s_addr });
+		ip_ranges.push_back({ (uint32_t)saNet.sin_addr.s_addr, (uint32_t)saMask.sin_addr.s_addr });
 	if (1 == inet_pton(AF_INET, "169.254.0.0", &(saNet.sin_addr)) && 1 == inet_pton(AF_INET, "255.255.0.0", &(saMask.sin_addr)))
-		ip_ranges.push_back({ saNet.sin_addr.s_addr, saMask.sin_addr.s_addr });
+		ip_ranges.push_back({ (uint32_t)saNet.sin_addr.s_addr, (uint32_t)saMask.sin_addr.s_addr });
 
 	return ip_ranges;
 }
