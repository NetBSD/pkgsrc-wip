# $NetBSD$

DISTNAME=	scikit-build-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scikit-build/scikit-build
COMMENT=	Improved build system generator for Python C/C++/Fortran/Cython
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-distro>=0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=28.0.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.29.0:../../devel/py-wheel

USE_LANGUAGES=	c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
