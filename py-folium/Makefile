# $NetBSD$

DISTNAME=	folium-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=f/folium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cheeseshop.python.org/pypi/folium
COMMENT=	Visualize leaflet.js maps in python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-branca>=0.3.0:../../wip/py-branca
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.9:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-pytest>=0:../../devel/py-test

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
