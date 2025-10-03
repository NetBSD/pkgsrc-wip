$NetBSD$

llvm 17 to 19 migration, patch shared upstream

--- v2/AaGeneration/src/Utils.cpp.orig	2025-09-12 13:36:48.000000000 +0000
+++ v2/AaGeneration/src/Utils.cpp
@@ -411,22 +411,22 @@ IOCode Aa::get_io_code(CallInst &C)
 	// 	return NOT_IO;
 
 	StringRef name = f->getName();
-	IOCode ioc = (name.equals("read_uint32") ? READ_UINT32
-			: (name.equals("write_uint32") ? WRITE_UINT32
-				: (name.equals("read_float32") ? READ_FLOAT32
-					: (name.equals("write_float32") ? WRITE_FLOAT32
-					: (name.equals("read_float64") ? READ_FLOAT64
-					: (name.equals("write_float64") ? WRITE_FLOAT64
-						: (name.equals("write_uintptr") ? WRITE_UINTPTR
-							: (name.equals("read_uintptr") ? READ_UINTPTR
-								: (name.equals("write_pointer") ? WRITE_POINTER
-									: (name.equals("read_pointer") ? READ_POINTER
-										: (name.equals("write_uint16") ? WRITE_UINT16
-											: (name.equals("read_uint16") ? READ_UINT16
-												: (name.equals("write_uint8") ? WRITE_UINT8
-													: (name.equals("read_uint8") ? READ_UINT8
-														: (name.equals("write_uint64") ? WRITE_UINT64
-															: (name.equals("read_uint64") ? READ_UINT64
+	IOCode ioc = (name == "read_uint32" ? READ_UINT32
+			: (name == "write_uint32" ? WRITE_UINT32
+				: (name == "read_float32" ? READ_FLOAT32
+					: (name == "write_float32" ? WRITE_FLOAT32
+					: (name == "read_float64" ? READ_FLOAT64
+					: (name == "write_float64" ? WRITE_FLOAT64
+						: (name == "write_uintptr" ? WRITE_UINTPTR
+							: (name == "read_uintptr" ? READ_UINTPTR
+								: (name == "write_pointer" ? WRITE_POINTER
+									: (name == "read_pointer" ? READ_POINTER
+										: (name == "write_uint16" ? WRITE_UINT16
+											: (name == "read_uint16" ? READ_UINT16
+												: (name == "write_uint8" ? WRITE_UINT8
+													: (name == "read_uint8" ? READ_UINT8
+														: (name == "write_uint64" ? WRITE_UINT64
+															: (name == "read_uint64" ? READ_UINT64
 																: NOT_IO))))))))))))))));
 
 	return ioc;
@@ -1385,7 +1385,7 @@ bool Aa::get_loop_pipelining_info(llvm::
 			if(f->isDeclaration())
 			{
 				StringRef name = f->getName();
-				if(name.equals("__loop_pipelining_on__"))
+				if(name == "__loop_pipelining_on__")
 				{
 					opt_fn_found = true;
 					if(C.getNumOperands() > 0)
