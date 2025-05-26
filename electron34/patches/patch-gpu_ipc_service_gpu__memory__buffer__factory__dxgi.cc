$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/ipc/service/gpu_memory_buffer_factory_dxgi.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/ipc/service/gpu_memory_buffer_factory_dxgi.cc
@@ -178,7 +178,8 @@ gfx::GpuMemoryBufferHandle GpuMemoryBuff
   // so make sure that the usage is one that we support.
   DCHECK(usage == gfx::BufferUsage::GPU_READ ||
          usage == gfx::BufferUsage::SCANOUT ||
-         usage == gfx::BufferUsage::SCANOUT_CPU_READ_WRITE)
+         usage == gfx::BufferUsage::SCANOUT_CPU_READ_WRITE ||
+         usage == gfx::BufferUsage::SCANOUT_VEA_CPU_READ)
       << "Incorrect usage, usage=" << gfx::BufferUsageToString(usage);
 
   D3D11_TEXTURE2D_DESC desc = {
@@ -192,7 +193,9 @@ gfx::GpuMemoryBufferHandle GpuMemoryBuff
       D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET,
       0,
       D3D11_RESOURCE_MISC_SHARED_NTHANDLE |
-          D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX};
+          static_cast<UINT>(usage == gfx::BufferUsage::SCANOUT_VEA_CPU_READ
+                                ? D3D11_RESOURCE_MISC_SHARED
+                                : D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX)};
 
   Microsoft::WRL::ComPtr<ID3D11Texture2D> d3d11_texture;
 
