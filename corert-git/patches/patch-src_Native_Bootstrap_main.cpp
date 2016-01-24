$NetBSD$

--- src/Native/Bootstrap/main.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Bootstrap/main.cpp
@@ -135,8 +135,7 @@ namespace System_Private_CoreLib { names
 
 using namespace System_Private_CoreLib;
 
-extern "C" void __EEType_System_Private_CoreLib_System_String();
-extern "C" void __EEType_System_Private_CoreLib_System_String__Array();
+extern "C" void* __EEType_System_Private_CoreLib_System_String;
 
 Object * __allocate_string(int32_t len)
 {
@@ -248,8 +247,8 @@ extern "C" void RhReRegisterForFinalize(
 extern "C" void * g_pDispatchMapTemporaryWorkaround;
 void * g_pDispatchMapTemporaryWorkaround;
 
-extern "C" void __StringTableStart();
-extern "C" void __StringTableEnd();
+extern "C" void* __StringTableStart;
+extern "C" void* __StringTableEnd;
 extern "C" void* GetModuleSection(int id, int* length)
 {
     struct ModuleSectionSymbol
@@ -266,8 +265,8 @@ extern "C" void* GetModuleSection(int id
         { System::String::__getMethodTable(), sizeof(void*) },
         { nullptr, 0 },
 #else
-        { __EEType_System_Private_CoreLib_System_String, sizeof(void*) },
-        { __StringTableStart, (uint8_t*)__StringTableEnd - (uint8_t*)__StringTableStart },
+        { (void*)&__EEType_System_Private_CoreLib_System_String, sizeof(void*) },
+        { (void*)&__StringTableStart, (uint8_t*)&__StringTableEnd - (uint8_t*)&__StringTableStart },
 #endif
     };
 
