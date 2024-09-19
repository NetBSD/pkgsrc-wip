# $NetBSD$

DISTNAME=	dit-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dit.io/
COMMENT=	Python package for information theory
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-boltons>=21.0.0:../../devel/py-boltons
DEPENDS+=	${PYPKGPREFIX}-contextlib2>=0.6.0:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.5.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.3:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-prettytable>=2.1.0:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-debtcollector>=2.2.0:../../wip/py-debtcollector

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
