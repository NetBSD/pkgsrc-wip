# $NetBSD$

DISTNAME=	weblib-0.1.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=w/weblib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/w/weblib/
COMMENT=	Set of tools for web scraping projects
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.4.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-user_agent>=0.1.0:../../wip/py-user_agent
DEPENDS+=	${PYPKGPREFIX}-tils>=0.3:../../wip/py-tils

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
