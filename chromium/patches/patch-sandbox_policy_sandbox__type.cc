$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox_type.cc.orig	2024-07-24 02:44:43.565452600 +0000
+++ sandbox/policy/sandbox_type.cc
@@ -38,7 +38,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
 #endif
     case Sandbox::kAudio:
       return false;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return false;
 #endif
@@ -63,7 +63,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
     case Sandbox::kMirroring:
     case Sandbox::kNaClLoader:
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -74,7 +74,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
     case Sandbox::kLibassistant:
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) | BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
     case Sandbox::kHardwareVideoEncoding:
 #endif
@@ -131,7 +131,7 @@ void SetCommandLineFlagsForSandboxType(b
 #endif
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -142,10 +142,10 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kMediaFoundationCdm:
     case Sandbox::kWindowsSystemProxyResolver:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoEncoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -174,7 +174,7 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kNaClLoader:
       break;
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       break;
 #endif
@@ -218,7 +218,7 @@ sandbox::mojom::Sandbox SandboxTypeFromC
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -266,7 +266,7 @@ std::string StringFromUtilitySandboxType
       return switches::kUtilitySandbox;
     case Sandbox::kAudio:
       return switches::kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return switches::kVideoCaptureSandbox;
 #endif
@@ -296,11 +296,11 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kMirroring:
       return switches::kMirroringSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
       return switches::kHardwareVideoDecodingSandbox;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoEncoding:
       return switches::kHardwareVideoEncodingSandbox;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -322,7 +322,7 @@ std::string StringFromUtilitySandboxType
 #if BUILDFLAG(IS_MAC)
     case Sandbox::kNaClLoader:
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED_IN_MIGRATION();
@@ -394,11 +394,11 @@ sandbox::mojom::Sandbox UtilitySandboxTy
   if (sandbox_string == switches::kScreenAISandbox)
     return Sandbox::kScreenAI;
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kVideoCaptureSandbox)
     return Sandbox::kVideoCapture;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kHardwareVideoDecodingSandbox)
     return Sandbox::kHardwareVideoDecoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
