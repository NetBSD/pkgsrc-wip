$NetBSD$

--- src/vm/interoputil.cpp.orig	2016-02-02 01:31:09.000000000 +0000
+++ src/vm/interoputil.cpp
@@ -4580,7 +4580,7 @@ void IUInvokeDispMethod(REFLECTCLASSBASE
         UINT cPositionalArgs = cArgs - cNamedArgs;
        
         DispParams.cArgs = cArgs;
-        DispParams.rgvarg = (VARIANTARG *)_alloca(cArgs * sizeof(VARIANTARG));
+        DispParams.rgvarg = (VARIANTARG *)Alloca(cArgs * sizeof(VARIANTARG));
         params = new DispParamHolder[cArgs];
 
         // Initialize all the variants.
@@ -4670,12 +4670,12 @@ void IUInvokeDispMethod(REFLECTCLASSBASE
             size_t allocSize = cNamesToConvert * sizeof(LPWSTR);
             if (allocSize < cNamesToConvert)
                 COMPlusThrowArgumentOutOfRange(W("namedParameters"), W("ArgumentOutOfRange_Capacity"));
-            LPWSTR *aNamesToConvert = (LPWSTR *)_alloca(allocSize);
+            LPWSTR *aNamesToConvert = (LPWSTR *)Alloca(allocSize);
             
             allocSize = cNamesToConvert * sizeof(DISPID);
             if (allocSize < cNamesToConvert)
                 COMPlusThrowArgumentOutOfRange(W("namedParameters"), W("ArgumentOutOfRange_Capacity"));
-            aDispID = (DISPID *)_alloca(allocSize);
+            aDispID = (DISPID *)Alloca(allocSize);
 
             // The first name to convert is the name of the method itself.
             aNamesToConvert[0] = (*pStrName)->GetBuffer();
@@ -4826,7 +4826,7 @@ void IUInvokeDispMethod(REFLECTCLASSBASE
     if (cArgs > 0)
     {
         // Allocate the byref argument information.
-        aByrefArgInfos = (ByrefArgumentInfo*)_alloca(cArgs * sizeof(ByrefArgumentInfo));
+        aByrefArgInfos = (ByrefArgumentInfo*)Alloca(cArgs * sizeof(ByrefArgumentInfo));
         memset(aByrefArgInfos, 0, cArgs * sizeof(ByrefArgumentInfo));
 
         // Set the byref bit on the arguments that have the byref modifier.
@@ -4877,7 +4877,7 @@ void IUInvokeDispMethod(REFLECTCLASSBASE
                 // If we are doing a property put then we need to set the DISPID of the
                 // argument to DISP_PROPERTYPUT if there is at least one argument.
                 DispParams.cNamedArgs = cNamedArgs + 1;
-                DispParams.rgdispidNamedArgs = (DISPID*)_alloca((cNamedArgs + 1) * sizeof(DISPID));
+                DispParams.rgdispidNamedArgs = (DISPID*)Alloca((cNamedArgs + 1) * sizeof(DISPID));
                 
                 // Fill in the array of named arguments.
                 DispParams.rgdispidNamedArgs[0] = DISPID_PROPERTYPUT;
