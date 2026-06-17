# $NetBSD$

DISTNAME=	doggo-1.1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mr-karan/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mr-karan/doggo/
COMMENT=	Connamd Line DNS client
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

GO_BUILD_PATTERN=	./cmd/doggo
GOFLAGS=		-ldflags="-X 'main.buildVersion=${PKGVERSION_NOREV}' -X 'main.buildDate=2026-01-01 00:00:00'"

.include "go-modules.mk"

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
