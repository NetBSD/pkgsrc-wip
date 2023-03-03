# $NetBSD$

DISTNAME=	yamlfmt-0.7.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/yamlfmt
COMMENT=	Extensible command line tool or library to format yaml files
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd/yamlfmt

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
