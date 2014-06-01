# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:46 thomasklausner Exp $

DISTNAME=	sunpy-0.3.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/sunpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.sunpy.org/
COMMENT=	Python for Solar Physicists
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-fits>=2.4.0:../../graphics/py-fits
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.11.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy


WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
