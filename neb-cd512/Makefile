# $NetBSD: Makefile,v 1.6 2006/10/29 08:32:48 shattered Exp $
#

DISTNAME=		neb-cd512-src-0.9.1
PKGNAME=		neb-cd512-0.9.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=neb-stoehr/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		netbsd@wolfnode.de
HOMEPAGE=		http://neb-stoehr.sourceforge.net/
COMMENT=	512 bytes/sector disklabel recalculation tool

NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-cd512 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-cd512.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
