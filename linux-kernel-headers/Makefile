# $NetBSD: Makefile,v 1.1.1.1 2004/01/28 10:22:22 marttikuparinen Exp $

.include "../../wip/linux-kernel/Makefile.common"

PKGNAME=		linux-kernel-headers-${LINUX_VERSION}
COMMENT=		Linux kernel headers

NO_BUILD=		# defined

do-install:
	(cd ${WRKSRC}/include && ${GTAR} -cf - linux asm*) | \
		${GTAR} -xf - -C ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
