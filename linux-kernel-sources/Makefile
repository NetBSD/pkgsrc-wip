# $NetBSD: Makefile,v 1.1.1.1 2004/01/27 14:23:38 marttikuparinen Exp $

DISTNAME=		linux-${KERNEL_VERSION}
PKGNAME=		linux-kernel-sources-${KERNEL_VERSION}
CATEGORIES=		linux
MASTER_SITES=		http://www.kernel.org/pub/linux/kernel/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.kernel.org/
COMMENT=		Linux kernel sources

KERNEL_VERSION=		2.4.24

ONLY_FOR_PLATFORM=	Linux-*-*

NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/src/${DISTNAME}
	(cd ${WRKDIR} && ${GTAR} -cf - ${DISTNAME}) | \
		${GTAR} -xf - -C ${PREFIX}/src

.include "../../mk/bsd.pkg.mk"
