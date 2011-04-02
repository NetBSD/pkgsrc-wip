# $NetBSD: Makefile,v 1.1.1.1 2011/04/02 22:35:05 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/Bottleneck-0.1.0dev

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
