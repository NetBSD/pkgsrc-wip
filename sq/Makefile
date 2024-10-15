# $NetBSD$

DISTNAME=	sq-0.48.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=neilotoole/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sq.io/
COMMENT=	Jq-style access to structured data sources
LICENSE=	mit

GO_BUILD_PATTERN+=      -ldflags ' \
			-X github.com/neilotoole/sq/cli/buildinfo.Version=${PKGVERSION_NOREV} \
			-X github.com/neilotoole/sq/cli/buildinfo.Commit= \
			-X github.com/neilotoole/sq/cli/buildinfo.Timestamp='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
