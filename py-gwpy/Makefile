# $NetBSD: Makefile,v 1.1 2015/08/05 20:41:42 jihbed Exp $

DISTNAME=	gwpy-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gwpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://gwpy.github.io/
COMMENT=	Package to enable gravitational-wave astrophysics in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-astropy>=1.2.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-lscsoft-glue-[0-9]*:../../wip/py-lscsoft-glue
DEPENDS+=	${PYPKGPREFIX}-ligotimegps-[0-9]*:../../time/py-ligotimegps

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
BUILD_DEPENDS+=	${PYPKGPREFIX}-sqlparse-[0-9]*:../../databases/py-sqlparse

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-m2crypto via py-lscsoft-glue

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
