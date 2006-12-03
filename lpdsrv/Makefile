# $NetBSD: Makefile,v 1.1.1.1 2006/12/03 15:30:44 gschwarz Exp $

DISTNAME=	${PKGNAME:C/-.*$//}
PKGNAME=	lpdsrv-1.4
CATEGORIES=	net
MASTER_SITES=	http://www.ledow.org.uk/Freesco/Programs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
COMMENT=	Non-spooling LPD server (RFC1179)

NO_CONFIGURE=	YES
WRKSRC=		${WRKDIR}
EXTRACT_USING=	gtar # archive does not properly extract using BSD tar

INSTALLATION_DIRS=	sbin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/lpdsrv ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
