# $NetBSD$

DISTNAME=	carburetta-0.8.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kingletbv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://carburetta.com/
COMMENT=	Fused scanner parser generator
LICENSE=	apache-2.0

USE_TOOLS=	gmake

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/carburetta
INSTALLATION_DIRS+=	share/doc/carburetta/examples
INSTALLATION_DIRS+=	share/doc/carburetta/examples/calc
INSTALLATION_DIRS+=	share/doc/carburetta/examples/inireader
INSTALLATION_DIRS+=	share/doc/carburetta/examples/template_scan

post-install:
	${INSTALL_DATA} ${WRKSRC}/readme.md \
		${DESTDIR}${PREFIX}/share/doc/carburetta
	${INSTALL_DATA} ${WRKSRC}/examples/calc/* \
		${DESTDIR}${PREFIX}/share/doc/carburetta/examples/calc
	${INSTALL_DATA} ${WRKSRC}/examples/inireader/* \
		${DESTDIR}${PREFIX}/share/doc/carburetta/examples/inireader
	${INSTALL_DATA} ${WRKSRC}/examples/template_scan/* \
		${DESTDIR}${PREFIX}/share/doc/carburetta/examples/template_scan

.include "../../mk/bsd.pkg.mk"
