# $NetBSD$

DISTNAME=	holoviews-1.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/holoviews/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.holoviews.org/
COMMENT=	Plotting your data annotate your data and let it visualize itself
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-param>=1.10.0:../../wip/py-param
DEPENDS+=	${PYPKGPREFIX}-viz-comms>=0.7.3:../../wip/py-viz-comms
DEPENDS+=	${PYPKGPREFIX}-panel>=0.10.2:../../wip/py-panel
DEPENDS+=	${PYPKGPREFIX}-colorcet>=2.0.2:../../wip/py-colorcet
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
