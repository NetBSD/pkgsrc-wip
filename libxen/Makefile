#	$NetBSD: Makefile,v 1.3 2005/10/01 04:28:23 xtraeme Exp $

DISTNAME=		xen-${VERSION}-src
PKGNAME=		libxen-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/
COMMENT=		Xen libraries

CONFLICTS+=		xentools20-[0-9]*

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/xen-2.0/tools
VERSION=		2.0.7

ONLY_FOR_PLATFORM=	NetBSD-*-i386

pre-build:
	${MKDIR} ${WRKSRC}/libxc/xen/NetBSD
	${CP} ${FILESDIR}/xenio.h ${WRKSRC}/libxc/xen/NetBSD

.include "../../mk/bsd.pkg.mk"
