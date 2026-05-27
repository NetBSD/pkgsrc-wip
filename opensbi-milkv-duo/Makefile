# $NetBSD$

OPENSBI_BOARD=		milkv-duo
OPENSBI_PLATFORM=	generic

DEPENDS+=	u-boot-milkv-duo-[0-9]*:../../wip/u-boot-milkv-duo

MAKE_ENV+=	FW_PAYLOAD_PATH=${PREFIX}/share/u-boot/milkv-duo/u-boot.bin \
		FW_FDT_PATH=${PREFIX}/share/u-boot/milkv-duo/cv1800b_milkv_duo_sd.dtb

OPENSBI_BIN=		fw_dynamic.bin

.include "../../sysutils/opensbi/opensbi.mk"
.include "../../mk/bsd.pkg.mk"
