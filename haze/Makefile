# $NetBSD: Makefile,v 1.2 2007/11/08 23:13:34 thomasklausner Exp $
#

DISTNAME=	haze
PKGNAME=	haze-20071107
CATEGORIES=	sysutils
MASTER_SITES=	http://www.NetBSD.org/~elad/

MAINTAINER=	haaaad@gmail.com,elad@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~elad/
COMMENT=	Offer a system to generate binary updates for NetBSD

WRKSRC= 	${WRKDIR}/haze

INSTALLATION_DIRS= sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/haze ${PREFIX}/sbin/haze

.include "../../mk/bsd.pkg.mk"
