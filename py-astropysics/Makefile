# $NetBSD: Makefile,v 1.4 2011/04/24 18:42:08 jihbed Exp $
#

DISTNAME=	Astropysics-0.1.dev-r596
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics
MASTER_SITES=	http://pypi.python.org/packages/source/A/Astropysics/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.physics.uci.edu/~etolleru/software.html#astropysics
COMMENT=	Astrophysics libraries for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../wip/py-pyfits

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Astropysics-0.1.dev-r596
USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
