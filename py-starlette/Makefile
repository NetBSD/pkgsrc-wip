# $NetBSD$
# NetBSD$

DISTNAME=	starlette-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=s/starlette/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.starlette.io/
COMMENT=	The little ASGI framework that shines
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-anyio>=3.6.2:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
