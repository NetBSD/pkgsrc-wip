# $NetBSD: $

DISTNAME=	typescript-7.0.2
CATEGORIES=	lang
GITHUB_PROJECT=	TypeScript
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://www.typescriptlang.org/
COMMENT=	Superset of JavaScript that compiles to clean JavaScript output
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}/tsc

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
