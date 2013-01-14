$NetBSD: patch-build__mozc.py,v 1.1 2013/01/14 14:00:55 ryo-on Exp $

--- build_mozc.py.orig	2012-08-31 05:36:42.000000000 +0000
+++ build_mozc.py
@@ -60,6 +60,7 @@ from build_tools.util import GetRelPath
 from build_tools.util import IsLinux
 from build_tools.util import IsMac
 from build_tools.util import IsWindows
+from build_tools.util import IsNetBSD
 from build_tools.util import PrintErrorAndExit
 from build_tools.util import RemoveDirectoryRecursively
 from build_tools.util import RemoveFile
@@ -111,6 +112,8 @@ def GetBuildBaseName(options, target_pla
     build_base = 'out_mac'
   elif target_platform == 'Linux' or target_platform == 'ChromeOS':
     build_base = 'out_linux'
+  elif target_platform == 'NetBSD':
+    build_base = 'out_bsd'
   elif target_platform == 'Android':
     build_base = 'out_android'
   elif target_platform == 'NaCl':
@@ -208,7 +211,7 @@ def GetGypFileNames(options):
   if IsWindows():
     gyp_file_names.extend(glob.glob('%s/win32/*/*.gyp' % SRC_DIR))
     gyp_file_names.extend(glob.glob('third_party/breakpad/*.gyp'))
-  elif IsLinux():
+  elif IsLinux() or IsNetBSD():
     gyp_file_names.extend(glob.glob('%s/unix/*/*.gyp' % SRC_DIR))
     # Add ibus.gyp if ibus version is >=1.4.1.
     if not PkgExists('ibus-1.0 >= 1.4.1'):
@@ -274,6 +277,7 @@ def AddCommonOptions(parser):
                     help='Specifies the base directory of the built binaries.')
   parser.add_option('--language', dest='language', default='japanese',
                     help='Specify the target language to build.')
+  parser.add_option('--os', dest='os', default='linux')
   return parser
 
 
@@ -284,6 +288,8 @@ def AddTargetPlatformOption(parser):
   # If you want Android build, specify "Android".
   if IsLinux():
     default_target = 'Linux'
+  elif IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -481,7 +487,7 @@ def ParseBuildOptions(args=None, values=
   """Parses command line options for the build command."""
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -501,7 +507,7 @@ def ParseRunTestsOptions(args=None, valu
   parser = optparse.OptionParser(
       usage='Usage: %prog runtests [options] [test_targets] [-- build options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -634,6 +640,8 @@ def GypMain(options, unused_args):
     command_line.extend(['-D', 'wix_dir=%s' % options.wix_dir])
   else:
     command_line.extend(['-D', 'use_wix=NO'])
+  if options.os:
+    command_line.extend(['-D', 'OS=%s' % options.os])
 
   command_line.extend(['-D', 'android_arch_abi=%s' % options.android_arch_abi])
   command_line.extend(['-D', 'android_application_id=%s' %
@@ -669,7 +677,7 @@ def GypMain(options, unused_args):
 
   def SetCommandLineForFeature(option_name, windows=False, mac=False,
                                linux=False, chromeos=False, android=False,
-                               nacl=False):
+                               nacl=False, netbsd=False):
     """Updates an option like '--enable_foober' and add a -D argument for gyp.
 
     This function ensures an option like '--enable_foober' exists and it has a
@@ -693,6 +701,8 @@ def GypMain(options, unused_args):
           option on Android platform.
       nacl: A boolean which replesents the default value of the target
           option on NaCl.
+      netbsd:  boolean which replesents the default value of the target option
+          on NetBSD platform.
 
     Raises:
       ValueError: An error occurred when 'option_name' is empty.
@@ -706,6 +716,7 @@ def GypMain(options, unused_args):
                        'Linux': linux,
                        'ChromeOS': chromeos,
                        'Android': android,
+                       'NetBSD' : netbsd,
                        'NaCl': nacl}[options.target_platform]
     enable_option_name = 'enable_%s' % option_name
     enabled = options.ensure_value(enable_option_name, default_enabled)
@@ -769,7 +780,7 @@ def GypMain(options, unused_args):
   else:
     command_line.extend(['-D', 'use_zinnia=NO'])
 
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     if '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names:
       command_line.extend(['-D', 'use_libibus=1'])
 
@@ -790,7 +801,7 @@ def GypMain(options, unused_args):
   # command for pkg-config.  Here we catch the environment variable
   # and use the specified command instead of actual pkg-config
   # command.
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     command_line.extend(['-D', 'pkg_config_command=%s' % GetPkgConfigCommand()])
   else:
     command_line.extend(['-D', 'pkg_config_command='])
@@ -927,6 +938,41 @@ def BuildOnMac(options, targets, origina
               '-parallelizeTargets',
               'BUILD_WITH_GYP=1'])
 
+def BuildOnBSD(options, targets, unused_original_directory_name):
+  """Build the targets on *BSD."""
+  target_names = []
+  for target in targets:
+    (unused_gyp_file_name, target_name) = (
+        CanonicalTargetToGypFileAndTargetName(target))
+    target_names.append(target_name)
+
+    make_command = os.getenv('BUILD_COMMAND', 'gmake')
+
+  envvars = [
+      'CFLAGS',
+      'CXXFLAGS',
+      'CXX',
+      'CC',
+      'AR',
+      'AS',
+      'RANLIB',
+      'LD',
+  ]
+  for envvar in envvars:
+    if envvar in os.environ:
+      os.environ[envvar] = os.getenv(envvar)
+
+  # set output directory
+  os.environ['builddir_name'] = 'out_bsd'
+
+  build_args = ['-j%s' % options.jobs,
+                'MAKE_JOBS=%s' % options.jobs,
+                'BUILDTYPE=%s' % options.configuration]
+  build_args.append('builddir_name=%s' %
+                    GetBuildBaseName(options,
+                                     GetMozcVersion().GetTargetPlatform()))
+
+  RunOrDie([make_command] + build_args + target_names)
 
 def LocateMSBuildDir():
   """Locate the directory where msbuild.exe exists.
@@ -1079,6 +1125,8 @@ def BuildMain(options, targets, original
     BuildOnMac(options, targets, original_directory_name)
   elif IsLinux():
     BuildOnLinux(options, targets, original_directory_name)
+  elif IsNetBSD():
+    BuildOnBSD(options, targets, original_directory_name)
   elif IsWindows():
     BuildOnWindows(options, targets, original_directory_name)
   else:
@@ -1350,7 +1398,7 @@ def CleanBuildFilesAndDirectories(option
     elif IsMac():
       directory_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                     '*.xcodeproj')))
-    elif IsLinux():
+    elif IsLinux() or IsNetBSD():
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                '*.target.mk')))
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
@@ -1377,6 +1425,10 @@ def CleanBuildFilesAndDirectories(option
     file_names.append('Makefile')
   elif IsWindows():
     file_names.append('third_party/breakpad/breakpad.gyp')
+    directory_names.append('out_win')
+  elif IsNetBSD():
+    file_names.append('Makefile')
+    directory_names.append('out_bsd')
   # Remove files.
   for file_name in file_names:
     RemoveFile(file_name)
