# $NetBSD: Makefile,v 1.2 2009/09/25 09:11:07 bartoszkuzma Exp $
#

DISTNAME=		wbox-4
CATEGORIES=		wip www
MASTER_SITES=		http://www.hping.org/wbox/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.hping.org/wbox/
COMMENT=		HTTP testing tool
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=    user-destdir

WRKSRC=			${WRKDIR}/wbox

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbox ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
