# $NetBSD$

DISTNAME=	rom64-0.5.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=mroach/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mroach/rom64/
COMMENT=	Nintendo 64 ROM utility
LICENSE=	mit

USE_LANGUAGES=	# none

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
