# $NetBSD$

DISTNAME=	flake8-polyfill-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-polyfill/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gitlab.com/pycqa/flake8
COMMENT=	Polyfill package for Flake8 plugins
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flakes>=0.8.1:../../devel/py-flakes

WRKSRC=		${WRKDIR}/flake8-polyfill-1.0.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
