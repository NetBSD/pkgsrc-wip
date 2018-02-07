# $NetBSD$

DISTNAME=	qexpy-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qexpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Queens-Physics/QExPy
COMMENT=	Analysis and data plotting aimed at undergraduate physics
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-bokeh>=0.12.2:../../wip/py-bokeh
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
