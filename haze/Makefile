# $NetBSD: Makefile,v 1.1.1.1 2007/11/07 20:23:37 haad Exp $
#

DISTNAME=	haze
CATEGORIES=	wip
MASTER_SITES=	http://www.netbsd.org/~elad/

MAINTAINER=	haaaad@gmail.com elad@netbsd.org
HOMEPAGE=	http://www.netbsd.org/~elad/
COMMENT=	Offer a system to generate binary updates for NetBSD.

WRKSRC= 	${WRKDIR}/haze

INSTALLATION_DIRS= sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/haze ${PREFIX}/sbin/haze 

.include "../../mk/bsd.pkg.mk"
