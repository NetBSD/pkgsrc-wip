# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:42 asau Exp $


.include "Makefile.common"

PKGNAME=	linux-kernel-${LINUX_VERSION}
COMMENT=	The Linux kernel

BUILD_DEPENDS+=	linux-modutils-[0-9]*:../../wip/linux-modutils

do-configure:
	cd ${WRKSRC} && \
	yes "" | ${GMAKE} config && \
	${CAT} ${FILESDIR}/extra-configs >> .config && \
	yes "" | ${GMAKE} oldconfig # regenerate config after appending to it

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} dep

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} bzImage && \
	${SETENV} ${MAKE_ENV} ${GMAKE} modules

do-install:
	${CP} ${WRKSRC}/arch/${LOWER_ARCH}/boot/bzImage \
		${PREFIX}/boot/bzImage-${LINUX_VERSION}
	${CP} ${WRKSRC}/System.map \
		${PREFIX}/boot/System.map-${LINUX_VERSION}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} modules_install

.include "../../mk/bsd.pkg.mk"

# FIXME Is this needed?
#CC=	${LOCALBASE}/gcc3/bin/gcc
