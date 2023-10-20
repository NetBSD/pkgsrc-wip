# $NetBSD$

DISTNAME=	go-curlie-1.7.1
GITHUB_PROJECT=	curlie
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rs/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rs/curlie/
COMMENT=	The power of curl, the ease of use of httpie
LICENSE=	mit

USE_TOOLS+=	bash:run

REPLACE_BASH+=	args/gen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/curlie ${DESTDIR}${PREFIX}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
