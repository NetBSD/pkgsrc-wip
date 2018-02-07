# $NetBSD: Makefile,v 1.12 2014/01/19 20:34:14 thomasklausner Exp $

DISTNAME=	Astropysics-0.1.dev-r596
PKGNAME=	${PYPKGPREFIX}-Astropysics-0.1
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Astropysics/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.physics.uci.edu/~etolleru/software.html#astropysics
COMMENT=	Astrophysics libraries for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-fits>=2.3.1:../../graphics/py-fits
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

EGG_NAME=	${DISTNAME:S/-r596//}0
USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.1dev-r596

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
