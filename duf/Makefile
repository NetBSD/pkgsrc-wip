# $NetBSD$

DISTNAME=	duf-v0.7.0
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=muesli/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/muesli/duf/
COMMENT=	Disk Usage/Free Utility - a better df alternative
LICENSE=	mit AND modified-bsd

USE_LANGUAGES=	# none

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
