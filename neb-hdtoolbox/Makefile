# $NetBSD: Makefile,v 1.6 2006/10/29 08:32:48 shattered Exp $
#

DISTNAME=		neb-hdtoolbox-src-0.9
PKGNAME=		neb-hdtoolbox-0.9
CATEGORIES=		sysutils
MASTER_SITES=		http://binary.florian-stoehr.de/
EXTRACT_SUFX=		.tgz

MAINTAINER=		netbsd@wolfnode.de
HOMEPAGE=		http://binary.florian-stoehr.de/
COMMENT=	Tool for cross-partitioning a disk for NetBSD/amiga

NO_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-hdtoolbox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-hdtoolbox.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
