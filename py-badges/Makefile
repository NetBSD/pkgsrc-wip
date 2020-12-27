# $NetBSD$

DISTNAME=	pybadges-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybadges/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/google/pybadges
COMMENT=	Library and command-line tool for generating Github-style badges
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-fonttools>=3.26:../../fonts/py-fonttools
BUILD_DEPENDS+=	${PYPKGPREFIX}-nox-[0-9]*:../../wip/py-nox
BUILD_DEPENDS+=	${PYPKGPREFIX}-Pillow>=5:../../graphics/py-Pillow
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=6.1.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.0,<3:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
