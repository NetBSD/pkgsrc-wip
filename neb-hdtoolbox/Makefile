# $NetBSD: Makefile,v 1.5 2006/04/21 07:31:47 cheusov Exp $
#

DISTNAME=		neb-hdtoolbox-src-0.9
PKGNAME=		neb-hdtoolbox-0.9
CATEGORIES=		sysutils
MASTER_SITES=		http://binary.florian-stoehr.de/
EXTRACT_SUFX=		.tgz

MAINTAINER=	 	netbsd@wolfnode.de
HOMEPAGE=		http://binary.florian-stoehr.de/
COMMENT=	 	Tool for cross-partitioning a disk for NetBSD/amiga

NO_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-hdtoolbox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-hdtoolbox.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
