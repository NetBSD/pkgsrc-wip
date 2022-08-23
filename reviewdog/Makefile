# $NetBSD$

DISTNAME=	reviewdog-0.14.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=reviewdog/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/reviewdog/reviewdog
COMMENT=	Automated code review tool integrated with any code analysis
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/reviewdog/reviewdog/commands.Version==${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/reviewdog

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
