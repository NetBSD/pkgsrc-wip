# $NetBSD$

DISTNAME=	jsonnet-bundler-0.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jsonnet-bundler/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jsonnet-bundler/jsonnet-bundler
COMMENT=	Jsonnet package manager
LICENSE=	apache-2.0

GOFLAGS+=		-ldflags ' \
			-X main.Version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/jb

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
