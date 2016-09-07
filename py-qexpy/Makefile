# $NetBSD$

DISTNAME=	qexpy-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/61/87/15cf8be5acc2523b26eaf96f1e44630d11e0220903688ba80633c86768a0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Queens-Physics/QExPy
COMMENT=	Analysis and data plotting aimed at undergraduate physics
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-bokeh>=0.12.2:../../wip/py-bokeh

WRKSRC=		${WRKDIR}/qexpy-0.3.2

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
