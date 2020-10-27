# $NetBSD$

DISTNAME=	fastapi-0.61.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=   ${MASTER_SITE_PYPI:=f/fastapi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://fastapi.tiangolo.com/
COMMENT=	High performance, easy to learn, fast to code, ready for production
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-jose>=3.1.0:../../wip/py-jose
BUILD_DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.2:../../wip/py-passlib
BUILD_DEPENDS+=	${PYPKGPREFIX}-autoflake>=1.3.1:../../wip/py-autoflake
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.3:../../wip/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-uvicorn>=0.11.5:../../www/py-uvicorn
BUILD_DEPENDS+=	${PYPKGPREFIX}-graphene>=2.1.8:../../wip/py-graphene
DEPENDS+=	${PYPKGPREFIX}-starlette>=0.13.6:../../wip/py-starlette
DEPENDS+=	${PYPKGPREFIX}-dantic>=1.0.0../../wip/py-dantic

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
