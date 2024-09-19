# $NetBSD$

DISTNAME=	mpld3-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpld3/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://mpld3.github.com
COMMENT=	D3 Viewer for Matplotlib
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
