# $NetBSD$

DISTNAME=	camel-converter-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sanders41/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/sanders41/camel-converter/
COMMENT=	Convert between camelCase and snake_case
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
