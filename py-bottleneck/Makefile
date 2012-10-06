# $NetBSD: Makefile,v 1.2 2012/10/06 17:22:16 asau Exp $
#

DISTNAME=	bottleneck-0.1.0dev
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/B/Bottleneck/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://berkeleyanalytics.com/bottleneck/
COMMENT=	Fast, NumPy array functions written in Cython
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

WRKSRC=	${WRKDIR}/Bottleneck-0.1.0dev

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
