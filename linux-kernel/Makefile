# $NetBSD: Makefile,v 1.5 2004/03/07 06:46:17 jeremy-c-reed Exp $

.include "Makefile.common"

PKGNAME=	linux-kernel-${LINUX_VERSION}
COMMENT=	The Linux kernel

BUILD_DEPENDS+=		linux-module-init-tools-[0-9]*:../../wip/linux-module-init-tools
# This means that old linux-modutils aren't available for other kernel
#BUILD_DEPENDS+=	linux-modutils-[0-9]*:../../wip/linux-modutils

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} bzImage && \
	${SETENV} ${MAKE_ENV} ${GMAKE} modules

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/boot
	${CP} ${WRKSRC}/arch/${LOWER_ARCH}/boot/bzImage \
		${PREFIX}/boot/bzImage-${LINUX_VERSION}
	${CP} ${WRKSRC}/System.map \
		${PREFIX}/boot/System.map-${LINUX_VERSION}
	${INSTALL_DATA} ${WRKSRC}/.config ${PREFIX}/boot/${PKGNAME}.config
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} modules_install

.include "../../mk/bsd.pkg.mk"

# FIXME Is this needed?
#CC=	${LOCALBASE}/gcc3/bin/gcc
