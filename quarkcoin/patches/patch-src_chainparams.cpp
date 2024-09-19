$NetBSD$

--- src/chainparams.cpp.orig	2015-05-31 10:15:00.000000000 +0000
+++ src/chainparams.cpp
@@ -78,11 +78,11 @@ public:
         vSeeds.push_back(CDNSSeedData("seed7.qrkcoin.org", "seed7.qrkcoin.org"));
         vSeeds.push_back(CDNSSeedData("seed8.qrkcoin.org", "seed8.qrkcoin.org"));
 		
-        base58Prefixes[PUBKEY_ADDRESS] = list_of(58);
-        base58Prefixes[SCRIPT_ADDRESS] = list_of(9);
-        base58Prefixes[SECRET_KEY] =     list_of(186);
-        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
-        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
+        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 58);
+        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 9);
+        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 186);
+        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
 
         // Convert the pnSeeds array into usable address objects.
         for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
@@ -140,11 +140,11 @@ public:
         vFixedSeeds.clear();
         vSeeds.clear();
 
-        base58Prefixes[PUBKEY_ADDRESS] = list_of(119);
-        base58Prefixes[SCRIPT_ADDRESS] = list_of(199);
-        base58Prefixes[SECRET_KEY]     = list_of(247);
-        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
-        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
+        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 119);
+        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 199);
+        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 247);
+        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
+        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
     }
     virtual Network NetworkID() const { return CChainParams::TESTNET; }
 };
