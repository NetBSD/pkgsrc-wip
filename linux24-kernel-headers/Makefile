# $NetBSD: Makefile,v 1.1.1.1 2004/01/29 07:32:47 marttikuparinen Exp $

.include "../../wip/linux24-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

PLIST_SRC+=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h)

do-install:
	(cd ${WRKSRC}/include && ${GTAR} -cf - linux) | \
		${GTAR} -xf - -C ${PREFIX}/include
	(cd ${WRKSRC}/include && ${GTAR} -cf - asm-${LOWER_ARCH}) | \
		${GTAR} -xf - -C ${PREFIX}/include
	(cd ${WRKSRC}/include && ${GTAR} -cf - asm-generic) | \
		${GTAR} -xf - -C ${PREFIX}/include
	(cd ${PREFIX}/include && ${LN} -sf asm-${LOWER_ARCH} asm)

.include "../../mk/bsd.pkg.mk"
