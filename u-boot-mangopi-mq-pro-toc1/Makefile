# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-d1-2022-04-05
MASTER_SITES=	${MASTER_SITE_GITHUB:=smaeul/}
GITHUB_PROJECT=	u-boot
GITHUB_TAG=	refs/tags/${DISTNAME:S/${GITHUB_PROJECT}-//}
EXTRACT_SUFX=	.tar.gz
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/patches

UBOOT_TARGET=		mangopi-mq-pro
UBOOT_VERSION=		2022.04
UBOOT_CONFIG=		mangopi_mq_pro_defconfig
UBOOT_BIN=		u-boot.toc1

MAKE_ENV+=	OPENSBI=${LOCALBASE}/share/opensbi/sun20i-d1/fw_dynamic.bin

WRKSRC=		${WRKDIR}/${DISTNAME}

post-extract:
	# Copy dts/dtsi files from d1-2022-10-31
	${CP} ${FILESDIR}/*.dts ${WRKSRC}/arch/riscv/dts
	${CP} ${FILESDIR}/*.dtsi ${WRKSRC}/arch/riscv/dts
	${CP} ${FILESDIR}/mangopi_mq_pro_defconfig ${WRKSRC}/configs
	${CP} ${FILESDIR}/toc1.cfg ${WRKSRC}

post-build:
	${CP} ${LOCALBASE}/share/opensbi/sun20i-d1/fw_dynamic.bin ${WRKSRC}
	cd ${WRKSRC} && tools/mkimage -T sunxi_toc1 -d toc1.cfg u-boot.toc1

.include "../../wip/opensbi-sun20i-d1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
