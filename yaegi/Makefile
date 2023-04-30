# $NetBSD$

DISTNAME=	yaegi-0.15.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=traefik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/traefik/yaegi
COMMENT=	Another Elegant Go Interpreter
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/yaegi

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
