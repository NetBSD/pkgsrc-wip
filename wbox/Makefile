# $NetBSD: Makefile,v 1.6 2012/11/14 00:16:17 othyro Exp $
#

DISTNAME=		wbox-5
CATEGORIES=		www
MASTER_SITES=		http://www.hping.org/wbox/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.hping.org/wbox/
COMMENT=		HTTP testing tool
LICENSE=		modified-bsd

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbox ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
