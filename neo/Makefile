# $NetBSD$

DISTNAME=	neo-0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=owainlewis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/owainlewis/neo/
COMMENT=	AI-powered coding agent for the terminal
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/neo

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
