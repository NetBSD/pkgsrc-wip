# $NetBSD$

DISTNAME=	cymem-2.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cymem/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/explosion/cymem
COMMENT=	Manage calls to calloc/free through Cython
LICENSE=	mit

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.py-cython+=       ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
