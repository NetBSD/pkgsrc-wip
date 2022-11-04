# $NetBSD$

DISTNAME=	pyls-spyder-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyls-spyder/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/pyls-spyder
COMMENT=	Spyder extensions for the python-lsp-server
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lsp-server>=1.0.1:../../wip/py-lsp-server

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
