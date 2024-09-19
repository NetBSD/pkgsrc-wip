# $NetBSD: Makefile,v 1.1 2015/08/01 22:23:14 jihbed Exp $

DISTNAME=	pydy-viz-0.1.0
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydy-viz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydy/pydy-viz/
COMMENT=	Browser based 3D visualization of multibody simulations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
