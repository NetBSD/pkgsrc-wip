# $NetBSD: Makefile,v 1.8 2005/04/11 21:13:53 tvierling Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

USE_LANGUAGES=	# empty

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}
PLIST_SRC+=	${PKGDIR}/PLIST.common

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h

do-install:
	cd ${WRKSRC}/include && ${PAX} -rw -pe linux ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/include/asm
	${RM} ${PREFIX}/include/asm-generic
	${LN} -s ${PREFIX}/include/asm ${PREFIX}/include/asm-generic
	cd ${WRKSRC}/include/asm-${LOWER_ARCH} && \
		${PAX} -rw -pe . ${PREFIX}/include/asm
	cd ${WRKSRC}/include/asm-generic && \
		${PAX} -rw -pe . ${PREFIX}/include/asm

.include "../../mk/bsd.pkg.mk"
