# $NetBSD: Makefile,v 1.9 2012/10/12 11:46:59 asau Exp $
#

DISTNAME=	pycvf-0.2.0
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	http://master.dl.sourceforge.net/project/pycvf/0.2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pycvf.sourceforge.net/
COMMENT=	Python Computer Vision Framework
LICENSE=	gnu-lgpl-v3


DEPENDS+=	${PYPKGPREFIX}-Pyro4>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=0.87.2
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
