# $NetBSD: Makefile,v 1.7 2006/10/29 08:32:48 shattered Exp $
#

DISTNAME=		neb-wipe-src-1.0
PKGNAME=		neb-wipe-1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=neb-stoehr/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		netbsd@wolfnode.de
HOMEPAGE=		http://neb-stoehr.sourceforge.net/
COMMENT=	Secure disk partition eraser (NetBSD only)

NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-wipe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-wipe.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
