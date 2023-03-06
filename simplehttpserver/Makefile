# $NetBSD$

DISTNAME=	simplehttpserver-0.0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/simplehttpserver
COMMENT=	Go alternative of python SimpleHTTPServer
LICENSE=	mit

DOCDIR=		share/doc/simplehttpserver

INSTALLATION_DIRS+=	${DOCDIR}

.include "go-modules.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${DOCDIR}/README.md

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
