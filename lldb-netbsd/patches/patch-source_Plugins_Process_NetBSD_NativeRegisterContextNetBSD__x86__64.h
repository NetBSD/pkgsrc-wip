$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.h.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.h
@@ -46,17 +46,39 @@ public:
 
   Error WriteAllRegisterValues(const lldb::DataBufferSP &data_sp) override;
 
+  Error IsWatchpointHit(uint32_t wp_index, bool &is_hit) override;
+                                    
+  Error GetWatchpointHitIndex(uint32_t &wp_index,
+                              lldb::addr_t trap_addr) override;
+
+  Error IsWatchpointVacant(uint32_t wp_index, bool &is_vacant) override;
+
+  bool ClearHardwareWatchpoint(uint32_t wp_index) override;
+
+  Error ClearAllHardwareWatchpoints() override;   
+                     
+  Error SetHardwareWatchpointWithIndex(lldb::addr_t addr, size_t size,
+                                       uint32_t watch_flags, uint32_t wp_index);
+                      
+  uint32_t SetHardwareWatchpoint(lldb::addr_t addr, size_t size,
+                                 uint32_t watch_flags) override;
+
+  lldb::addr_t GetWatchpointAddress(uint32_t wp_index) override;
+
+  uint32_t NumSupportedHardwareWatchpoints() override;
+
 protected:
   void *GetGPRBuffer() override { return &m_gpr_x86_64; }
   void *GetFPRBuffer() override { return &m_fpr_x86_64; }
 
 private:
   // Private member types.
-  enum { GPRegSet, FPRegSet };
+  enum { GPRegSet, FPRegSet, DBRegSet };
 
   // Private member variables.
   struct reg m_gpr_x86_64;
   struct fpreg m_fpr_x86_64;
+  struct dbreg m_dbr_x86_64;
 
   int GetSetForNativeRegNum(int reg_num) const;
 
