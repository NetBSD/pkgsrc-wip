# $NetBSD$

DISTNAME=	go-reflect2-1.0.1
GITHUB_PROJECT=	reflect2
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=modern-go/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/modern-go/reflect2
COMMENT=	Reflect api without runtime reflect.Value cost
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/modern-go/${GITHUB_PROJECT}

USE_TOOLS+=	bash:run

REPLACE_BASH+=	test.sh

.include "../../wip/go-concurrent/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
