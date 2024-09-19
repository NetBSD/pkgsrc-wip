# $NetBSD$

DISTNAME=	cppimport-20.8.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cppimport/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tbenthompson/cppimport
COMMENT=	Import C++ files directly from Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mako>=0:../../devel/py-mako

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-pybind11+=	${PYPKGPREFIX}-pybind11>=2.5.0
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
