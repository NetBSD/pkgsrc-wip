# $NetBSD$

DISTNAME=	blocky-0.34.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=0xERR0R/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://github.com/0xERR0R/blocky/
COMMENT=	DNS proxy and ad-blocker for the local network written in Go
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

#USE_LANGUAGES=	#none
USE_TOOLS+=	gmake

MAKE_ENV+=	GO_SKIP_GENERATE=1

.include "go-modules.mk"

do-build:
	cd ${WRKSRC} && ${GMAKE} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/blocky \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
