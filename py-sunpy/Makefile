# $NetBSD: Makefile,v 1.1 2013/09/06 18:35:09 jihbed Exp $

DISTNAME=	sunpy-0.3.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/sunpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.sunpy.org/
COMMENT=	Python for Solar Physicists
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.4.0:../../graphics/py-pyfits
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.11.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

FETCH_USING=	curl

WRKSRC=	${WRKDIR}/${DISTNAME}

PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
