# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Thu Nov 21 15:57:10 CST 2024               #
###########################################################

DISTNAME=	orca-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orca/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/UDST/orca
COMMENT=	Python library for task orchestration
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.15.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-tables>=3.1:../../math/py-tables
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.1:../../devel/py-toolz

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
