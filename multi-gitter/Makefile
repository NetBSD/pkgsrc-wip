# $NetBSD$

DISTNAME=	multi-gitter-0.42.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=lindell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lindell/multi-gitter
COMMENT=	CLI to update multiple repositories in bulk
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${PKGVERSION_NOREV} \
			-X main.commit= \
			-X main.date='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
