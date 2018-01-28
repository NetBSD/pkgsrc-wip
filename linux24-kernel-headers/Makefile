# $NetBSD: Makefile,v 1.6 2012/10/03 09:10:42 asau Exp $


.include "../../wip/linux24-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

USE_LANGUAGES=	# empty

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH:Q}
PLIST_SRC+=	${PKGDIR}/PLIST.common

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h)

do-install:
	(cd ${WRKSRC}/include && ${GTAR} -cf - linux) | \
		${GTAR} -xf - -C ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/include/asm
	(cd ${WRKSRC}/include/asm-generic && ${GTAR} -cf - *) | \
		${GTAR} -xf - -C ${PREFIX}/include/asm
	(cd ${WRKSRC}/include/asm-${LOWER_ARCH:Q} && ${GTAR} -cf - *) | \
		${GTAR} -xf - -C ${PREFIX}/include/asm

.include "../../mk/bsd.pkg.mk"
