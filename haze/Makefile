# $NetBSD: Makefile,v 1.3 2008/05/24 15:34:10 tnn2 Exp $
#

DISTNAME=	haze
PKGNAME=	haze-20071107
CATEGORIES=	sysutils
MASTER_SITES=	http://www.NetBSD.org/~elad/

MAINTAINER=	haaaad@gmail.com,elad@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~elad/
COMMENT=	Offer a system to generate binary updates for NetBSD

WRKSRC=	${WRKDIR}/haze

INSTALLATION_DIRS= sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/haze ${PREFIX}/sbin/haze

.include "../../mk/bsd.pkg.mk"
