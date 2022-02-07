# $NetBSD$

DISTNAME=	hey-0.1.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rakyll/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rakyll/hey
COMMENT=	HTTP load generator, ApacheBench (ab) replacement
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
