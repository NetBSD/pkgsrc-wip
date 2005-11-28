# $NetBSD: Makefile,v 1.3 2005/11/28 21:39:08 florian_stoehr Exp $
#

DISTNAME=		neb-wipe-src-0.9.1
PKGNAME=		neb-wipe-0.9.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=neb-stoehr/}
EXTRACT_SUFX=		.tgz

MAINTAINER=	 	netbsd@wolfnode.de
HOMEPAGE=		http://neb-stoehr.sourceforge.net/
COMMENT=	 	Secure disk partition eraser

NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-wipe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-wipe.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
