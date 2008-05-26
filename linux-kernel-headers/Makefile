# $NetBSD: Makefile,v 1.10 2008/05/26 13:59:45 tnn2 Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

USE_LANGUAGES=	# empty

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}
PLIST_SRC+=	${PKGDIR}/PLIST.common

do-build:
	cd ${WRKSRC:Q} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h

do-install:
	cd ${WRKSRC:Q}/include && pax -rw -pe linux ${PREFIX:Q}/include
	${INSTALL_DATA_DIR} ${PREFIX:Q}/include/asm
	${RM} ${PREFIX:Q}/include/asm-generic
	${LN} -s ${PREFIX:Q}/include/asm ${PREFIX:Q}/include/asm-generic
	cd ${WRKSRC:Q}/include/asm-${LOWER_ARCH:Q} && \
		pax -rw -pe . ${PREFIX:Q}/include/asm
	cd ${WRKSRC:Q}/include/asm-generic && \
		pax -rw -pe . ${PREFIX:Q}/include/asm

.include "../../mk/bsd.pkg.mk"
