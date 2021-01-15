# $NetBSD$

DISTNAME=	spherical-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spherical/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/moble/spherical
COMMENT=	Evaluate and transform D matrices 3-j symbols, and spherical harmonics
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-quaternionic>=0.2.0:../../wip/py-quaternionic
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy


BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
