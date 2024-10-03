$NetBSD$

--- board/sunxi/board-riscv.c.orig	2024-10-02 22:48:51.254018155 +0000
+++ board/sunxi/board-riscv.c
@@ -202,7 +202,11 @@ int spl_board_init_f(void)
 	       csr_read(CSR_MCOR),
 	       csr_read(CSR_MHINT));
 
+#ifdef CONFIG_RISCV_MAEE
 	csr_set(CSR_MXSTATUS, 0x638000);
+#else
+	csr_set(CSR_MXSTATUS, 0x438000);
+#endif
 	csr_write(CSR_MCOR, 0x70013);
 	csr_write(CSR_MHCR, 0x11ff);
 	csr_write(CSR_MHINT, 0x16e30c);
