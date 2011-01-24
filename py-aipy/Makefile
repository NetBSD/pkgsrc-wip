# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:36:05 jihbed Exp $
#

DISTNAME=	aipy-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	astronomy python
MASTER_SITES=	http://pypi.python.org/packages/source/a/aipy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://casper.berkeley.edu/astrobaki/index.php/AIPY
COMMENT=	Astronomical Interferometry in Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.3.4:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../wip/py-pyfits

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/aipy-0.9.1

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=	yes

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
