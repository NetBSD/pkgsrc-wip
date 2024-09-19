# $NetBSD$

DISTNAME=	grab-0.6.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grab/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://grablib.org
COMMENT=	Web Scraping Framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.4.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-user_agent>=0.1.0:../../wip/py-user_agent
DEPENDS+=	${PYPKGPREFIX}-selection>=0.0.11:../../wip/py-selection
DEPENDS+=	${PYPKGPREFIX}-weblib>=0.1.20:../../wip/py-weblib


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
