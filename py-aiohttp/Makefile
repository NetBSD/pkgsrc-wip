# $NetBSD$

DISTNAME=	aiohttp-0.22.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/KeepSafe/aiohttp/
COMMENT=	Http client/server for asyncio
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/aiohttp-0.22.3

PYTHON_VERSIONS_INCOMPATIBLE= 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
