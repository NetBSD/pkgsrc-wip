# $NetBSD: Makefile,v 1.3 2004/02/03 09:20:15 marttikuparinen Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}
PLIST_SRC+=	${PKGDIR}/PLIST.common

do-build:
	${TOUCH} ${WRKSRC}/.config
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h)

do-install:
	(cd ${WRKSRC}/include && ${GTAR} -cf - linux) | \
		${GTAR} -xf - -C ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/include/asm
	(cd ${WRKSRC}/include/asm-generic && ${GTAR} -cf - *) | \
		${GTAR} -xf - -C ${PREFIX}/include/asm
	(cd ${WRKSRC}/include/asm-${LOWER_ARCH} && ${GTAR} -cf - *) | \
		${GTAR} -xf - -C ${PREFIX}/include/asm

.include "../../mk/bsd.pkg.mk"
