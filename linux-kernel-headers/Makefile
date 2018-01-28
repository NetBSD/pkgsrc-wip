# $NetBSD: Makefile,v 1.11 2012/10/03 08:49:34 asau Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

USE_LANGUAGES=	# empty

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}
PLIST_SRC+=	${PKGDIR}/PLIST.common

INSTALLATION_DIRS=	include

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h

do-install:
	cd ${WRKSRC}/include && pax -rw -pe linux ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/asm
	${RM} ${DESTDIR}${PREFIX}/include/asm-generic
	${LN} -s ${PREFIX}/include/asm ${DESTDIR}${PREFIX}/include/asm-generic
	cd ${WRKSRC}/include/asm-${LOWER_ARCH:Q} && \
		pax -rw -pe . ${DESTDIR}${PREFIX}/include/asm
	cd ${WRKSRC}/include/asm-generic && \
		pax -rw -pe . ${DESTDIR}${PREFIX}/include/asm

.include "../../mk/bsd.pkg.mk"
