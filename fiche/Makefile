# $NetBSD$

DISTNAME=	fiche-0.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=solusipse/}

MAINTAINER=	tm@core.io
HOMEPAGE=	https://github.com/solusipse/fiche/
COMMENT=	Command line pastebin for sharing terminal output
LICENSE=	mit

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiche ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
