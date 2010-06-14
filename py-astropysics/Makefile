# $NetBSD: Makefile,v 1.3 2010/06/14 15:16:22 jihbed Exp $
#

DISTNAME=	Astropysics-0.1.dev-r596.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/S/.tar//}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/A/Astropysics/
EXTRACT_SUFX=	.gz#md5=15cb8e36b433ba6660c67939d234c6af

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
