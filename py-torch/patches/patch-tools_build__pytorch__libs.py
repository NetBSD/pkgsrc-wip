$NetBSD$

--- tools/build_pytorch_libs.py.orig	2026-07-03 17:19:32.498221335 +0000
+++ tools/build_pytorch_libs.py
@@ -4,7 +4,6 @@ import subprocess
 import platform
 import subprocess
 
-from .optional_submodules import checkout_nccl
 from .setup_helpers.cmake import CMake, USE_NINJA
 from .setup_helpers.env import (
     check_env_flag,
@@ -87,13 +86,6 @@ def build_pytorch(
     cmake: CMake,
 ) -> None:
     my_env = _create_build_env()
-    if (
-        not check_negative_env_flag("USE_DISTRIBUTED")
-        and not check_negative_env_flag("USE_CUDA")
-        and not check_negative_env_flag("USE_NCCL")
-        and not check_env_flag("USE_SYSTEM_NCCL")
-    ):
-        checkout_nccl()
     build_test = not check_negative_env_flag("BUILD_TEST")
     cmake.generate(
         version, cmake_python_library, build_python, build_test, my_env, rerun_cmake
