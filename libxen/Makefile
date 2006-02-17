#	$NetBSD: Makefile,v 1.4 2006/02/17 09:29:31 marttikuparinen Exp $

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
	${MKDIR} ${WRKSRC:Q}/libxc/xen/NetBSD
	${CP} ${FILESDIR:Q}/xenio.h ${WRKSRC:Q}/libxc/xen/NetBSD

.include "../../mk/bsd.pkg.mk"
