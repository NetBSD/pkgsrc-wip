# $NetBSD: Makefile,v 1.12 2014/01/19 20:34:14 thomasklausner Exp $

DISTNAME=	Astropysics-0.1.dev-r596
PKGNAME=	${PYPKGPREFIX}-Astropysics-0.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Astropysics/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.physics.uci.edu/~etolleru/software.html#astropysics
COMMENT=	Astrophysics libraries for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-fits>=2.3.1:../../graphics/py-fits

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

#WRKSRC=		${WRKDIR}/Astropysics-0.1.dev-r596
EGG_NAME=	${DISTNAME:S/-r596//}
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
