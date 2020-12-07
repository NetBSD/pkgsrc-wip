# $NetBSD$

DISTNAME=	sphinxcontrib-asyncio-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-asyncio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/aio-libs/sphinxcontrib-asyncio
COMMENT=	Sphinx extension to support coroutines in markup
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
