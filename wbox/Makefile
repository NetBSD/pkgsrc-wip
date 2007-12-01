# $NetBSD: Makefile,v 1.1.1.1 2007/12/01 08:27:28 bartoszkuzma Exp $
#

DISTNAME=	wbox-4
CATEGORIES=	wip www
MASTER_SITES=	http://www.hping.org/wbox/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.hping.org/wbox/
COMMENT=	HTTP testing tool

WRKSRC=		${WRKDIR}/wbox

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbox ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
