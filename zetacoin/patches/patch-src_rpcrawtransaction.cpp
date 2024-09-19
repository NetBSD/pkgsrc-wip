$NetBSD$

--- src/rpcrawtransaction.cpp.orig	2015-03-24 01:40:33.000000000 +0000
+++ src/rpcrawtransaction.cpp
@@ -296,7 +296,7 @@ Value listunspent(const Array& params, b
             CTxDestination address;
             if (ExtractDestination(pk, address))
             {
-                const CScriptID& hash = boost::get<const CScriptID&>(address);
+                const CScriptID& hash = boost::get<CScriptID>(address);
                 CScript redeemScript;
                 if (pwalletMain->GetCScript(hash, redeemScript))
                     entry.push_back(Pair("redeemScript", HexStr(redeemScript.begin(), redeemScript.end())));
