# $NetBSD$

DISTNAME=	python-lsp-jsonrpc-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-lsp-jsonrpc/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-lsp/python-lsp-jsonrpc
COMMENT=	JSON RPC 2.0 server library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ujson>=3.0.0:../../textproc/py-ujson

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
