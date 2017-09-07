# $NetBSD$

GITHUB_PROJECT=	fiche
DISTNAME=	0.9
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=solusipse/}
DIST_SUBDIR=	${GITHUB_PROJECT}

AINTAINER=	tm@core.io
HOMEPAGE=	https://github.com/solusipse/fiche/
COMMENT=	Command line pastebin for sharing terminal output
LICENSE=	MIT

WRKSRC=	${WRKDIR}/fiche-0.9
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiche ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
