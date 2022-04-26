# $NetBSD$

DISTNAME=	zed-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=brimdata/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brimdata/zed/
COMMENT=	Tooling for super-structured data
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

GO_BUILD_PATTERN=	cmd/zq

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
