$NetBSD: patch-src_api.cpp,v 1.5 2014/08/15 20:22:16 thomasklausner Exp $

Revert upstream diff to switch to regex, causes coredumps on NetBSD.

--- src/api.cpp.orig	2014-08-13 06:21:35.000000000 +0000
+++ src/api.cpp
@@ -9,7 +9,6 @@
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
-#include <regex>
 #include <jsoncpp/json/json.h>
 
 size_t writeMemoryCallback(char *ptr, size_t size, size_t nmemb, void *userp) {
@@ -286,7 +285,6 @@ gameDetails API::getGameDetails(const st
             game.gamename = game_name;
             game.title = root["game"]["title"].asString();
             game.icon = root["game"]["icon"].asString();
-            std::vector<std::string> membernames = root["game"].getMemberNames();
 
             // Installer details
             // Create a list of installers from JSON
@@ -367,24 +365,32 @@ gameDetails API::getGameDetails(const st
                 if (lang & GlobalConstants::LANGUAGES[i].languageId)
                 {
                     // Try to find a patch
-                    std::regex re(GlobalConstants::LANGUAGES[i].languageCode + "\\d+patch\\d+", std::regex_constants::icase); // regex for patch node names
+                    unsigned int patch_number = 0;
+                    const unsigned int maxTriesLangNum = 8;
+                    const unsigned int maxTriesPatchNum = 20;
                     std::vector<std::string> patchnames;
-                    for (unsigned int j = 0; j < membernames.size(); ++j)
+                    while (patch_number < maxTriesLangNum)
                     {
-                        if (std::regex_match(membernames[j], re))
-                        {   // Regex matches, we have a patch node
-                            std::string patchname = membernames[j];
-                            unsigned int platformId;
-                            if (root["game"][patchname]["link"].asString().find("/mac/") != std::string::npos)
-                                platformId = GlobalConstants::PLATFORM_MAC;
-                            else if (root["game"][patchname]["link"].asString().find("/linux/") != std::string::npos)
-                                platformId = GlobalConstants::PLATFORM_LINUX;
-                            else
-                                platformId = GlobalConstants::PLATFORM_WINDOWS;
+                        unsigned int patch_number_file = 0;
+                        while (patch_number_file < maxTriesPatchNum)
+                        {
+                            std::string patchname = GlobalConstants::LANGUAGES[i].languageCode + std::to_string(patch_number) + "patch" + std::to_string(patch_number_file);
+                            if (root["game"].isMember(patchname)) // Check that patch node exists
+                            {
+                                unsigned int platformId;
+                                if (root["game"][patchname]["link"].asString().find("/mac/") != std::string::npos)
+                                    platformId = GlobalConstants::PLATFORM_MAC;
+                                else if (root["game"][patchname]["link"].asString().find("/linux/") != std::string::npos)
+                                    platformId = GlobalConstants::PLATFORM_LINUX;
+                                else
+                                    platformId = GlobalConstants::PLATFORM_WINDOWS;
 
-                            if (type & platformId)
-                                patchnames.push_back(patchname);
+                                if (type & platformId)
+                                    patchnames.push_back(patchname);
+                            }
+                            patch_number_file++;
                         }
+                        patch_number++;
                     }
 
                     if (!patchnames.empty()) // found at least one patch
@@ -498,12 +504,20 @@ gameDetails API::getGameDetails(const st
                 if (lang & GlobalConstants::LANGUAGES[i].languageId)
                 {
                     // Try to find a language pack
-                    std::regex re(GlobalConstants::LANGUAGES[i].languageCode + "\\d+langpack\\d+", std::regex_constants::icase); // regex for language pack node names
+                    unsigned int lang_pack_number = 0;
+                    const unsigned int maxTries = 4;
                     std::vector<std::string> langpacknames;
-                    for (unsigned int j = 0; j < membernames.size(); ++j)
+                    while (lang_pack_number < maxTries)
                     {
-                        if (std::regex_match(membernames[j], re))
-                            langpacknames.push_back(membernames[j]);
+                        unsigned int lang_pack_number_file = 0;
+                        while (lang_pack_number_file < maxTries)
+                        {
+                            std::string langpackname = GlobalConstants::LANGUAGES[i].languageCode + std::to_string(lang_pack_number) + "langpack" + std::to_string(lang_pack_number_file);
+                            if (root["game"].isMember(langpackname)) // Check that language pack node exists
+                                langpacknames.push_back(langpackname);
+                            lang_pack_number_file++;
+                        }
+                        lang_pack_number++;
                     }
 
                     if (!langpacknames.empty()) // found at least one language pack
