# $NetBSD$

DISTNAME=	constructive_geometries-0.7
PKGNAME=	${PYPKGPREFIX}-constructive-geometries-0.7
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/constructive_geometries/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cmutel/constructive_geometries
COMMENT=	Simple tools to define world locations from a set of topological faces and set algebra
#LICENSE=	Copyright (c) 2016, Chris Mutel and Paul Scherrer Institute

DEPENDS+=	${PYPKGPREFIX}-country-converter>=0.7.2:../../wip/py-country-converte
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.12.1:../../devel/py-wrapt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
