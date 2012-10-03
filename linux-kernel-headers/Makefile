# $NetBSD: Makefile,v 1.11 2012/10/03 08:49:34 asau Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

USE_LANGUAGES=	# empty

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}
PLIST_SRC+=	${PKGDIR}/PLIST.common

INSTALLATION_DIRS=	include

do-build:
	cd ${WRKSRC:Q} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h

do-install:
	cd ${WRKSRC:Q}/include && pax -rw -pe linux ${DESTDIR}${PREFIX:Q}/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/include/asm
	${RM} ${DESTDIR}${PREFIX:Q}/include/asm-generic
	${LN} -s ${PREFIX:Q}/include/asm ${DESTDIR}${PREFIX:Q}/include/asm-generic
	cd ${WRKSRC:Q}/include/asm-${LOWER_ARCH:Q} && \
		pax -rw -pe . ${DESTDIR}${PREFIX:Q}/include/asm
	cd ${WRKSRC:Q}/include/asm-generic && \
		pax -rw -pe . ${DESTDIR}${PREFIX:Q}/include/asm

.include "../../mk/bsd.pkg.mk"
