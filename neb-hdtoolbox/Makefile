# $NetBSD: Makefile,v 1.7 2012/10/03 17:39:52 asau Exp $
#

DISTNAME=		neb-hdtoolbox-src-0.9
PKGNAME=		neb-hdtoolbox-0.9
CATEGORIES=		sysutils
MASTER_SITES=		http://binary.florian-stoehr.de/
EXTRACT_SUFX=		.tgz

MAINTAINER=	netbsd@wolfnode.de
HOMEPAGE=	http://binary.florian-stoehr.de/
COMMENT=	Tool for cross-partitioning a disk for NetBSD/amiga

NO_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-hdtoolbox ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-hdtoolbox.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
