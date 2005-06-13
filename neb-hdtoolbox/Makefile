# $NetBSD: Makefile,v 1.2 2005/06/13 00:09:10 kristerw Exp $
#

DISTNAME=		neb-hdtoolbox-src-0.9
PKGNAME=		neb-hdtoolbox-0.9
CATEGORIES=		wip
MASTER_SITES=		http://binary.florian-stoehr.de/
EXTRACT_SUFX=		.tgz

MAINTAINER=	 	netbsd@wolfnode.de
HOMEPAGE=		http://binary.florian-stoehr.de/
COMMENT=	 	Tool for cross-partitioning a disk for NetBSD/amiga

NO_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-hdtoolbox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-hdtoolbox.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
