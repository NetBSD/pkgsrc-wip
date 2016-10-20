$NetBSD$

--- src/chainparams.cpp.orig	2015-06-15 08:51:30.000000000 +0000
+++ src/chainparams.cpp
@@ -161,11 +161,11 @@ public:
         vSeeds.push_back(CDNSSeedData("koin-project.com", "dnsseed.koin-project.com"));
         vSeeds.push_back(CDNSSeedData("weminemnc.com", "dnsseed.weminemnc.com"));
 
-        base58Prefixes[PUBKEY_ADDRESS] = list_of(48);
-        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
-        base58Prefixes[SECRET_KEY] =     list_of(176);
-        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
-        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
+        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 48);
+        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 5);
+        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 176);
+        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
 
         convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
 
@@ -222,11 +222,11 @@ public:
         vSeeds.push_back(CDNSSeedData("xurious.com", "testnet-seed.ltc.xurious.com"));
         vSeeds.push_back(CDNSSeedData("wemine-testnet.com", "dnsseed.wemine-testnet.com"));
 
-        base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
-        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
-        base58Prefixes[SECRET_KEY]     = list_of(239);
-        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
-        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
+        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 111);
+        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
+        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
+        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
 
         convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
 
