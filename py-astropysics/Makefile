# $NetBSD: Makefile,v 1.7 2012/10/06 17:13:32 asau Exp $
#

DISTNAME=	Astropysics-0.1.dev-r596
PKGNAME=	${PYPKGPREFIX}-Astropysics-0.1
PKGREVISION=	2
CATEGORIES=	physics
MASTER_SITES=	http://pypi.python.org/packages/source/A/Astropysics/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.physics.uci.edu/~etolleru/software.html#astropysics
COMMENT=	Astrophysics libraries for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../graphics/py-pyfits

#WRKSRC=		${WRKDIR}/Astropysics-0.1.dev-r596
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
