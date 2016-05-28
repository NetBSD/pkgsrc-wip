# $NetBSD: Makefile,v 1.6 2012/10/03 09:10:42 asau Exp $


.include "../../wip/linux24-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

USE_LANGUAGES=	# empty

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH:Q}
PLIST_SRC+=	${PKGDIR}/PLIST.common

do-build:
	(cd ${WRKSRC:Q} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h)

do-install:
	(cd ${WRKSRC:Q}/include && ${GTAR} -cf - linux) | \
		${GTAR} -xf - -C ${PREFIX:Q}/include
	${INSTALL_DATA_DIR} ${PREFIX:Q}/include/asm
	(cd ${WRKSRC:Q}/include/asm-generic && ${GTAR} -cf - *) | \
		${GTAR} -xf - -C ${PREFIX:Q}/include/asm
	(cd ${WRKSRC:Q}/include/asm-${LOWER_ARCH:Q} && ${GTAR} -cf - *) | \
		${GTAR} -xf - -C ${PREFIX:Q}/include/asm

.include "../../mk/bsd.pkg.mk"
