# $NetBSD$
UBOOT_TARGET=           visionfive2
UBOOT_CONFIG=           starfive_visionfive2_defconfig
UBOOT_BIN=              u-boot-nodtb.bin

DISTNAME=	visionfive2	
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=starfive-tech/}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/u-boot-JH7110_VisionFive2_devel
MAINTAINER=	port-riscvs@NetBSD.org

UBOOT_INSTALLBOOT_PLIST=        installboot.plist

.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
