# $NetBSD$

GIT_REPO=	https://github.com/smaeul/u-boot
GIT_BRANCH=	d1-wip

UBOOT_TARGET=	mangopi-mq-pro
UBOOT_VERSION=	2024.01
UBOOT_CONFIG=	mangopi_mq_pro_defconfig
UBOOT_BIN=	u-boot-sunxi-with-spl.bin

MAKE_ENV+=	OPENSBI=${LOCALBASE}/share/opensbi/sun20i-d1/fw_dynamic.bin

.include "../../sysutils/opensbi-sun20i-d1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
