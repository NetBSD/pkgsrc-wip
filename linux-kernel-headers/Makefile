# $NetBSD: Makefile,v 1.2 2004/01/28 17:25:51 marttikuparinen Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=	linux-kernel-headers-${LINUX_VERSION}
COMMENT=	Linux kernel headers

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} include/linux/version.h)

do-install:
	(cd ${WRKSRC}/include && ${GTAR} -cf - linux asm*) | \
		${GTAR} -xf - -C ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
