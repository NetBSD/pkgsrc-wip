# $NetBSD: Makefile,v 1.1 2015/06/10 21:51:12 jihbed Exp $

DISTNAME=	cf-python-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cf-python/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cfpython.bitbucket.org/
COMMENT=	Python interface to the CF data model
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	30 34 35 36 37

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-psutil-2.1.3:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-netcdf4>=1.1.8:../../wip/py-netcdf4

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
