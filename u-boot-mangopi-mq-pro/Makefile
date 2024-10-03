# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-d1-2022-10-31
MASTER_SITES=	${MASTER_SITE_GITHUB:=smaeul/}
GITHUB_PROJECT=	u-boot
GITHUB_TAG=	refs/tags/${DISTNAME:S/${GITHUB_PROJECT}-//}
EXTRACT_SUFX=	.tar.gz
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/patches

UBOOT_TARGET=		mangopi-mq-pro
UBOOT_VERSION=		2022.10
UBOOT_CONFIG=		mangopi_mq_pro_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

MAKE_ENV+=	OPENSBI=${LOCALBASE}/share/opensbi/sun20i-d1/fw_dynamic.bin

WRKSRC=		${WRKDIR}/${DISTNAME}

post-extract:
	${CP} ${FILESDIR}/mangopi_mq_pro_defconfig ${WRKSRC}/configs

.include "../../sysutils/opensbi-sun20i-d1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
