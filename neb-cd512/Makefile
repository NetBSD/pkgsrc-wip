# $NetBSD: Makefile,v 1.1.1.1 2005/03/03 23:59:44 florian_stoehr Exp $
#

DISTNAME=		neb-cd512-src-0.9
PKGNAME=		neb-cd512-0.9
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=neb-stoehr/}
EXTRACT_SUFX=		.tgz

MAINTAINER=	 	netbsd@wolfnode.de
HOMEPAGE=		http://neb-stoehr.sourceforge.net/
COMMENT=	 	512 bytes/sector disklabel recalculation tool

NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-cd512 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-cd512.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
