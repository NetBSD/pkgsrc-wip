# $NetBSD$

DISTNAME=	aiohttp-jinja2-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-jinja2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://aiohttp-jinja2.readthedocs.io/en/stable/
COMMENT=	Jinja2 template renderer for aiohttp.web
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.9.6:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.5.4:../../www/py-aiohttp

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
