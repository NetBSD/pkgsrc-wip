# $NetBSD: Makefile,v 1.4 2011/08/02 12:13:31 bartoszkuzma Exp $
#

DISTNAME=		wbox-5
CATEGORIES=		wip www
MASTER_SITES=		http://www.hping.org/wbox/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.hping.org/wbox/
COMMENT=		HTTP testing tool
LICENSE=		modified-bsd

INSTALLATION_DIRS=	bin

PKG_DESTDIR_SUPPORT=    user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbox ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
