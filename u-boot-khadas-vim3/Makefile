# $NetBSD: Makefile,v 1.6 2019/11/04 21:28:56 rillig Exp $

UBOOT_TARGET=		khadas-vim3
UBOOT_CONFIG=		khadas-vim3_defconfig
UBOOT_BIN=		u-boot.g12b

PKGREVISION=		1
UBOOT_VERSION=		2021.07

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

DISTINFO_FILE=		${.CURDIR}/../../wip/u-boot-khadas-vim3/distinfo
DISTFILES=		${DEFAULT_DISTFILES}

#
# Khadas-supplied BLxx binaries
#
KHADAS=			khadas-vims-v2015.01
MESON=			g12b
AMLOGIC=		${UBOOT_TARGET}-v2015.01

xBL2_BIN=		bl2.bin
BL2_BIN=		${AMLOGIC}-${xBL2_BIN}
DISTFILES+=		${BL2_BIN}
SITES.${BL2_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xBL2_BIN} @}

xBL30_BIN=		bl30.bin
BL30_BIN=		${AMLOGIC}-${xBL30_BIN}
DISTFILES+=		${BL30_BIN}
SITES.${BL30_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xBL30_BIN} @}

xBL31_IMG=		bl31.img
BL31_IMG=		${AMLOGIC}-${xBL31_IMG}
DISTFILES+=		${BL31_IMG}
SITES.${BL31_IMG}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xBL31_IMG} @}

xDDR3_1D_FW=		ddr3_1d.fw
DDR3_1D_FW=		${AMLOGIC}-${xDDR3_1D_FW}
DISTFILES+=		${DDR3_1D_FW}
SITES.${DDR3_1D_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xDDR3_1D_FW} @}

xDDR4_1D_FW=		ddr4_1d.fw
DDR4_1D_FW=		${AMLOGIC}-${xDDR4_1D_FW}
DISTFILES+=		${DDR4_1D_FW}
SITES.${DDR4_1D_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xDDR4_1D_FW} @}

xDDR4_2D_FW=		ddr4_2d.fw
DDR4_2D_FW=		${AMLOGIC}-${xDDR4_2D_FW}
DISTFILES+=		${DDR4_2D_FW}
SITES.${DDR4_2D_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xDDR4_2D_FW} @}

xDIAG_LPDDR4_FW=	diag_lpddr4.fw
DIAG_LPDDR4_FW=		${AMLOGIC}-${xDIAG_LPDDR4_FW}
DISTFILES+=		${DIAG_LPDDR4_FW}
SITES.${DIAG_LPDDR4_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xDIAG_LPDDR4_FW} @}

xLPDDR3_1D_FW=		lpddr3_1d.fw
LPDDR3_1D_FW=		${AMLOGIC}-${xLPDDR3_1D_FW}
DISTFILES+=		${LPDDR3_1D_FW}
SITES.${LPDDR3_1D_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xLPDDR3_1D_FW} @}

xLPDDR4_1D_FW=		lpddr4_1d.fw
LPDDR4_1D_FW=		${AMLOGIC}-${xLPDDR4_1D_FW}
DISTFILES+=		${LPDDR4_1D_FW}
SITES.${LPDDR4_1D_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xLPDDR4_1D_FW} @}

xLPDDR4_2D_FW=		lpddr4_2d.fw
LPDDR4_2D_FW=		${AMLOGIC}-${xLPDDR4_2D_FW}
DISTFILES+=		${LPDDR4_2D_FW}
SITES.${LPDDR4_2D_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xLPDDR4_2D_FW} @}

xPIEI_FW=		piei.fw
PIEI_FW=		${AMLOGIC}-${xPIEI_FW}
DISTFILES+=		${PIEI_FW}
SITES.${AML_DDR_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xPIEI_FW} @}


xAML_DDR_FW=		aml_ddr.fw
AML_DDR_FW=		${AMLOGIC}-${xAML_DDR_FW}
DISTFILES+=		${AML_DDR_FW}
SITES.${AML_DDR_FW}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/${MESON}/${xAML_DDR_FW} @}

xACS_BIN=		acs.bin
ACS_BIN=		${AMLOGIC}-${xACS_BIN}
DISTFILES+=		${ACS_BIN}
SITES.${ACS_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}thirdyouth/u-boot-blobs/raw/main/boards/khadas/vim3/${xACS_BIN} @}

xBL301_BIN=		bl301.bin
BL301_BIN=		${AMLOGIC}-${xBL301_BIN}
DISTFILES+=		${BL301_BIN}
SITES.${BL301_BIN}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}thirdyouth/u-boot-blobs/raw/main/boards/khadas/vim3/${xBL301_BIN} @}

# pkgsrc tries to run distfiles that end in .bin; handle manually
EXTRACT_ONLY=		${DISTFILES:N*.bin}

post-extract:
	cp ${DISTDIR}/${BL2_BIN} ${WRKSRC}/${xBL2_BIN}
	cp ${DISTDIR}/${BL30_BIN} ${WRKSRC}/${xBL30_BIN}
	cp ${DISTDIR}/${BL31_IMG} ${WRKSRC}/${xBL31_IMG}
	cp ${DISTDIR}/${DDR3_1D_FW} ${WRKSRC}/${xDDR3_1D_FW}
	cp ${DISTDIR}/${DDR4_1D_FW} ${WRKSRC}/${xDDR4_1D_FW}
	cp ${DISTDIR}/${DDR4_2D_FW} ${WRKSRC}/${xDDR4_2D_FW}
	cp ${DISTDIR}/${DIAG_LPDDR4_FW} ${WRKSRC}/${xDIAG_LPDDR4_FW}
	cp ${DISTDIR}/${LPDDR3_1D_FW} ${WRKSRC}/${xLPDDR3_1D_FW}
	cp ${DISTDIR}/${LPDDR4_1D_FW} ${WRKSRC}/${xLPDDR4_1D_FW}
	cp ${DISTDIR}/${LPDDR4_2D_FW} ${WRKSRC}/${xLPDDR4_2D_FW}
	cp ${DISTDIR}/${PIEI_FW} ${WRKSRC}/${xPIEI_FW}
	cp ${DISTDIR}/${AML_DDR_FW} ${WRKSRC}/${xAML_DDR_FW}
	cp ${DISTDIR}/${ACS_BIN} ${WRKSRC}/${xACS_BIN}
	cp ${DISTDIR}/${BL301_BIN} ${WRKSRC}/${xBL301_BIN}

#
# XXX For now, we use the fip_create and aml_encrypt_gxb binaries
# from Hardkernel.
#
TOOL_DEPENDS+=		amlogic-meson-fwtools>=0.0:../../sysutils/amlogic-meson-fwtools
post-build:
	cp ${WRKSRC}/u-boot.bin ${WRKSRC}/bl33.bin

	bash ${PREFIX}/bin/blx_fix_g12a.sh \
		${WRKSRC}/${xBL30_BIN} \
		${WRKSRC}/zero_tmp \
		${WRKSRC}/bl30_zero.bin \
		${WRKSRC}/${xBL301_BIN} \
		${WRKSRC}/bl301_zero.bin \
		${WRKSRC}/bl30_new.bin \
		bl30

	bash ${PREFIX}/bin/blx_fix_g12a.sh \
		${WRKSRC}/${xBL2_BIN} \
		${WRKSRC}/zero_tmp \
		${WRKSRC}/bl2_zero.bin \
		${WRKSRC}/${xACS_BIN} \
		${WRKSRC}/bl21_zero.bin \
		${WRKSRC}/bl2_new.bin \
		bl2

	${PREFIX}/bin/aml_encrypt_g12b --bl30sig --input ${WRKSRC}/bl30_new.bin \
		--output ${WRKSRC}/bl30_new.bin.g12a.enc \
		--level v3

	${PREFIX}/bin/aml_encrypt_g12b --bl3sig --input ${WRKSRC}/bl30_new.bin.g12a.enc \
		--output ${WRKSRC}/bl30_new.bin.enc \
		--level v3 --type bl30

	${PREFIX}/bin/aml_encrypt_g12b --bl3sig --input ${WRKSRC}/${xBL31_IMG} \
		--output ${WRKSRC}/${xBL31_IMG}.enc \
		--level v3 --type bl31

	${PREFIX}/bin/aml_encrypt_g12b --bl3sig --input ${WRKSRC}/bl33.bin --compress lz4 \
		--output ${WRKSRC}/bl33.bin.enc \
		--level v3 --type bl33 --compress lz4

	${PREFIX}/bin/aml_encrypt_g12b --bl2sig --input ${WRKSRC}/bl2_new.bin \
		--output ${WRKSRC}/bl2.n.bin.sig

	${PREFIX}/bin/aml_encrypt_g12b --bootmk \
		--output ${WRKSRC}/${UBOOT_BIN} \
		--bl2 ${WRKSRC}/bl2.n.bin.sig \
		--bl30 ${WRKSRC}/bl30_new.bin.enc \
		--bl31 ${WRKSRC}/${xBL31_IMG}.enc \
		--bl33 ${WRKSRC}/bl33.bin.enc \
		--ddrfw1 ${WRKSRC}/${xDDR4_1D_FW} \
		--ddrfw2 ${WRKSRC}/${xDDR4_2D_FW} \
		--ddrfw3 ${WRKSRC}/${xDDR3_1D_FW} \
		--ddrfw4 ${WRKSRC}/${xPIEI_FW} \
		--ddrfw5 ${WRKSRC}/${xLPDDR4_1D_FW} \
		--ddrfw6 ${WRKSRC}/${xLPDDR4_2D_FW} \
		--ddrfw7 ${WRKSRC}/${xDIAG_LPDDR4_FW} \
		--ddrfw8 ${WRKSRC}/${xAML_DDR_FW} \
		--ddrfw9 ${WRKSRC}/${xLPDDR3_1D_FW} \
		--level v3

CHECK_PORTABILITY_SKIP+=	tools/imx8m_image.sh
PKG_DEFAULT_OPTIONS+=		el1

.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
