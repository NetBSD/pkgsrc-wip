# $NetBSD$

DISTNAME=	towncrier-19.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/towncrier/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hawkowl/towncrier
COMMENT=	Building newsfiles for your project
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-incremental>=17.5.0:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
