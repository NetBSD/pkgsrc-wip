# $NetBSD$

DISTNAME=	pyvis-0.1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvis/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/WestHealth/pyvis
COMMENT=	Python network visualization library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=5.3.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.9.6:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
#DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-jsonpickle>=1.4.1:../../textproc/py-jsonpickle

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
