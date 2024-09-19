$NetBSD: patch-dolfin_io_HDF5Interface.h,v 1.1 2013/03/23 19:30:01 outpaddling Exp $

--- dolfin/io/HDF5Interface.h.orig	2013-03-23 18:11:48.000000000 +0000
+++ dolfin/io/HDF5Interface.h
@@ -230,11 +230,13 @@ namespace dolfin
 
     // Set parallel access
     const hid_t plist_id = H5Pcreate(H5P_DATASET_XFER);
+#if H5_HAVE_PARALLEL
     if (use_mpi_io)
     {
       status = H5Pset_dxpl_mpio(plist_id, H5FD_MPIO_COLLECTIVE);
       dolfin_assert(status != HDF5_FAIL);
     }
+#endif
 
     // Write local dataset into selected hyperslab
     status = H5Dwrite(dset_id, h5type, memspace, filespace1, plist_id,
