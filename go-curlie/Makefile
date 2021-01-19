# $NetBSD$

DISTNAME=	go-curlie-1.6.0
GITHUB_PROJECT=	curlie
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rs/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rs/curlie/
COMMENT=	The power of curl, the ease of use of httpie
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/rs/curlie

USE_TOOLS+=	bash:run

REPLACE_BASH+=	args/gen.sh

.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
