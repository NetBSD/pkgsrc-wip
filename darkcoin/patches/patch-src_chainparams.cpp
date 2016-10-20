$NetBSD$

--- src/chainparams.cpp.orig	2015-09-28 15:49:30.000000000 +0000
+++ src/chainparams.cpp
@@ -165,12 +165,12 @@ public:
         vSeeds.push_back(CDNSSeedData("masternode.io", "dnsseed.masternode.io"));
         vSeeds.push_back(CDNSSeedData("dashpay.io", "dnsseed.dashpay.io"));
 
-        base58Prefixes[PUBKEY_ADDRESS] = list_of( 76);                    // Dash addresses start with 'X'
-        base58Prefixes[SCRIPT_ADDRESS] = list_of( 16);                    // Dash script addresses start with '7'
-        base58Prefixes[SECRET_KEY] =     list_of(204);                    // Dash private keys start with '7' or 'X'
-        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x02)(0xFE)(0x52)(0xF8); // Dash BIP32 pubkeys start with 'drkv'
-        base58Prefixes[EXT_SECRET_KEY] = list_of(0x02)(0xFE)(0x52)(0xCC); // Dash BIP32 prvkeys start with 'drkp'
-        base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000005);             // Dash BIP44 coin type is '5'
+        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 76);                    // Dash addresses start with 'X'
+        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 16);                    // Dash script addresses start with '7'
+        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 204);                    // Dash private keys start with '7' or 'X'
+        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0xFE)(0x52)(0xF8).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0xFE)(0x52)(0xCC).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80000005).convert_to_container<std::vector<unsigned char> >();
 
         convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
 
@@ -234,12 +234,12 @@ public:
         vSeeds.push_back(CDNSSeedData("darkcoin.qa", "testnet-seed.darkcoin.qa"));
         vSeeds.push_back(CDNSSeedData("masternode.io", "test.dnsseed.masternode.io"));
 
-        base58Prefixes[PUBKEY_ADDRESS] = list_of(139);                    // Testnet dash addresses start with 'x' or 'y'
-        base58Prefixes[SCRIPT_ADDRESS] = list_of( 19);                    // Testnet dash script addresses start with '8' or '9'
-        base58Prefixes[SECRET_KEY]     = list_of(239);                    // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
-        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x3a)(0x80)(0x61)(0xa0); // Testnet dash BIP32 pubkeys start with 'DRKV'
-        base58Prefixes[EXT_SECRET_KEY] = list_of(0x3a)(0x80)(0x58)(0x37); // Testnet dash BIP32 prvkeys start with 'DRKP'
-        base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000001);             // Testnet dash BIP44 coin type is '5' (All coin's testnet default)
+        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139);                    // Testnet dash addresses start with 'x' or 'y'
+        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);                    // Testnet dash script addresses start with '8' or '9'
+        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);                  // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
+        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80000001).convert_to_container<std::vector<unsigned char> >();
 
         convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
 
