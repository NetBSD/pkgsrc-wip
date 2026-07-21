# $NetBSD$

DISTNAME=	camel_converter-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/camel_converter/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/sanders41/camel-converter/
COMMENT=	Convert between camelCase and snake_case
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
