# $NetBSD$

GITHUB_PROJECT=	esbuild
GITHUB_TAG=	v0.12.22
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG:S,^v,,}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=evanw/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://esbuild.github.io/
COMMENT=	Fast JavaScript bundler and minifier
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
