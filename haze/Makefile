# $NetBSD: Makefile,v 1.5 2012/09/29 16:50:14 asau Exp $
#

DISTNAME=	haze
PKGNAME=	haze-20071107
CATEGORIES=	sysutils
MASTER_SITES=	# http://www.NetBSD.org/~elad/

MAINTAINER=	haaaad@gmail.com
HOMEPAGE=	# http://www.NetBSD.org/~elad/
COMMENT=	Offer a system to generate binary updates for NetBSD

WRKSRC=	${WRKDIR}/haze

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/haze ${DESTDIR}${PREFIX}/sbin/haze

.include "../../mk/bsd.pkg.mk"
