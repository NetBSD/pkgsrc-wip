# $NetBSD$

DISTNAME=	quantities-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=python-quantities/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/quantities
COMMENT=	Support for physical quantities with units, based on numpy
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
