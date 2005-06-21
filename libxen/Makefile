#	$NetBSD: Makefile,v 1.1.1.1 2005/06/21 18:59:34 marttikuparinen Exp $

DISTNAME=		xen-${VERSION}-src
PKGNAME=		libxen-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/
COMMENT=		Xen libraries

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/xen-2.0/tools
VERSION=		2.0.6

ONLY_FOR_PLATFORM=	NetBSD-*-i386

pre-build:
	${MKDIR} ${WRKSRC}/libxc/xen/NetBSD
	${CP} ${FILESDIR}/xenio.h ${WRKSRC}/libxc/xen/NetBSD

.include "../../mk/bsd.pkg.mk"
