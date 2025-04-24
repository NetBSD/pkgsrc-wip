# $NetBSD$

DISTNAME=	gosec-2.22.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=securego/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/securego/gosec
COMMENT=	Golang security checker
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.Version=${GITHUB_TAG} \
			-X main.GitTag=${GITHUB_TAG} \
			-X main.BuildDate='
GO_BUILD_PATTERN+=	./cmd/gosec

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
