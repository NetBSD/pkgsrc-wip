# $NetBSD: Makefile,v 1.4 2004/03/07 04:06:52 jeremy-c-reed Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_ARCH}
PLIST_SRC+=	${PKGDIR}/PLIST.common

do-build:
	${TOUCH} ${WRKSRC}/.config
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h)

do-install:
	cd ${WRKSRC}/include && ${PAX} -rw -pe linux ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/include/asm
	cd ${WRKSRC}/include/asm-generic && \
		${PAX} -rw -pe . ${PREFIX}/include/asm
	cd ${WRKSRC}/include/asm-${LOWER_ARCH} && \
		${PAX} -rw -pe . ${PREFIX}/include/asm

.include "../../mk/bsd.pkg.mk"
